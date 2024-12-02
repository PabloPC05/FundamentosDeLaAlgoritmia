//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

//Funcion que suma que compara todas las filas desde la columna x_ini hasta x_fin
bool matrizDegradada(vector<vector<int>> const& v, int x_ini, int x_fin, int y){
    if(x_fin - x_ini == 1) return true;
    int mitad = (x_ini + x_fin) / 2;
    bool seCumple = true;
    for(int i = 0; i < y && seCumple; i++){
        int sumaIzq = 0, sumaDerech = 0;
        for(int j = x_ini; j < mitad; j++){ 
            sumaIzq += v[i][j];
        }
        for(int j = mitad; j < x_fin; j++){ 
            sumaDerech += v[i][j];
        }
        seCumple = sumaIzq <= sumaDerech;
    }
    return seCumple && matrizDegradada(v, x_ini, mitad, y) && matrizDegradada(v, mitad, x_fin, y);
}

bool resuelveCaso(){
    int x, y; 
    cin >> y >> x; 
    if(!cin) return false;
    vector<vector<int>> v(y, vector<int>(x));
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            cin >> v[i][j];
        }
    }
    if(matrizDegradada(v, 0, x, y)) cout << "SI\n";
    else cout << "NO\n";
    return true;
}

	
int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    // Resolvemos
    while(resuelveCaso());
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}