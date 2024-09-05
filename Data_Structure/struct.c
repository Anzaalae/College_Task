#include <stdio.h>

struct student1 // student1 이라는 구조체 정의
{               
    char lastName;
    int studentId;
    char grade;
};

typedef struct // 아래 내용의 구조체를 student2라고 사용자 변수 정의를 함.
{              // 구조체에 포함되는 변수들은 struct1 구조체와 같음.
    char lastName;
    int studentId;
    char grade;
} student2;

int main()
{
    printf("[----- [김예준] [2020025051] -----]");
    printf("\n\n");

    struct student1 st1= {'A', 100, 'A'}; // st1 구조체 변수 선언 및 초기화

    printf("st1.lastName = %c\n", st1.lastName);
    printf("st1.studentId = %d\n", st1.studentId);
    printf("st1.grade = %c\n", st1.grade);

    student2 st2= {'B', 200, 'B'};        // st2 구조체 변수 선언 및 초기화
                                          // 사용자 변수 정의를 하였으므로 struct라고 명시를 안 해줘도 됨.
    printf("\n");
    printf("st2.lastName = %c\n", st2.lastName);
    printf("st2.studentId = %d\n", st2.studentId);
    printf("st2.grade = %c\n", st2.grade);

    student2 st3;

    st3= st2;                             // st3 구조체 변수를 선언한 후 기존의 st2의 값으로 초기화

    printf("\n");
    printf("st3.lastName = %c\n", st3.lastName);
    printf("st3.studentId = %d\n", st3.studentId);
    printf("st3.grade =  %c\n", st3.grade);

    /*equality test*/
    if(st3.lastName== st2.lastName && st2.grade== st2.grade && st2.studentId== st2.studentId) printf("equal\n");
    else printf("not equal\n");
}