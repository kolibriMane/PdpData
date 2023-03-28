#include "func.h"

int main() {
    /* Box volume */
    std::cout << "Enter box volume: ";
    int volume = getInteger();

    /* How many things in shop */
    std::cout << "Enter count of things: ";
    int count = getInteger();

    /* Array for volume and cost of things */
    int* vol = new int[count];
    int* cost = new int[count];

    /* Get shop things volumes and costs */
    for (int i = 0; i < count; ++i) {
        std::cout << "Volume of " << i + 1 << ": ";
        vol[i] = getInteger();
        std::cout << "Cost of " << i + 1 << ": ";
        cost[i] = getInteger();
    }

    /* Show things and costs pretty */
    showThings(vol, cost, count);

    double* priority = new double[count];
    getPriority(vol, cost, priority, count);
    getOptimalWay(vol, cost, count, volume);

    return 0;
}