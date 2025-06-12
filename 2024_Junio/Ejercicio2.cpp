#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


void divideYVenceras(const vector<int>& n, const vector<int>& g, int c, int f, bool& hablan, int& escalon){
    if(f - c == 1){
        hablan = false;
        escalon = c;
    } else{
        int m = (f + c)/2;
        if(n[m] > g[m]){
            divideYVenceras(n, g, c, m, hablan, escalon);
        } else if(g[m] > n[m]){
            divideYVenceras(n, g, m, f, hablan, escalon);
        } else{
            hablan = true;
            escalon = m;
        }
    }
}

bool resuelveCaso() {
    // Lectura del número de saltos
    int n;
    cin >> n;
    if (n == 0) return false;
    
    // Lectura de las secuencias de escalones
    vector<int> novita(n);
    vector<int> gigante(n);
    
    for(int i = 0; i < n; i++) {
        cin >> novita[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> gigante[i];
    }


    bool hablan = false;
    int escalon = -1;
    int i = 0;
    divideYVenceras(novita, gigante, i, n, hablan, escalon);
    if(hablan){
        cout << "HABLAN " << novita[escalon] << '\n';
    } else cout << "SE CRUZAN " << novita[escalon] << ' ' << novita[escalon + 1] << '\n';

    return true;
}

int main() {
    // Ajustes para entrada por fichero
#ifndef PROXUS
    ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // Restablecimiento de la entrada
#ifndef PROXUS 
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}