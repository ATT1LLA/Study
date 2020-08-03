//
//  main.c
//  С ассемблерными вставками
//
//  Created by Тастеков Адиль Азатович on 23.05.17.
//  Copyright © 2017 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>

int summ (int a, int b) {
    return (a + b);
}

int main(void)
{
    int foo = 10, bar = 15;
    /*__asm__ __volatile__(	"imull %%ebx,%%eax\n"
                         
                            "incl %%eax;\n"
                            :"=a"(foo)
                            :"a"(foo), "b"(bar)
                         );*/
    printf("Res=%d\n", foo);
    return 0;
}
