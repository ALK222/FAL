unsigned int num_singulares(int a[], unsigned int n)
{
    int result = 0;
    int suma = 0;
    int i = 0;
    while (i < n)
    {
        while (i < n && a[i] % 2 == 0)
        {
            if (a[i] == suma)
            {
                result++;
            }
            suma += a[i];
            i++;
        }
        if (i < n)
        {
            if (a[i] == suma)
            {
                result++;
            }
            suma += a[i];
            i++;
        }
    }
    return result;
}
