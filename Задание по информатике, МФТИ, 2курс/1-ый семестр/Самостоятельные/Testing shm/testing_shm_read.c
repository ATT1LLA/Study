//
//  main.cpp
//  Test progg
//
//  Created by Тастеков Адиль Азатович on 28.09.17.
//  Copyright © 2017 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>

int n = 100000;

int main() {
    char c = '0';
    char* path = "/Users/adil9kzn/Documents/Программы/Задание по информатике, МФТИ, 2курс/Самостоятельные/Testing shm/shared_mem.txt";
    key_t shm_key;
    int shm_id;
    int* shm_adr;
    int pid;
    int count_child = 0, count_parent = 0;
    
    shm_key = ftok(path, c);
    if (shm_key < 0) {
        printf("ftok error/n");
        printf("errno: %d/n", errno);
        exit(-1);
    }
    
    shm_id = shmget(shm_key, (2 * n) * sizeof(int), 0777|IPC_CREAT);
    if (shm_id < 0) {
        if (errno == EEXIST) {
            printf("shmget: Can't create memory\n");
            exit(-1);
        } else {
            shm_id = shmget(shm_key, (2 * n) * sizeof(int), 0);
            if (shm_id < 0) {
                printf("shmget: Can't find shared memory\n");
                printf("errno: %d\n", errno);
                exit(-1);
            }
        }
    }
    
    shm_adr = (int*)shmat(shm_id, NULL, 0);
    if (shm_adr == (int*)(-1)) {
        printf("shmat: Can't get address");
        printf("errno: %d/n", errno);
        exit(-1);
    }
    
    for(int i = 0; i < (2 * n); i++) {
        printf ("%d\t", shm_adr[i]);
    }
    
    shmctl(shm_id, IPC_RMID, NULL);
    
    exit(0);
}
