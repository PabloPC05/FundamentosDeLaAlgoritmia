#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;


int numPatrocinios(const vector<float>& v, const int& numElems){
    int media = 0; 
    int cont = 0;
    for(int i = 0; i < numElems; i++){
        if(v[i] > media * 1.5) cont++;
        media = (i)*media;
        media += v[i];
        media = media / (i+1);
    }
    return cont;
}


void resuelveCaso(){
    int numElems;
    cin >> numElems;
    vector<float> v(numElems, 0);
    for(int i = 0; i < numElems; i++){
        cin >> v[i];
    }
    cout << numPatrocinios(v, numElems) << '\n';
}

int main() {
    #ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    int numCasos;
    cin >> numCasos;
    while(numCasos--)resuelveCaso();
    #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
    #endif
    return 0;
}