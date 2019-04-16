#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    const int c=5;
    printf("%d\n", c);
    *const_cast<int*>(&c)=8;
    printf("%d\n", c);
}
