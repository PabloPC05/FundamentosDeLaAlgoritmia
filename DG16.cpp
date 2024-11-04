//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

// CerosUnos(v, p, q) = {#k : p <= k <= q && v[k] == 1} == {#k : p <= k <= q && v[k] == 0}
bool cerosUnos(vector<int> v, int p, int q){
    int numUnos = 0, numCeros = 0;
    for(int i = p; i < q; i++){
        if(v.at(i) == 1) numUnos++;
        else if(v.at(i) == 0) numCeros++;
    }
    return numUnos == numCeros;
}

int numSegmentos(vector<int> v, int l){
    int N = v.size();
    int numCeros = 0, numUnos = 0;
    int numIntervalos = 0;
    for(int j  = 0; j < l; j++){
        if(v.at(j) == 1) numUnos++;
        else if(v.at(j) == 0) numCeros++;
    }
    if(numUnos == numCeros) numIntervalos++;
    for(int i = 0; i < N-l; i++){
        if(v.at(i) == 1) numUnos--;
        else if(v.at(i) == 0) numCeros--;
        if(v.at(i+l) == 1) numUnos++;
        else if(v.at(i+l) == 0) numCeros++;
        if(numUnos == numCeros) numIntervalos++;
    }
    return numIntervalos;
}


void resuelveCaso() {
    int l, N; 
    cin >> l >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    //Invariante = {0 <= j <= l && 0 <= i <= N-l && numUnos = {#k : i <= k <= i+l && v[k] == 1} 
    // && numCeros = {#k : i <= k <= i+l && v[k] == 0} && numIntervalos = {#(i, i+l) : 0 <= i <= N-l : numUnos == numCeros}}
    //Cota = N - i
    //El caso peor sería en el que se cumplen la mayoía de los condicionales, pues de todas formas se tiene que recorrer el vector
    //Debido a ello, como son operaciones de coste constante el coste sería a grandes rasgos de los 2 bucles
    //Entonces, dado que el primero se ejecuta l veces y el segundo N-l veces, el coste sería de O(N)
    cout << numSegmentos(v, l) << endl;
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
    while(numCasos--){
        resuelveCaso();
    }
    #ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}