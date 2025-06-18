#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <climits>
using namespace std;

/*void bateria(const vector<int>& pesos, const int& d, const int& N, int& suma_minima, const int& ini){
    if(d == 1){
        int result = 0;
        for(int i = ini; i < N; i++) result += pesos[i];
        suma_minima = result;
    } else{
        int este_dron = 0, otro_dron = 0; 
        for(int i = 0; i <= N-d; i++){
            bateria(pesos, d - 1, N, otro_dron, i + 1);
            este_dron += pesos[i];
            int maximo = max(este_dron, otro_dron);
            suma_minima = min(maximo, suma_minima);
        }
    }
}*/


bool posible(const vector<int>& paquetes, int d, int max_bateria) {
    int usados = 1, suma = 0;
    for(int peso : paquetes) {
        if(peso > max_bateria) return false;
        if(suma + peso > max_bateria) {
            usados++;
            suma = peso;
        } else {
            suma += peso;
        }
    }
    return usados <= d;
}

// Búsqueda binaria recursiva
int busqueda_binaria(const vector<int>& paquetes, int d, int left, int right) {
    if(left > right) return left; // Al final, left es el mínimo posible

    int mid = (left + right) / 2;
    if(posible(paquetes, d, mid)) {
        // Si es posible con mid, intentamos menos batería
        return busqueda_binaria(paquetes, d, left, mid - 1);
    } else {
        // Si no es posible, necesitamos más batería
        return busqueda_binaria(paquetes, d, mid + 1, right);
    }
}


bool resuelveCaso(){
    int N, d; // N - num paquetes, d - num drones
    cin >> N >> d;
    if(N == 0 && d == 0) return false;
    vector<int> pesos(N, 0);
    for(int i = 0; i < N; i++){
        int elem;
        cin >> elem;
        pesos[i] = elem;
    }
    int left = *max_element(pesos.begin(), pesos.end());
    int right = 0;
    for(int p : pesos) right += p;
    int res = busqueda_binaria(pesos, d, left, right);
    cout << (res * 2) << endl;
    return true;
}

int main() {
    #ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    while(resuelveCaso()) resuelveCaso();
    #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
    #endif
    return 0;
}