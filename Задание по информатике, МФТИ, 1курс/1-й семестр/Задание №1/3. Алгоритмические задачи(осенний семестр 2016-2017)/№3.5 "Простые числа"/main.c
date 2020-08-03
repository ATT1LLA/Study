//
//  main.c
//  №3.5 "Простые числа"
//
//  Created by Тастеков Адиль Азатович on 15.10.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int main(int argc, const char * argv[]) {
    
    int n;
    scanf("%d", &n);
    
    bool flag = 1;
    int i = 2;
    while (flag && (i < sqrt(n))) {
        if (n % i == 0) flag = 0;
        i++;
    }
    
    if (flag)
        printf("Prostoe\n");
    else
        printf("Sostavnoe\n");
    
    return 0;
}
