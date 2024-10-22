//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> leerVector(int size) {
    vector<int> v(size);
    for (int i = 0; i < size; ++i) {
        cin >> v[i];
    }
    return v;
}

bool resuelveCaso(vector<int> v) {
    int i = 0;
    bool creciente = false, decreciente = false;
    //Comprobamos si es creciente
    while(i < v.size()-1 && v.at(i+1) > v.at(i)){
        i++;
    }
    if(i == v.size()-1) creciente = true;
    i = 0; 
    //Comprobamos si es decreciente
    while(!creciente && i < v.size()-1 && v.at(i) > v.at(i+1)){
        i++;
    }
    if(i == v.size()-1) decreciente = true; 
    return (creciente || decreciente);
}
	
int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    // Resolvemos
    unsigned int n; 
    cin >> n; 
    while(n != 0){
        //Precondicion = {N > 0}
        //Invariante = {0 <= i <= N && creciente = (forall k : 0 <= k < i : v[k] < v[k+1]) && decreciente = (forall k : 0 <= k < i : v[k] > v[k+1])}
        //Funcion cota = {N - i}
		if(resuelveCaso(leerVector(n))) cout << "DALTON\n";
        //Postcondicion = (creciente || decreciente)
        else cout << "DESCONOCIDOS\n";
        cin >> n;
    }
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}