#include <iostream>
#include <filesystem>
#include <string> // подключаем заголовочный файл <string>


namespace fs = std::filesystem;

int fmu_first_script() {
    std::string path;
    std::cout << "Введите путь к директории: ";
    std::getline(std::cin, path);

    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::cout << entry.path() << std::endl;
        }
    }

    return 0;
}