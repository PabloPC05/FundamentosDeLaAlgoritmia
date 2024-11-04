//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int max(int n){
    int max = 0;
    while(n > 0){
        int digito = n%10; 
        if(digito > max) max = digito;
        n = n/10;
    }
    return max;
}

int numeroCodificado(int n, int posicion = 0, int minimo = -1, int maximo = -1){
    int digito = n%10, c = 0;
    if(n == 0) return 0;
    if(minimo == -1) minimo = digito;
    maximo = max(n/10);
    // Si la posicion es par se multiplica el digito por 2 y se suma el maximo numero a la izquierda
    if(posicion%2 == 0) c = 2*digito + maximo;
    // Si la posicion es impar se multiplica el digito por 3 y se suma el minimo numero a la derecha
    else c = 3*digito + minimo;
    if(minimo > digito) minimo = digito;
    return c + numeroCodificado(n/10, posicion+1, minimo, maximo);
}

void resuelveCaso() {   
    int numero; 
    cin >> numero;
    cout << numeroCodificado(numero) << endl;
}
	
int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    // Resolvemos
    int numCasos; 
    cin >> numCasos; 
    for(int i = 0; i < numCasos; i++) resuelveCaso();
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}