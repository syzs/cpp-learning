#include<iostream>

using namespace std;

int main()
{
    char choice = 'A';
    switch (choice)
    {
    case 'A':
    case 'B':
        cout << "A or B";
        break;
    case 'C':
        cout << "C";
        break;
    default:
        cout << "UNKNOWN";
    }
    return 0;
}
