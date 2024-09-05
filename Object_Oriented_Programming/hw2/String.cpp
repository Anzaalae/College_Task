#include <algorithm>
#include <cstring>
#include <cctype>
#include "String.h"

const unsigned String::npos = 0xFFFFFFFF;

String::String(unsigned capacity) : memory(nullptr), capacity(capacity) {
    this->memory = allocate(this->capacity);
    strcpy(this->memory, "");
}

String::String(const char *str) : memory(nullptr), capacity(strlen(str) + 1) {
    this->memory = allocate(this->capacity);
    strcpy(this->memory, str);
}

String::String(const String &str) : memory(nullptr), capacity(str.length() + 1) {
    this->memory = allocate(this->capacity);
    strcpy(this->memory, str.memory);
}

String::~String() { delete[] this->memory; }

void String::set(const char *str) {
    unsigned len = strlen(str);
    unsigned cap = len + 1;
    if (cap > this->capacity) {
        char *mem = allocate(cap);
        delete[] this->memory;
        this->memory = mem;
        this->capacity = cap;
    }
    strcpy(this->memory, str);
}

void String::set(const String &str) { this->set(str.memory); }

unsigned String::length() const { return strlen(this->memory); }

unsigned String::size() const { return strlen(this->memory); }

String String::substr(unsigned start, unsigned length) const {
    check_index(start);
    String s(length + 1);
    strncpy(s.memory, this->memory + start, length);
    return s;
}

void String::insert(unsigned index, const char *str) {
    check_index(index);
    unsigned len = this->length() + strlen(str);
    unsigned cap = len + 1;
    char *mem = allocate(cap);
    strncpy(mem, this->memory, index);
    strcat(mem, str);
    strcat(mem, this->memory + index);
    if (this->capacity < cap) {
        delete[] this->memory;
        this->memory = mem;
    } else {
        strcpy(this->memory, mem);
        delete[] mem;
        this->capacity = cap;
    }
}

void String::insert(unsigned index, const String &str) {
    this->insert(index, str.memory);
}

void String::erase(unsigned start, unsigned length) {
    this->check_index(start);
    unsigned len = this->size() - length;
    char *dest = new char[len + 1];
    strncpy(dest, this->memory, start);
    strcat(dest, this->memory + start + length);
    strcpy(this->memory, dest);
    delete[] dest;
}

void String::replace(unsigned start, unsigned length, const char *str) {
    this->erase(start, length);
    this->insert(start, str);
}

void String::replace(unsigned start, unsigned length, const String &str) {
    this->erase(start, length);
    this->insert(start, str);
}

unsigned String::find(const char *str, unsigned pos) const {
    char *p = strstr(this->memory + pos, str);
    if (p == nullptr) return String::npos;
    return p - this->memory;
}

unsigned String::find(const String &str, unsigned pos) const {
    return find(str.memory, pos);
}

String String::tolower() const {
    String ret = *this;
    std::transform(ret.memory, ret.memory + ret.size(), ret.memory, ::tolower);
    return ret;
}

String String::toupper() const {
    String ret = *this;
    std::transform(ret.memory, ret.memory + ret.size(), ret.memory, ::toupper);
    return ret;
}

void String::check_index(unsigned index) const {
    if (index < this->length()) return;
    throw "out of range";
}

char *String::allocate(unsigned cap) const {
    char *mem = new char[cap];
    if (!mem) throw "fail to allocate mem";
    return mem;
}

const char &String::operator[](unsigned index) const {
    check_index(index); // 먼저 index length를 확인한 후
    return memory[index]; // memory의 내용을 출력해줌
}

char &String::operator[](unsigned index) { // 위의 구현 내용과 같음, 비 const 버전
    check_index(index);
    return memory[index];
}

String String::operator+(const String &str) const { // 현재 객체에 입력받은 객체의 memory 내용을 합치는 +연산자 재정의
    String output(this->length() + str.length() + 1); // 입력받은 객체의memory 길이와 현재 memory의 길이를 합친 결과물 객체를 만듬
    strcpy(output.memory, this->memory); // 현재 memory의 내용을 output 객체에 복사
    strcat(output.memory, str.memory); // 입력 받은 memory의 내용을 output 객체에 이어서 복사
    return output; // 연산자의 왼쪽 객체의 memory 내용과 오른쪽 객체의 memory를 합친 객체 output을 반환
}

String String::operator+(const char *str) const { // 같은 구현, 비 const 버전
    String output(this->length() + strlen(str) + 1);
    strcpy(output.memory, this->memory);
    strcat(output.memory, str);
    return output;
}

