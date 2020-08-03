//
//  main.c
//  №4.3 for, while, do while in asm
//
//  Created by Тастеков Адиль Азатович on 23.05.17.
//  Copyright © 2017 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int arr[10], i;
    
    for (i = 0; i < 10; i++) {
        arr[i] = i;
    }
    
    /*printf("for: ");
    for (i = 0; i < 10; i++) {
        printf ("%d ", arr[i]);
    }
    printf("\n");*/
    
    i = 0;
    
    while (i < 10) {
        arr[i] = i;
        i++;
    }
    
    /*printf("while: ");
    for (i = 0; i < 10; i++) {
        printf ("%d ", arr[i]);
    }
    printf("\n");*/
    
    i = 0;
    
    do {
        arr[i] = i;
        i++;
    } while (i < 9);
    
    /*printf("do while: ");
    for (i = 0; i < 10; i++) {
        printf ("%d ", arr[i]);
    }
    printf("\n");*/
    
    return 0;
}
