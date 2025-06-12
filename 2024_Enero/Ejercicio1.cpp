/*
* (a) todosPares(v, p, q) : forall i : p <= i < q : v[i] == v[p]
* (b)   {l >= 1 && v.size() >= l}
        fun contarSegmentos(int l, int[] v) dev int count
        {# (p,q): 0 <= p <= q < v.size() && q - p >= l : todosPares(v, p, q)}
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Invariante: 0 <= i < n && returnValue = #{(p,q) : 0 <= p < q < i : p - q >= l && {forall k : 0 < p <= k < q : v[k] = [p]}}
// Cota: n - i - 1
// Coste: coste lineal con respecto al numero de elementos del vector v O(n)
int numSegmentos(const vector<int>& v, const int& n, const int& l){
    int returnValue = 0;
    int elem = *v.begin();
    int numSeguidos = 0;
    int i = 0; 
    while(i < n){
        if(elem == v[i]) numSeguidos++;
        else{
            if(numSeguidos >= l){
                int m = (numSeguidos - l) +1;
                returnValue += m*(m+1)/2;
            }
            numSeguidos = 1;
            elem = v[i];
        }
        i++;
    }
    if(numSeguidos >= l){
        int m = (numSeguidos - l) +1;
        returnValue += m*(m+1)/2;
    }
    return returnValue;
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