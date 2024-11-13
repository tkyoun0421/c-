#include "IntegerStorage.h"
#include <iostream>

int main() {
    try {
        // IntegerStorage 객체 생성 (초기 크기 5)
        IntegerStorage storage(5);

        // 숫자 추가
        storage.push(10);
        storage.push(5);
        storage.push(8);
        storage.push(3);
        storage.push(7);

        // 평균값 출력
        std::cout << "평균값: " << storage.getAverage() << std::endl;

        // 최대값 제거 및 출력
        std::cout << "최대값: " << storage.popMax() << std::endl;

        // 최소값 제거 및 출력
        std::cout << "최소값: " << storage.popMin() << std::endl;

        // 가장 최근 추가된 값 제거 및 출력
        std::cout << "최근 값: " << storage.popNewest() << std::endl;

        // 가장 오래된 값 제거 및 출력
        std::cout << "가장 오래된 값: " << storage.popOldest() << std::endl;

    } catch (const std::exception& e) {
        std::cout << "오류 발생: " << e.what() << std::endl;
    }

    return 0;
} 