#include <iostream>
// (�갡 �ַ�)����, ��� ����, ��ĭ ä���
using namespace std;

int sum(int, int);

int main()
{
    int n(0);
    cout<< "������ �Է��ϼ���>>";
    cin>> n;
    if(n<= 0)
    {
        cout<< "����� �Է��Ͻÿ�!\n";
        return 0;
    }

    cout<< "1���� "<<n <<"������ ���� "<< sum(1, n)<< "�Դϴ�"<< endl;

    return 0;
}

int sum(int a, int b)
{
    int res(0);

    for(int k= a; k<= b; k++) res+= k;

    return res;
}