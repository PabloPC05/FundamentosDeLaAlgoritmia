//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> leerVector(){
    int size;
    cin >> size;
    vector<int> v(size);
    for(int i = 0; i < size; i++){
        cin >> v[i];
    }
    return v;
}

void resuelveCaso(vector <int> v) {
    int numPistas = 0, numPistasDef = 0;
    int N = v.size();
    for(int i = 0; i < N-1; i++){
        //Si se da que la secuencia es dereciente se incrementa en una unidad el contador de pistas que decrecen
        if(v.at(i) >= v.at(i+1)){
            numPistas++;
            //Si el numero de pistas que decrecen es mayor que el numero de pistas que cumplen la condicion
            //que se tenia guardado se guarda el nuevo numero de pistas que decrecen
            if(numPistas > numPistasDef){
                numPistasDef = numPistas;
            }
        }
        //Si no se cumple que las pistas decrecen, se vuelve rompe la cadena y se empieza desde 0
        else numPistas = 0;
    }
    
    if(!v.empty()) numPistasDef++;
    cout << numPistasDef << "\n";
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
        //Precondicion = {0 <= N <= 10^6}
        //Invariante = {0 <= i < N-1 && numPistas = {#k : 0 <= k <= i : v[k] > v[k+1]} && numPistasDef = max{#k : 0 <= k <= i : v[k] > v[k+1]}
        //Funcion de cota = {N - i}
        //Coste asintotico: El caso peor seria aquel en el que la lista sea toda decreciente en cuyo caso siempre entraria a los condicionales dado que se cumplirian las condiciones
        //y por tanto el coste obviando asignaciones y accesos a memoria seria de 2*N - 2 entonces el coste seria O(N)
		resuelveCaso(leerVector());
        //Postcondicion = {numPistasDef = max{#k : 0 <= k < N-1 : v[k] > v[k+1]}}
    }
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}