//
//  main.c
//  №3.2 "Числа Фибоначчи"(не рекурсивно)
//
//  Created by Тастеков Адиль Азатович on 10.10.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    int n;
    
    scanf("%d", &n);
    
    int* arr = (int*)malloc((n + 1) * sizeof(int));
    
    arr[1] = 1;
    arr[2] = 1;
    
    for (int i = 3; i < n + 1; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    
    printf("%d\n", arr[n]);
    
    return 0;
}
