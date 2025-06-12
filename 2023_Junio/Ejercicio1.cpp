#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool resuelveCaso(){
    int numElems;
    cin >> numElems; 
    if(numElems == -1) return false;
    vector<int> elems(numElems);
    for(int i = 0; i < numElems; i++){
        cin >> elems[i];
    }
    int min = elems[0];
    bool minimalista = true;
    for(int i = 1; i < numElems && minimalista; i++){
        if(elems[i] < min) min = elems[i];
        else if(elems[i] == min) minimalista = false; 
    }
    if(minimalista) cout << "SI\n";
    else cout << "NO\n";
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