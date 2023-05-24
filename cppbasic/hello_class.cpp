#include <iostream>
using namespace std;

// 函数声明
void initBox();

class Box
{
public:
    double length;
    double breadth;
    double height;

    // 构造函数
    Box();
    Box(double l);
    Box(double len, double hei, double bre);

    // 析构函数，不返回任何值，不接受任何入参
    ~Box();

    // 类成员函数声明
    double getArea();
    void set(double length, double breadth, double height);

    // 成员函数定义：成员函数可以定义在类定义内部
    // 可以访问对象中的所有成员
    double getVolumn()
    {
        return length * breadth * height;
    }

    void setColor(string col)
    {
        color = col;
    }
    string getColor()
    {
        return color;
    }

    // 友元函数：定义在类外部，但是有权访问类的私有和保护成员
    friend void printColor(Box box);

private:
    string color;
};

Box::Box()
{
    cout << "init box" << endl;
}
Box::Box(double l)
{
    cout << "init box with length" << endl;
    length = l;
}

// 使用初始化列表来初始化字段
Box::Box(double len, double hei, double bre) : length(len), height(hei), breadth(bre)
{
}
// ====== 等同于
// Box::Box(double len, double hei, double bre)
// {
//     length = len;
//     height = hei;
//     breadth = bre;
// }

Box::~Box()
{
    cout << "object is being deleted" << endl;
}

void printColor(Box box)
{
    cout << "color of box3:" << box.color << endl;
}

// 成员函数定义：在类的外部使用
// 范围解析运算符:: 来定义
double Box::getArea()
{
    return length * breadth * height;
}

void Box::set(double len, double bre, double hei)
{
    length = len;
    breadth = bre;
    height = hei;
}

class Line
{
public:
    int getLength(void);
    Line(int len);         // 简单的构造函数
    Line(const Line &obj); // 拷贝构造函数
    ~Line();               // 析构函数
    void setLine(int len)
    {
        cout << "setline" << len << endl;
        *ptr = len;
    }

private:
    int *ptr;
};

// 成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "调用构造函数" << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj)
{
    cout << "调用拷贝构造函数并为指针 ptr 分配内存 " << *obj.ptr << endl;
    ptr = new int;
    *ptr = *obj.ptr; // 拷贝值
}

Line::~Line(void)
{
    cout << "释放内存" << endl;
    delete ptr;
}
int Line::getLength(void)
{
    return *ptr;
}

void display(Line obj)
{
    cout << "line 大小 : " << obj.getLength() << endl;
}

/**
 * @brief
调用构造函数
调用拷贝构造函数并为指针 ptr 分配内存 10
setline20
调用拷贝构造函数并为指针 ptr 分配内存 10
line 大小 : 10
释放内存
调用拷贝构造函数并为指针 ptr 分配内存 20
line 大小 : 20
释放内存
释放内存
释放内存
 *
 */
void initLine()
{
    Line line1(10);

    Line line2 = line1; // 这里也调用了拷贝构造函数
    line2.setLine(20);

    display(line1);
    display(line2);
}

void initBox()
{
    Box box1;
    box1.length = 1.0,
    box1.breadth = 2.0;
    box1.height = 3.0;
    cout << "area of box1:" << box1.length * box1.breadth * box1.height << endl;

    Box box2;
    box2.set(4.0, 5.0, 6.0);
    cout << "area of box2:" << box2.getArea() << endl;
    cout << "volumn of box2:" << box2.getVolumn() << endl;

    Box box3;
    box3.setColor("green");
    printColor(box3);

    Box box4(4);
    cout << "length of box4:" << box4.length << endl;
}

/**
 * @brief
 * 静态成员在类的所有对象中是共享的。
 * 如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为零。
 * 我们不能把静态成员的初始化放置在类的定义中，但是可以在类的外部通过使用范围解析运算符 :: 来重新声明静态变量从而对它进行初始化
 *
 */
class StaticBox
{
public:
    static int objectCount;
    StaticBox(double l = 2.0, double b = 2.0, double h = 2.0)
    {
        cout << "constructor called " << l << endl;
        length = l;
        breadth = b;
        height = h;
        objectCount++;
    }
    // 静态成员函数没有 this 指针，只能访问静态成员（包括静态成员变量和静态成员函数）
    // 普通成员函数有 this 指针，可以访问类中的任意成员；而静态成员函数没有 this 指针。
    static int getCount()
    {
        // auto &tmp = height + breadth; // invalud use of member 'height' in static member function
        return objectCount;
    }

private:
    double length;  // 长度
    double breadth; // 宽度
    double height;  // 高度
};

// 初始化类 StaticBox 的静态成员
int StaticBox::objectCount = 0;

void initStatic()
{
    // 如果把函数成员声明为静态的，就可以把函数与类的任何特定对象独立开来。静态成员函数即使在类对象不存在的情况下也能被调用，静态函数只要使用类名加范围解析运算符 :: 就可以访问。
    cout << "Total objects: " << StaticBox::getCount() << endl;
    StaticBox Box1(3.3, 1.2, 1.5); // 声明 box1
    // Box1.objectCount = 1;
    StaticBox Box2(8.5, 6.0, 2.0); // 声明 box2

    // 输出对象的总数
    cout << "Total objects: " << StaticBox::objectCount << endl;
}

int main()
{
    // initBox();
    // initLine();
    initStatic();
}
