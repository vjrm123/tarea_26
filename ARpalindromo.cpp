#include <iostream>

using namespace std;

bool espalindromo(int numero[], int inicio, int final){
    
    if(inicio >= final){
        return true;
    }
    if(numero[inicio] != numero[final]){
        return false;
    }
    return espalindromo(numero, inicio+1, final-1);
}

int main(){
    int numero[] = {1,2,3,4,5};
    int longitud = sizeof(numero) / sizeof(numero[0]);

    cout<<espalindromo(numero,0,longitud-1);
    
    return 0;
}