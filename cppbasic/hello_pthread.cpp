#include <iostream>
// 必须的头文件
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

#define NUM_THREADS 5

// 线程的运行函数
void *say_hello(void *args)
{
    cout << "Hello Runoob！" << endl;
    return 0;
}

void *PrintHello(void *threadId)
{
    // 对传入的参数进行强制类型转换，由无类型指针变为整形指针，然后再读取
    int tid = *((int *)threadId);
    cout << "thread id: " << tid << endl;
    // pthread_exit(NULL);
    return 0;
}

void initThreadWithoutArgs()
{
    // 定义线程的 id 变量，多个变量使用数组
    pthread_t tids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        // 参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if (ret != 0)
        {
            cout << "pthread_create error: error_code=" << ret << endl;
        }
    }
    // 等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    pthread_exit(NULL);
}

void initThreadWithThreadId()
{
    pthread_t threads[NUM_THREADS];
    int indexes[NUM_THREADS]; // 用数组来保存i的值
    int rc;
    for (int i = 0; i < NUM_THREADS; i++)
    {
        cout << "main create thread:" << i << endl;
        indexes[i] = i;
        // 传入的时候必须强制转换为void* 类型，即无类型指针
        rc = pthread_create(&threads[i], NULL,
                            PrintHello, (void *)&(indexes[i]));
        if (rc)
        {
            cout << "Error:无法创建线程," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

struct thread_data
{
    int thread_id;
    char *message;
};

void *PrintThreadArgs(void *threadArgs)
{
    struct thread_data *my_data;
    my_data = (struct thread_data *)threadArgs;

    cout << "id:" << my_data->thread_id << ",message:" << my_data->message << endl;
    return 0;
}

void initThreadWithThreadArgs()
{
    pthread_t threads[NUM_THREADS];
    struct thread_data td[NUM_THREADS];
    int rc;
    int i;

    for (i = 0; i < NUM_THREADS; i++)
    {
        cout << "main() : creating thread, " << i << endl;
        td[i].thread_id = i;
        td[i].message = (char *)"This is message";
        rc = pthread_create(&threads[i], NULL,
                            PrintThreadArgs, (void *)&td[i]);
        if (rc)
        {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

void *wait(void *t)
{
    // int tid = *((int *)threadId);

    int tid = *((int *)t);

    sleep(1);
    cout << tid << endl;
    return 0;
}

void initThreadJoin()
{
    int rc;
    int i;
    pthread_t threads[NUM_THREADS];
    // pthread_attr_t attr;
    void *status;
    int indexes[NUM_THREADS];

    // 初始化并设置线程为可连接的（joinable）
    // 只有创建时定义为可连接的线程才可以被连接。如果线程创建时被定义为可分离的，则它永远也不能被连接。
    // pthread_attr_init(&attr);
    // pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < NUM_THREADS; i++)
    {
        indexes[i] = i;
        cout << "main() : creating thread, " << i << endl;
        rc = pthread_create(&threads[i], NULL, wait, (void *)&(indexes[i]));
        if (rc)
        {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }

    // 删除属性，并等待其他线程
    // pthread_attr_destroy(&attr);
    for (i = 0; i < NUM_THREADS; i++)
    {
        // pthread_join() 子程序阻碍调用程序，直到指定的 threadid 线程终止为止

        rc = pthread_join(threads[i], &status);
        if (rc)
        {
            cout << "Error:unable to join," << rc << endl;
            exit(-1);
        }
        cout << "Main: completed thread id :" << i << "  exiting with status :" << status << endl;
    }

    cout << "Main: program exiting." << endl;
    pthread_exit(NULL);
}

int main()
{
    // initThreadWithoutArgs();
    // initThreadWithThreadId();
    // initThreadWithThreadArgs();
    initThreadJoin();
}