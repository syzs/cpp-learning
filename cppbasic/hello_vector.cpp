#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    cout << "v1_size: " << v1.size() << "\t vl_capacity: " << v1.capacity() << endl;
    cout << "v2_size: " << v2.size() << "\t v2_capacity: " << v2.capacity() << endl;
    cout << "v3_size: " << v3.size() << "\t v3_capacity: " << v3.capacity() << endl;
    cout << "v4_size: " << v4.size() << "\t v4_capacity: " << v4.capacity() << endl
         << endl;

    v2.push_back(99);
    cout << "v2_size: " << v2.size() << "\t v2_capacity: " << v2.capacity() << endl;

    int nums = 20;
    for (int i = 0; i < nums; ++i)
    {
        v2.push_back(i + 1);
        cout << "v2_size: " << v2.size() << "\t v2_capacity: " << v2.capacity() << endl;
    }

    cout << endl;

    v1.resize(100);
    v2.resize(100);
    v2.push_back(99); // 添加一个元素

    v3.reserve(100);
    v4.reserve(100);

    cout << "v1_size: " << v1.size() << "\t vl_capacity: " << v1.capacity() << endl;
    cout << "v2_size: " << v2.size() << "\t v2_capacity: " << v2.capacity() << endl;
    cout << "v3_size: " << v3.size() << "\t v3_capacity: " << v3.capacity() << endl;
    cout << "v4_size: " << v4.size() << "\t v4_capacity: " << v4.capacity() << endl
         << endl;

    v1.resize(200);
    v2.reserve(200);
    v3.reserve(200);
    v4.resize(200);

    cout << "v1_size: " << v1.size() << "\t vl_capacity: " << v1.capacity() << endl;
    cout << "v2_size: " << v2.size() << "\t v2_capacity: " << v2.capacity() << endl;
    cout << "v3_size: " << v3.size() << "\t v3_capacity: " << v3.capacity() << endl;
    cout << "v4_size: " << v4.size() << "\t v4_capacity: " << v4.capacity() << endl
         << endl;

    v3.push_back(8);
    v4.push_back(8);

    cout << "v1_size: " << v1.size() << "\t vl_capacity: " << v1.capacity() << endl;
    cout << "v2_size: " << v2.size() << "\t v2_capacity: " << v2.capacity() << endl;
    cout << "v3_size: " << v3.size() << "\t v3_capacity: " << v3.capacity() << endl;
    cout << "v4_size: " << v4.size() << "\t v4_capacity: " << v4.capacity() << endl
         << endl;

    typedef std::unique_ptr<string> Ptr;
    std::vector<Ptr> v5;
    v5.push_back(Ptr(new string("sq")));

    // unique_ptr<string> p1(new string("S1"));
    // unique_ptr<string> p2(new string("S2"));

    // vector<unique_ptr<T>> v5;

    // v5.push_back(p1);
    // v5.push_back(p2);

    cout << "v5_size: " << v5.size() << "\t vl_capacity: " << v5.capacity() << endl;

    return 0;
}