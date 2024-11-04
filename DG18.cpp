//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int suma(int n){
    int suma = 0;
    while(n != 0){
        int digito = n%10;
        suma += digito;
        n /= 10;
    }
    return suma;
}

bool esSumDivisible(int n){
    int orden = log10(n)+1;
    if(orden == 1) return true;
    int sum = suma(n);
    bool sumaDivisible = sum % orden == 0;
    return sumaDivisible && esSumDivisible(n/10);
}

bool resuelveCaso() {
    int numero;
    cin >> numero;
    if(numero == 0) return false;
    if(esSumDivisible(numero)) cout << "SI\n";
    else cout << "NO\n";
    return true;
}
	
int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    // Resolvemos 
    while(resuelveCaso());
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}