int resul(int a[], int n, int c){
    int i=0;
    int j=i+1;
    int suma=a[0];
    while(j<n){
        if(a[j]>c){
            i=j+1;
            suma=a[i];
            j=i+1;
        }
        else if(a[j]==c){
            return true;
        }
        else{
            if(suma+a[j]<c){
                suma+=a[j];
                j++;
            }
            else if(suma+a[j]==c){
                suma+=a[j];
                return true;
            }
            else{
                i++;
                suma=a[i];
                j=i+1;
            }
        }
    }
}