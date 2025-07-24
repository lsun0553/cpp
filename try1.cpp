/* try{} catch(){} три варианта */
#include <iostream>
#include <stdexcept> // Для std::runtime_error
//<stdexcept> можно не подключать, а использовать просто строки ( и string и char* ), см вариант 2
#include <cmath>     // Для sqrt()

using namespace std;

// Две вспомогательные ф-и для иллюстрации работы throw
// Вторая вызовется когда пример запущен с аргументом/аргументами
int div0(int a, int b) {//№1
/*  // вариант 1
    if (b == 0) {
        throw runtime_error("Деление на нуль!"); // Генерация исключения
    }
    return a / b;
//
    // вариант 2 */
    if (b) {// любое отличное от нуля это true
        return a / b;
    }
    throw runtime_error("Деление на нуль!");// Генерация исключения
}

double sqrt0 (double c) {//№2
  if (c < 0) {
    //throw 0;// сработает последний catch(...)
    throw "Отрицательные не обрабатываю !!";
  }
  return sqrt(c);
}

int main(int argc, char **argv)
{
  int result = 0, k = 0;
  double  i1 = 0;
  cout << "введите число:" << endl;
  cin >> i1;
  try {
    if (argc == 1) {
      result = div0(1000,i1);
      cout << "1000 / " << i1 << " = " << result << endl;
    } else {
      //result = sqrt0(i1);// неявно преобразует в int, дробная часть теряется
      sqrt0(i1);
      cout << "sqrt0( " << i1 << " ) = " << sqrt0(i1) << endl;
    }
  } catch (const runtime_error &err){ // вариант 1
    // желательно именно const и ссылка, иначе компилятор ругнется
    // catch ( runtime_error err)     // но работать будет и так
      cerr <<  err.what() << endl;
      cerr << "ERROR. на нуль делить нельзя" << endl;
      k = 1;
  } catch (const char* error_message){ // вариант 2
      cerr << error_message;
      k = 2;
  }  catch(...) { // можно так (ловит все исключения) вариант 0
    // нужно ставить последним
    // для проверки комментируем или вариант1 или вариант2 или оба
    // или "кидаем" исключение необрабатываемое ни вариантом1 ни вариантом2, см строку 27 (закомментирована в ф-и sqrt0())
      cerr << "ОШИБКА!" << endl;
      k = 3;
  }
  return k;
}
