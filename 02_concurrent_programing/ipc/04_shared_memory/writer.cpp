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

void writeMemory() {
    key_t key = ftok(pathname, 0x03);
    if (key == -1) return ;
    int shm_id = shmget(key, 4096, IPC_CREAT | 0600);
    if (shm_id == -1) return ;
    people* p_map = (people*)shmat(shm_id, NULL, 0);

    char temp[8] = "abcdefg";
    for (int i = 0; i < 3; i++) {
        memcpy((p_map + i)->name, &temp[i], 5);
        (p_map + i)->age = 0 + i;
    }

    shmdt(p_map);
}

int main(int argc, char** argv) {
    writeMemory();
    return 0;
}