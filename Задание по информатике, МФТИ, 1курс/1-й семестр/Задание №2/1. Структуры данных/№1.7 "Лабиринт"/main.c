//
//  main.c
//  №1.7 "Лабиринт"
//
//  Created by Тастеков Адиль Азатович on 14.11.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>

#define Stack_Max_Size 100

typedef struct point {
    int x;
    int y;
} point;

typedef point T;

typedef struct Stack_tag {
    T data[Stack_Max_Size];
    size_t size;
} Stack_t;

void push(Stack_t *stack, const T value) {
    stack->data[stack->size] = value;
    stack->size++;
}

T pop(Stack_t *stack) {
    stack->size--;
    return stack->data[stack->size];
}


int main(int argc, const char * argv[]) {

    int lab[10][10];
    int n, m, i, j;
    
    scanf("%d", &n);
    scanf("%d", &m);
    
    for (i = 0; i <= m + 1; i++) {
        for (j = 0; j <= n + 1; j++) {
            lab[i][j] = 0;
        }
    }
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &lab[i + 1][j + 1]);
        }
    }
    
    Stack_t stack;
    stack.size = 0;
    
    point lab_point, trash;
    
    if (lab[1][1] == '0') {
        printf("NO");
    } else {
        lab_point.x = 1; i = 1;
        lab_point.y = 1; j = 1;
        
        lab[1][1] = 2; // мы там уже были
        
        push(&stack, lab_point);
        while (i != m && j != n) {
            //printf("Выше-%d\tНиже-%d\tЛевее-%d\tПравее_%d\n", lab[i - 1][j], lab[i + 1][j], lab[i][j - 1], lab[i][j + 1]);
            if (lab[i - 1][j] != 0 && lab[i - 1][j] != 2) {
                lab_point.x = i - 1;
                lab_point.y = j;
            
                lab[i][j] = 2; // мы там уже были
                
                i = i - 1;
                    
                push(&stack, lab_point);
            } else {
                
                if (lab[i + 1][j] != 0 && lab[i + 1][j] != 2) {
                    lab_point.x = i + 1;
                    lab_point.y = j;
                    
                    lab[i][j] = 2; // мы там уже были
                    
                    i = i + 1;

                    push(&stack, lab_point);
                } else {
                    if (lab[i][j - 1] != 0 && lab[i][j - 1] != 2) {
                        lab_point.x = i;
                        lab_point.y = j - 1;
                        
                        lab[i][j] = 2; // мы там уже были
                        
                        j = j - 1;

                        push(&stack, lab_point);
                    } else {
                        if (lab[i][j + 1] != 0 && lab[i][j + 1] != 2) {
                            lab_point.x = i;
                            lab_point.y = j + 1;
                                
                            lab[i][j] = 2; // мы там уже были
                            
                            j = j + 1;

                            push(&stack, lab_point);
                        } else {
                            trash = pop(&stack);
                        }
                    }
                }
            }
        }
        if (lab[i][j] == 0) {
            printf("NO");
        } else {
            lab_point.x = m;
            lab_point.y = n;
            
            push(&stack, lab_point);
        }
    }
    
    point arr[100];
    
    int counter = 0;
    
    i = 0;
    
    while (stack.size != 0) {
        arr[i] = pop(&stack);
        i++;
    }
    
    i--;
    
    printf("Enter-->");
    
    while (i >= 0) {
        printf("(%d; %d)-->", arr[i].x, arr[i].y);
        i--;
    }
    
    printf("Exit!\n");
    
    return 0;
}
