//
//  main.c
//  №3.1 "Max"
//
//  Created by Тастеков Адиль Азатович on 10.10.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    
    int n;
    
    scanf("%d", &n);
    
    int per;
    
    scanf("%d", &per);
    
    int max = per;
    
    for (int i = 1; i < n; i++) {
        scanf("%d", &per);
        if (max < per) max = per;
    }
    
    printf("%d\n", max);
    
    return 0;
}
