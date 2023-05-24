#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Test
{
public:
    Test() { cout << "Test的构造函数..." << endl; }
    ~Test() { cout << "Test的析构函数..." << endl; }

    int getDebug() { return this->debug; }

private:
    int debug = 20;
};

class Person
{
public:
    Person(int v)
    {
        this->no = v;
        cout << "构造函数 \t no = " << this->no << endl;
    }

    ~Person()
    {
        cout << "析构函数 \t no = " << this->no << endl;
    }

private:
    int no;
};

// 仿函数，内存删除
class DestructPerson
{
public:
    void operator()(Person *pt)
    {
        cout << "DestructPerson..." << endl;
        delete pt;
    }
};

int main()
{
    unique_ptr<string> p1(new string("S1"));
    unique_ptr<string> p2(new string("S2"));

    cout << "p1:" << p1.get() << endl;
    cout << "p2:" << p2.get() << endl;

    // p1 = p2; // 禁止左值赋值
    // unique_ptr<string> p3(p2); // 禁止左值赋值构造
    unique_ptr<string> p3(std::move(p1));
    cout << "p1 被move后：" << p1.get() << endl;
    p1 = std::move(p2);
    cout << "p1 = p2 赋值后：" << endl;
    cout << "p1:" << p1.get() << endl;
    cout << "p2:" << p2.get() << endl;
    cout << "p3:" << p3.get() << endl;

    cout << "--------------" << endl;

    // vector<unique_ptr<string>> vec;
    // unique_ptr<string> p4(new string("I'm P4"));
    // unique_ptr<string> p5(new string("I'm P5"));
    // vec.push_back(std::move(p4));
    // vec.push_back(std::move(p5));

    // cout << "vec.at(0)：" << vec.at(0) << endl;

    cout << "shared_ptr --------------" << endl;
    shared_ptr<Person> sp1;

    shared_ptr<Person> sp2(new Person(2));

    // 获取智能指针管控的共享指针的数量	use_count()：引用计数
    cout << "sp1	use_count() = " << sp1.use_count() << endl;
    cout << "sp2	use_count() = " << sp2.use_count() << endl
         << endl;

    // 共享
    sp1 = sp2;

    cout << "sp1	use_count() = " << sp1.use_count() << endl;
    cout << "sp2	use_count() = " << sp2.use_count() << endl
         << endl;

    shared_ptr<Person> sp3(sp1);
    cout << "sp1	use_count() = " << sp1.use_count() << endl;
    cout << "sp2	use_count() = " << sp2.use_count() << endl;
    cout << "sp2	use_count() = " << sp3.use_count() << endl
         << endl;

    // 初始化，使用make_shared 初始化对象，分配内存效率更高(推荐使用)
    // make_shared函数的主要功能是在动态内存中分配一个对象并初始化它，返回指向此对象的shared_ptr; 用法：
    // 1 make_shared<类型>(构造类型对象需要的参数列表);
    shared_ptr<int> up3 = make_shared<int>(2);
    shared_ptr<string> up4 = make_shared<string>("字符串");
    shared_ptr<Person> up5 = make_shared<Person>(9);
    // 2 赋值
    shared_ptr<int> up1(new int(10)); // int(10) 的引用计数为1
    shared_ptr<int> up2(new int(11)); // int(11) 的引用计数为1
    up1 = up2;                        // int(10) 的引用计数减1,计数归零内存释放，up2共享int(11)给up1, int(11)的引用计数为2

    // 主动释放
    up1 = nullptr; // int(10) 的引用计数减1,计数归零内存释放

    // 重置
    // p.reset(); // 将p重置为空指针，所管理对象引用计数 减1

    // p.reset(p1); // 将p重置为p1（的值）, p 管控的对象计数减1，p接管对p1指针的管控

    //  p.reset(p1, d);  // 将p重置为p1（的值），p 管控的对象计数减1并使用d作为删除器

    //  p1是一个指针！

    // 交换
    // std::swap(p1, p2); // 交换p1 和p2 管理的对象，原对象的引用计数不变
    // p1.swap(p2);       // 交换p1 和p2 管理的对象，原对象的引用计数不变

    return 0;
}