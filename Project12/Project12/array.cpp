#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class Array {
private:
    int* arr;
    size_t size;

public:
    // Конструктор створення пустого масиву
    Array(size_t n = 0) : size(n) {
        arr = new int[size];
        std::fill(arr, arr + size, 0);
    }

    // Конструктор створення масиву з випадковими значеннями
    Array(size_t n, bool random) : size(n) {
        arr = new int[size];
        if (random) {
            std::srand(std::time(0)); // Ініціалізація генератора випадкових чисел
            for (size_t i = 0; i < size; ++i) {
                arr[i] = std::rand() % 100;  // Випадкові числа від 0 до 99
            }
        }
    }

    // Конструктор створення масиву з однаковими значеннями в діапазоні
    Array(size_t n, int min, int max) : size(n) {
        arr = new int[size];
        for (size_t i = 0; i < size; ++i) {
            arr[i] = min + std::rand() % (max - min + 1);
        }
    }

    // Конструктор копіювання
    Array(const Array& other) : size(other.size) {
        arr = new int[size];
        std::copy(other.arr, other.arr + size, arr);
    }

    // Деструктор
    ~Array() {
        delete[] arr;
    }

    // Відображення масиву
    void display() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // Заповнення масиву випадковими значеннями
    void fillRandom() {
        for (size_t i = 0; i < size; ++i) {
            arr[i] = std::rand() % 100;
        }
    }

    // Зміна розміру масиву
    void resize(size_t newSize) {
        int* newArr = new int[newSize];
        std::copy(arr, arr + std::min(size, newSize), newArr);
        delete[] arr;
        arr = newArr;
        size = newSize;
    }

    // Сортування масиву
    void sortArray() {
        std::sort(arr, arr + size);
    }

    // Мінімальне значення
    int min() const {
        return *std::min_element(arr, arr + size);
    }

    // Максимальне значення
    int max() const {
        return *std::max_element(arr, arr + size);
    }
};

int main() {
    Array arr1(5);            // Масив з 5 елементів
    Array arr2(5, true);       // Масив з випадковими значеннями
    Array arr3(10, 10, 50);    // Масив з випадковими значеннями в діапазоні 10-50

    arr1.display();
    arr2.display();
    arr3.display();

    std::cout << "Min: " << arr2.min() << std::endl;
    std::cout << "Max: " << arr2.max() << std::endl;

    arr2.sortArray();
    arr2.display();

    return 0;
}
