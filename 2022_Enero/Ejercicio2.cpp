#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int mayoritario(const vector<int>& v, int l, int r) {
    if (l + 1 == r) return v[l]; // Solo un elemento

    int m = (l + r) / 2;
    int izq = mayoritario(v, l, m);
    int der = mayoritario(v, m, r);

    if (izq == der) return izq;

    // Contar cuántas veces aparecen izq y der en [l, r)
    int count_izq = 0, count_der = 0;
    for (int i = l; i < r; ++i) {
        if (v[i] == izq) count_izq++;
        else if (v[i] == der) count_der++;
    }

    int n = r - l;
    if (count_izq > n/2) return izq;
    if (count_der > n/2) return der;
    return -1; // No hay mayoritario en este rango
}

bool resuelveCaso(){
    int elem;
    cin >> elem;
    vector<int> v;
    while(elem != 0){
        v.push_back(elem);
        cin >> elem;
    }
    int n = v.size();   
    int result = mayoritario(v, 0, n);
    if(result != -1) cout << result << '\n';
    else cout << "NO\n";
    return true;
}


int main() {
    #ifndef DOMJUDGE
        std::ifstream in("casos.txt");
        auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    int numCasos;
    cin >> numCasos;
    for(int i = 0; i < numCasos; i++) resuelveCaso();

    #ifndef DOMJUDGE
        std::cin.rdbuf(cinbuf);
        system("PAUSE");
    #endif
        return 0;
}