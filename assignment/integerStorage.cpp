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
        std::cout << "���� ������ ���� á���ϴ�. ������ �� �����ϴ�." << std::endl;
        return;
    }
    arr[currentCount++] = value;
    resizeStorage();  
}

void IntegerStorage::popOldest() {
    if (currentCount == 0) {
        std::cout << "����� ���ڰ� �����ϴ�." << std::endl;
        return;
    }
    std::cout << "���� �������� ����� ����: " << arr[0] << std::endl;

    for (int i = 0; i < currentCount - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --currentCount;
    resizeStorage(); 
}

void IntegerStorage::popLatest() {
    if (currentCount == 0) {
        std::cout << "����� ���ڰ� �����ϴ�." << std::endl;
        return;
    }
    std::cout << "���� �ֱٿ� ����� ����: " << arr[currentCount - 1] << std::endl;
    --currentCount;
    resizeStorage();  
}

void IntegerStorage::popMax() {
    if (currentCount == 0) {
        std::cout << "����� ���ڰ� �����ϴ�." << std::endl;
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

    std::cout << "���� ū ����: " << arr[maxIndex] << std::endl;

    for (int i = maxIndex; i < currentCount - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --currentCount;
    resizeStorage();  
}

void IntegerStorage::popMin() {
    if (currentCount == 0) {
        std::cout << "����� ���ڰ� �����ϴ�." << std::endl;
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

    std::cout << "���� ���� ����: " << arr[minIndex] << std::endl;

    for (int i = minIndex; i < currentCount - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --currentCount;
    resizeStorage(); 
}

void IntegerStorage::printAverage() {
    if (currentCount == 0) {
        std::cout << "����� ���ڰ� �����ϴ�." << std::endl;
        return;
    }

    int sum = 0;
    for (int i = 0; i < currentCount; ++i) {
        sum += arr[i];
    }
    std::cout << "����� ������ ���: " << static_cast<double>(sum) / currentCount << std::endl;
}

void IntegerStorage::changeMaxCount(int newMaxCount) {
    if (newMaxCount < currentCount) {
        std::cout << "���ο� �ִ� ũ��� ���� ����� ���� �������� ���� �� �����ϴ�." << std::endl;
        return;
    }

    maxCount = newMaxCount;

    resizeStorage();  
}


void IntegerStorage::resizeStorage() {
    int newMax;

    if (currentCount <= maxCount / 4) {
        newMax = std::max(maxCount / 2, currentCount);  
    } else if (currentCount == maxCount) {
        newMax = maxCount * 2;  
    } else {
        return; 
    }

    int* newArr = new int[newMax];
    for (int i = 0; i < currentCount; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    maxCount = newMax;

    std::cout << "���� ������ ũ�Ⱑ " << maxCount << "���� ����Ǿ����ϴ�." << std::endl;
}

void IntegerStorage::printStoredNumbers() {
    if (currentCount == 0) {
        std::cout << "����� ���ڰ� �����ϴ�." << std::endl;
        return;
    }

    std::cout << "����� ���ڵ�: [";
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

    std::cout << "������ �� �ִ� ������ �ִ� ������ �Է��ϼ���: ";
    std::cin >> max;

    IntegerStorage storage(max);

    int choice, value;

    while (true) {
        storage.printStoredNumbers();

        std::cout << "\n�ɼ��� �����ϼ���: \n";
        std::cout << "1. ���� ����\n";
        std::cout << "2. ���� �������� ������ ���� ����\n";
        std::cout << "3. ���� �ֱ� ������ ���� ����\n";
        std::cout << "4. ���� ū ���� ����\n";
        std::cout << "5. ���� ���� ���� ����\n";
        std::cout << "6. ��� ���\n";
        std::cout << "7. �ִ� ������ �� �ִ� ���� ���� ����\n";
        std::cout << "0. ����\n";
        std::cout << "����: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "������ ������ �Է��ϼ���: ";
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
                std::cout << "���ο� �ִ� ���� ������ �Է��ϼ���: ";
                std::cin >> value;
                storage.changeMaxCount(value);  
                break;
            case 0:
                std::cout << "���α׷��� �����մϴ�." << std::endl;
                return 0;
            default:
                std::cout << "�߸��� �Է��Դϴ�." << std::endl;
        }
    }

    return 0;
}
