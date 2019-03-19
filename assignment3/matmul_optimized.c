/* This file performs a matmul operation
 * C := C + A * B
 * where A, B, and C are n-by-n matrices stored in column-major format.
 * On exit, A and B maintain their input values. 
 */

// This function computes the parity of a given 64-bit number
inline int parity(long long v) {
	v ^= v >> 1;
	v ^= v >> 2;
	v = (v & 0x1111111111111111UL) * 0x1111111111111111UL;
	return (v >> 60) & 1;
}

/* Optimized implementation of matrix multiplication 
 * This routine performs a matrix multiplication operation
 * C := C + A * B
 * where A, B, and C are n-by-n matrices stored in column-major format.
 * On exit, A and B maintain their input values. 
 * DO NOT change the API of the function matmul_optimized()	
 */
void matmul_optimized(int n, int * A, int * B, int * C) {
	// Register frequently used variables for quicker access
	register int i, j, k, cij;
	register long long a_temp = 0, b_temp = 0;

	// Transpose A into A_t
	int * A_t = malloc(n * n * sizeof(int));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			A_t[i * n + j] = A[i + j * n];

	// Calculate the sizes needed for the compressed matrices
	const int comp_width = n / 64,
			  size = n * comp_width * sizeof(long long);
	long long * A_c = malloc(size),
			  * B_c = malloc(size);

	// Compress A and B into A_c and B_c respectively
	int offset, comp_offset;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < comp_width; ++j) {
			// Calculate offsets
			offset = i * n + j * 64;
			comp_offset = i * comp_width + j;
			// Compress 64 integers into a long long
			for (k = 0; k < 64; ++k) {
				a_temp = (a_temp << 1) | A_t[offset + k];
				b_temp = (b_temp << 1) | B[offset + k];
			}
			// Store in the compressed A matrices
			A_c[comp_offset] = a_temp;
			B_c[comp_offset] = b_temp;
		}
	}

	// Matrix multiplication with:
	// A_t in row-major order
	// B, C in column-major order
	int index;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			index = i + j * n;
			cij = C[index];
			long long cij_temp = 0;
			for (k = 0; k < comp_width; ++k) {
				// 64 bits
				a_temp = A_c[i * comp_width + k];
				b_temp = B_c[j * comp_width + k];
				// Bitwise and for multiplication of bits
				a_temp = a_temp & b_temp;
				// Bitwise xor for addition of bits
				cij_temp ^= a_temp;
			}
			// Add the result to the previous value
			C[index] = cij ^ parity(cij_temp);
		}
	}

	// Free the transposed matrix, then the compressed matrices
	free(A_t);
	free(A_c);
	free(B_c);
}