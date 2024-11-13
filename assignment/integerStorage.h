#include <iostream>
#include <climits>

class IntegerStorage {
private:
    int* arr;
    int currentCount;
    int maxCount;

public:
    IntegerStorage(int max);
    ~IntegerStorage();

    // 정수 추가
    void add(int value);

    // 가장 오래전에 저장된 숫자 인출
    void popOldest();

    // 가장 최근에 저장된 숫자 인출
    void popLatest();

    // 가장 큰 숫자 인출 (최대값이 2개 이상이면 가장 오래전에 저장한 값)
    void popMax();

    // 가장 작은 숫자 인출 (최소값이 2개 이상이면 가장 오래전에 저장한 값)
    void popMin();

    // 평균 계산
    void printAverage();

    // 최대 개수 변경
    void changeMaxCount();

    // 저장된 숫자 출력
    void printStoredNumbers();
};
