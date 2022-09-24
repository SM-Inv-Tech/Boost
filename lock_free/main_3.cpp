////////////////////////////////////////////////////////////////////////
/// \file      main_3.cpp
/// \copyright Copyright (c) 2022 标准模型投资有限公司.
///            All rights reserved.
///            Licensed under the MIT License.
/// \author    金小海
/// \date      2022年09月24日, Sat, 10:25
/// \version   1.0
/// \brief
#include <iostream>

#include "boost/thread/thread.hpp"
#include "boost/lockfree/stack.hpp"
#include "boost/atomic.hpp"

boost::atomic_int producer_count(0);
boost::atomic_int consumer_count(0);

boost::lockfree::stack<int> stack(128);

const int iterations = 1000000;
const int producer_thread_count = 4;
const int consumer_thread_count = 4;

void producer()
{
    for (int i = 0; i != iterations; ++i)
    {
        int value = ++producer_count;
        while (!stack.push(value))
        {
            //
        }
    }
}

boost::atomic<bool> done(false);

void consumer()
{
    int value;
    while (!done)
    {
        while (stack.pop(value))
        {
            ++consumer_count;
        }
    }

    while (stack.pop(value))
    {
        ++consumer_count;
    }
}

int main(int argc, char *argv[])
{
    using namespace std;
    cout << "boost::lock_free::stack is ";
    if (!stack.is_lock_free())
    {
        cout << "not ";
    }
    cout << "lock_free" << endl;

    boost::thread_group producer_threads, consumer_threads;

    for (int i = 0; i != producer_thread_count; ++i)
    {
        producer_threads.create_thread(producer);
    }

    for (int i = 0; i != consumer_thread_count; ++i)
    {
        consumer_threads.create_thread(consumer);
    }

    producer_threads.join_all();
    done = true;

    consumer_threads.join_all();

    cout << "produced " << producer_count << " objects." << endl;
    cout << "consumed " << consumer_count << " objects." << endl;
}