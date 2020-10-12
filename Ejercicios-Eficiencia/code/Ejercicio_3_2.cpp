unsigned int num_singulares(int a[], unsigned int n)
{
    int resul = 0;
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == suma)
            resul++;
        suma += a[i];
    }
    return resul;
}
