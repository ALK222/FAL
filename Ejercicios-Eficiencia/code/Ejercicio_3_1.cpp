unsigned int num_singulares(int a[], unsigned int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int suma = 0;
        for (int j = 0; j < i; j++)
        {
            suma += a[j];
        }
        if (a[i] == suma)
            result++;
    }
    return result;
}
