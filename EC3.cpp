#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include <climits>
#include <algorithm>
using namespace std;

void variaciones(int index, const int& numCiudades, const int& numPatrullas, const int& sueldo_reserva, const vector<int>& minimos, const vector<int>& maximos, const vector<int>& sueldos, const vector<int>& patrullas, int& sueldoActual, int& sueldoMinimo, bool& solucionEncontrada, vector<int>& personas_repartidas, int& numCompletadas, const vector<int>& poda){
    if(index == numPatrullas){
        if(numCompletadas != numCiudades) return;
        sueldoMinimo = min(sueldoActual, sueldoMinimo);
        solucionEncontrada = true;
        return;
    }
    for(int i = 0; i < numCiudades; i++){
        int personas_aportadas = patrullas[index];
        if(personas_aportadas + personas_repartidas[i] <= maximos[i]){ // Si las personas aportadas por la patrulla index, sumadas a las que ya están en la ciudad son menores que el maximo
            sueldoActual += personas_aportadas * sueldos[i];
            if(personas_repartidas[i] < minimos[i] && personas_aportadas + personas_repartidas[i] >= minimos[i]) numCompletadas++;
            personas_repartidas[i] += personas_aportadas;
            
            if(personas_repartidas[i] + poda[index] >= minimos[i] && sueldoActual + poda[index] < sueldoMinimo){
                variaciones(index + 1, numCiudades, numPatrullas, sueldo_reserva, minimos, maximos, sueldos, patrullas, sueldoActual, sueldoMinimo, solucionEncontrada, personas_repartidas, numCompletadas, poda);
            }
            personas_repartidas[i] -= personas_aportadas;
            if(personas_repartidas[i] < minimos[i] && personas_aportadas + personas_repartidas[i] >= minimos[i]) numCompletadas--;
            sueldoActual -= personas_aportadas * sueldos[i];

        }
    }
    int aporte_reserva = patrullas[index]* sueldo_reserva;
    if(sueldoActual + aporte_reserva + poda[index] < sueldoMinimo){ 
        sueldoActual += aporte_reserva;
        variaciones(index + 1, numCiudades, numPatrullas, sueldo_reserva, minimos, maximos, sueldos, patrullas, sueldoActual, sueldoMinimo, solucionEncontrada, personas_repartidas, numCompletadas, poda);
        sueldoActual -= aporte_reserva;
    }
}

void resuelveCaso(){
    int numCiudades, numPatrullas, sueldo_reserva;
    cin >> numCiudades >> numPatrullas >> sueldo_reserva;

    vector<int> minimos(numCiudades);
    for(int& x : minimos) cin >> x;

    vector<int> maximos(numCiudades);
    for(int& x : maximos) cin >> x;

    vector<int> sueldos(numCiudades);
    int sueldo_minimo = sueldo_reserva;
    for(int& x : sueldos){
        cin >> x;
        sueldo_minimo = min(sueldo_minimo, x);
    }

    vector<int> patrullas(numPatrullas);
    for(int& x : patrullas) cin >> x;

    vector<int> poda(numPatrullas, 0);
    for(int i = numPatrullas - 2; i >= 0; i--) {
        poda[i] = poda[i + 1] + patrullas[i + 1] * sueldo_minimo;
    }

    vector<int> personas_repartidas(numCiudades, 0);

    int sueldoActual = 0;
    int sueldoMinimo = INT_MAX;
    int numCompletadas = 0;
    bool solucionEncontrada = false;

    variaciones(0, numCiudades, numPatrullas, sueldo_reserva, minimos, maximos, sueldos,
                patrullas, sueldoActual, sueldoMinimo, solucionEncontrada,
                personas_repartidas, numCompletadas, poda);

    if (solucionEncontrada)
        cout << sueldoMinimo << '\n';
    else
        cout << "NO\n";
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