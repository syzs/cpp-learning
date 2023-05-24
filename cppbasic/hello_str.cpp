#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int memFree = 10;
    int f_size = 20;
    int mem_g_will_used = 0;
    int f_size_ori = 0;
    string path = "path";
    char *bForceLoad = std::getenv("SKIP_SPARSE_MEMORY_CHECK");

    if ((bForceLoad && strcmp(bForceLoad, "1") == 0) || memFree > (f_size + mem_g_will_used))
    {
        cout << "memFree = " << memFree << "kB under f_size" << f_size << "kB, begin to load hashtable " << path << " loading is " << mem_g_will_used
             << "kB. original total file size=" << f_size_ori << " kB" << endl;
    }
    else
    {
        cout << "not enough" << endl;
    }
}