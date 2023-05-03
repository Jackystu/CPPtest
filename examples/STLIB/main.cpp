#include <elog/logger.h>

#include <iostream>
#include <mytest/mytest.h>
#include <mylog/log.h>
using namespace elog;

class Base
{
public:
   Base() {}
};

int main()
{
   log_info("hello world!\n");
   my_test();
   Log::info("hello, world!");
   std::cout << "Hello, World!" << std::endl;
   return 0;
}
