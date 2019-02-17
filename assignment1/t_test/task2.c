#include "task1.c"

// Function for computing mean and variance
// The mean is stored in *mean and the variance is stored in *variance 
void mean_variance(float *measurements, int size, float *mean, float *variance)
{
	int i;
	float sum=0;

    //  Compute  mean	
    for (i = 0; i < size; i++)
    {
        sum = sum + measurements[i];
    }
    *mean = sum /size;

    //  Compute  variance
	sum = 0;	
    for (i = 0; i < size; i++)
    {
        sum = sum + (measurements[i]-*mean)*(measurements[i]-*mean);
    }
    *variance = sum /(size-1);
}

// Function for computing the t-static
// For computing square-root of a float data 'a' use b = sqrt(a) where type of b is also float.
float t_test(float *measurements1, int size1, float *measurements2, int size2)
{
	float t=0;

	// write the body of the function
	return t;
}

