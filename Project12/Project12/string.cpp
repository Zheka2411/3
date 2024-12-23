#include <iostream>
#include <cstring>

class String {
private:
    char* str;
    size_t length;

public:
    // Конструктор за замовчуванням (80 символів)
    String() : length(80) {
        str = new char[length + 1];
        std::memset(str, '\0', length + 1);
    }

    // Конструктор, що дозволяє створювати рядок довільного розміру
    explicit String(size_t len) : length(len) {
        str = new char[length + 1];
        std::memset(str, '\0', length + 1);
    }

    // Конструктор, який створює рядок, ініціалізуючи його рядком користувача
    String(const char* s) {
        length = std::strlen(s);
        str = new char[length + 1];
        std::strcpy(str, s);
    }

    // Конструктор копіювання
    String(const String& other) : length(other.length) {
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }

    // Деструктор
    ~String() {
        delete[] str;
    }

    // Метод для введення рядка з клавіатури
    void input() {
        std::cout << "Enter string: ";
        std::cin.getline(str, length + 1);
    }

    // Метод для виведення рядка
    void output() const {
        std::cout << str << std::endl;
    }

    // Отримати рядок
    const char* getStr() const {
        return str;
    }
};

int main() {
    String s1;              // Використання конструктора за замовчуванням
    String s2(100);          // Використання конструктора з довільним розміром
    String s3("Hello!");     // Використання конструктора з ініціалізацією

    s1.input();              // Введення рядка
    s1.output();             // Виведення рядка

    s2.output();
    s3.output();

    return 0;
}
