//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

int numPares(vector<int> v){
    int numPares = 0;
    for(int i = 0; i < v.size(); i++){
        numPares += (v.at(i)%2==0);
    }
    return numPares; 
}

bool esCaucasico(vector<int> v){
    if (v.size() <= 4) return true; 
    int mitad = v.size()/2;
    int izq = numPares(vector<int>(v.begin(), v.begin()+mitad));
    int derech = numPares(vector<int>(v.begin()+mitad, v.end()));
    int diff = abs(izq-derech);
    return diff <= 2 && esCaucasico(vector<int>(v.begin(), v.begin()+mitad)) && esCaucasico(vector<int>(v.begin()+mitad, v.end()));
}

bool resuelveCaso(){
    int N; 
    cin >> N; 
    if(N == 0) return false;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    if(esCaucasico(v)) cout << "SI\n"; 
    else cout << "NO\n";
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