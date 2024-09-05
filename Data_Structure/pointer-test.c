#include <stdio.h>

int main()
{
    int i, *p; // integer 형 변수 i와 integer 변수의 주소값을 저장하는 변수 p를 선언하였다.

    i = 10; 

    printf("Value of i = %d\n", i); // 변수 i에 저장된 값 10을 출력한다.
    printf("address of i = %p\n", &i); // 주소 연산자(&)를 이용하여 변수 i가 저장된 메모리 주소값을 출력한다.
    printf("value of p = %p\n", p); // 변수 p의 값(p변수가 가르키고있는 주소값)을 출력한다.
    printf("address of p = %p\n", &p); // 주소 연산자(&)를 이용하여 변수 p가 저장된 메모리 주소값을 출력한다.

    p = &i; // 변수 p에 변수 i의 메모리 주소값을 저장한다.

    printf("\n\n----- after p = &i ------------\n\n");

    printf("value of p = %p\n", p); // 변수 p에 저장된 값을 출력한다(변수 i의 메모리 주소값).
    printf("adress of p = %p\n", &p); // 변수 p가 저장된 메모리 주소값을 출력한다.
    printf("dereferencing *p = %d\n", *p); // 역참조 연산자(*)를 이용해 변수 p가 가르키는 주소에 저장된 데이터(변수 i)를 출력한다.

    return 0;
}