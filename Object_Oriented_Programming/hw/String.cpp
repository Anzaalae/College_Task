#include "String.h"
#include <cstring>

const unsigned String::npos= 4294967295; // npos를 unsigned int 의 최대 크기로 초기화

// 생성자
String::String() {
    // 메모리의 크기(capacity)가 10인 동적 메모리를 할당하고, 이 메모리에 빈 문자열을 저장
    capacity= 10;               // 메모리의 크기(capacity) 10으로 초기화
    memory= new char[capacity]; // 메모리 동적 할당
    memory[0]= '\0';            // 빈 문자열 저장
}

String::String(const char *str) {
    // str 문자열을 저장할 메모리 공간을 동적으로 생성하고, 이 문자열을 memory에 저장
    capacity= strlen(str)+ 1;   // 메모리의 크기(capacity)를 입력받은 str의 크기로 초기화
    memory= new char[capacity]; // 메모리 동적 할당
    strcpy(memory, str);        // str의 내용을 메모리(memory)에 복사
}

String::String(const String &str) {
    // 복사 생성자: str에 저장된 문자열을 memory에 저장
    capacity= str.capacity;     // 메모리의 크기(capacity)를 입력받은 str의 메모리 크기로 초기화
    memory= new char[capacity]; // 메모리 동적 할당
    strcpy(memory, str.memory); // 입력받은 str의 memory에 저장된 데이터를 현재 객체의 memory에 복사
}

// 소멸자
String::~String() {
    // memory가 가리키는 동적 메모리를 해제
    delete [] memory; // 동적 메모리 해제
}

// memory의 문자열을 str로 변경
void String::set(const char *str) {
    unsigned _size= strlen(str)+ 1; // 입력받은 str의 문자열 크기를 저장하는 변수 초기화 

    if(capacity >= _size) {         // capacity가 입력받은 문자열의 크기보다 큰 경우
        strcpy(memory, str);        // 입력받은 문자열을 memory에 복사
    } else {                        // capacity가 입력받은 문자열의 크기보다 작은 경우
        delete [] memory;           // 더 큰 크기의 동적 메모리 할당을 위해 동적 메모리 할당을 해제

        capacity= _size;            // 입력받은 문자열의 크기에 맞게 capacity 변수값 변경
        memory= new char[capacity]; // 입력받은 문자열의 크기에 맞게 memory를 동적 할당

        strcpy(memory, str);        // 입력 받은 문자열을 memory에 복사
    }
}

void String::set(const String &str) {
    if(capacity>= str.capacity) {   // capacity가 입력받은 문자열의 크기보다 큰 경우
        strcpy(memory, str.memory); // 입력받은 str의 memory를 현재 객체의 memory에 복사
    } else {                        // capacity가 입력받은 문자열의 크기보다 작은 경우
        delete [] memory;           // 더 큰 크기의 동적 메모리 할당을 위해 동적 메모리 할당을 해제

        capacity= str.capacity;     // 입력받은 str의 capacity에 맞게 현재 객체의 capacity 변수값 변경
        memory= new char[capacity]; // 입력받은 str의 capacity의 크기에 맞게 현재 객체의 memory를 동적 할당

        strcpy(memory, str.memory); // 입력받은 str의 memory를 현재 객체의 memory에 복사
    }
}

// length(), size() 모두 문자열의 길이를 반환
unsigned String::length() const {
    return strlen(memory); // 문자열의 크기를 반화
}

unsigned String::size() const {
    return strlen(memory); // length() 함수와 똑같이 구현
}

// 위치(인덱스)가 position인 위치부터 길이가 length인 부분 문자열을 String 객체로 리턴
String String::substr(unsigned position, unsigned length) const {
    if(position <= size()) { // 입력받은 position 값이 memory의 문자열을 넘지 않는지 검사
        if(length > size()- position) position= size()- position; // 만약 length가 memory의 최대 길이를 넘어간다면 length의 길이를 조절

        char *temp= new char[length+ 1];                          // 반환해줄 문자열 메모리 동적 할당
        strncpy(temp, memory+ position, length);                  // 입력값으로 지정한 memory의 일부를 동적할당한 문자열 배열에 복사
        temp[length]= '\0';                                       // 문자열의 끝을 알리는 NULL 값 초기화

        String output(temp);                                      // 반환을 위한 객체 생성, 동시에 이전에 동적할당한 문자열을 이용해 초기화
        delete [] temp;                                           // 동적 할당한 문자열 동적 메모리 반환
        return output;                                            // 객체 반환
    }
}

