class IntegerStorage {
private:
    int* numbers;        // 동적 배열
    int capacity;        // 현재 저장 공간의 크기
    int initialCapacity; // 초기 저장 공간의 크기
    int size;           // 현재 저장된 숫자의 개수
    
    void resize(int newCapacity);  // 저장 공간 크기 조절 헬퍼 함수

public:
    // 생성자: 초기 저장 공간의 크기를 지정
    explicit IntegerStorage(int initialSize);
    
    // 소멸자
    ~IntegerStorage();
    
    // 숫자 저장
    void push(int number);
    
    // 가장 오래된 숫자 인출
    int popOldest();
    
    // 마지막으로 저장한 숫자 인출
    int popNewest();
    
    // 최댓값 인출
    int popMax();
    
    // 최솟값 인출
    int popMin();
    
    // 평균값 계산
    double getAverage() const;
    
    // 최대 저장 개수 변경
    bool setCapacity(int newCapacity);
    
    // 현재 저장된 숫자 개수 반환
    int getSize() const { return size; }
};