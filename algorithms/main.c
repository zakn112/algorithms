//
//  main.c
//  algorithms
//
//  Created by Андрей Закусов on 18.02.2020.
//  Copyright © 2020 Андрей Закусов. All rights reserved.
//

#include <stdio.h>

void decToBin(void);
int bin(int);

void taskPow(void);
int powABRec(int, int);
int powAB(int, int);

int main(int argc, const char * argv[]) {
   
    //decToBin();
    taskPow();
    
    return 0;
}


void decToBin(){
    int number10;
    printf("Введите число в десятиричной системе: ");
    scanf("%i", &number10);
    
    printf("Ваше число в двоичной системе: %i \n", bin(number10));
    
}

int bin(number10){
    if (number10 == 0) {
        return 0;
    }
    
    int res = number10 % 2 + 10 * bin(number10/2);
    return res;
}

void taskPow(){
    int number, degree, numberDeg;
    printf("Введите число и степень: ");
    scanf("%i %i", &number, &degree);
    
    numberDeg = powAB(number, degree);
    printf("%i в степени %i = %i \n", number, degree, numberDeg);
    
    numberDeg = powABRec(number, degree);
    printf("%i в степени %i = %i \n", number, degree, numberDeg);
}

int powAB(number, degree){
    int numberDeg;
    numberDeg = number;
    int i = 1;
    while (i < degree) {
        numberDeg *= number;
        i += 1;
    }
    
    return numberDeg;
}

int powABRec(number, degree){
    if (degree == 1) {
        return number;
    }
    
    return number * powABRec(number, degree - 1);
}
