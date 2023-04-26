#include <iostream>

using namespace std;

bool espalindromo(int numero[], int inicio, int final){

    for(int i=inicio; i<=final; inicio++){
        if(numero[inicio] != numero[final]){
            return false;
        }
        final--;
    }
    return true;
}

int main(){

    int numero[] = {1,2,3,2,1};
    int longitud = sizeof(numero) / sizeof(numero[0]);
    cout<<espalindromo(numero,0,longitud-1);

    return 0;
}