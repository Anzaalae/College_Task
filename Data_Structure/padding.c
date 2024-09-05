#include <stdio.h>

struct student
{
    char lastName[13];  // 13 bytes 문자열
    int studentId;      // 4 bytes intager
    short grade;        // 2 bytes short intager
};

int main()
{
    printf("[----- [김예준] [2020025051] -----]");
    printf("\n\n");

    struct student pst;

    printf("size of student = %ld\n", sizeof(struct student)); // padding byte 생성에 의해 24바이트 출력
    printf("size of int     = %ld\n", sizeof(int));            // integer의 자료형은 4바이트
    printf("size of short   = %ld\n", sizeof(short));          // short형 자료형은 2바이트
}
/*
    구조체는 운영체제가 특정 메모리 크기 단위로 data를 읽음
    그래서 구조체를 정의할 때 제일 메모리를 많이 차지하는 변수의 배수만큼 메모리 할당함
    student 구조체에서는 integer형 변수가 4바이트로 4바이트의 배수로 결정
    (lastName 변수는 13바이트지만 char 1바이트로 판정함)
    이때 메모리 크기만 맞추면 되는 것이 아니라 변수를 선언한 순서대로 메모리가 할당되므로...
    (즉, 구조체 내부의 변수 선언 순서에 따라 할당되는 메모리 크기가 달라짐)
    char lastName[13] <= 4 * 4 == 16
    int student <= 4
    short grade <= 4
    즉, 16 + 4 + 4 == 24바이트 만큼 메모리를 할당함
    메모리의 빈 공간은 padding byte로 비워둠.
*/