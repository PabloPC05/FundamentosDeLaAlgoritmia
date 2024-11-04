//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> leerVector(int size){
    vector<int> v(size);
    for(int i = 0; i < size; i++){
        cin >> v[i];
    }
    return v;
}

bool seCumple(vector<int> v, int N, int seguidos){
    int constante = v.at(0), consecutivos = 1; 
    for(int i = 0; i < N-1; i++){
        if(v.at(i) == v.at(i+1)) consecutivos++; 
        else if(v.at(i) < v.at(i+1)){
            if(consecutivos >= seguidos) return true;
            consecutivos = 1;
        }
        else consecutivos = 1;
    }
    return false;
}

bool resuelveCaso() {
    int N, seguidos; 
    cin >> N >> seguidos; 
    if(N == 0 && seguidos == 0) return false;
    vector<int> v = leerVector(N);
    if(seCumple(v, N, seguidos)) cout << "SI\n";
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