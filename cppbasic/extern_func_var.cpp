#include <iostream>

// 对于无法初始化的变量，会把变量名指向一个之前定义过的存储位置。
extern int ecount;

void write_extern(){
    std::cout << "extern count:" << ecount << std::endl;
}