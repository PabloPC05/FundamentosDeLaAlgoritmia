//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int numComplementario(int n){
    return 9-n;
}

int calcularComplemento(int n){
    if(n < 10) return numComplementario(n);
    int digito = n%10;
    int complementario = numComplementario(digito);
    return complementario + 10*calcularComplemento(n/10);
}

//Funcion recursiva que calcula el numero inverso de un numero
int numeroInverso(int n){
    if(n < 10) return n;
    int digito = n%10;
    int potencia = log10(n);
    return digito * pow(10, potencia) + numeroInverso(n/10);
}

void resuelveCaso() {
    int numero, numComplementario = 0, numInverso = 0; 
    cin >> numero;
    //El coste de ambas funciones es T(n) = T(n/10) + O(1) = O(log n)
    numComplementario = calcularComplemento(numero);
    numInverso = numeroInverso(numComplementario);
    cout << numComplementario << " " << numInverso << endl;
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