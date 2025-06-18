//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

// La tupla es duracion_limit de la primera, duracion_limit de la segunda, puntuacion máxima
void variaciones(const vector<int>& duraciones, const vector<int>& puntuaciones, const int& numCanciones, const int& duracion_limit, const int& index, int& maximo, int cara1, int cara2, int puntuacion_actual, const vector<int>& cota){
    if(index == numCanciones){
        if(maximo < puntuacion_actual){
            maximo = puntuacion_actual;
        }
    } else{
        int duracion = duraciones[index];
        int puntuacion = puntuaciones[index];
        if(cara1 + duracion <= duracion_limit && puntuacion_actual + puntuacion + cota[index] > maximo){ 
            variaciones(duraciones, puntuaciones, numCanciones, duracion_limit, index + 1, maximo, cara1 + duracion, cara2, puntuacion_actual + puntuacion, cota);
        }
        if(cara2 + duracion <= duracion_limit  && puntuacion_actual + puntuacion + cota[index] > maximo){
            variaciones(duraciones, puntuaciones, numCanciones, duracion_limit, index + 1, maximo, cara1, cara2 + duracion, puntuacion_actual + puntuacion, cota);
        }
        variaciones(duraciones, puntuaciones, numCanciones, duracion_limit, index + 1, maximo, cara1, cara2, puntuacion_actual, cota);

    }
}

bool resuelveCaso(){
    int numCanciones; 
    cin >> numCanciones; 
    if(numCanciones == 0) return false;
    int duracion_limit; 
    cin >> duracion_limit;
    vector<int> duraciones(numCanciones);
    vector<int> puntuaciones(numCanciones);
    for(int i = 0; i < numCanciones; i++){  
        cin >> duraciones[i] >> puntuaciones[i];
    }
    int maximo = 0;
    vector<int> cota(numCanciones);
    cota[numCanciones-1] = 0;
    for (int i = cota.size() - 2; i >=0; i--) {
		cota[i] = cota[i + 1] + puntuaciones[i + 1];
	}
    variaciones(duraciones, puntuaciones, numCanciones, duracion_limit, 0, maximo, 0, 0, 0, cota);
    cout << maximo << '\n';
    return true;
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
    while(resuelveCaso());
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    return 0;
}