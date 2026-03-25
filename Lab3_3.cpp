#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, int> count_characters(std::string& s) {
    std::unordered_map<std::string, int> freq;
    
    // Проходимось по кожному символу в рядку
    for (char c : s) {
        // Конвертуємо char у std::string, оскільки такий тип ключа вимагає сигнатура функції
        std::string char_str(1, c);
        // Збільшуємо лічильник для цього символу (якщо його ще немає, він автоматично ініціалізується 0)
        freq[char_str]++;
    }
    
    return freq;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::unordered_map<std::string, int> res = count_characters(s);
    
    // Перекладаємо в std::map для автоматичного сортування ключів перед виводом
    std::map<std::string, int> ordered_res(res.begin(), res.end());
    for (auto const& [key, val] : ordered_res) {
        std::cout << key << ' ' << val << '\n';
    }
    return 0;
}