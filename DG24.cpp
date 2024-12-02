//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

int numeroATachar(vector<int> const& v, const int numCantado, int ini, int fin) {
    if (ini >= fin) return -1; // Condición de parada correcta
    int mitad = (ini + fin) / 2;
    if (numCantado + mitad == v.at(mitad)) return v.at(mitad);
    else if (v.at(mitad) < numCantado + mitad) return numeroATachar(v, numCantado, mitad + 1, fin);
    else return numeroATachar(v, numCantado, ini, mitad);
}



void resuelveCaso() {
    int N, numCantado; 
    cin >> N >> numCantado;        
    vector<int> v(N); 
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    int result = numeroATachar(v, numCantado, 0, v.size());
    if(result == -1) cout << "NO" << endl;
    else cout << result << endl;
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
    while(numCasos--) resuelveCaso();
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}