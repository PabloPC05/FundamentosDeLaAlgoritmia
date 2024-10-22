//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
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
    int N = v.size();
    int numConsecutivos = 0, numConsecutivosDef = 0, i = 0;
    while(N > 1 && i < N-1){
        if(abs(v.at(i) - v.at(i+1)) == 1){
            numConsecutivos++;
            if(numConsecutivos > numConsecutivosDef){
                numConsecutivosDef = numConsecutivos;
            }
        }
        else numConsecutivos = 0;
        i++;
    }
    if(N <= 1) numConsecutivosDef = N;
    else numConsecutivosDef++;
    cout << numConsecutivosDef << "\n";
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
        //Precondicion = {0 <= N}
        //Invariante = {0 <= i <= N && numConsecutivos = {#k : 0 <= k < i : v[k+1] = v[k] + 1 || v[k+1] = v[k] - 1} && numConsecutivosDef = max{numConsecutivos}}
        //Funcion de cota = {N - i}
        //Coste asintotico: El peor caso seria cuando el vector tenga N elementos y todos sean consecutivos
        //En cuyo caso, el coste seria aproximadamente (obviando asignaciones y accesos a memoria) 3N por el bucle while y 2 por el if
        //Por tanto el coste asintotico seria O(N)
        //fun resuelve caso (vector<int> v) return numConsecutivosDef
		resuelveCaso(leerVector());
        //Postcondicione= {numConsecutivosDef = max{#k : 0 <= k < N-1 : v[k+1] = v[k] + 1 || v[k+1] = v[k] - 1}}
    }
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}