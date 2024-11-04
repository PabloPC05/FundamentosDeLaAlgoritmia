//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int numPares(vector<int> v, const int l){
    int N = v.size();
    int numPares = 0, longitudActual = 0, longitudMaxima = 0; 
    for(int i = 0; i < N; i++){
        longitudActual++;
        if(v.at(i)%2 == 0){
            numPares++;
            if(numPares > l) longitudActual = l;
        }
        else numPares = 0;
        longitudMaxima = max(longitudMaxima, longitudActual);
    }
    return longitudMaxima;
}

void resuelveCaso(){
    int l, N;
    cin >> N >> l;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    // Invariante = {0 <= i <= N && numPares = {#k : 0 <= k <= i && v[k]%2==0}
    // && longitudActual = {#k : 0 <= k <= i && numPares <= l}} && longitudMaxima = max{longitudActual}
    // Funcion cota = N - i
    // Coste asintotico en el peor caso, se mete en el bucle while varias veces
    cout << numPares(v, l) << endl;
}

	
int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    while(numCasos--) resuelveCaso();
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}