#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Devuelve si es posible hacer el viaje con "maxParadas" y un tiempo máximo entre paradas de "maxTiempo"
bool esPosible(const int& maxParadas, const int& maxTiempo, const vector<int>& tiempos) {
    int cont = 0; // número de paradas hechas
    int suma = 0;
    for (int t : tiempos) {
        if (suma + t > maxTiempo) {
            ++cont;
            suma = 0;
        }
        suma += t;
    }
    // Al llegar al final del viaje puede que se necesite una parada más si hay algo acumulado
    return cont <= maxParadas;
}

// Búsqueda binaria recursiva correcta
int busquedaBinaria(int ini, int fin, const int& maxParadas, const vector<int>& tiempos) {
    if (ini == fin) return ini;
    int mid = (ini + fin) / 2;
    if (esPosible(maxParadas, mid, tiempos)) {
        return busquedaBinaria(ini, mid, maxParadas, tiempos);
    } else {
        return busquedaBinaria(mid + 1, fin, maxParadas, tiempos);
    }
}

bool resuelveCaso() {
    int n, p;
    cin >> n >> p;
    if (n == 0 && p == 0) return false;

    vector<int> tiempos(n);
    for (int i = 0; i < n; ++i) cin >> tiempos[i];

    int ini = *max_element(tiempos.begin(), tiempos.end());
    int fin = 0;
    for (int i = 0; i < n; ++i) fin += tiempos[i];

    int resultado = busquedaBinaria(ini, fin, p, tiempos);
    cout << resultado << '\n';
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("casos.txt");
    cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    cin.rdbuf(cin.rdbuf());
#endif
    return 0;
}
