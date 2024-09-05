#include <iostream>
#include "10-3Queue.h"

using namespace std;

int main() {
    Queue queue;
    int n;

    cout<< "ť�� ������ 5���� ������ �Է�>> ";
    for(int i= 0; i< 5; i++) {
        cin>> n;
        queue.enqueue(n);
        queue.pushBack(n); // ������ ����
    }

    cout<< "ť���� �� ���� ���Ҹ� �����Ͽ� ����Ѵ�."<< endl;
    for(int i= 0; i< 2; i++) {
        cout<< queue.dequeue()<< " ";
        cout<< queue.popFront()<< " "; // ������ ����
    }
    cout<< "\nEmpty?"<< (queue.empty() ? "true": "false")<< endl;

    cout << "ť�� ���Ҹ� ������� ��� �����Ͽ� ����Ѵ�." << endl;

    while(!queue.empty()) cout << queue.dequeue() << " ";

    cout << "\nEmpty? " << (queue.empty() ? "true" : "false") << endl;
}