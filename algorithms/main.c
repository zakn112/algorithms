//
//  main.c
//  algorithms
//
//  Created by Андрей Закусов on 18.02.2020.
//  Copyright © 2020 Андрей Закусов. All rights reserved.
//

#include <stdio.h>
#include "Stack.c"
#include "StackChar.c"

int decToBin(int);

int checkBrackets(char x[20]);

int main(int argc, const char * argv[]) {

    //1. Перевод из десятичной системы в двоичную
    printf("Введите число:");
    int c10;
    scanf("%i", &c10);
    Stack.maxSize = 100;
    Stack.head = NULL;
    printf("Ваше число в двоичной системе счисления: %i\n", decToBin(c10));
    
    //2. Проверка скобочной последовательности
    StackChar.maxSize = 100;
    StackChar.head = NULL;
    char x[20];
    printf("Введите последовательность со скобками:");
    scanf("%s", x);
    if (checkBrackets(x)) {
        printf("Последовательность верна\n");
    }else{
        printf("Последовательность не верна\n");
    }
    
    return 0;
}

int decToBin(int c10){
    while (c10 > 0) {
        push(c10%2);
        c10 = c10/2;
    }
    int c8, item;
    c8 = 0;
    item = pop();
    while (item != -1) {
        c8 = c8*10 + item;
        item = pop();
    }
    
    return c8;
}

int checkBrackets(char x[20]){
    
    for (int i = 0; i<20; i++) {
        if (x[i] == '(')
        {
            pushChar(x[i]);
            continue;
        }
        
        if (x[i] == ')' )
        {
            char item;
            item = popChar();
            if (item != '(')
            {
                return 0;
            }
        }
    }
    
    char item;
    item = popChar();
    if (item == '-')
    {
        return 0;
    }
    
    return 1;
}
