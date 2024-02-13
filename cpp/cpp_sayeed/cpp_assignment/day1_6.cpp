#include<stdio.h>
#include<iostream>

float inline area_of_triangle(int ht, int base)
{
    float area;
    area = 0.5 * base * ht;

    return area;

}

int main(void)
{
    int ht, base;
    float area = 0;
    printf("Enter base of triangle : ");
    scanf("%d", &ht);

    printf("Enter height of triangle : ");
    scanf("%d", &base);

    area = area_of_triangle(ht,base);
    printf("Area of triangle with base:%d, height:%d = %.2f\n",ht,base,area);

    return 0;
}