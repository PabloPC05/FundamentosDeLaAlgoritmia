#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int esHiperminimalista(const vector<int> v, const int& c, const int& f) {
    if(f - c == 1) return min(v[f], v[c]);
    else if(f - c == 0) return v[f];
    else{
        int mid = (f + c)/2;
        int left_min = esHiperminimalista(v, c, mid);
        int right_min = esHiperminimalista(v, mid + 1, f);
        if(left_min == -1 || right_min == -1) return -1;
        if(left_min == right_min){ // Si ambos minimos son iguales, ya no es hiperminimalista
            return -1;
        } else return min(left_min, right_min);
    }
}

bool resuelveCaso() {

    int n;

    cin >> n;

    if (n == -1) return false;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if (esHiperminimalista(v, 0, v.size() - 1) == -1) {
        cout << "NO" << endl;
    }
    else {
        cout << "SI" << endl;
    }

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}