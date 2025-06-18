//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include <climits>
using namespace std;

void variaciones(const int index, const vector<vector<int>>& teclas, const int& numTeclas, const int& long_deseada, const int limite_castigo, int puntuacion, int castigos, int& max_puntuacion, int elems, bool& solucion_encontrada, const int& maximo){
    if(elems == long_deseada){
        max_puntuacion = max(max_puntuacion, puntuacion);
        solucion_encontrada = true;
    } else{
        for(int siguiente = 0; siguiente < numTeclas; siguiente++){
            int variacion = teclas[index][siguiente];
            int nueva_puntuacion = puntuacion + max(variacion, 0);
            int nuevos_castigos = castigos + max(0, -variacion);
            if(max_puntuacion < nueva_puntuacion + (long_deseada - elems - 1)*maximo && nuevos_castigos <= limite_castigo){
                variaciones(siguiente, teclas, numTeclas, long_deseada, limite_castigo, nueva_puntuacion, nuevos_castigos, max_puntuacion, elems + 1, solucion_encontrada, maximo);
            }
        }
    }
}

void resuelveCaso(){
    int numTeclas, long_deseada, limite_castigo;
    cin >> numTeclas >> long_deseada >> limite_castigo;
    vector<vector<int>> teclas(numTeclas, vector<int>(numTeclas, 0));
    for(int i = 0; i < numTeclas; i++){
        for(int j = 0; j < numTeclas; j++){
            cin >> teclas[i][j];
        }
    }
    int maximo = INT_MIN;
    for(int i = 0; i < numTeclas; i++){
        for(int j = 0; j < numTeclas; j++){
            maximo = max(maximo, teclas[i][j]);
        }
    }
    maximo = max(0, maximo);
    int max_puntuacion = INT_MIN;
    bool solucionEncontrada = false;
    for (int i = 0; i < numTeclas; ++i) {
        variaciones(i, teclas, numTeclas, long_deseada, limite_castigo,
                    0, 0, max_puntuacion, 1, solucionEncontrada, maximo);
    }    
    if(solucionEncontrada) cout << max_puntuacion << '\n';
    else cout << "NO\n";
}

int main() {
    /*while(resuelveCaso());
    return 0;*/
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    // Resolvemos
    int numCasos;
    cin >> numCasos;
    while(numCasos--) resuelveCaso();
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    return 0;
}