#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;






bool resuelveCaso(){
    int elem;
    cin >> numElems;
    if(numElems == 0) return false;
    vector<int> v(numElems, 0);
    for(int& x : v) cin >> x;
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