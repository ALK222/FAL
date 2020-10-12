void ordena(tSecuencia &sec)
{
    bool hay_movimientos;
    int tope = sec.nelems - 1;
    do
    {
        hay_movimientos = false;
        for (int i = 0; i < tope; i++)
        {
            if (sec.datos[i] > sec.datos[i + 1])
            {
                int tmp = sec.datos[i];
                sec.datos[i] = sec.datos[i + 1];
                sec.datos[i + 1] = tmp;
                hay_movimientos = true;
            }
        }

    } while (hay_movimientos);
}
