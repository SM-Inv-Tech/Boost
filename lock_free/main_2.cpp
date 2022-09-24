////////////////////////////////////////////////////////////////////////
/// \file      main_2.cpp
/// \copyright Copyright (c) 2022 标准模型投资有限公司.
///            All rights reserved.
///            Licensed under the MIT License.
/// \author    金小海
/// \date      2022年09月24日, Sat, 10:18
/// \version   1.0
/// \brief
#include <iostream>

#include "boost/thread.hpp"
#include "boost/lockfree/spsc_queue.hpp"
#include "boost/chrono.hpp"
#include "boost/atomic.hpp"

int producer_count = 0;
boost::atomic_int consumer_count(0);

// boost::lockfree::spsc_queue<int, boost::lockfree::capacity<1024> > spsc_queue;
boost::lockfree::spsc_queue<int> spsc_queue(10);

const int iterations = 100;

void producer()
{
    for (int i = 0; i != iterations; ++i)
    {
        int value = ++producer_count;
        while (!spsc_queue.push(value))
        {

        }
    }
}

boost::atomic<bool> done(false);

void consumer()
{
    int value;
    while (!done)
    {
        while (spsc_queue.pop(value))
        {
            ++consumer_count;
            boost::this_thread::sleep_for(boost::chrono::microseconds(1));
        }
    }

    while (spsc_queue.pop(value))
    {
        ++consumer_count;
    }
}

int main(int argc, char *argv[])
{
    using namespace std;
    cout << "boost::lock_free::queue is ";
    if (!spsc_queue.is_lock_free())
    {
        cout << "not ";
    }
    cout << "lock_free" << endl;

    boost::thread producer_thread(producer);
    boost::thread consumer_thread(consumer);

    producer_thread.join();
    done = true;
    consumer_thread.join();

    cout << "produced " << producer_count << " objects." << endl;
    cout << "consumed " << consumer_count << " objects." << endl;
}