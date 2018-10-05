#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;
using namespace std::chrono;

mutex mut;

void task_1(condition_variable &condition)
{
    // Task one will initially sleep for a few seconds
    cout << "Task 1 sleeping for 3 seconds \n";
    this_thread::sleep_for(seconds(3));
    // Create lock - thread 2 should manged to grab it first
    auto lock = unique_lock<mutex>(mut);
    // Notify waiting thread
    cout << "Task 1 notifying waiting thread \n";
    condition.notify_one();
    // Now wait for notification
    cout << "Task 1 waiting for notification \n";
    // Wait, freeing lock as we do.
    condition.wait(lock);
    // We are free to continue
    cout << "Task 1 notified \n";
    // Sleep for 3 seconds
    cout << "Task 1 sleeping for 3 seconds \n";
    this_thread::sleep_for(seconds(3));
    // Notify any waiting thread
    cout << "Task 1 notifying waiting thread \n";
    condition.notify_one();
    // Now wait 3 seconds for notification
    cout << "Task 1 waiting 3 seconds for notification \n";
    if (condition.wait_for(lock, seconds(3)) == cv_status::no_timeout)
        cout << "Task 1 notified before 3 seconds \n";
    else
        cout << "Task 1 got tired waiting \n";
    // Print finished message
    cout << "Task 1 finished \n";
}

void task_2(condition_variable &condition)
{
    // Create lock
    auto lock = unique_lock<mutex>(mut);
    // Task two will initially wait for notification
    cout << "Task 2 waiting for notification \n";
    // Wait, releasing the lock as we do.
    condition.wait(lock);
    // We are free to continue
    cout << "Task 2 notified \n";
    // Sleep for 5 seconds
    cout << "Task 2 sleeping for 5 seconds \n";
    this_thread::sleep_for(seconds(5));
    // Notify waiting thread
    cout << "Task 2 notifying waiting thread \n";
    condition.notify_one();
    // Now wait 5 seconds for notification
    cout << "Task 2 waiting 5 seconds for notification \n";
    if (condition.wait_for(lock, seconds(5)) == cv_status::no_timeout)
        cout << "Task 2 notified before 5 seconds \n";
    else
        cout << "Task 2 got tired waiting \n";
    // Sleep for 5 seconds
    cout << "Task 2 sleeping for 5 seconds \n";
    this_thread::sleep_for(seconds(5));
    // Notify any waiting thread
    cout << "Task 2 notifying waiting thread \n";
    condition.notify_one();
    // Print finished message
    cout << "Task 2 finished \n";
}

int main(int argc, char **argv)
{
    // Create condition variable
    condition_variable condition;

    // Create two threads
    thread t1(task_1, ref(condition));
    thread t2(task_2, ref(condition));

    // Join two threads
    t1.join();
    t2.join();

    return 0;
}
