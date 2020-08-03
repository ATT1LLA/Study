//
//  main.c
//  №1.1 "Перевод в двоичную СИ"
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
    
    var_s = var;
    
    int counter = 0;
    char* res = (char*)malloc(sizeof(char));
    char rest;
    
    while (var != 0) {
    
        if (var % 2 == 0)
            rest = '0';
        else
            rest = '1';
        
        var /= 2;
        counter++;
        
        res = (char*)realloc(res, counter);
        res[counter - 1] = rest;
    }
    
    printf ("Число %d в двоичной системе исчисления: ", var_s);
    
    for (int i = counter - 1; i >= 0; i--) {
        printf("%c", res[i]);
    }

    printf("\n");
    
    return 0;
}
