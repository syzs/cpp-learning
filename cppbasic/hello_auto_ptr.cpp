#include <iostream>

using namespace std;

class Test
{
public:
    Test() { cout << "Test的构造函数..." << endl; }
    Test(string args_name)
    {
        cout << args_name << " Test的构造函数..." << endl;
        name = args_name;
    }
    ~Test() { cout << name << " Test的析构函数..." << endl; }

    int getDebug() { return this->debug; }

private:
    int debug = 20;
    string name;
};

int main(void)
{
    // Test *test = new Test(); // Test的构造函数...
    // delete test;             // Test析构函数...

    // 定义智能指针
    auto_ptr<Test> test(new Test());
    cout << "test->debug：" << test->getDebug() << endl;     // -> 返回指针对象。test->debug：20
    cout << "(*test).debug：" << (*test).getDebug() << endl; // -> 但会普通对象。(*test).debug：20

    Test *tmp = test.get(); // get() 返回智能指针托管的指针地址
    cout << "tmp->debug:" << tmp->getDebug() << endl;

    Test *tmp2 = test.release(); // 取消智能指针会动态内存的托管，不会再打印析构喊出

    delete tmp2; // 之前分配的内存需要手动删除

    cout << "already release" << endl;

    // reset函数会将参数的指针(不指定则为NULL)，与托管的指针比较，如果地址不一致，那么就会析构掉原来托管的指针，然后使用参数的指针替代之。然后智能指针就会托管参数的那个指针了。
    auto_ptr<Test> test_reset(new Test("reset_0"));
    test_reset.reset();                    // 释放掉只能指针托管的 指针内存，并将其置NULL
    test_reset.reset(new Test("reset_1")); // 释放掉只能指针托管的指针内存，并将参数指针取代之

    return 0;
}