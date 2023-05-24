#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    // 基于当前系统的当前日期/时间
    time_t now = time(0);

    char *dt = ctime(&now);
    cout << "本地日期、时间：" << now << "," << dt << endl;

    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC 日期和时间：" << dt << endl;

    tm *ltm = localtime(&now);
    cout << "年：" << 1900 + ltm->tm_year << endl;
    cout << "月：" << 1 + ltm->tm_mon << endl;
    cout << "日：" << ltm->tm_mday << endl;
    cout << "时：" << ltm->tm_hour << endl;
    cout << "分：" << ltm->tm_min << endl;
    cout << "秒：" << ltm->tm_sec << endl;
    return 0;
}