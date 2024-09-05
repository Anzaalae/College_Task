#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <ostream>

template<class T>
class Vector {
    T *_memory;
    unsigned _capacity;
    unsigned _size;

public:
    Vector(unsigned capacity = 5);
    Vector(unsigned size, const T &element);
    Vector(const T arr[], unsigned size);
    Vector(const Vector<T> &vector);
    ~Vector();

    unsigned size() const { return this->_size; }
    unsigned capacity() const { return this->_capacity; }
    const T &at(unsigned index) const { return _memory[index]; }
    void set(unsigned index, const T &element);
    bool empty() const { return _size == 0; }
    void push_back(const T &element);
    void pop_back();
    void erase(unsigned index);
    void insert(unsigned index, const T &element);

    /*
      과제 구현 내용
      아래의 멤버 함수 및 연산자에 대한 코드를 구현하여라.
      - begin()
      - end()
      - operator[]
      - operator+
      - operator=
      - operator+=
      - operator==
      - operator!=
      - operator>
      - operator>=
      - operator<
      - operator<=
      - ostream &operator<<
    */
    // Vector의 첫번째 요소에 대한 포인터 반환
    T *begin();

    const T *begin() const;

    // Vector의 마지막 다음 요소에 대한 포인터 반환
    T *end();

    const T *end() const;

    // Vector의 index 위치의 값을 반환하는 연산자를 정의할 것
    T &operator[](unsigned index);             // 비 const 버전
    const T &operator[](unsigned index) const; // const 버전

    // vector1 = vector2 수행 시 vector1의 내용을 vector2로 변경하는 연산자를
    // 정의할 것
    Vector<T> &operator=(const Vector<T> &vector);

    // vector1 + vector2 수행시 두 벡터가 연결된 새로운 벡터를 리턴하는 연산자를
    // 정의할 것
    Vector<T> operator+(const Vector<T> &vector) const;

    // vector1 += vector2 수행 시 vector1 뒤에 vector2 연결되는 연산자를 정의할 것
    Vector<T> &operator+=(const Vector<T> &vector);

    // vector1 == vector2 수행 시 vector1과 vector2의 모든 값이 같은지 아닌지를
    // 판별하는 연산자를 정의할 것
    bool operator==(const Vector<T> &vector) const;

    // vector1 != vector2 수행 시 vector1과 vector2의 값들 중 하나라도 다르면
    // true, 그렇지 않으면 false를 리턴하는 연산자를 정의할 것
    bool operator!=(const Vector<T> &vector) const;

    // 출력 스트림으로 vector를 출력하는 프렌드 함수를 정의할 것
    friend std::ostream &operator<<(std::ostream &out, const Vector<T> &vector) {
        // 템플릿 클래스의 경우는 프렌드 함수를 여기에 정의해야 함
        // 만약 벡터에 <1, 2, 3, 4, 5>가 저장되어 있을 경우. 출력 형식은 [ 1, 2, 3, 4, 5 ]
        
        // Vector의 각 요소들을 출력하기 전 대괄호를 먼저 출력
        out << "[ ";
        for (unsigned i = 0; i < vector._size; ++i) {
            // vector의 memory의 요소들을 하나씩 출력
            out << vector._memory[i];
            // 마지막 요소 전 까지 , 출력하기 위한 조건문
            if (i < vector._size - 1) out << ", ";
        }
        // 각 요소들을 출력한 후 대괄호 닫기
        out << " ]";
        
        return out;
    }

private:
    // utility member functions
    // 여기부터는 이미 구현되어 있으므로 구현이 필요 없음
    void check_index(unsigned index) const;
    T *allocate(unsigned capacity) const;
    void reallocate() { reallocate(_size); }
    void reallocate(unsigned size);
};

template<class T>
Vector<T>::Vector(unsigned capacity)
        : _memory(nullptr), _capacity(capacity), _size(0) {
    this->_memory = this->allocate(this->_capacity);
}

template<class T>
Vector<T>::Vector(unsigned size, const T &element)
        : _memory(nullptr), _capacity(size * 2), _size(size) {
    this->_memory = this->allocate(this->_capacity);
    for (unsigned i = 0; i < this->_size; i++)
        this->_memory[i] = element;
}

template<class T>
Vector<T>::Vector(const T arr[], unsigned size): _memory(nullptr), _capacity(size * 2), _size(size) {
    this->_memory = this->allocate(this->_capacity);
    for (unsigned i = 0; i < this->_size; i++) this->_memory[i] = arr[i];
}

template<class T>
Vector<T>::Vector(const Vector<T> &vector)
        : _memory(nullptr), _capacity(vector._capacity), _size(vector._size) {
    this->_memory = this->allocate(this->_capacity);
    for (unsigned i = 0; i < vector._size; i++)
        this->_memory[i] = vector._memory[i];
}

template<class T>
Vector<T>::~Vector() {
    delete[] this->_memory;
}

template<class T>
void Vector<T>::set(unsigned index, const T &element) {
    this->check_index(index);
    this->_memory[index] = element;
}

template<class T>
void Vector<T>::push_back(const T &element) {
    reallocate(this->_size + 1);
    _memory[_size++] = element;
}

