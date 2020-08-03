//
//  main.c
//  №3.6 "Площадь фигуры"
//
//  Created by Тастеков Адиль Азатович on 15.10.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

typedef struct {
    int x;
    int y;
} point;


int main(int argc, const char * argv[]) {
    
    int n;
    scanf("%d", &n);
    
    point p[100];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].x);
        scanf("%d", &p[i].y);
    }
    
    point min = p[0];
    point max = p[0];
    
    for (int i = 1; i < n; i++) {
        if (p[i].x < min.x) min.x = p[i].x;
        if (p[i].x > max.x) max.x = p[i].x;
        if (p[i].y < min.y) min.y = p[i].y;
        if (p[i].y > max.y) max.y = p[i].y;
    }
    
    int line[100];
    int l = 0, s = 0;
    
    int timeLine[100];
    int count = 0, count_plus = 0;;
    
    for (int k_y = min.y; k_y < max.y; k_y++) {
        for (int i = 0; i < n; i++) {
            if (p[i].y == k_y) {
                timeLine[count] = p[i].x;
                count++;
            }
        }
        
        qsort(timeLine, count, sizeof(int), cmp);
        
        for (int l = 0; l < count; l += 2) {
            for (int j = 1; j < timeLine[l + 1] - timeLine[l]; j++) {
                timeLine[count + j] = timeLine[l + j];
            }
            count_plus += timeLine[l + 1] - timeLine[l];
        }
        
        for (int i = 0; i < count_plus; i++) {
            p[n + i + 1].x = timeLine[count + i + 1];
            p[n + i + 1].y = k_y;
        }
        
        n += count_plus;
        count = 0;
        count_plus = 0;
    }
    
    for (int k_y = min.y; k_y < max.y; k_y++) {
        for (int i = 0; i < n; i++) {
            if (p[i].y == k_y) {
                line[l] = p[i].x;
                l++;
            }
        }
        qsort(line, l, sizeof(int), cmp);
        
        
        
        s += line[l - 1] - line[0];
        for (int i = 0; i < l; i++) {
        line[i] = 0;
        }
        l = 0;
    }
    
    printf("%d\n", s);

    return 0;
}
