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
struct TNode
{
    int value;
    struct TNode *next;
};

typedef struct TNode Node;

struct Stack
{
    Node *head;
    int size;
    int maxSize;
};

struct Stack Stack;

void push(int value)
{
    if (Stack.size >= Stack.maxSize) {
        printf("Error stack size");
        return;
    }
    Node *tmp = (Node*) malloc(sizeof(Node));
    
    if (tmp == NULL){
      printf("Ошибка выделения памяти для элемента стека");
      return;
    }
    
    tmp->value = value;
    tmp->next = Stack.head;
    Stack.head = tmp;
    Stack.size++;
}

char pop() {
    int value;
    
    if (Stack.size == 0)
    {
        //printf("Stack is empty");
        return -1;
    }
    // Временный указатель
    Node* next = NULL;
    // Значение "наверху" списка
    
    value = Stack.head->value;
    next = Stack.head;
    Stack.head = Stack.head->next;
    // Запись, на которую указывала голова удаляем, освобождая память
    free(next);
    // Возвращаем значение, которое было в голове
    Stack.size--;
    return value;
}

void PrintStack()
{
    Node *current = Stack.head;
    while(current != NULL)
    {
        printf("%i ", current->value);
        current = current->next;
    }
}
