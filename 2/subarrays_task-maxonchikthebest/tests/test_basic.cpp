#include "../src/library.hpp"
#include <iostream>
#include <vector>

void TEST1() {
    // Простой случай
    std::cout<<"Expected: 3; result: " << template_library::longest_duplicate_subarray({1,2,3,4,2,3,4,5}) <<"\n";

    // Все элементы одинаковые
    std::cout<<"Expected: 3; result: " << template_library::longest_duplicate_subarray({5,5,5,5}) << "\n";

    // Дубликаты перекрываются
    std::cout<<"Expected: 4; result: " << template_library::longest_duplicate_subarray({1,2,1,2,1,2}) << "\n";
}

void TEST2() {
    // Минимальная длина массива
    std::cout<<"Expected: 0; result: " << template_library::longest_duplicate_subarray({1,2,1,2,3,1,2}) << "\n";

    std::cout<<"Expected: 1; result: " << template_library::longest_duplicate_subarray({1}) << "\n";

    // Нет дубликатов
    std::cout<<"Expected: 0; result: " << template_library::longest_duplicate_subarray({1,2,3,4,5}) << "\n";

    // Максимальный дубликат в конце
    std::cout<<"Expected: 3; result: " << template_library::longest_duplicate_subarray({1,2,3,1,2,3}) << "\n";
}

void TEST3() {
    // Чередование элементов
    std::cout<<"Expected: 3; result: " << template_library::longest_duplicate_subarray({1,2,1,2,3,1,2}) << "\n";

    // Дубликаты из одного элемента
    std::cout<<"Expected: 1; result: " << template_library::longest_duplicate_subarray({1,2,2,3,3,4}) << "\n";

    // Дубликаты с отрицательными числами
    std::cout<<"Expected: 2; result: " << template_library::longest_duplicate_subarray({-1,0,-1,0}) << "\n";
    
}

void TEST4() {
    // Большой массив (10^5 элементов) - для проверки O(n log n)
    std::vector<int> big_array(100000, 7); // Все элементы 7
    std::cout<<"Expected: 99999; result: " << template_library::longest_duplicate_subarray(big_array) << "\n";

    // Паттерн: 1,2,3,4 повторяется 25000 раз
    std::vector<int> pattern;
    for (int i = 0; i < 25000; ++i) {
        pattern.insert(pattern.end(), {1,2,3,4});
    }
    std::cout<<"Expected: 3; result: " << template_library::longest_duplicate_subarray(pattern) << "     #Не нашел исправленные тесты, но насколько понимаю, все-таки должно ожидаться 99996" << "\n";
}
int main() {
    TEST1();
    TEST2();
    TEST3();
    TEST4();
    return 0;
    }