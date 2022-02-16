#include<stdio.h>

int main()
{
    int a , b , x , y , pens , pencils , total;
    scanf("%d %d %d %d",&a,&b,&x,&y);

    pens = a*x;
    pencils = b*y;

    total = pens+pencils;

    printf("%d",total);

    return 0;
}