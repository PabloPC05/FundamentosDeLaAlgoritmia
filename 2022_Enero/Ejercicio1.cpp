#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

pair<int, int> orden(vector<int>& paquetes, const int& numPaquetes, const int& pesoMediano, const int& pesoGrande){
    int i = 0, index_mediano = 0, index_grande = numPaquetes;
    while(i < index_grande){
        if(paquetes[i] < pesoMediano){
            swap(paquetes[i], paquetes[index_mediano]);
            i++;
            index_mediano++;
        } else if(paquetes[i] >= pesoGrande){
            index_grande--;
            swap(paquetes[i], paquetes[index_grande]);
        } else{
            i++;
        }
    }
        return {index_mediano, index_grande};
}

bool resuelveCaso(){
    int numPaquetes, pesoMediano, pesoGrande;
    cin >> numPaquetes >> pesoMediano >> pesoGrande;
    if(!cin) return false;
    vector<int> paquetes(numPaquetes, 0);
    for(int& x : paquetes) cin >> x;
    pair<int, int> result = orden(paquetes, numPaquetes, pesoMediano, pesoGrande);
    for(int i = 0; i < result.first; i++){
        cout << paquetes[i] << ' ';
    }
    cout << '\n';
    for(int i = result.first; i < result.second; i++){
        cout << paquetes[i] << ' ';
    }
    cout << '\n';
    for(int i = result.second; i < numPaquetes; i++){
        cout << paquetes[i] << ' ';
    }
    cout << "\n---\n";
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