// memory의 position 위치에 str 을 삽입
void String::insert(unsigned position, const char *str) {
    if(position <= size()) { // 입력받은 position이 memory의 범위를 넘어가는지 검사
        if(size() + strlen(str) >= capacity) {             // str을 삽입했을 때 capacity를 넘어가는 경우 memory의 크기 조절
            capacity= size() + strlen(str)+ 1;             // capacity를 memory의 길이에서 str의 길이만큼 더한 값으로 초기화
            char *temp= new char[capacity];                // capacity만큼 임시로temp 문자열에 메모리 동적 할당
            strcpy(temp, memory);                          // temp 문자열에 memory 내용 복사
            delete [] memory;                              // memory 동적 할당 해제
            memory= temp;                                  // temp 문자열의 주소값을 memory에 초기화 해줌
        }

        String behind= substr(position, size()- position); // str을 삽입하고 복사할 뒷 부분을 substr 함수를 이용해 behind 임시 객체에 저장
        erase(position, size()- position);                 // 기존 객체에 str 가 들어가기 전 까지 남겨두고 memory의 뒷 부분을 제거

        strcat(memory, str);                               // memory에 str을 붙이고
        strcat(memory, behind.get());                      // 그 뒤에 이전에 str 뒷부분에 해당하는 behind 객체를 이용해 문자열을 완성
    }
}

void String::insert(unsigned position, const String &str) {
    insert(position, str.get());                           // str 객체의 get() 접근 함수를 이용하여 바로 전에 구현한 함수를 호출
}

// memory에 저장된 문자열의 position 위치부터 길이가 length인 문자열을 삭제
void String::erase(unsigned position, unsigned length) {
    if(position < size()) { // 입력받은 position이 memory의 범위를 넘어가는지 검사
      if(position+ length> size()) length= size()- position;                              // length가 memory의 범위를 벗어날 경우 length 크기 조정
        for(int i= position+ length; memory[i]!= '\0'; i++) memory[i- length]= memory[i]; // position 이후의 값을 length만큼 떨어져 있는 문자열로 복사
        memory[strlen(memory)-length]= '\0';                                              // 복사가 끝나면 문자열의 마지막임을 암시하기 위해 뒤를 NULL로 초기화
    }
}

// memory에 저장된 문자열의 position 위치부터 길이가 length인 문자열을 str로 치환
void String::replace(unsigned position, unsigned length, const char *str) {
    erase(position, length); // position 부터 길이가 length인 문자열을 제거
    insert(position, str);   // position 위치에 str을 삽입하는 함수 호출
}

void String::replace(unsigned position, unsigned length, const String &str) {
    replace(position, length, str.get()); // get() 접근 함수를 사용하여 str의 memory를 입력값으로 바로 전에 구현한 함수 호출
}

// memory에 저장된 문자열의 position 위치부터 str 문자열을 찾으며,
// position 뒤의 위치에서 가장 처음 str이 나타나는 위치의 인덱스를 반환
// 찾지 못할 경우 npos를 리턴
unsigned String::find(const char *str, unsigned position) const {
    const char* seek= strstr(memory+ position, str); // memory에서 position 만큼 떨어진 주소부터 str 문자열을 찾는 함수 strstr() 호출
    if(seek== nullptr) return npos;                  // 만약 찾지 못하면(strstr() 함수가 nullptr을 반환하면 npos 값을 반환

    return seek- memory;                             // seek의 주소에서 memory 시작 위치의 주소를 빼 어느 위치에 있는지 수치로 반환해줄 수 있음
}

unsigned String::find(const String &str, unsigned position) const {
    return find(str.get(), position); // get() 접근 함수를 사용하여 str의 memory를 입력값으로 바로 전에 구현한 함수 호출
}