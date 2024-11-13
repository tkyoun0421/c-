#include "IntegerStorage.h"
#include <stdexcept>
#include <algorithm>

IntegerStorage::IntegerStorage(int initialSize) {
    if (initialSize <= 0) {
        throw std::invalid_argument("초기 크기는 0보다 커야 합니다.");
    }
    capacity = initialSize;
    initialCapacity = initialSize;
    size = 0;
    numbers = new int[capacity];
}

IntegerStorage::~IntegerStorage() {
    delete[] numbers;
}

void IntegerStorage::resize(int newCapacity) {
    int* temp = new int[newCapacity];
    for (int i = 0; i < size; i++) {
        temp[i] = numbers[i];
    }
    delete[] numbers;
    numbers = temp;
    capacity = newCapacity;
}

void IntegerStorage::push(int number) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    numbers[size++] = number;
}

int IntegerStorage::popOldest() {
    if (size == 0) {
        throw std::runtime_error("저장된 숫자가 없습니다.");
    }
    
    int result = numbers[0];
    for (int i = 0; i < size - 1; i++) {
        numbers[i] = numbers[i + 1];
    }
    size--;
    
    // 빈 공간이 3/4 이상이면 저장 공간 축소
    if (size * 4 <= capacity) {
        int newCapacity = std::max(initialCapacity, capacity / 2);
        if (newCapacity < capacity) {
            resize(newCapacity);
        }
    }
    
    return result;
}

int IntegerStorage::popNewest() {
    if (size == 0) {
        throw std::runtime_error("저장된 숫자가 없습니다.");
    }
    
    int result = numbers[--size];
    
    // 빈 공간이 3/4 이상이면 저장 공간 축소
    if (size * 4 <= capacity) {
        int newCapacity = std::max(initialCapacity, capacity / 2);
        if (newCapacity < capacity) {
            resize(newCapacity);
        }
    }
    
    return result;
}

int IntegerStorage::popMax() {
    if (size == 0) {
        throw std::runtime_error("저장된 숫자가 없습니다.");
    }
    
    int maxIdx = 0;
    for (int i = 1; i < size; i++) {
        if (numbers[i] >= numbers[maxIdx]) {
            maxIdx = i;
        }
    }
    
    int result = numbers[maxIdx];
    for (int i = maxIdx; i < size - 1; i++) {
        numbers[i] = numbers[i + 1];
    }
    size--;
    
    // 빈 공간이 3/4 이상이면 저장 공간 축소
    if (size * 4 <= capacity) {
        int newCapacity = std::max(initialCapacity, capacity / 2);
        if (newCapacity < capacity) {
            resize(newCapacity);
        }
    }
    
    return result;
}

int IntegerStorage::popMin() {
    if (size == 0) {
        throw std::runtime_error("저장된 숫자가 없습니다.");
    }
    
    int minIdx = 0;
    for (int i = 1; i < size; i++) {
        if (numbers[i] <= numbers[minIdx]) {
            minIdx = i;
        }
    }
    
    int result = numbers[minIdx];
    for (int i = minIdx; i < size - 1; i++) {
        numbers[i] = numbers[i + 1];
    }
    size--;
    
    // 빈 공간이 3/4 이상이면 저장 공간 축소
    if (size * 4 <= capacity) {
        int newCapacity = std::max(initialCapacity, capacity / 2);
        if (newCapacity < capacity) {
            resize(newCapacity);
        }
    }
    
    return result;
}

double IntegerStorage::getAverage() const {
    if (size == 0) {
        throw std::runtime_error("저장된 숫자가 없습니다.");
    }
    
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum / size;
}

bool IntegerStorage::setCapacity(int newCapacity) {
    if (newCapacity < size) {
        return false;
    }
    resize(newCapacity);
    initialCapacity = newCapacity;
    return true;
}