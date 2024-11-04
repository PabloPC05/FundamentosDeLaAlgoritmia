//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;


int valorMaximo(vector<int> v, int ini, int fin){
    int maximo = v.at(ini);
    for(int i = ini; i <= fin; i++){
        if(v.at(i) > maximo) maximo = v.at(i);
    }
    return maximo;
}

int valorMinimo(vector<int> v, int ini, int fin){
    int minimo = v.at(ini);
    for(int i = ini; i <= fin; i++){
        if(v.at(i) < minimo) minimo = v.at(i);
    }
    return minimo;
}

bool estaParcialmenteOrdenado(vector<int> v, int ini = 0, int fin = -1){
    if(fin == -1) fin = v.size() - 1;
    bool estaOrdenado = true;
    if(ini == fin) return true;
    int mitad = (ini + fin) / 2;
    int maximo = valorMaximo(v, mitad+1, fin);
    int minimo = valorMinimo(v, ini, mitad);
    for(int i = ini; i <= mitad && estaOrdenado; i++){
        estaOrdenado = (v.at(i) <= maximo);
    }
    for(int i = mitad+1; i <= fin && estaOrdenado; i++){
        estaOrdenado = (v.at(i) >= minimo);
    }
    return estaOrdenado && estaParcialmenteOrdenado(v, ini, mitad) && estaParcialmenteOrdenado(v, mitad+1, fin);
}

bool resuelveCaso() {
    int n; 
    cin >> n; 
    if(n == 0) return false;
    vector<int> v;
    while(n != 0){
        v.push_back(n);
        cin >> n;
    }
    if(estaParcialmenteOrdenado(v)) cout << "SI\n";
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