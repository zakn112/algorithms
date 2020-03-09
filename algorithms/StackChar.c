//
//  Stack.c
//  algorithms
//
//  Created by Андрей Закусов on 04.03.2020.
//  Copyright © 2020 Андрей Закусов. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// Опишем структуру узла списка
struct TNodeC
{
    char value;
    struct TNodeC *next;
};

typedef struct TNodeC NodeC;

struct StackC
{
    NodeC *head;
    int size;
    int maxSize;
};

struct StackC StackChar;

void pushChar(char value)
{
    if (StackChar.size >= StackChar.maxSize) {
        printf("Error stack size");
        return;
    }
    NodeC *tmp = (NodeC*) malloc(sizeof(NodeC));
    
    if (tmp == NULL){
      printf("Ошибка выделения памяти для элемента стека");
      return;
    }
    
    tmp->value = value;
    tmp->next = StackChar.head;
    StackChar.head = tmp;
    StackChar.size++;
}

char popChar() {
    char value;
    
    if (StackChar.size == 0)
    {
        //printf("Stack is empty");
        return '-';
    }
    // Временный указатель
    NodeC* next = NULL;
    // Значение "наверху" списка
    
    value = StackChar.head->value;
    next = StackChar.head;
    StackChar.head = StackChar.head->next;
    // Запись, на которую указывала голова удаляем, освобождая память
    free(next);
    // Возвращаем значение, которое было в голове
    StackChar.size--;
    return value;
}

void PrintStackChar()
{
    NodeC *current = StackChar.head;
    while(current != NULL)
    {
        printf("%c ", current->value);
        current = current->next;
    }
}
