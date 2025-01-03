//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

int minimo(vector <int> const& v){
    int min = v.at(v.size()-1);
    if(v.size() == 1) return min;
    int min2 = minimo(vector<int>(v.begin(), v.end()-1));
    if(min > min2) min = min2;
    return min;
}


bool resuelveCaso() {
    int N; 
    cin >> N;
    if(!cin) return false;
    vector<int> v(N);
    while(N--){
        cin >> v[N];
    }
    cout << minimo(v) << endl;
    return true;
}
	
int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    // Resolvemos
    while(resuelveCaso());
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}