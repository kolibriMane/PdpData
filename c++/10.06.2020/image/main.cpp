#include <string>
#include <fstream>
#include <iostream>

int main() {
    /* Open image fila as binary */
    std::ifstream inFile("nkar.jpg", std::ios::in | std::ios::binary);

    /* New .jpg file, open it binary */
    std::ofstream outFile;
    outFile.open("new.jpg", std::ios::out | std::ios::binary);

    /* Buffer, where we read binary file line */
    char buffer[1024];

    /* Read charecter count */
    int length = inFile.readsome(buffer, 1024);

    /* Read from file, while read charecters great then 0 */
    while (0 < length) {
        outFile.write(buffer, length);
        length = inFile.readsome(buffer, 1024);
    }

    return 0;
}