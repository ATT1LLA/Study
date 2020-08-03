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
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>
#include <time.h>
#include <sys/wait.h>

//Структура с названиями программ и временем их выполнения (для удобства)
typedef struct {
    int time[100];
    char* name[100];
    int count;
} proggr;
/**/
//Функция, читающая файл и записывающая время выполнения программы и ее название в структуру proggr
proggr read_file(char* filename) {
    proggr proggr;
    proggr.count = 0;
    for (int i = 0; i < 100; i++) {                             // На всякий случай заполняем массив со временем нулями
        proggr.time[i] = 0;
    }
    int fd, char_count = 0;;
    char ch;
    bool flag_time = 1, flag_name = 0;
    ssize_t ret;
    
    fd = open(filename, O_RDONLY | O_CREAT, 666);
    if (fd < 0) {
        printf("fopen: Can't open the file\n");                 // Если fd < 0 выводим ошибку и останавливаем выполнение программы
        exit(1);
    }
    
    while ((ret = read(fd, &ch, 1) > 0)) {
        /* Пока не дошли до пробела записываем символы из файла в time
         После того как дошли до пробела, опускаем флаг времени и поднимаем флаг названия
         Пока не дойдем до перевода строки записываем символы в строку названия
         После записи всей строки опускаем оба флагаб меняем счетчики и переходим на следующую строчку в файле
         (я не хотел делать все динамически, т.к. забыл как динамически создавать двумерный массив, но при желании это можно сделать) */
        if (ch == ' ' && !(flag_name)) {
            flag_time = 0;
            flag_name = 1;
        }
        if (ch == '\n') {
            flag_time = 0;
            flag_name = 0;
        }
        if (flag_time) {
            /*if (ch - '0' < 0 || ch - '0' > 9) {
             printf("Неверный формат ввода: Время должно быть записано в цифрах.\n");
             }*/
            proggr.time[proggr.count] = proggr.time[proggr.count] * 10 + (int)(ch - '0');
        }
        if (flag_name) {
            /*if (ch == ' ') {
             printf("Неверный формат ввода: В названии программы не должно быть пробелов.\n");
             exit(1);
             }*/
            proggr.name[proggr.count] = (char*)realloc(proggr.name[proggr.count], char_count + 1);
            proggr.name[proggr.count][char_count - 1] = ch;
            char_count++;
        }
        if (!(flag_name || flag_time)) {
            flag_time = 1;
            flag_name = 0;
            char_count = 0;
            proggr.count++;
        }
    }
    
    if (ret < 0) {
        printf("read: Can't read file\n");                       // Если ret < 0 выводим ошибку и останавливаем выполнение программы
        exit(1);
    }
    close (fd);
    return proggr;
}

int main(int argc, const char * argv[]) {
    char* filename = "/Users/adil9kzn/Documents/Программы/Задание по информатике, МФТИ, 2курс/x.c files/test.txt"; // На маке нужно вводить полный путь
    proggr progg;
    pid_t pid;
    int exec, counter;
    
    progg = read_file(filename);
    counter = progg.count;
    
    printf ("Программ в файле %d:\n", progg.count + 1);
    printf("- time: %d, name: %s\n", progg.time[0], progg.name[0]);
    printf("- time: %d, name: %s\n", progg.time[1], progg.name[1]);
    printf("Исполнение данных программ:\n");
    printf("---------------------------------------------\n");
    
    for (int i = 0; i <= progg.count; i++) {
        switch(pid = fork()) {
            case -1:
                perror("fork"); /* произошла ошибка */
                exit(1); /*выход из родительского процесса*/
            case 0:
                //printf(" CHILD: Это процесс-потомок!\n");
                if (progg.name[i] != "/Users/adil9kzn/Documents/Программы/useless") {
                    printf(" Пауза в секундах: %d\n", progg.time[i]);
                    sleep(progg.time[i]);
                    printf(" Proggram %s is executing:\n", progg.name[i]);
                    printf("- Result:\n");
                    execl(progg.name[i], NULL);
                } else {
                    printf("error: Эта программа не вызывает сама себя\n");
                }
                exit(0);
            default:
                //printf("PARENT: Это процесс-родитель!\n");
                waitpid(pid, NULL, 0);
                //printf("PARENT: Выход!\n");
                printf("---------------------------------------------\n");
        }
    }
    exit(0);
}
