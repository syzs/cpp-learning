#include <iostream>
#include <vector>
#include <execinfo.h>
#include <gtest/gtest.h>
#include "butil/time.h"
#include "butil/macros.h"
#include "butil/logging.h"
#include "butil/logging.h"
#include "butil/gperftools_profiler.h"
#include "bthread/bthread.h"
#include "bthread/unstable.h"
#include "bthread/task_meta.h"

using namespace std;

static long sleep_in_adding_func = 0;

void main()
{
    for (size_t z = 0; z < 2; ++z)
    {
        sleep_in_adding_func = (z ? 1 : 0);
        char prof_name[32];
        if (sleep_in_adding_func)
        {
            snprintf(prof_name, sizeof(prof_name), "smallthread.prof");
        }
        else
        {
            snprintf(prof_name, sizeof(prof_name), "smallthread_nosleep.prof");
        }

        butil::atomic<size_t> s(0);
        size_t N = (sleep_in_adding_func ? 40000 : 100000);
        std::vector<bthread_t> th;
        th.reserve(N);
        butil::Timer tm;
        for (size_t j = 0; j < 3; ++j)
        {
            th.clear();
            if (j == 1)
            {
                ProfilerStart(prof_name);
            }
            tm.start();
            for (size_t i = 0; i < N; ++i)
            {
                bthread_t t1;
                ASSERT_EQ(0, bthread_start_urgent(
                                 &t1, &BTHREAD_ATTR_SMALL, adding_func, &s));
                th.push_back(t1);
            }
            tm.stop();
            if (j == 1)
            {
                ProfilerStop();
            }
            for (size_t i = 0; i < N; ++i)
            {
                bthread_join(th[i], NULL);
            }
            LOG(INFO) << "[Round " << j + 1 << "] bthread_start_urgent takes "
                      << tm.n_elapsed() / N << "ns, sum=" << s;
            ASSERT_EQ(N * (j + 1), (size_t)s);

            // Check uniqueness of th
            std::sort(th.begin(), th.end());
            ASSERT_EQ(th.end(), std::unique(th.begin(), th.end()));
        }
    }
}