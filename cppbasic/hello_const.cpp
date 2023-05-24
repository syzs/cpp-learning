#include <iostream>
#include <typeinfo>
#include <vector>

// https://blog.csdn.net/shift_wwx/article/details/79020617
/**
 * @brief

const int a;            // a 代表一个常整型数
int const a;            // a 代表一个常整型数
const int *a;           // a 代表一个指向常整型数的指针，即a的值是可变的，但是*a是不能变的，函数的一些形参经常会用到
int * const a;          // a 代表一个常指针，即a的值是不可变的，但是*a是可变的
int const * a const;    // a代表的是一个指向常整型数的常指针

 *
 */

using namespace std;
void constVariable();
void funcPtr();

int main(void)
{

    // constVariable();
    funcPtr();
    return 0;
}

void funcPtr()
{
    // A: const 修饰指针指向的内容，则内容为不可变量。
    const int *p = 8; // 指针指向的内容8不可改变，简称左定值，因为const位于*左边
    *p = 10;
    // B: const 修饰指针，则指针为不可变量。
    // C: const 修饰指针和指针指向的内容，则指针和指针指向的内容都为不可变量。
}

/**
 * @brief const + 类型
 *
 *
 */
void constVariable()
{
    // 常量
    const int a = 1;
    int b = 1;
    cout << "a:" << typeid(a).name() << " ; "
         << "b:" << typeid(b).name() << endl; // a:i ; b:i

    // a = 8; // cannot assign to variable 'a' with const-qualified type 'const int'

    /**
     * @brief PKi 指针 常量整数
     * Pi 指针 整数
     *
     */
    auto tmpp = &a;
    cout << "tmpp:" << typeid(tmpp).name() << " v:" << *tmpp << endl; // tmpp:PKi v:1
    auto tmpq = &b;
    cout << "tmpq:" << typeid(tmpq).name() << " v:" << *tmpq << endl; // tmpq:Pi v:1

    int *p = (int *)&a; // cannot initialize a variable of type 'int *' with an rvalue of type 'const int *'

    cout << "p:" << typeid(p).name() << " v:" << *p << endl; // Pi

    *p = 10;
    cout << "a:" << a << endl; // 仍然是 a=1，常量是不可变更的 ！！！！
}