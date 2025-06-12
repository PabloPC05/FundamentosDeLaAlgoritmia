#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// Por el Teorema de la resta,T(n) = aT(n - b) + k_1 * n^k, en nuestro caso a = 1, k = 0 -> como a = 1, el Coste es O(n^{k+1}) = O(n^{1}) = O(n) con n el número de elementos del vector
int maxDiferencia(const vector<int>& v, const int& ini, const int& fin){
    if(ini + 1 == fin){ // Caso final, se devuelve laresta entre los dos últimos numeros
        return v[fin] - v[ini];
    } else{  // Caso concreto, se calcula la diferencia entre
        return max(maxDiferencia(v, ini + 1, fin), v[ini+1]-v[ini]);
    }
}

void resuelveCaso(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int elem;
        cin >> elem;
        v[i] = elem;
    }
    int ini = 0;
    cout << maxDiferencia(v, ini, n-1) << '\n';
}

int main() {
    #ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    int numCasos;
    cin >> numCasos;
    while(numCasos--) resuelveCaso();
    #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
    #endif
    return 0;
}