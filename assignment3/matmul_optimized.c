/* Optimized implementation of matrix multiplication 
 * This routine performs a matrix multiplication operation
 * C := C + A * B
 * where A, B, and C are n-by-n matrices stored in column-major format.
 * On exit, A and B maintain their input values. 
 * DO NOT change the API of the function matmul_optimized()	
*/    
void matmul_optimized(int n, int* A, int* B, int* C)
{
	int i, j, k;
	int cij;

	// Transpose A into A_t
	int *A_t = malloc(n*n*sizeof(int));
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			A_t[i*n+j] = A[i+j*n];
 

	// Matrix multiplication with:
	// A_t in row-major order
	// B, C in column-major order
	for(i=0; i<n; ++i)
	{	
		for(j=0; j<n; ++j)
   		{
			cij = C[i+j*n];
			for(k=0; k<n; ++k)
            	cij+=A_t[i*n+k]*B[k+j*n];
      		C[i+j*n] = mod2(cij);
         }
 	}
	free(A_t);
}
