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
	float t = 0;

    float median1 = sort_and_find_median(measurements1, size1);
    int new_size1;
    float *measurements1_wo_outliers = discard_outliers(measurements1, size1, median1, &new_size1);

    float median2 = sort_and_find_median(measurements2, size2);
    int new_size2;
    float *measurements2_wo_outliers = discard_outliers(measurements2, size2, median2, &new_size2);

    float mean1, variance1;
    mean_variance(measurements1_wo_outliers, new_size1, &mean1, &variance1);

    float mean2, variance2;
    mean_variance(measurements2_wo_outliers, new_size2, &mean2, &variance2);

    // Since variance is standard deviation ^ 2, we can use variance instead
    float standard_deviation_dif = sqrt((variance1 / new_size1) + (variance2 / new_size2));

    t = (mean1 - mean2) / standard_deviation_dif;

    free(measurements1_wo_outliers);
    free(measurements2_wo_outliers);

	return t;
}
