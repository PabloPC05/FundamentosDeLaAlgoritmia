//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> leerVector() {
    int size; 
    cin >> size;
    vector<int> v(size);
    for (int i = 0; i < size; ++i) {
        cin >> v[i];
    }
    return v;
}

bool esPastoso(vector<int> v, int& pos){
    bool encontrado = false;
    int suma = 0; 
    v.push_back(0);
    for(int i = v.size()-1; i > 0 && !encontrado; i--){
        suma += v.at(i);
        if(suma == v.at(i-1)){
            pos = i-1;
            encontrado = true;
        }
    }
    return encontrado;
}

void resuelveCaso() {
    int pos = -1;
    if(esPastoso(leerVector(), pos)) cout << "Si " << pos << " \n";
    else cout << "No\n";
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
    for (int i = 0; i < numCasos; ++i) {
        //Invariante = {0 <= i <= N && suma = {sum k : 0 <= k < i : v[k]} 
        // && encontrado = {Exits k : 0 <= k < i : v.at(k) = sum{ j : 0 <= j < k : v[j]}} && -1 <= pos <= N}
        //Funcion cota = {N - i}
        //Coste asintotico en el caso peor : El coste en el peor caso se da cuando la suma es igual al primer elemento del vector, en cuyo caso se completa el bucle entonces:
        // T(n) = 2 + 1 + n*(1 + 1 + 1 + 1 + 1) + 1 = 4 + 5n = O(n) 
		resuelveCaso();
    }
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}