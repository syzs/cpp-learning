#include <iostream>

using namespace std;

/**
 * @brief
 *cout 标准输出流
 *  cout 对象"连接"到标准输出设备，通常是显示屏。
 *  cout 是与流插入运算符 << 结合使用的
 *  C++ 编译器根据要输出变量的数据类型，选择合适的流插入运算符来显示值。
 *  << 运算符被重载来输出内置类型（整型、浮点型、double 型、字符串和指针）的数据项。
 *
 *预定义的对象 cerr 是 iostream 类的一个实例。
 *  cerr 对象附属到标准输出设备，通常也是显示屏，但是 cerr 对象是非缓冲的，且每个流插入到 cerr 都会立即输出。
 *
 * 预定义的对象 clog 是 iostream 类的一个实例。
 *  clog 对象附属到标准输出设备，通常也是显示屏，但是 clog 对象是缓冲的。
 *  这意味着每个流插入到 clog 都会先存储在缓冲区，直到缓冲填满或者缓冲区刷新时才会输出。
 * @return int
 */

int main()
{

    // cout: 标准输出
    char str[] = "Hello C++";
    const char *names[3] = {
        "Zara Ali",
        "Hina Ali",
        "Nuha Ali",
    };

    cout << "Value of str is : " << str << endl;
    cout << "Value of str is : " << names << endl;

    // // cin: 标准输入
    // char name[50];
    // char age[10];
    // cout << "请输入您的名称： ";
    // cin >> name;
    // cout << "请输入您的年龄： ";
    // cin >> age; // == cin >> name >> age
    // cout << "您的名称是： " << name << endl;

    // cerr: 标准错误流
    cerr << "err message: panic" << endl;

    // clog: 标准日志流
    clog << "log err message" << endl;
    return 0;
}