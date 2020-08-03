//
//  main.c
//  №4.3 "Коммивояжер"
//
//  Created by Тастеков Адиль Азатович on 10.10.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} point;

double r(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main(int argc, const char * argv[]) {
    int n;
    
    scanf("%d", &n);
    
    point* p = (point*)malloc(n * sizeof(point));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].x);
        scanf("%d", &p[i].y);
    }
    
    double path_length = 0;
    double min_s = 100000000;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                printf("%lf\t", r(p[i], p[j]));
                if (min_s > r(p[i], p[j])) {
                    min_s = r(p[i], p[j]);
                }
            }
        }
        printf("\n%lf\n-----------------\n", min_s);
        if (min_s != 100000000) {
            path_length += min_s;
            min_s = 100000000;
        }
    }
    
    printf("%lf\n", path_length);
    return 0;
}
