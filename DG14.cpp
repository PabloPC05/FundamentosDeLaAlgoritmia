//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int numSegmentos(vector<int> v){
    int N = v.size();
    int numSegmentos = 0;
    for(int i = 1; i < N; i++){
        int numPares = 0;
        for(int j = 0; j < N; j++){
            if(v.at(j) % 2 == 0) numPares++;
        }
        if(numPares == i) numSegmentos++;
    }
    return numSegmentos;
}

void resuelveCaso(){
    int l, N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    cout << numSegmentos(v) << endl;
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