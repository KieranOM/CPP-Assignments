// function to sort the array in ascending order
float sort_and_find_median(float *measurements , int size)
{ 

    int i=0 , j=0;
    float temp=0;

    for(i=0 ; i<size ; i++)
    {
        for(j=0 ; j<size-1 ; j++)
        {
            if(measurements[j]>measurements[j+1])
            {
                temp        = measurements[j];
                measurements[j]    = measurements[j+1];
                measurements[j+1]  = temp;
            }
        }
    }
	
	return measurements[size/2];
}

float *discard_outliers(float *measurements, int size, float median, int *new_size)
{
	// write the body of the function

}

