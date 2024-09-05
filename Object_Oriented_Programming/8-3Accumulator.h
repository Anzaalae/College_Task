#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

class Accumulator {
    int value;
public:
    Accumulator(int value); // 매개변수 value로 멤버 value를 초기화
    Accumulator& add(int n); // value에 n을 더해 값을 누적한다.
    int get() const; // 누적된 값 value를 리턴한다.
};

#endif