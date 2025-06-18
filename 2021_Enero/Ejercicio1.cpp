#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

/*
*   contarPositivos(v, i, j) = #{k : i <= k <= j : v[k] > 0}

*/

int contarPositivos(const vector<int>& v, const int& numElems, const int& longIntervalo){
    int mid = longIntervalo / 2;
    int cont_right = 0, cont_left = 0;
    int cont = 0;
    for(int i = 0; i < longIntervalo; i++){
        if(i >= mid && v[i] > 0){
            cont_right++;
        } else if(v[i] > 0){
            cont_left++;
        }
    }
    if(cont_right <= cont_left) cont++;
    for(int i = longIntervalo; i < numElems; i++){
        if(v[i-longIntervalo] > 0) cont_left--;
        if(v[i] > 0) cont_right++;
        if(v[i-longIntervalo + mid ] > 0){ 
            cont_left++;
            cont_right--;
        }
        if(cont_left >= cont_right) cont++;
    }
    return cont;
}


bool resuelveCaso(){
    int numElems, longIntervalo;
    cin >> numElems >> longIntervalo;
    if(numElems == 0) return false;
    vector<int> elems (numElems, 0);
    for(int& x : elems) cin >> x;
    cout << contarPositivos(elems, numElems, longIntervalo) << '\n';

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