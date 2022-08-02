#include <iostream>
#include <pthread.h>
#include <semaphore.h>

using namespace std;
#define MAX_THREAD 10

void* foo1(void* vargp) {
	int myid;
	myid = *((int*)vargp);
	free(vargp);
	printf("thread %d\n", myid);
}

void test1() { // no race: heap data
	pthread_t tid[MAX_THREAD];
	int i, *ptr;
	for (i = 0; i < MAX_THREAD; ++i) {
		ptr = (int*)malloc(sizeof(int*));
		*ptr = i;
		pthread_create(&tid[i], 0, foo1, ptr);
	}
	for (size_t j = 0; j < MAX_THREAD; ++j) pthread_join(tid[j], 0);
}

void* foo2(void* vargp) {
	int myid;
	myid = *((int*)vargp);
	printf("thread %d\n", myid);
}

void test2() { // race: stack data
	pthread_t tid[MAX_THREAD];
	int i;
	for (i = 0; i < MAX_THREAD; ++i) {
		pthread_create(&tid[i], 0, foo2, &i);
	}
	for (size_t j = 0; j < MAX_THREAD; ++j) pthread_join(tid[j], 0);
}

// follow part is semaphore
sem_t sem;
void* foo4(void* vargp) {
	int myid;
	sem_wait(&sem); // sem - 1
	myid = *((int*)vargp);
	sem_post(&sem); // sem + 1
	printf("thread %d\n", myid);
}

void test4() { // race
	pthread_t tid[MAX_THREAD];
	int i;
	sem_init(&sem, 0, 1);
	for (i = 0; i < MAX_THREAD; ++i) {
		pthread_create(&tid[i], 0, foo4, &i);
	}
	for (size_t j = 0; j < MAX_THREAD; ++j) pthread_join(tid[j], 0);
}

void* foo5(void* vargp) {
	int myid;
	myid = *((int*)vargp);
	sem_post(&sem);
	printf("thread %d\n", myid);
}

void test5() { // race
	pthread_t tid[MAX_THREAD];
	int i;
	sem_init(&sem, 0, 1);
	for (i = 0; i < MAX_THREAD; ++i) {
		pthread_create(&tid[i], 0, foo5, &i);
		sem_wait(&sem);
	}
	for (size_t j = 0; j < MAX_THREAD; ++j) pthread_join(tid[j], 0);
}

void* foo6(void* vargp) {
	int myid;
	myid = *((int*)vargp);
	printf("thread %d\n", myid);
	sem_post(&sem);
}

void test6() { // no race and ordered
	pthread_t tid[MAX_THREAD];
	int i;
	sem_init(&sem, 0, 1);
	for (i = 0; i < MAX_THREAD; ++i) {
		sem_wait(&sem);
		pthread_create(&tid[i], 0, foo6, &i);
	}
	for (size_t j = 0; j < MAX_THREAD; ++j) pthread_join(tid[j], 0);
}

void* foo7(void* vargp) {
	int myid;
	myid = *((int*)vargp);
	printf("thread %d\n", myid);
}

void test7() { // race
	pthread_t tid[MAX_THREAD];
	int i;
	sem_init(&sem, 0, 1);
	for (i = 0; i < MAX_THREAD; ++i) {
		sem_wait(&sem);
		pthread_create(&tid[i], 0, foo7, &i);
		sem_post(&sem);
	}
	for (size_t j = 0; j < MAX_THREAD; ++j) pthread_join(tid[j], 0);
}

void* foo8(void* vargp) {
	int myid;
	myid = *((int*)vargp);
	sem_post(&sem);
	printf("thread %d\n", myid);
}

void test8() { // no race
	pthread_t tid[MAX_THREAD];
	int i;
	sem_init(&sem, 0, 0);
	for (i = 0; i < MAX_THREAD; ++i) {
		pthread_create(&tid[i], 0, foo8, &i);
		sem_wait(&sem);
	}
	for (size_t j = 0; j < MAX_THREAD; ++j) pthread_join(tid[j], 0);
}

int main() {
	test6();
	return 0;
}