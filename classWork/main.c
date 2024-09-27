#include <stdio.h>
#include <stdlib.h>
//yanal omar
//1230156
void calculate(float a, float b, float *sum, float *difference, float *mult, float *div){
    *sum = a+b;
    *difference = a-b;
    *mult = a*b;
    *div = a/b;
}
void change(int diff, int *twohundreds, int *hundreds, int *fifties, int *twen, int *tens, int *fives, int *twos, int *ones){
    if(diff < 0){
        printf("you owe me money");
    }else if(diff == 0) printf("you are good to go");
    else{
    if(diff >= 200){
        *twohundreds = diff/200;
        diff = diff%200;
    }
    if(diff >= 100 && diff<200){
        *hundreds = diff/100;
        diff = diff%100;
    }
    if(diff >= 50 && diff<100){
        *fifties = diff/50;
        diff = diff%50;
    }
    if(diff >= 20 && diff<50){
        *twen = diff/20;
        diff = diff%20;
    }
    if(diff >= 10 && diff<20){
        *tens = diff/10;
        diff = diff%10;
    }
    if(diff >= 5 && diff<10){
        *fives = diff/5;
        diff = diff%5;
    }
    if(diff >= 2 && diff<5){
        *twos = diff/2;
        diff = diff%2;
    }
    if(diff >=1 && diff < 2){
        *ones = diff/1;
        diff--;
    }
    }
}
void main()
{
    //question 1
    int q=2;
    int *p;
    p=&q;
    *p=100;
    printf("%d\n",q);
    printf("%p\n",p);
    printf("%d\n",*p);
    printf("%p\n",&q);
    printf("%p\n",&p);
    // question 2
    int x=3,y=4,z=6;
    int *p1,*p2,*p3;
    p1=&x;
    p2=&y;
    p3=&z;
    *p1=*p2+*p3;
    (*p1)++;
    (*p2)--;
    *p1=(*p2)*(*p3);
    *p2=(*p2)*(*p1);
    x=y+z;
    printf("%d\n",x);
    printf("%d\n",y);
    printf("%d\n",z);
    printf("%d\n",*p1);
    printf("%d\n",*p2);
    printf("%d\n",*p3);
    //question 3
    float  num1, num2, sum, difference, mult, div;
    printf("enter 2 numbers: ");
    scanf("%f %f", &num1, &num2);
    calculate(num1, num2, &sum, &difference, &mult, &div);
    printf("sum: %.0f\nDifference: %.0f\nmultiplication: %.0f\nDivision: %.0f\n", sum, difference, mult, div);
    // question 4
    int paid, due;
    printf("\nEnter the amount paid: ");
    scanf("%d", &paid);
    printf("Enter the amount due: ");
    scanf("%d", &due);
    int diff = paid - due;
    int twohundreds = 0, hundreds = 0, fifties = 0, twen = 0, tens = 0, fives = 0, twos = 0, ones = 0;
    change(diff, &twohundreds, &hundreds, &fifties, &twen, &tens, &fives, &twos, &ones);
    printf("200 = %d, 100 = %d, 50 = %d, 20 = %d, 10 = %d, 5 = %d, 2 = %d, 1 = %d\n", twohundreds, hundreds, fifties, twen, tens, fives, twos, ones);

}































