/**  Программа принимает один или несколько путей к файлам в качестве аргументов.
Для каждого файла вычисляется  MD5-хеш с помощью метода MD5::fileToHash и выводит результат на консоль.
Если пути к файлам не указаны, выводится подсказка  как запустить программу.
 */
#include <iostream>
#include "md5.hpp"
using std::cout, std::endl;

int main(int argc, char** argv) {
    if(argc > 1) {
    // Вычисляем md5-хэш для каждого из файлов, указанных в аргументах.
        for(int i = 1; i < argc; ++i) {
            cout << MD5::fileToHash(argv[i]) << endl;}
    } else { // Если аргументов нет - выводим подсказку.
        cout << "Usage:" << endl
        << "\t" << argv[0] << " <file-to-hash>" << endl;
    }
    return 0;
}
