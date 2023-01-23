void generalizacion(int a[],int n, int ini, int fin, bool& resul){
    if(ini == fin){
        resul = false;
    }
    else{
        int mid = (ini + fin) / 2;
        if(a[ini]==a[mid]){
            generalizacion(a,n,mid+1,fin,resul);
        }
        if(a[mid]==a[fin]){
            generalizacion(a,n,ini,mid,resul);
        }
    }
}

bool ejer2(int a[],int n){
    int ini=0;
    int fin=n-1;
    bool resul=true;
    generalizacion(a,n,ini,fin,resul);
    return resul;
}