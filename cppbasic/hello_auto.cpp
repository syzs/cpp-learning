#include <iostream>
#include <unordered_map>

using namespace std;

void f1();
void f2();

int main()
{
    f1();
    return 0;
}

void f1()
{
    std::unordered_map<int, int> reNameMap;
}

void f2(const std::unordered_map<int, int> &reNameMap)
{
    std::cout << "==>" << reNameMap.count(1) << std::endl;
}