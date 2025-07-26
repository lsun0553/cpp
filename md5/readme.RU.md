В CodeBloks в новом консольном проекте удаляем `main.cpp`, добавляем `md5.cpp` `md5.hpp` `md5test0.cpp` <br>
компилируется норм, проверка на нескольких файлах совпадает с результатом из md5sum <br>
лог компилятора:<br>
`---------------- Build: Debug in md5 (compiler: GNU GCC Compiler) ---------------`<br>
`g++.exe -Wall -fexceptions -g  -c C:\bin\x64\CodeBlocks\tmp\2\md5\md5.cpp -o obj\Debug\md5.o`<br>
`g++.exe -Wall -fexceptions -g  -c C:\bin\x64\CodeBlocks\tmp\2\md5\md5test0.cpp -o obj\Debug\md5test0.o`<br>
`g++.exe  -o bin\Debug\md5.exe obj\Debug\md5.o obj\Debug\md5test0.o `<br>
`---------------------------------------------------------------------------------`
