bool busca(const int[] elems, int elem)
{
    int i = 0;
    while (elems[i] != elem && elems[i] != -1)
    {
        i++;
    }
    return elems[i] != -1;
}
