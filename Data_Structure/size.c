#include <stdio.h>

int main()
{
    printf("[----- [김예준] [2020025051] -----]");
    printf("\n\n");
    
    int **x;

    printf("sizeof(x) = %lu\n", sizeof(x));     // x가 차지하는 메모리 크기를 바이트 단위로 출력
    printf("sizeof(*x) = %lu\n", sizeof(*x));   // *x가 차지하는 메모리 크기를 바이트 단위로 출력
    printf("sizeof(**x) = %lu\n", sizeof(**x)); // **x가 차지하는 메모리 크기를 바이트 단위로 출력
}
/*
    %lu는 unsighned long int형 변수 형식으로 출력할 때 사용
    x 변수는 *x의 주소를 가리킴, address
    *x는 x가 가리키는 주소의 값을 의미함(**x의 주소를 가리킴), address
    **x는 *x가 가리키는 주소의 값을 의미함, intager
    현재 64bit 운영체제를 사용 중이지만 32bit 운영체제 전용 컴파일러가 작동해서 주소가 4 byte로 출력됨
*/