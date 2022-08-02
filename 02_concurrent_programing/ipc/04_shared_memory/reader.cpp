#include <iostream>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
using namespace std;

typedef struct {
    char name[8];
    int age;
} people;

char pathname[30] = "/tmp";

void readMemory() {
    key_t key = ftok(pathname, 0x03);
    if (key == -1) return ;
    int shm_id = shmget(key, 0, 0);
    if (shm_id == -1) return ;
    people* p_map = (people*)shmat(shm_id, NULL, 0);

    for (int i = 0; i < 3; i++) {
        cout << "name: " << (*(p_map + i)).name << endl;
        cout << "age: " << (*(p_map + i)).age << endl;
    }

    shmdt(p_map);
}

int main() {
    readMemory();
    return 0;
}