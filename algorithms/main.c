//
//  main.c
//  algorithms
//
//  Created by Андрей Закусов on 18.02.2020.
//  Copyright © 2020 Андрей Закусов. All rights reserved.
//

#include <stdio.h>
#define MaxN 100
void print(int N, int *a);
void swap(int *a, int *b);
void simpleCountingSort(int *A, int k);
void quickSort(int* array, int first, int last);

int main(int argc, const char * argv[]) {
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
    printf("Сортировка подсчетом\n");
    printf("Исходный массив\n");
    print(N, a);
    simpleCountingSort(a,N);
    
    printf("Отсортированный массив\n");
    print(N, a);
    
    printf("Быстрая сортировка\n");
    printf("Исходный массив\n");
    print(N, a2);
    quickSort(a2, 0, N);
    
    printf("Отсортированный массив\n");
    print(N, a2);
       
    return 0;
}

void simpleCountingSort(int *A, int k) // где k – длина массива А,
// а 1000 – его максимальное значение
{
    int C[1000], i, b, j;
    
    for (i = 0; i < 1000; i++)
        C[i] = 0;
    
    for (i = 0; i < k; i++)
        C[A[i]]++;
    
    b = 0;
    
    for (j = 0; j < 1000; j++)
    {
        
        for (i = 0; i < C[j]; i++)
        {
           
            A[b++] = j;
            
        }
    }
}

void quickSort(int* array, int first, int last)
{
    int i = first, j = last, x = array[(first + last) / 2];
    do
    {
        while (array[i] < x)
            i++;
        while (array[j] > x)
            j--;
        if(i <= j)
        {
            if (array[i] > array[j])
                swap(&array[i], &array[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (i < last)
        quickSort(array, i, last);
    if (first < j)
        quickSort(array, first, j);
}

void print(int N, int *a)
{
    int i;
    for(i = 0; i < N; i++)
        printf("%6i", a[i]);
    printf("\n");
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
