#include <iostream>

int main() {
    int n = 0;
    std::cout << "Enter array size: ";
    std::cin >> n;
    int * array = new int(n);

    // Init array
    for (int i = 0; i < n; ++i) {
        std::cout << "[" << i + 1 << "]: ";
        std::cin >> array[i];
    }

    int sum = 0;
    int prod = 1;
    for (int i = 0, k = n - 1; i < n; ++i, --k) {
        sum += array[k];
        prod *= array[k];
    }

    std::cout << "Sum  : " << sum << std::endl;
    std::cout << "Prod : " << prod << std::endl;
}