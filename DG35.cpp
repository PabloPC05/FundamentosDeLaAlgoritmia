//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include <climits>
#include <algorithm>
using namespace std;

void variaciones(int index, const int& numSupers, const int& numProductos, const vector<vector<int>>& productos, int& costeTotal, int& costeMinimo, const vector<int>& cota, vector<bool>& comprados, vector<int>& supersComprados, bool& solucionEncontrada){
    if(index == numProductos){
        costeMinimo = min(costeMinimo, costeTotal);
        solucionEncontrada = true;
    } else{
        for(int i = 0; i < numSupers; i++){
            if(!comprados[index]  && supersComprados[i] < 3){ // Si ya se ha comprado el producto, no lo tenemos en cuenta
                int precio = productos[i][index]; // Precio del producto index en el supermercado i
                if(costeTotal + precio + cota[index] < costeMinimo){
                    costeTotal += precio;
                    comprados[index] = true;
                    supersComprados[i]++;
                    variaciones(index + 1, numSupers, numProductos, productos, costeTotal, costeMinimo, cota, comprados, supersComprados, solucionEncontrada);
                    costeTotal -= precio;
                    comprados[index] = false;
                    supersComprados[i]--;
                }
            }
        }
    }
}

void resuelveCaso() {
    int numSupers, numProductos;
    cin >> numSupers >> numProductos;

    vector<vector<int>> productos(numSupers, vector<int>(numProductos));
    vector<int> minimos(numProductos, INT_MAX);  // Mínimo precio por producto

    // Leer los precios y calcular mínimo por producto
    for (int i = 0; i < numSupers; i++) {
        for (int j = 0; j < numProductos; j++) {
            cin >> productos[i][j];
            minimos[j] = min(minimos[j], productos[i][j]);
        }
    }

    // Precalcular poda hacia atrás: suma acumulada de mínimos
    vector<int> cota(numProductos, 0);
    for (int i = numProductos - 2; i >= 0; i--) {
        cota[i] = cota[i + 1] + minimos[i + 1];
    }

    vector<bool> supermercadosUsados(numSupers, false);
    int costeTotal = 0;
    int costeMinimo = INT_MAX;
    vector<int> supersComprados(numSupers, 0);
    bool solucionEncontrada = false;

    // Llamada a la función de vuelta atrás
    variaciones(0, numSupers, numProductos, productos,
                costeTotal, costeMinimo, cota, supermercadosUsados, supersComprados, solucionEncontrada);
    
    if(solucionEncontrada) cout << costeMinimo << '\n';
    else cout << "Sin solucion factible\n";
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