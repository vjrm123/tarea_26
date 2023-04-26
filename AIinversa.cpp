#include <iostream>

using namespace std;

void inversa(int numero[],int inicio,int final){
    
    for(inicio=0; inicio<=final; inicio++){
        int temporal = numero[final];
        numero[final] = numero[inicio];
        numero[inicio] = temporal;
        final--;
    }
}

int main(){
    int numero[] = {1,2,3,4,5};
    int longitud = sizeof(numero) / sizeof(numero[0]);
    inversa(numero,0,longitud-1);
    for(int i=0; i<longitud; i++){
        cout<<numero[i]<<" ";
    }
}