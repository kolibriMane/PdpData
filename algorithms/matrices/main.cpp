#include "matrix.h"

int main() {
    /* Create and initialize first matrix */
    std::cout << "*** First matrix ***" << std::endl;
    int n = getSize();
    int** matrix1 = createMatrix(n);
    initMatrix(matrix1, n);

    /* Create and initialize second matrix */
    std::cout << "*** Second matrix ***" << std::endl;
    int** matrix2 = createMatrix(n);
    initMatrix(matrix2, n);

    /* Show matrices pretty */
    std::cout << "*** First matrix is ***" << std::endl;
    showMatrix(matrix1, n);
    std::cout << "*** Second matrix is ***" << std::endl;
    showMatrix(matrix2, n);

    /* Multiply 2 matrices */
    int** mulMatrices = createMatrix(n);
    mulMatrices = getMul(matrix1, matrix2, mulMatrices, n);

    /* Check is successfully calculated */
    if (NULL == mulMatrices) {
        std::cout << "Warning: Sizes are inappropriate to Multiply!" << std::endl;
    } else {
        std::cout << "*** Matrix 1 * Matrix 2 ***" << std::endl;
        showMatrix(mulMatrices, n);
        deleteMatrix(mulMatrices, n);
    }

    /* Delete 2 matrices */
    deleteMatrix(matrix1, n);
    deleteMatrix(matrix2, n);

    return 0;
}