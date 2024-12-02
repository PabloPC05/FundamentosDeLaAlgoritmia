//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

//Ordenacion recursiva con el algoritmo merge sort
int minimo(vector<int> v){
    int min = v.at(0);
    if(v.size() == 1) return min;
    int mitad = v.size()/2;
    int min1 = minimo(vector<int>(v.begin(), v.begin() + mitad));
    int min2 = minimo(vector<int>(v.begin()+ mitad, v.end()));
    if(min1 < min2) min = min1;
    else min = min2;
    return min;
}

bool resuelveCaso() {
    int N;
    cin >> N; 
    if(!cin) return false;
    vector <int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    cout << minimo(v) << endl;
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