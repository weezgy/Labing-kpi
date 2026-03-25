#include <iostream>
#include <limits>
#include <string>

// Наша функція для безпечної заміни
std::string safe_modify_string(std::string& s, int index, std::string& new_char) {
    std::string result = s;              // 1. Створюємо копію оригінального рядка
    result.replace(index, 1, new_char);  // 2. Робимо заміну в копії
    return result;                       // 3. Віддаємо готовий результат
}

// Допоміжна функція для очищення вводу
void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Головна функція програми
int main() {
    std::string s;
    std::getline(std::cin, s);      // Читаємо початковий рядок
    
    int index;
    std::cin >> index;              // Читаємо номер позиції (індекс)
    ignore_line();                  // Очищаємо "сміття" після вводу числа
    
    std::string new_char;
    std::getline(std::cin, new_char); // Читаємо символ для заміни
    
    // Викликаємо нашу функцію і зберігаємо результат
    std::string res = safe_modify_string(s, index, new_char);
    
    std::cout << res << '\n';       // Виводимо результат на екран
}