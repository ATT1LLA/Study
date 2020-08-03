//
//  main.c
//  №1.2 Перевод в двоичную СИ(отриц. число)
//
//  Created by Тастеков Адиль Азатович on 21.05.17.
//  Copyright © 2017 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, const char * argv[]) {
    int var, var_s;
    
    scanf("%d", &var);
    
    var_s = -var;
    
    int counter = 0;
    bool* res = (bool*)malloc(sizeof(bool));
    char rest;
    
    while (var != 0) {
        
        if (var % 2 == 0)
            rest = 0;
        else
            rest = 1;
        
        var /= 2;
        counter++;
        
        res = (bool*)realloc(res, counter);
        res[counter - 1] = rest;
    }
    
    printf ("Число %d в двоичной системе исчисления: ", var_s);
    
    for (int i = counter - 1; i >= 0; i--) {
        if (res[i])
            printf("%d", 1);
        else
            printf("%d", 0);
    }
    
    printf("\n");
    
    for (int i = counter - 2; i >= 0; i--) {
        res[i] = res[i] ^ 1;
    }
    
    for (int i = 0; i < counter; i++) {
        if (res[i]) {
            res[i] = 0;
        } else {
            res[i] = 1;
            break;
        }
    }
    
    printf ("Дополнительный код %d в двоичной системе исчисления: ", -var_s);
    
    for (int i = counter - 1; i >= 0; i--) {
        if (res[i])
            printf("%d", 1);
        else
            printf("%d", 0);

    }
    
    printf("\n");
    
    return 0;
}
