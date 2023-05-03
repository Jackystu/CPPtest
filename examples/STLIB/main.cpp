#include <elog/logger.h>
#include <mylog/log.h>
#include <mytest/mytest.h>

#include <iostream>
using namespace elog;

int main()
{
    log_info("hello world!\n");
    my_test();
    Log::info("hello, world!");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
