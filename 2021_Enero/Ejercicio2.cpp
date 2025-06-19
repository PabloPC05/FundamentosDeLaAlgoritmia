#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


/*int mayorFaltante(const vector<int>& v, const int& ini){
    if(ini == 0) return v[ini] - 1; 
    if(v[ini] - v[ini - 1] > 1) return v[ini] - 1;
    else return mayorFaltante(v, ini - 1);
}*/


int mayorFaltante(std::vector<int> const& v, int ini, int fin) {
    if (ini + 2 == fin) {
        return v[ini+1] -1;
    }
    else {
        int m = (ini + fin) / 2;
        if (v[fin-1] - v[m] == (fin-1) -m)
            return mayorFaltante(v,ini,m+1);
        else return mayorFaltante(v,m,fin);
    }
}

bool resuelveCaso(){
    int numElems;
    cin >> numElems;
    if(numElems == 0) return false;
    vector<int> v(numElems, 0);
    for(int& x : v) cin >> x;
    cout << mayorFaltante(v, 0, numElems) << '\n';
    return true;
}


int main() {
    #ifndef DOMJUDGE
        std::ifstream in("casos.txt");
        auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    while(resuelveCaso());

    #ifndef DOMJUDGE
        std::cin.rdbuf(cinbuf);
        system("PAUSE");
    #endif
        return 0;
}