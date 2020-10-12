unsigned int num_singulares(int a[], unsigned int n)
{
    int result = 0;
    int suma = 0;
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (j == i)
        {
            if (a[i] == suma)
            {
                result++;
            }
            suma = 0;
            j = 0;
            i++;
        }
        else
        {
            suma += a[j];
            j++;
        }
    }
    return result;
}
