/*
* (a): noMasDeDos(v, q, p) = not exists k : p <= k <= q - 3 : v[k] < v[k+1] < v[k+2]
* (b): 
        Pre: {k >=3 && n >= k && n = v.size()}
        fun numSegmentos(v, k, n) dev int numSegmentos
        Post: numSegmentos = #{(p,q) : 0 <= p < q : q - p == k && noMasDeDos(v, q, p)}
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Invariante: 0 <= i < n && returnValue = #{(p,q) : 0 <= p < q < i : p - q >= l && {forall k : 0 < p <= k < q : v[k] = [p]}}
// Cota: n - i - 1
// Coste: coste lineal con respecto al numero de elementos del vector v O(n)
int numSegmentos(const vector<int>& v, const int& n, const int& k){
    int cont = 0;
    bool creciente = false;
    int r = -1;
    // Vemos la primera ventana
    for(int i = 1; i < k-1; i++){ // Miramos la primera ventana
        if(v[i-1] < v[i] && v[i] < v[i+1]){
            r = i-1;
        }
    }
    if(r == -1) cont++;
    for(int i = k-1; i < n-1; i++){
        if(v[i-1] < v[i] && v[i] < v[i+1]){
            r = i - 1;
        }
        if(r < i+2 - k){
            cont++;
        }
    }
    return cont;
}

bool resuelveCaso(){
    int l, n;
    cin >> n >> l;
    if(n == 0) return false;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int elem;
        cin >> elem;
        v[i] = elem;
    }
    cout << numSegmentos(v, n, l) << '\n';
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