#include <iostream>
using namespace std;

class Shape
{
protected:
    int width, height;

public:
    Shape(int a = 0, int b = 0)
    {
        width = a;
        height = b;
    }
    // 1. 虚函数 是在基类中使用关键字 virtual 声明的函数。在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。
    virtual int area()
    {
        cout << "Parent class area :" << endl;
        return 0;
    }

    // 2.您可能想要在基类中定义虚函数，以便在派生类中重新定义该函数更好地适用于对象，但是您在基类中又不能对虚函数给出有意义的实现，这个时候就会用到纯虚函数。
    // pure virtual function
    virtual int areaVirtual() = 0;
};
class Rectangle : public Shape
{
public:
    Rectangle(int a = 0, int b = 0) : Shape(a, b) {}
    int area()
    {
        cout << "Rectangle class area :" << endl;
        return (width * height);
    }
    int areaVirtual()
    {
        cout << "Rectangle class areaVirtual :" << endl;
        return (width * height);
    }
};
class Triangle : public Shape
{
public:
    Triangle(int a = 0, int b = 0) : Shape(a, b) {}
    int area()
    {
        cout << "Triangle class area :" << endl;
        return (width * height / 2);
    }
    int areaVirtual()
    {
        cout << "Triangle class areaVirtual :" << endl;
        return (width * height);
    }
};

void initShape()
{
    Shape *shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);

    // 存储矩形的地址
    shape = &rec;
    // 调用矩形的求面积函数 area
    shape->area();

    shape->areaVirtual();

    // 存储三角形的地址
    shape = &tri;
    // 调用三角形的求面积函数 area
    shape->area();
    shape->areaVirtual();
}
// 程序的主函数
int main()
{
    initShape();

    int m = 2;
    int n = 2;
    int **array;
    // 假定数组第一维长度为 m， 第二维长度为 n
    // 动态分配空间
    array = new int *[m];
    for (int i = 0; i < m; i++)
    {
        array[i] = new int[n];
    }
    // 释放
    for (int i = 0; i < m; i++)
    {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}