//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int numSegmentos(vector<int> v){
    int numSegmentos = 0, paresSeguidos = 0; 
    for(int i = 0; i < v.size(); i++){
        if(v.at(i)%2==0){
            while(i < v.size() && v.at(i)%2==0){ 
                paresSeguidos++;
                i++;
            }
            numSegmentos += (paresSeguidos*(paresSeguidos+1))/2;
            paresSeguidos = 0;
        }
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