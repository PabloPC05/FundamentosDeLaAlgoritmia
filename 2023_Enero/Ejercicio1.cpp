#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*
* cerosUnos(v, p, q) = #{k : p <= k < q : v[k] == 0} == #{i : p <= i < q : v[i] == 1}
*   Pre: {l >= 1 && v.size() >= l && forall k : 0 <= k < l : v[k] != 0  && v[k] != 1}
    fun contarSegmentos(v, l) return int result
    Post: {result = #{(p,q) : 0 <= p < q < v.size() && q - p == l : cerosUnos(v, p, q)}}
*/

// Especificar una función que cuente los segmentos de longitud l
int contarSegmentos(const vector<int>& v, int l) { // C(O) = v.size() = n
    int num_ceros = 0;
    int num_unos = 0;
    int num_segmentos = 1;
    int n = v.size();
    for(int i = l ; i < n; i++){
        num_ceros += (v[i] == 0);
        num_unos += (v[i] == 1);
        num_ceros -= (v[i-l] == 0);
        num_unos -= (v[i-l] == 1);
        if(num_ceros == num_unos) num_segmentos++;
    }
    return num_segmentos;
}

void resolverProblema() {

    int l, n;
    cin >> l >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << contarSegmentos(v, l) << endl;

}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int i;
    cin >> i;
    for (int j = 0; j < i; j++) { resolverProblema(); }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // Descomentar si se trabaja en Windows
    // system("PAUSE");
#endif
    return 0;
}