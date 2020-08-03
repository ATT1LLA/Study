//
//  main.c
//  №3.3 "Числа Фибоначчи"(рекурсивно)
//
//  Created by Тастеков Адиль Азатович on 10.10.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int fib (int* arr, int n) {
    if (n < 2) {
        arr[n] = 1;
    } else {
        if (arr[n] == 0) {
            arr[n] = fib(arr, n - 1) + fib(arr, n - 2);
        }
    }
    return arr[n];
}

int main(int argc, const char * argv[]) {
    
    int n;
    
    scanf("%d", &n);
    
    int* arr = (int*)malloc((n + 1) * sizeof(int));
    
    for (int i = 0; i < n + 1; i++) {
        arr[i] = 0;
    }
    
    /*for (int i = 0; i < n; i++) {
        printf ("%d\t" ,fib(arr, i));
    }
    
    printf("\n");*/
    
    printf ("%d\t" ,fib(arr, n - 1));
    
    return 0;
}
