//
//  main.cpp
//  Lesson_2
//
//  Created by Тастеков Адиль Азатович on 14.09.17.
//  Copyright © 2017 Тастеков Адиль Азатович. All rights reserved.
//
//  !!!!!Компилировать через терминал!!!!!


#include <iostream>
#include "sys/types.h"
#include <unistd.h>
#include <stdio.h>

using namespace std;

int main(int argc, const char * argv[], char** env) {
    
    cout << "Hello\n";
    
    int fork_1 = fork();
    
    if (fork_1 == 0) {
        
        int fork_2 = fork();
        
        if (fork_2 == 0) {
            execl(argv[2], argv[2], 0);
        } else {
            execl(argv[3], argv[3], 0);
        }
        
    } else {
        execl(argv[1], argv[1], 0);
    }
    
    cout << "World!\n";
    
    return 0;
}
