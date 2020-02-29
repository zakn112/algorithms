//
//  main.c
//  algorithms
//
//  Created by Андрей Закусов on 18.02.2020.
//  Copyright © 2020 Андрей Закусов. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int a[]);
void bubbleSortOpt(int a[]);
void shakerSort(int a[]);
int binarySearch(int a[], int s);

// Определяем максимальный размер массива
#define MaxN 100
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
// Распечатываем массив
void print(int N, int *a)
{
    int i;
    for(i = 0; i < N; i++)
        printf("%6i", a[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    int a[MaxN], a2[MaxN], a3[MaxN], a4[MaxN]; // создаём массив максимального размера
    int N = MaxN;
    
    
    int i, c;
    for(i = 0; i < N; i++)
    {
        c = rand() % 1000;
        a[i] = c;
        a2[i] = c;
        a3[i] = c;
        a4[i] = i*2 + 3;
    }
    
    puts("Array before sort");
    print(N, a);
    
    bubbleSort(a);
    bubbleSortOpt(a2);
    shakerSort(a3);
    
    printf("=== Бинарный поиск ===\n");
    puts("Array");
    print(N, a4);
    printf("Введите число для поиска:");
    int s;
    scanf("%i", &s);
    
    printf("Найденный элемент %i:\n", binarySearch(a4, s));
    
    return 0;
}

void bubbleSort(int a[]) {
    int N = MaxN;
    int numComp = 0;
    int numSwap = 0;
    int j = 0;
    int i;
    for(i = 0; i < N; i++){
        numComp += 1;//сравнение в цикле
        for(j = 0; j < N - 1; j++){
            numComp += 1;//сравнение в цикле
            numComp += 1;//сравнение в условии
            if (a[j] > a[j + 1])
            {
                numSwap += 1;
                swap(&a[j], &a[j + 1]);
            }
        }
    }
    printf("=== Пузырьковая сортировка ===\n");
    puts("Array after sort");
    print(N, a);
    
    printf("Количество элементов массива: %i\n", N);
    printf("Количество сравнений: %i\n", numComp);
    printf("Количество перестановок: %i\n", numSwap);
    
}

void bubbleSortOpt(int a[]) {
    int N = MaxN;
    int numComp = 0;
    int numSwap = 0;
    int j = 0;
    int i;
    for(i = 0; i < N; i++){
        numComp += 1;//сравнение в цикле
        for(j = 0; j < N - 1 - i; j++){
            numComp += 1;//сравнение в цикле
            numComp += 1;//сравнение в условии
            if (a[j] > a[j + 1])
            {
                numSwap += 1;
                swap(&a[j], &a[j + 1]);
            }
        }
    }
    printf("=== Пузырьковая сортировка оптимизированная ===\n");
    puts("Array after sort");
    print(N, a);
    
    printf("Количество элементов массива: %i\n", N);
    printf("Количество сравнений: %i\n", numComp);
    printf("Количество перестановок: %i\n", numSwap);
    
}

void shakerSort(int a[]) {
    int N = MaxN;
    int numComp = 0;
    int numSwap = 0;
    int j = 0;
    int i;
    for(i = 0; i < N; i++){
        if (i >= N - 1 - i)
        {
            break;
        }
        numComp += 1;//сравнение в цикле
        for(j = i; j < N - 1 - i; j++){
            numComp++;//сравнение в цикле
            numComp++;//сравнение в условии
            if (a[j] > a[j + 1])
            {
                numSwap++;
                swap(&a[j], &a[j + 1]);
            }
        }
        
        for(j; j > i; j--){
            numComp++;//сравнение в цикле
            numComp++;//сравнение в условии
            if (a[j] < a[j - 1])
            {
                numSwap++;
                swap(&a[j], &a[j - 1]);
            }
        }
        
    }
    printf("=== Шейкерная сортировка ===\n");
    puts("Array after sort");
    print(N, a);
    
    printf("Количество элементов массива: %i\n", N);
    printf("Количество сравнений: %i\n", numComp);
    printf("Количество перестановок: %i\n", numSwap);
    
}

int binarySearch(int a[], int s) {
    int j = MaxN;
    int i = 0;
    
    while(i < j){
        if (a[i] == s) return i;
        if (a[j] == s) return j;
        
        if (s < a[i + (j - i)/2]) {
            j = i + (j - i)/2 - 1;
        }else{
            i = i + (j - i)/2;
        }
        
    }
    return -1;
}
