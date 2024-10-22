//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void resuelveCaso() {
    int size, limit;
    cin >> size >> limit; 
    vector<int> v(size);
    for(int i = 0; i < size; i++){
        cin >> v[i];
    }
    int numSeguidos = 0, indexDef =  0, numSeguidosDef = 0; 
    //Se recorre el vector de las alturas de los edificios
    for(int i = 0; i < size; i++){
        //Si el edificio es mayor que el limit (A) se incrementa el contador de edificios seguidos en una unidad
        if(v.at(i) > limit) {
            numSeguidos++;
            //Si el numero de edificios que cumplen A es mayor que el numero de edifcios que cumplen A 
            //que se tenia guardado hasta el momento se actualiza por el nuevo y se guarda el indice a partir del cual 
            //se ha dado ambas condiciones
            if(numSeguidos > numSeguidosDef){
                numSeguidosDef = numSeguidos;
                indexDef = i;
            }
        }
        //En caso de que la secuencia de edificios que cumplen A se rompa se reinicia el contador
        else numSeguidos = 0;
    }
    //Se devuelven los puntos frontera del intervalo que cumplen la condicion
    int limitInf = indexDef-numSeguidosDef+1, limitSup = indexDef;
    cout << limitInf << " " << limitSup<< "\n";
}
	
int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        //Precondicion = {0 < size}
        //Invariante = {0 <= i < size && numSeguidos = {#k : 0 <= k < i : v[k] > limit} && numSeguidosDef = max{#k : 0 <= k < i : v[k] > limit}
        // && indexDef = k : 0 <= k < i : v[k] > limit && forall j : k-numSeguidosDef+1 <= j <= k : v[j] < limit}
        //Funcion de cota = {size - i}
		resuelveCaso();
        //Poscondicion = {limitInf = indexDef - numSeguidosDef + 1 && limitSup = indexDef}
    }
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}