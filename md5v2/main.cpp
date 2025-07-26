// MD5 test program
#include "md5.h"
#include <iostream>

int main()
{
// проверка
// echo -n "Hello World" | md5sum -t
//                     b10a8db164e0754105b7a99be72e3fe5 -
// онлайн калькул§торы b10a8db164e0754105b7a99be72e3fe5
// пример на java тоже b10a8db164e0754105b7a99be72e3fe5


  std::string s0 = "Hello World";

  // создадим экземпл€р класса MD5
  MD5 md5(s0);
  std::cout << "md5(\"" << s0 << "\") :" << std::endl;
  // хэшируем
  std::cout << md5.hexdigest() << std::endl;
  //                     => b10a8db164e0754105b7a99be72e3fe5
  const std::string chek = "b10a8db164e0754105b7a99be72e3fe5";
  if(chek == md5.hexdigest()) std::cout << "OK" << std::endl;

  // можно не создавать экземпл§р MD5
  std::cout << "md5(\"hello \") :" << std::endl;
  std::cout << MD5("hello").hexdigest() << std::endl;
  // => 5d41402abc4b2a76b9719d911017c592
  return 0;
}
