//
//  main.cpp
//  Test progg
//
//  Created by Тастеков Адиль Азатович on 28.09.17.
//  Copyright © 2017 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <signal.h>

// Структура для удобной записи названий программ
typedef struct {
    char* name[100];
    int count;
} proggr;

#define FTOK_FILE "sem"

key_t key; //ключ для ftok
int count; // общее количество подаваемых программ
proggr list;
pid_t *pid; // массив для значений id процессов
int sem_id = -1; // id семафора

void cleanup () { // Функция, при завершении программы удаляющая все
    for (int i = 0; i < count; i++) {
        if (pid[i] > 0)
            kill(pid[i], SIGTERM);
    }
    if (sem_id >= 0)
        semctl(sem_id, 0, IPC_RMID);
}

void pexit (char const* str) { // Функция для завершения программы при ошибке
    perror(str);
    exit(1);
}

void tired_to_wait() { // Функция для завершения программы при превышении количества ожидающих
    printf("Слишком много ожидающих программ\n");
    exit(1);
}

void P() { // Функция ожидания пока семафор не разрешит программе выполняться, блокирующая семафор при начале выполнии программы
    struct sembuf wait[] = {{1, 0, 0}, {1, 1, 0}};
    if (semop(sem_id, wait, 2) < 0)
        pexit("semop");
}

void V() { // Функция разблокирующая семафор при успешном выполнении программы
    struct sembuf unlock[] = {{1, -1, 0}};
    if (semop(sem_id, unlock, 1) < 0)
        pexit("semop");
}

int main () {
    int i, N, W;
    int executing = 0, waiting = 0;
    
    atexit(cleanup); // При завершении программы вызывается cleanup
    
    // Ввод всех необходимых данных
    printf("Введите количество программ: ");
    scanf("%d", &count);
    printf("Введите максильное число выполняемых программ: ");
    scanf("%d", &N);
    printf("Введите максильное число ожидающих программ: ");
    scanf("%d", &W);
    
    char* str;
    //printf("Введите %d названий программ: \n", count);
    /*for (i = 0; i < count; i++) {
        scanf("%s", str);
        list.name[i] = str;
    }*/
    list.name[0] = "/Users/adil9kzn/Documents/Программы/Задание по информатике, МФТИ, 2курс/x.c files/hello";
    list.name[1] = "/Users/adil9kzn/Documents/Программы/Задание по информатике, МФТИ, 2курс/x.c files/sum";
    list.count = count;
    pid = (pid_t*)malloc(sizeof(pid_t) * count);
    
    // Создание семафора
    key = ftok(FTOK_FILE, 0);
    if ((sem_id = semget(key, 2, IPC_CREAT | IPC_EXCL | 0600)) < 0)
        pexit("semget");
    if (semctl(sem_id, 1, SETVAL, 0) < 0)
        pexit("semctl");
    
    for (i = 0; i < count; i++) { // Здесь запускаются и выполняются N программ
        pid[i] = fork(); // делим процесс на два
        switch (pid[i]) {
            case -1:
                pexit("fork");
            case 0:
                if (executing < N) { // если пока что не запущено макс кол-во программ N запускаем программу
                    printf("Выполняем программу номер %d:\n", i + 1);
                    printf("Executing: %d\n", executing);
                    executing++;
                    execl(list.name[i], NULL);
                    executing--;
                } else {
                    waiting++; // если уже запущено N программ, встаем в очередь
                    if (waiting >= W) //если очередь слишком большая сообщаем об этом и завершаемся с ошибкой
                        tired_to_wait();
                    P(); // тут вот ждем
                    waiting--; // дождались и заблокировали семафор
                    
                    executing++; // начинаем выполняться
                    printf("Выполняем программу номер %d:\n", i + 1);
                    execl(list.name[i], NULL);
                    executing--; // выполнились
                    
                    V(); // разблокировали семафор
                }
            default:
                waitpid(pid[i], NULL, 0);
        }
    }
    return 0;
}
