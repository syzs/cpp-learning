// #include <iostream>
// using namespace std;

// int main(){
//     cout << "Hello cpp" << endl;
//     return 0;
// }

#include<iostream>
using namespace std;

// 函数声明
int variable();
void storeClass();
void staticVFunc();
void func_loop();

// TODO 修饰符 volatile 告诉编译器不需要优化volatile声明的变量，让程序可以直接从内存中读取变量。对于一般的变量编译器会对变量进行优化，将内存中的变量值放在寄存器中以加快读写效率。
// TODO signed、unsigned

int main(){
    int a = variable();
    storeClass();
    func_loop();
    return 0;
}

void func_array(){
    int a0[10];
    int a1[10] = {1,2,3,4,5,6,7,8,9,10};
    int a2[] = {1,2,3};

    int a[5][2] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8}};
 
   // 输出数组中每个元素的值                      
   for ( int i = 0; i < 5; i++ ){
      for ( int j = 0; j < 2; j++ )
      {
         cout << "a[" << i << "][" << j << "]: ";
         cout << a[i][j]<< endl;
      }
   }
}

void func_loop(){
    for (int i = 0; i < 5; i++)
    {
        cout << "for i:"<<i << endl;
    }
    
   int  t=5;
    while (t--)
    {
        cout << "while t:" <<t << endl;
    }

    int x = 5;
    do
    {
        cout<< "do x:" << x<<endl;
    } while (x--);
    
    
}

/**
 * @brief 存储类
 * 储类定义 C++ 程序中变量/函数的范围（可见性）和生命周期。这些说明符放置在它们所修饰的类型之前。下面列出 C++ 程序中可用的存储类：
auto
register
static
extern
mutable
thread_local (C++11)
从 C++ 17 开始，auto 关键字不再是 C++ 存储类说明符，且 register 关键字被弃用。
 * 
 */

static int tcount = 10; /* 文件内的全局变量，仅在hello.cpp 中全局变量 */
// 当您有多个文件且定义了一个可以在其他文件中使用的全局变量或函数时，可以在其他文件中使用 extern 来得到已定义的变量或函数的引用。可以这么理解，extern 是用来在另一个文件中声明一个全局变量或函数
// extern 修饰符通常用于当有两个或多个文件共享相同的全局变量或函数的时候
extern void write_extern();
int ecount;
void storeClass(){
    // auto:1、初始化表达式自动推断被声明的变量的类型；2、声明函数时函数返回值的占位符？？
    // auto f = 3.14;
    // cout << f<< "\n";

    // static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。
    // static 修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。
    // 在 C++ 中，当 static 用在类数据成员上时，会导致仅有一个该成员的副本被类的所有对象共享。

    while (tcount--)
    {
        staticVFunc();
    }
    ecount = 5;
    write_extern();
}

void staticVFunc (){
    static int i=5;
    i++;
    cout << "i:" << i << "count:" << tcount << endl;
}


/**
 * @brief 常量、变量、数据类型、作用域、修饰符
 * 
 */
// 类型别名
typedef int int_alias;

// 常量，#define预处理器
#define VALUE0 10
// 常量，const 声明。const 类型的对象在程序执行期间不能被修改改变。
const int VALUE1 = 20; 
const int_alias VALUE2= 30;

int variable(){
    std::cout << "Hello cpp\n";
    std::cout << VALUE0 << std::endl;
    std::cout << VALUE1 <<std::endl;
    std::cout << VALUE2 <<std::endl;

    int a = -1;
    std::cout << a <<std::endl;

    short int i;          // 有符号短整数
    short unsigned int j; // 无符号短整数
    j = 50000;
    i = j;
    cout << i << " " << j << "\n"; // -15536 50000
    return 0;
}