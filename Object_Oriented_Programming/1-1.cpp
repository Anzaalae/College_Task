#include <iostream>
// (얘가 주로)개념, 결과 예측, 빈칸 채우기
using namespace std;

int sum(int, int);

int main()
{
    int n(0);
    cout<< "끝수를 입력하세요>>";
    cin>> n;
    if(n<= 0)
    {
        cout<< "양수를 입력하시오!\n";
        return 0;
    }

    cout<< "1에서 "<<n <<"까지의 합은 "<< sum(1, n)<< "입니다"<< endl;

    return 0;
}

int sum(int a, int b)
{
    int res(0);

    for(int k= a; k<= b; k++) res+= k;

    return res;
}