#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 함수의 a 변수에 대해 값을 예상하지 못하므로 5, 8이 출력
int test(const int a)
{
    printf("%d\n", a);
    *((int *)&a) = 8;
    printf("%d\n", a);
    return 0;
}

int main()
{
    const int c = 5;

    printf("%d\n", c);

    *((int *)&c) = 8;

    // c에 대해 const로 지정되어 컴파일러가 값이 
    // 바뀌지 않을 것으로 예상하고 5로 변경되어 컴파일 된다.
    // 5로 출력됨..
    // c 변수 선언 시 volatail 지정을 해줘야함.
    printf("%d\n", c);

    test(5);

}
