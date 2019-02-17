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

// Since this function is used after the elements are sorted, we assume that it will
// only be used on sorted elements, which helps with efficiency
float *discard_outliers(float *measurements, int size, float median, int *new_size)
{
    // Define the new range of the list (all by default)
    int new_start = 0, new_end = size;

    float median_min = median * 0.5f, median_max = median * 1.5f;

    // Since the data is sorted, loop over to find the new start and end indexes
    int i;
    for (i = 0; i < size; i++) {
        float measurement = measurements[i];
        if (measurement < median_min) {
            // Start the new array from the next element, will stop updating once the
            // threshold is met
            new_start = i + 1;
        } else if (measurement > median_max) {
            // Stop looping when one outside the threshold is met, this is the new end
            new_end = i;
            break;
        }
    }
    
    // Calculate the number of elements based on the start and end
    *new_size = new_end - new_start;

    float *measurements_wo_outliers = malloc((*new_size) * sizeof(float));

    int temp_pointer = 0;
    // Populate array, incrementing pointer in-line
    for (i = new_start; i < new_end; i++)
        measurements_wo_outliers[temp_pointer++] = measurements[i];

    return measurements_wo_outliers;
}
