#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex;

void thread1(int a) {
    mutex.lock();
    for (int i = 0; i < a; ++i) {
        std::cout << "Mutex 1" << std::endl;
    }

    for (int i = 0; i < a; ++i) {
        std::cout << "Hello 1" << std::endl;
    }
}

void thread2(int b) {
    mutex.lock();
    for (int i = 0; i < b; ++i) {
        std::cout << "Mutex 2" << std::endl;
    }
    mutex.unlock();

    for (int i = 0; i < b; ++i) {
        std::cout << "Hello 2" << std::endl;
    }
}

int main() {
  std::thread first (thread1, 30);
  std::thread second (thread2, 50);
  second.join();
  first.join();

  std::cout << "****** Main ********";


  std::cout << "*** Over ***";

  return 0;
}