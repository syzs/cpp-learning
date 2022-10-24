#include <iostream>
using namespace std;

const int MAX = 3;
void getSeconds(unsigned long *v);
double getAvg(int *arr, int size);

int main()
{
    int *ptr = NULL;
    if (!ptr)
    {
        cout << "ptr is null" << endl;
    }
    else
    {
        cout << "ptr:" << *ptr << endl;
    }

    int var[MAX] = {10, 100, 1000};
    // 指针中的数组地址
    ptr = var; // == ptr = &var[0]; 指针中第一个元素的地址
    if (!ptr)
    {
        cout << "ptr is null" << endl;
    }
    else
    {
        cout << "ptr:" << *ptr << endl;
    }

    cout << "----" << endl;

    for (int i = 0; i < MAX; i++)
    {
        cout << "address of var[" << i << "] = " << ptr << endl;
        cout << "value of var[" << i << "] = " << *ptr << endl;
        // 移到下一个位置
        ptr++;
    }

    ptr = &var[MAX - 1];
    for (int i = MAX; i > 0; i--)
    {
        cout << "address of var[" << i << "] = " << ptr << endl;
        cout << "value of var[" << i << "] = " << *ptr << endl;
        // 移到下一个位置
        ptr--;
    }

    cout << "----" << endl;

    // 整数指针 的数组
    int *pptr[MAX];
    for (int i = 0; i < MAX; i++)
    {
        pptr[i] = &var[i];
    }
    for (int i = 0; i < MAX; i++)
    {
        cout << pptr[i] << "," << *pptr[i] << endl;
    }

    cout << "---- " << endl;
    char a = 'a';
    char b = 'b';
    char c = 'c';

    char *chars[MAX] = {
        &b, &b, &b};
    for (int i = 0; i < MAX; i++)
    {
        cout << "Value of names[" << i << "] = ";
        cout << chars[i] << endl;
    }
    char *pchar = "=====adas===";
    cout << "*char" << pchar << endl;

    cout << "----" << endl;
    // 指向 字符指针 的数组 来存储字符串列表
    const char *names[MAX] = {
        "Zara Ali",
        "Hina Ali",
        "Nuha Ali",
    };

    for (int i = 0; i < MAX; i++)
    {
        cout << "Value of names[" << i << "] = ";
        cout << names[i] << endl;
    }

    cout << "---- 指向指针的指针" << endl;
    int vv;
    int *vvptr;
    int **pvvptr;
    vv = 3000;
    vvptr = &vv;
    pvvptr = &vvptr;
    cout << "vv 值为 :" << vv << endl;            // vv 值为 :3000
    cout << "*vvptr 值为:" << *vvptr << endl;     //*vvptr 值为:3000
    cout << "*pvvptr 值为:" << *pvvptr << endl;   //*pvvptr 值为:0x7ffee5f257d8
    cout << "**pvvptr 值为:" << **pvvptr << endl; // **pvvptr 值为:3000

    cout << "---- 指向作为函数的入参" << endl;
    unsigned long sec;
    getSeconds(&sec);
    cout << "Number of seconds :" << sec << endl; // Number of seconds :1666581653

    // 带有 5 个元素的整型数组
    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;

    // 传递一个指向数组的指针作为参数
    avg = getAvg(balance, 5);

    // 输出返回值
    cout << "Average value is: " << avg << endl;

    cout << "---- 函数返回指针" << endl;
}

void getSeconds(unsigned long *v)
{
    *v = time(NULL);
    return;
}

double getAvg(int *arr, int size)
{
    int i, sum = 0;
    double avg;

    for (i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    avg = double(sum) / size;

    return avg;
}