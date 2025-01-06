#include <stdio.h>
#include <stdlib.h>

// Function to multiply two matrices
#ifdef COMPILER_INLINE
__attribute__((always_inline))
#else
__attribute__((noinline))
#endif
void matrixMultiply(int rowsA, int colsA, int colsB, 
                    long matA[rowsA][colsA], 
                    long matB[colsA][colsB], 
                    long result[rowsA][colsB]) {
    // Initialize the result matrix with zeros
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

#ifdef MANUAL_INLINE
int main(int argc, char** argv) {
	  long input = atol(argv[1]);
		long count = atol(argv[2]);
    // Example matrices
    long matA[2][3] = {
        {input, input, input},
        {input, input, input}
    };

    long matB[3][2] = {
        {input, input},
        {input, input},
        {input, input}
    };

    long result[2][2]; // Resultant matrix

		for (long i = 0; i < count; i++) {

			int rowsA = 2;
			int colsA = 3;
			int colsB = 2;
			// Perform matrix multiplication
			// Initialize the result matrix with zeros
			for (int i = 0; i < rowsA; i++) {
				for (int j = 0; j < colsB; j++) {
					result[i][j] = 0;
				}
			}

			// Perform matrix multiplication
			for (int i = 0; i < rowsA; i++) {
				for (int j = 0; j < colsB; j++) {
					for (int k = 0; k < colsA; k++) {
						result[i][j] += matA[i][k] * matB[k][j];
					}
				}
			}

		}

    // Print the result
    printf("Resultant Matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%ld ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#else
int main(int argc, char** argv) {
		long input = atol(argv[1]);
		long count = atol(argv[2]);
    // Example matrices
    long matA[2][3] = {
        {input, input, input},
        {input, input, input}
    };

    long matB[3][2] = {
        {input, input},
        {input, input},
        {input, input}
    };

    long result[2][2]; // Resultant matrix

		for (long i = 0; i < count; i++) {
			// Perform matrix multiplication
			matrixMultiply(2, 3, 2, matA, matB, result);
		}

    // Print the result
    printf("Resultant Matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%ld ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#endif
