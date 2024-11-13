#include "integerStorage.h"
#include <iostream>
#include <climits>

IntegerStorage::IntegerStorage(int max) {
    maxCount = max;
    currentCount = 0;
    arr = new int[maxCount];
}

IntegerStorage::~IntegerStorage() {
    delete[] arr;
}

void IntegerStorage::add(int value) {
    if (currentCount == maxCount) {
        std::cout << "저장 공간이 가득 찼습니다. 저장할 수 없습니다." << std::endl;
        return;
    }
    arr[currentCount++] = value;
}

void IntegerStorage::popOldest() {
    if (currentCount == 0) {
        std::cout << "저장된 숫자가 없습니다." << std::endl;
        return;
    }
    std::cout << "가장 오래전에 저장된 숫자: " << arr[0] << std::endl;

    // 배열을 왼쪽으로 이동
    for (int i = 0; i < currentCount - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --currentCount;
}

void IntegerStorage::popLatest() {
    if (currentCount == 0) {
        std::cout << "저장된 숫자가 없습니다." << std::endl;
        return;
    }
    std::cout << "가장 최근에 저장된 숫자: " << arr[currentCount - 1] << std::endl;
    --currentCount;
}

void IntegerStorage::popMax() {
    if (currentCount == 0) {
        std::cout << "저장된 숫자가 없습니다." << std::endl;
        return;
    }

    int maxVal = INT_MIN;
    int maxIndex = -1;
    for (int i = 0; i < currentCount; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
    }

    std::cout << "가장 큰 숫자: " << arr[maxIndex] << std::endl;

    // 삭제 후 배열을 왼쪽으로 이동
    for (int i = maxIndex; i < currentCount - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --currentCount;
}

void IntegerStorage::popMin() {
    if (currentCount == 0) {
        std::cout << "저장된 숫자가 없습니다." << std::endl;
        return;
    }

    int minVal = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < currentCount; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
    }

    std::cout << "가장 작은 숫자: " << arr[minIndex] << std::endl;

    // 삭제 후 배열을 왼쪽으로 이동
    for (int i = minIndex; i < currentCount - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --currentCount;
}

void IntegerStorage::printAverage() {
    if (currentCount == 0) {
        std::cout << "저장된 숫자가 없습니다." << std::endl;
        return;
    }

    int sum = 0;
    for (int i = 0; i < currentCount; ++i) {
        sum += arr[i];
    }
    std::cout << "저장된 숫자의 평균: " << static_cast<double>(sum) / currentCount << std::endl;
}

void IntegerStorage::changeMaxCount() {
    int newMax;
    std::cout << "새로운 최대 개수를 입력하세요: ";
    std::cin >> newMax;

    if (newMax < currentCount) {
        std::cout << "현재 저장된 숫자의 개수보다 작은 값으로 변경할 수 없습니다." << std::endl;
        return;
    }

    maxCount = newMax;
    std::cout << "최대 개수가 " << maxCount << "으로 변경되었습니다." << std::endl;
}

void IntegerStorage::printStoredNumbers() {
    if (currentCount == 0) {
        std::cout << "저장된 숫자가 없습니다." << std::endl;
        return;
    }

    std::cout << "저장된 숫자들: [";
    for (int i = 0; i < currentCount; ++i) {
        std::cout << arr[i];
        if (i < currentCount - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    int max;

    // 유저에게 최대 저장할 정수의 개수 입력받기
    std::cout << "저장할 수 있는 정수의 최대 개수를 입력하세요: ";
    std::cin >> max;

    IntegerStorage storage(max);

    int choice, value;

    while (true) {
        storage.printStoredNumbers();

        std::cout << "\n옵션을 선택하세요: \n";
        std::cout << "1. 정수 저장\n";
        std::cout << "2. 가장 오래전에 저장한 정수 인출\n";
        std::cout << "3. 가장 최근 저장한 정수 인출\n";
        std::cout << "4. 가장 큰 정수 인출\n";
        std::cout << "5. 가장 작은 정수 인출\n";
        std::cout << "6. 평균 계산\n";
        std::cout << "7. 최대 개수 변경\n";
        std::cout << "0. 종료\n";
        std::cout << "선택: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "저장할 정수를 입력하세요: ";
                std::cin >> value;
                storage.add(value);
                break;
            case 2:
                storage.popOldest();
                break;
            case 3:
                storage.popLatest();
                break;
            case 4:
                storage.popMax();
                break;
            case 5:
                storage.popMin();
                break;
            case 6:
                storage.printAverage();
                break;
            case 7:
                storage.changeMaxCount();
                break;
            case 0:
                std::cout << "프로그램을 종료합니다." << std::endl;
                return 0;
            default:
                std::cout << "잘못된 입력입니다." << std::endl;
        }
    }

    return 0;
}