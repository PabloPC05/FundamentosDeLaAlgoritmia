//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include <climits>
using namespace std;

void variaciones(int index, const int& numFacultades, const int& numSuministradores, const vector<int>& mascarillasNecesarias, const vector<int>& stock, const vector<int>& precios, vector<int>& mascarillas, int& precioTotal, int& precioMinimo, int& numCompletadas, bool& solucionEncontrada, const int& minPrecio, int& mascarillasTotalesNecesarias){
    for(int i = 0; i < numFacultades; i++){
        if(mascarillas[i] < mascarillasNecesarias[i]){
            int compradas = min(stock[index], mascarillasNecesarias[i] - mascarillas[i]);

            mascarillas[i] += compradas;    // Sumamos las mascarillas compradas a las que necesita la facultad
            mascarillasTotalesNecesarias -= compradas;
            //mascarillasRepartidas += compradas;
            precioTotal += compradas * precios[index];
            if(mascarillas[i] == mascarillasNecesarias[i]) numCompletadas++;

            if(index == numSuministradores - 1){    // Si hemos terminado de recorrer todos los suministradores
                if(numCompletadas == numFacultades){
                    precioMinimo = min(precioMinimo, precioTotal);
                    solucionEncontrada = true;
                }
            }else{  // Si aun quedan suministradores por asignar
                int precio_estimado = minPrecio * mascarillasTotalesNecesarias;
                bool poda1 = precioTotal + mascarillasTotalesNecesarias * precios[index+1] < precioMinimo;
                bool poda2 = numFacultades - numCompletadas - 1 <= numSuministradores - index - 1;
                if(poda1 && poda2){
                    variaciones(index + 1, numFacultades, numSuministradores, mascarillasNecesarias, stock, precios, mascarillas, precioTotal, precioMinimo, numCompletadas, solucionEncontrada, minPrecio, mascarillasTotalesNecesarias);
                }
            }
            if(mascarillas[i] == mascarillasNecesarias[i]) numCompletadas--;
            mascarillasTotalesNecesarias += compradas;
            precioTotal -= compradas * precios[index];
            mascarillas[i] -= compradas;  
        } else if(mascarillasTotalesNecesarias == 0){
                if(precioTotal < precioMinimo){
                    precioMinimo = precioTotal;
                    solucionEncontrada = true;
                }
        }
    }
}

void resuelveCaso() {
    int numFacultades, numSuministradores;
    cin >> numFacultades >> numSuministradores;

    vector<int> mascarillasNecesarias(numFacultades, 0);
    int mascarillasTotalesNecesarias = 0;

    for(int i = 0; i < numFacultades; i++){
        cin >> mascarillasNecesarias[i];
        mascarillasTotalesNecesarias += mascarillasNecesarias[i];
    }

    vector<int> stock(numSuministradores, 0);
    for(int i = 0; i < numSuministradores; i++){
        cin >> stock[i];
    }

    vector<int> precios(numSuministradores, 0);
    for(int i = 0; i < numSuministradores; i++){
        cin >> precios[i];
    }
    int minimoPrecio = precios[0];


    // Variables para el backtracking
    int precioTotal = 0;
    int precioMinimo = INT_MAX;
    int numCompletadas = 0;
    vector<int> mascarillas(numFacultades, 0);
    bool solucionEncontrada = false;
    int mascarillasRepartidas = 0;

    // Llamada al algoritmo
    variaciones(0, numFacultades, numSuministradores, mascarillasNecesarias, stock, precios,
                mascarillas, precioTotal, precioMinimo, numCompletadas, solucionEncontrada,
                minimoPrecio, mascarillasTotalesNecesarias);

    if (solucionEncontrada) cout << precioMinimo << '\n';
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
    while(numCasos--)resuelveCaso();
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    return 0;
}