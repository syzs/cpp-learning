#include <iostream>
using namespace std;

/**
 * @brief
 *
 * 引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。
 * 引用很容易与指针混淆，它们之间有三个主要的不同：
    不存在空引用。引用必须连接到一块合法的内存。
    一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
    引用必须在创建时被初始化。指针可以在任何时间被初始化
 *

 1、指针是存储变量地址的变量；引用是变量的别名。

2、指针变量定义时不必初始化；引用定义时必须初始化，不然会报错。

3、指针变量定义时可以初始化为NULL；引用不能初始化为NULL，不然报错。

4、const修饰指针变量，const放在之前，指针变量所指向变量的值不可改变，指针值可以改变；const放在之后，指针变量所指向变量的值可以改变，指针值不可以改变；const修饰引用，const放在&之前，不能修改引用所表示的变量的值；const放在&之后，const的作用被忽略，可以修改引用所表示的变量的值。

5、非常指针在指针赋值后可以改变指针值；引用在初始化后不能再作为别的变量的别名。

6、sizeof运算符作用于指针变量得到指针变量自身大小；作用于引用，得到引用所指向的变量的大小。

7、指针可以有多级，引用只有一级。

8、指针的自增、自减表示指向下一个同类型变量的地址，一般用于指向数组的指针；引用的自增、自减表示指向变量值的增、减。



 * @param x
 * @param y
 */
// 函数声明
void swap(int &x, int &y);

double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

double &setValues(int i);

int main()
{
    int i;
    double d;
    int &r = i;
    double &s = d;
    // int *&pt = t;

    i = 5;
    cout << "Value of i : " << i << ",type:" << typeid(i).name() << endl;
    cout << "Value of i reference : " << r << ",type:" << typeid(r).name() << endl;
    d = 11.7;
    cout << "Value of d : " << d << endl;
    cout << "Value of d reference : " << s << endl;

    // cout << "Value of t : " << t << ",type:" << typeid(t).name() << endl;
    // cout << "Value of pt reference : " << pt << ",type:" << typeid(pt).name() << endl;

    // 局部变量声明
    int a = 100;
    int b = 200;
    cout << "交换前，a 的值：" << a << endl;
    cout << "交换前，b 的值：" << b << endl;
    /* 调用函数来交换值 */
    swap(a, b);
    cout << "交换后，a 的值：" << a << endl;
    cout << "交换后，b 的值：" << b << endl;

    cout << "改变前的值" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }
    double &res = setValues(1) = 20.23; // 改变第 2 个元素
    setValues(3) = 70.8;                // 改变第 4 个元素
    cout << "改变后的值" << endl;
    double &v4 = setValues(4);
    v4 = 100;
    for (int i = 0; i < 5; i++)
    {
        cout << "vals[" << i << "] = " << vals[i] << endl;
    }
    cout << "res:" << res << endl;

    return 0;
}

double &setValues(int i)
{
    double &ref = vals[i];
    return ref; // 返回第 i 个元素的引用，ref 是一个引用变量，ref 引用 vals[i]
}

// 函数定义
void swap(int &x, int &y)
{
    int temp;
    temp = x; /* 保存地址 x 的值 */
    x = y;    /* 把 y 赋值给 x */
    y = temp; /* 把 x 赋值给 y  */

    return;
}

// 当返回一个引用时，要注意被引用的对象不能超出作用域。所以返回一个对局部变量的引用是不合法的，但是，可以返回一个对静态变量的引用
int &func()
{
    int q;
    //! return q; // 在编译时发生错误
    static int x;
    return x; // 安全，x 在函数作用域外依然是有效的
}