template<class T>
void Vector<T>::pop_back() {
    if (this->_size == 0)
        throw "vector is empty";
    this->_size--;
}

template<class T>
void Vector<T>::erase(unsigned index) {
    check_index(index);
    for (unsigned i = index; i < this->_size - 1; i++)
        this->_memory[i] = this->_memory[i + 1];
    this->_size--;
}

template<class T>
void Vector<T>::insert(unsigned index, const T &element) {
    this->reallocate(this->_size + 1);
    for (unsigned i = index; i < this->_size; i++)
        this->_memory[i + 1] = this->_memory[i];
    this->_memory[index] = element;
    this->_size++;
}

template<class T>
void Vector<T>::check_index(unsigned index) const {
    if (index < this->_size)
        return;
    throw "out of index";
}

template<class T>
T *Vector<T>::allocate(unsigned capacity) const {
    T *memory = new T[capacity];
    if (!memory)
        throw "fail to allocate memory";
    return memory;
}

template<class T>
void Vector<T>::reallocate(unsigned size) {
    if (size < this->_capacity)
        return;
    unsigned capacity = size * 2;
    T *memory = this->allocate(capacity);
    for (unsigned i = 0; i < this->_size; i++)
        memory[i] = this->_memory[i];
    delete[] this->_memory;
    this->_memory = memory;
    this->_capacity = capacity;
}

template<class T>
T *Vector<T>::begin() {
    // 벡터의 첫 요소의 포인터 반환
    return &_memory[0];
}

template<class T>
const T *Vector<T>::begin() const {
    // 벡터의 첫 요소의 포인터 반환 const 버전
    return &_memory[0];
}

template<class T>
T *Vector<T>::end() {
    // 벡터의 마지막 다음 요소 주소 반환
    // 메모리에 _size 까지 더한 주소를 반환
    return _memory + _size;
}

template<class T>
const T *Vector<T>::end() const {
    // 벡터의 마지막 다음 요소 주소 반환 const 버전
    return _memory + _size;
}

template<class T>
T &Vector<T>::operator[](unsigned index) {
    check_index(index); // index의 크기가 vector의 size 범위를 벗어나는지 검사
    return _memory[index]; // index의 크기가 vector의 size 범위를 안 벗어 날 경우 해당 index 위치의 _memory 반환
}

template<class T>
const T &Vector<T>::operator[](unsigned index) const {
    // 위에 구현한 접근 지정자 재정의 함수 const 버전
    check_index(index);
    return _memory[index];
}

template<class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &vector) {
    delete[] _memory; // 기존 memory 동적 할당 해제

    _capacity = vector._capacity; // _capacity랑 _size를 입력받은 vector의 
    _size = vector._size; // _capacity와 _size로 초기화

    _memory = new T[_capacity]; // 입력받은 _capacity의 크기에 맞게 _memory 메모리 동적 할당
    for (unsigned i = 0; i < _size; ++i) _memory[i] = vector._memory[i]; // _memory에 입력받은 객체의 _memory를 복사
    
    return *this;
}

template<class T>
Vector<T> Vector<T>::operator+(const Vector<T> &vector) const {
    Vector<T> output(this->_size + vector._size); // 새로운 객체 선언

    // 기존 객체의 memory 내용을 새로 만든 객체에 복사
    for (unsigned i = 0; i < this->_size; ++i) output._memory[i] = this->_memory[i];

    // 이후 + 연산하는 대상의 객체를 새로 만든 객체에 이어서 복사
    for (unsigned i = 0; i < vector._size; ++i) output._memory[this->_size + i] = vector._memory[i];

    // 새로 만든 객체의 size를 두 객체의 size를 합한 값으로 초기화
    output._size = this->_size + vector._size;

    return output;
}

template<class T>
Vector<T> &Vector<T>::operator+=(const Vector<T> &vector) {
    // 현재 객체에 입력받은 객체의 memory를 입력하도록 push_back 메소드를 호출하여 복사
    for (unsigned i = 0; i < vector._size; ++i) this->push_back(vector._memory[i]);
    return *this;
}

template<class T>
bool Vector<T>::operator==(const Vector<T> &vector) const {
    // 두 vector의 모든 요소를 비교
    // 먼저 두 vector의 _size와 _capacity를 비교
    if (this->_size != vector._size) return false;
    if (this->_capacity != vector._capacity) return false;

    // 이후 두 객체의 _memory의 요소를 하나씩 비교
    for (unsigned i = 0; i < this->_size; ++i) {
        if (this->_memory[i] != vector._memory[i])
            return false;
    }

    // 모든 요소들이 동일한 값을 가진다면 true 반환
    return true;
}

template<class T>
bool Vector<T>::operator!=(const Vector<T> &vector) const {
    // 두 벡터의 요소를 비교하여 다름 여부 반환
    // 먼저 두 vector의 _size와 _capacity를 비교
    if (this->_size != vector._size) return true;
    if (this->_capacity != vector._capacity) return true;

    // 모든 요소들을 하나씩 비교
    for (unsigned i = 0; i < this->_size; ++i) {
        if (this->_memory[i] != vector._memory[i]) 
            return true;
    }

    // 모든 요소들이 동일한 값을 가진다면 false 반환
    return false;
}

#endif // __VECTOR_H__