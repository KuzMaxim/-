#include "../src/library.hpp"
#include <iostream>

void TEST1() {
    // Пример из условия
    std::cout << "Expected: 4; result: " << template_library::josephus_problem({ 1,2,3,4,5,6,7 }, 3) << "\n";

    // K=1 (удаление по порядку)
    std::cout << "Expected: 4; result: " << template_library::josephus_problem({ 1,2,3,4 }, 1) << "\n";

    // K превышает размер массива
    std::cout << "Expected: 2; result: " << template_library::josephus_problem({ 1,2,3 }, 5) << "\n"; // 5 mod 3 = 2 → порядок удаления: 2, 1 → остаётся 3
}

void TEST2() {
    // Массив из одного элемента
    std::cout << "Expected: 42; result: " << template_library::josephus_problem({ 42 }, 10) << "\n";

    // K=2, чётный размер
    std::cout << "Expected: 1; result: " << template_library::josephus_problem({ 1,2,3,4 }, 2) << "\n";
}

void TEST3() {
    // K=2, нечётный размер
    std::cout << "Expected: 3; result: " << template_library::josephus_problem({ 1,2,3,4,5 }, 2) << "\n";

    // Все элементы удаляются за один круг
    std::cout << "Expected: 2; result: " << template_library::josephus_problem({ 1,2,3,4 }, 4) << "\n"; // Удаляются 4 → 1 → 3 → остаётся 2
}

void TEST4() {
    std::vector<int> big_array(1000);
    for (int i = 0; i < 1000; ++i) big_array[i] = i + 1;
    std::cout << "Expected: 404; result: " << template_library::josephus_problem(big_array, 7) << "\n"; // Проверка для большого N
}

int main() {
    TEST1();
    TEST2();
    TEST3();
    TEST4();

    return 0;
}
