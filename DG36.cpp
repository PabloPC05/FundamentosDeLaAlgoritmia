//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include <climits>
#include <algorithm>
using namespace std;

void variaciones(int index, const int& numQuitanieves, const int& numCaminos, const vector<int>& anchurasQuitanieves, const vector<int>& anchurasCaminos, const vector<vector<int>>& calidades, int& calidadTotal, int& maxCalidad, vector<bool>& caminosOcupados, const vector<int>& poda, int& numCompletados){
    if(index == numQuitanieves){
            maxCalidad = max(maxCalidad, calidadTotal);
            return;
    } else if(index < numQuitanieves){
        for(int i = 0; i < numCaminos; i++){
            if(!caminosOcupados[i] && anchurasCaminos[i] >= anchurasQuitanieves[index]){ // Si el camino no está ocupado y el carro index cabe en el camino i, continuamos
                int calidad = calidades[index][i];
                if(calidad + calidadTotal + poda[index] > maxCalidad){
                    calidadTotal += calidad;
                    caminosOcupados[i] = true;
                    numCompletados++;
                    variaciones(index + 1, numQuitanieves, numCaminos, anchurasQuitanieves, anchurasCaminos, calidades, calidadTotal, maxCalidad, caminosOcupados, poda, numCompletados);
                    calidadTotal -= calidad;
                    caminosOcupados[i] = false;
                    numCompletados--;
                }
            }
        }
        variaciones(index + 1, numQuitanieves, numCaminos, anchurasQuitanieves, anchurasCaminos, calidades, calidadTotal, maxCalidad, caminosOcupados, poda, numCompletados);
    }
}

void resuelveCaso() {
    int numQuitanieves, numCaminos;
    cin >> numQuitanieves >> numCaminos; 
    vector<int> anchurasQuitanieves (numQuitanieves, 0);
    for(int i = 0; i < numQuitanieves; i++){
        cin >> anchurasQuitanieves[i];
    }
    vector<int> anchurasCaminos (numCaminos, 0);
    for(int i = 0; i < numCaminos; i++){
        cin >> anchurasCaminos[i];
    }
    vector<vector<int>> calidades (numQuitanieves, vector<int>(numCaminos, 0));
    vector<int> maximos(numQuitanieves, INT_MIN);
    for(int i = 0; i < numQuitanieves; i++){
        for(int j = 0; j < numCaminos; j++){
            cin >> calidades[i][j];
            maximos[i] = max(calidades[i][j], maximos[i]);
        }
    }
    vector<int> poda(numQuitanieves, 0);
    for(int i = numQuitanieves - 2; i >= 0; i--){
        poda[i] = poda[i+1] + maximos[i + 1];
    }

    
    // Variables auxiliares para la búsqueda
    vector<bool> caminosOcupados(numCaminos, false);
    int calidadTotal = 0;
    int maxCalidad = 0;
    int numCompletados = 0;

    // Llamada a la función de backtracking
    variaciones(0, numQuitanieves, numCaminos, anchurasQuitanieves, anchurasCaminos,
                calidades, calidadTotal, maxCalidad, caminosOcupados, poda, numCompletados);

    cout << maxCalidad << '\n';

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
    while(numCasos--)resuelveCaso();
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    return 0;
}