String operator+(const char *str1, const String &str2) { // 현재 문자열에 String 객체의 memory 내용을 합치는 +연산자 재정의
    String output(strlen(str1) + str2.length() + 1); // 입력받은 객체와 문자열의 길이를 합친 길이의 새로운 객체 생성
    strcpy(output.memory, str1); // 새로운 객체에 입력받은 문자열을 복사해줌
    strcat(output.memory, str2.memory); // 새로운 객체에 이어서 입력받은 객체의 memory 내용을 복사
    return output; // 입력받은 문자열과 객체의 memory 내용을 합친 객체를 반환
}

String &String::operator=(const String &str) {
    this->set(str.memory); // 입력받은 객체의 memory를 현재 객체의 memory에 초기화
    return *this; // 초기화한 현재 객체를 반환
}

String &String::operator=(const char *str) {
    this->set(str); // 위 연산자 재정의의 객체 대신 문자열을 입력받은 버전으로 현재 객체에 문자열을 memory에 초기화
    return *this; // 초기화한 현재 객체를 반환
}

String &String::operator+=(const String &str) {
    *this = *this + str; // 앞에서 구현한 + 연산자 재정의를 이용해 객체1 += 객체2를 객체1 = 객체1 + 객체2로 바꿔줌 
    return *this;
}

String &String::operator+=(const char *str) {
    *this = *this + str; // 이전에 구현한 += 연산자 재정의 문자열을 입력받은 버전
    return *this;
}

bool String::operator==(const String &str) const {
    // 문자열을 비교하는 strcmp 대신 대소문자 구분 없이 문자열을 비교하는 strcasecmp 함수를 이용하여 두 문자열이 같은지 비교
    return strcasecmp(this->memory, str.memory) == 0;
}

bool String::operator==(const char *str) const {
    // 위와 같은 == 연산자 재정의인데 문자열을 입력받은 버전으로 객체의 memory와 문자열을 비교
    return strcasecmp(this->memory, str) == 0;
}

bool operator==(const char *str1, const String &str2) {
    // 위와 같은 == 연산자 재정의인데 문자열을 먼저 입력한 경우에 대해 정의
    return strcasecmp(str1, str2.memory) == 0;
}

bool String::operator!=(const String &str) const {
    // 문자열을 비교하는 strcmp 대신 대소문자 구분 없이 문자열을 비교하는 strcasecmp 함수를 이용하여 두 문자열이 같은지 비교
    return strcasecmp(this->memory, str.memory) != 0;
}

bool String::operator!=(const char *str) const {
    // 위와 같은 == 연산자 재정의인데 문자열을 입력받은 버전으로 객체의 memory와 문자열을 비교
    return strcasecmp(this->memory, str) != 0;
}

bool operator!=(const char *str1, const String &str2) {
    // 위와 같은 == 연산자 재정의인데 문자열을 먼저 입력한 경우에 대해 정의
    return strcasecmp(str1, str2.memory) != 0;
}

/* 아래 연산자 재정의 부분은 위의 ==, != 연산자 재정의에서 사용한 함수 strcasecmp 함수 호출의 출력값을 이용하여 */
/* 각각의 연산자 재정의에 맞게 결과값 반환 */
/* 문자열을 입력받은 경우, 객체를 입력 받은 경우에 따라 strcmp 함수를 호출할 때 각각의 방법들로 인자를 넘겨줌 */
bool String::operator>(const String &str) const {
    return strcasecmp(this->memory, str.memory) > 0;
}

bool String::operator>(const char *str) const {
    return strcasecmp(this->memory, str) > 0;
}

bool operator>(const char *str1, const String &str2) {
    return strcasecmp(str1, str2.memory) > 0;
}

bool String::operator>=(const String &str) const {
    return strcasecmp(this->memory, str.memory) >= 0;
}

bool String::operator>=(const char *str) const {
    return strcasecmp(this->memory, str) >= 0;
}

bool operator>=(const char *str1, const String &str2) {
    return strcasecmp(str1, str2.memory) >= 0;
}

bool String::operator<(const String &str) const {
    return strcasecmp(this->memory, str.memory) < 0;
}

bool String::operator<(const char *str) const {
    return strcasecmp(this->memory, str) < 0;
}

bool operator<(const char *str1, const String &str2) {
    return strcasecmp(str1, str2.memory) < 0;
}

bool String::operator<=(const String &str) const {
    return strcasecmp(this->memory, str.memory) <= 0;
}

bool String::operator<=(const char *str) const {
    return strcasecmp(this->memory, str) <= 0;
}

bool operator<=(const char *str1, const String &str2) {
    return strcasecmp(str1, str2.memory) <= 0;
}
/* 여기까지 strcasecmp 함수를 이용한 비교 연산자 재정의 부분 구현 */

std::ostream &operator<<(std::ostream &out, const String &str) {
    out << str.memory; // 출력 연산자 재정의를 통해 객체를 출력하려 하면 객체의 memory 문자열을 출력하도록 함
    return out;
}