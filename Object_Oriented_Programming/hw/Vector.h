#ifndef VECTOR_H
#define VECTOR_H

template <class T> class Vector {
  T *_memory;         // 동적으로 생성한 T 타입의 배열을 가리킬 포인터
  unsigned _capacity; // 동적으로 할당된 메모리의 크기
  unsigned _size;     // 배열에 저장된 요소의 수

public:
  Vector(unsigned capacity = 5) {
    // _memory의 크기를 매개변수 capacity 크기로 동적으로 할당하고
    // 동적으로 할당된 배열의 요소는 없도록 초기화하는 생성자를 여기에 구현
    _capacity= capacity;      // _capacity를 입력받은 capacity의 값으로 초기화 
    _size= 0;                 // 어떤 값도 Vector에 없으므로 _size는 0값으로 초기화
    _memory= new T[capacity]; // capacity의 크기에 맞게 _memory 배열을 동적 메모리 할당
  }

  Vector(unsigned size, const T &element) {
    // 메모리의 크기와 요소의 개수를 size 만큼 설정
    // size의 두 배 크기의 메모리를 동적으로 생성
    // 동적 메모리의 각 요소의 값은 element로 초기화
    _capacity= size* 2;            // 다음에 Vector에 push할 때 _capacity가 부족할 것이므로 미리 _capacity의 값을 입력 받은 값의 두 배로 초기화
    _size= size;                   // _size의 값을 입력받은 size 값으로 초기화
    _memory= new T[_capacity];     // _memory를 _capacity의 크기로 동적 메모리 할당
    for(int i= 0; i< _size; i++) { // for loop를 이용하여 입력받은 element로 _memory 내부의 값을 _size 개수 만큼 번부 초기화
      _memory[i]= element;
    }
  }

  ~Vector() {
    // 동적 메모리 해제
    delete [] _memory; // 동적 메모리 할당 해제
  }

  unsigned size() const {
    // 동적 배열에 저장된 요소의 갯수를 리턴
    return _size; // _size은 동적 배열에 저장된 요소의 갯수를 의미하므로 _size를 반환
  }

  unsigned capacity() const {
    // 동적 배열의 크기를 리턴
    return _capacity; // _capacity는 Vector의 _memory의 동적 배열의 크기를 의미하므로 _capacity를 반환
  }

  const T &at(unsigned index) const {
    // 동적 배열의 index 위치에 저장된 요소를 리턴
    // 배열의 크기를 넘는 인덱스틑 고려하지 않아도 됨
    return _memory[index]; // _memory의 index 위치의 값을 반환
  }

  void set(unsigned index, const T &element) {
    // index가 유효할 경우만 동적 배열의 index 위치의 요소를 element로 변경
    // index 요소가 유효하다는 의미는 배열의 요소의 갯수를 넘지 않는 범위의 인덱스라는 의미
    if(index < _size) { // index가 유효한지확인
      _memory[index]= element; // index가 유효할 경우 _memory의 index 위치의 값을 입력 받은 element로 변경
    }
  }

  bool empty() const {
    // 배열에 저장된 요소가 없을 경우 true, 그렇지 않다면 false를 리턴
    if(_size== 0) return true; // _size가 0일 경우 true 반환
    else return false;         // _size가 Vector에 저장된 요소의 갯수를 의미하기 때문
  }

  void push_back(const T &element) {
    // 배열의 끝에 element를 추가
    if(_size< _capacity) { // _size의 값이 _capacity를 넘어서지 않는 경우
      _memory[_size++]= element;
    } else {               // _size가 _capacity를 넘어서는 경우
      _capacity*= 2;                                    // _capacity의 값을 두 배로 조정
      T *temp= new T[_capacity];                         // 두배의 _capacity의 값을 가진 임시 배열 temp 동적 메모리 할당

      for(int i= 0; i< _size; i++) temp[i]= _memory[i]; // for loop를 이용하여 temp 배열에 _memory 배열의 값을 복사
      
      delete [] _memory;                                // 기존 _memory 배열을 동적 메모리 할당 해제
      _memory= temp;                                    // _memory에 temp 주소를 저장해줌
      _memory[_size++]= element;                        // _memory에 추가할 element값 초기화
    }
  }

  void pop_back() {
    // 배열의 마지막 요소를 제거
    // 더이상 제거할 요소가 없다면 무시
    if(_size!= 0) { // _size 값이 0이 아닌 경우 _size 값을 1 줄여 배열의 마지막 요소를 제거
      _size--;      // _size 값이 0인 경우 아무것도 수행 안 함
    }
  }

  void erase(unsigned index) {
    // index가 유효한 경우, 배열의 index 위치의 요소를 삭제
    // 유효하지 않은 경우는 아무 일도 일어나지 않음
    if(index< _size) { // index가 유효한 경우를 확인
      for(int i= index+ 1; i< _size; i++) { // for loop를 통해 제거할 부분의 _memory의 index의 뒷 부분 부터 한칸씩 당겨옴
        _memory[i- 1]= _memory[i];
      }
      _size--; // 배열의 값을 하나 제거했으므로 _size의 값을 1 감소시킴
    }
  }

  void insert(unsigned index, const T &element) {
    // index 위치가 유효한 경우(배열의 요소의 수를 넘지 않는 위치)
    // index 위치에 element를 삽입
    if(index< _size) { // index 위치가 유효한지 확인
      for(int i= _size- 1; i>= index; i--) _memory[i+ 1]= _memory[i]; // for loop를 이용해 element를 넣을 index 위치 부터 _memory의 값을 한칸씩 뒤로 이동시켜줌
      
      _memory[index]= element;                                        // _memory의 index 부분에 입력받은 element값 대입
      _size++;                                                        // _memory 배열의 값을 넣었으므로 _size값 1 증가
    } else { // _size가 _capacity를 넘어서는 경우
      _capacity*= 2;                                                  // _capacity의 값을 두 배로 조정
      T *temp= new T[_capacity];                                       // 두배의 _capacity의 값을 가진 임시 배열 temp 동적 메모리 할당

      for(int i= 0; i< index; i++) temp[i]= _memory[i];               // index 전과 index 후로 나눠 for loop룰 이용해 temp배열을 index 위치만 비워놓고
      for(int i= _size- 1; i>= index; i--) temp[i+ 1]= _memory[i];    // for loop를 이용해 _memory의 값을 temp에 복사
      temp[index]= element;                                           // temp의 index 부분에 입력받은 element값 대입
      _size++;                                                        // temp 배열에 값을 하나 추가했으므로 _size값 1 증가
      
      delete [] _memory;                                              // 기존 _memory 배열을 동적 메모리 할당 해제
      _memory= temp;                                                  // _memory에 temp 주소를 저장해줌
    }
  }
};

#endif