#include "classes.h"

int main() {
    Builder* siciliana = new Builder();
    siciliana->createSiciliana();
    delete siciliana;
    return 0;
}