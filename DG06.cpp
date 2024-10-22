//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int equilibrio(vector<int> v){
    int pos = -1, unos = 0, ceros = 0;
    for(int i = 0; i < v.size(); i++){
        if(v.at(i) == 1) unos++;
        else if(v.at(i) == 0) ceros++;
        if(unos == ceros){
            pos = i;
        }
    }
    return pos;
}

void resuelveCaso(){
    int size;
    cin >> size;
    vector<int> v(size);
    for(int i = 0; i < size; i++){
        cin >> v[i];
    }
    cout << equilibrio(v) << endl;
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
		resuelveCaso();
    }
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}