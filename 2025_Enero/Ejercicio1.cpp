/*
* (a) paresMayorImpares(v, p, q) = (\sum k : p <= k < q &&  v[k] % 2 == 0 : v[k]) > (\sum i : p <= i < q &&  v[i] % 2 != 0: v[i])
* (b)   Pre: {l >= 1}
        fun numSegmentos(v, p, q) return int num
        Post: {num = #{(p,q) : 0 <= p < q < v.size() && q - p == l : todosPares(v, p, q)}}
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Invariante: 
// Cota: 
// Coste: 
int numSegmentos(const vector<int>& v, const int& n, const int& l){
    if(l > n) return 0;
    int suma_pares = 0;
    int suma_impares = 0;
    int result = 0;
    for(int i = 0; i < l; i++){
        if(v[i] % 2 == 0)  suma_pares += v[i];
        else suma_impares +=  v[i];
    }
    if(suma_pares > suma_impares) result++;
    for(int i = l; i < n; i++){
        if(v[i-l] % 2 == 0) suma_pares -= v[i-l];
        else suma_impares -= v[i-l];
        if(v[i] % 2 == 0)  suma_pares += v[i];
        else suma_impares +=  v[i];
        if(suma_pares > suma_impares) result++;
    }
    return result;
}

void resuelveCaso(){
    int l, n;
    cin >> l >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int elem;
        cin >> elem;
        v[i] = elem;
    }
    cout << numSegmentos(v, n, l) << '\n';
}

int main() {
    #ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    int numCasos;
    cin >> numCasos;
    while(numCasos--) resuelveCaso();
    #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
    #endif
    return 0;
}