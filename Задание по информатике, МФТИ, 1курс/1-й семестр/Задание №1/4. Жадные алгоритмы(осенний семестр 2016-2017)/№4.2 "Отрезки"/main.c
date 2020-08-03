//
//  main.c
//  №4.2 "Отрезки"
//
//  Created by Тастеков Адиль Азатович on 10.10.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    double left;
    double right;
} segment;

int main(int argc, const char * argv[]) {
    int n;
    
    scanf("%d", &n);
    
    segment* little_segm = (segment*)malloc(n * sizeof(segment));
    
    for (int i = 0; i < n; i++) {
        scanf("%lf", &little_segm[i].left);
        scanf("%lf", &little_segm[i].right);
    }
    
    segment S;
    S.left = 0;
    S.right = 10;
    
    double max = 0;
    int max_pointer = 0, counter = 0;
    
    printf("Множество отрезков:\n");
    while (S.left < S.right) {
        for (int i = 0; i < n; i++) {
            if (little_segm[i].left <= S.left) {
                if (max < little_segm[i].right) {
                    max = little_segm[i].right;
                    max_pointer = i;
                }
            }
        }
        counter++;
        printf("%d. [%lf; %lf]\n", counter, little_segm[max_pointer].left, little_segm[max_pointer].right);
        S.left = little_segm[max_pointer].right;
    }
    return 0;
}
