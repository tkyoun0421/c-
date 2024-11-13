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

    void add(int value);

    void popOldest();

    void popLatest();

    void popMax();

    void popMin();

    void printAverage();

    void changeMaxCount(int newMaxCount);

    void printStoredNumbers();

    void resizeStorage();
};
