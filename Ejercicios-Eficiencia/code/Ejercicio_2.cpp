void insertar(tSecuencia &sec, int elem)
{
    int i = sec.nelems while (i > 0 && sec.datos[i - 1] > elem)
    {
        sec.datos[i] = sec.datos[i - 1];
        i--;
    }
    sec.datos[i] = elem;
    sec.nelems++;
}
