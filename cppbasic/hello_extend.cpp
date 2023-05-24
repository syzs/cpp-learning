#include <iostream>

using namespace std;

// 基类
class Shape
{
public:
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }

protected:
    int width;
    int height;
};

class PaintCost
{
public:
    int getCost(int area)
    {
        return area * 70;
    }
};

/**
 * @brief 一个派生类继承了所有的基类方法，但下列情况除外：
基类的构造函数、析构函数和拷贝构造函数。
基类的重载运算符。
基类的友元函数。
 */
class Rectangle : public Shape, public PaintCost
{
public:
    int getArea()
    {
        return (width * height);
    }
};

void initShape()
{
    Rectangle Rect;

    Rect.setWidth(5);
    Rect.setHeight(7);

    int area = Rect.getArea();
    // 输出对象的面积
    cout << "Total area: " << area << endl;

    // 输出总花费
    cout << "Total paint cost: $" << Rect.getCost(area) << endl;
}

int main()
{
    // initShape();

    return 0;
};