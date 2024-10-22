//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> leerVector(int size){
    vector<int> v(size);
    for(int i = 0; i < size; i++){
        cin >> v[i];
    }
    return v;
}

/*int resolverCaso(vector<int> v, int l){
int N = v.size();
    int numIntervalos = 0;
    int numPositivosIzquierda = 0, numPositivosDerecha = 0;
    int mitad = l / 2;

    // Inicializar los conteos para el primer intervalo
    for (int j = 0; j < l; j++) {
        if (j < mitad && v[j] > 0) numPositivosIzquierda++;
        else if (j >= mitad && v[j] > 0) numPositivosDerecha++;
    }
    if (numPositivosIzquierda >= numPositivosDerecha) numIntervalos++;

    // Deslizar la ventana
    for (int i = 1; i <= N - l; i++) {
        // Eliminar el elemento que sale de la ventana
        if (v[i - 1] > 0) {
            if (i - 1 < i - 1 + mitad) numPositivosIzquierda--;
            else numPositivosDerecha--;
        }
        // Agregar el elemento que entra en la ventana
        if (v[i + l - 1] > 0) {
            if (i + l - 1 < i + mitad) numPositivosIzquierda++;
            else numPositivosDerecha++;
        }
        if (numPositivosIzquierda >= numPositivosDerecha) numIntervalos++;
    }

    return numIntervalos;
}*/

/*int resolverCaso(vector<int> v, int l){
    int N = v.size(), numIntervalos = 0, numPositivosDerecha = 0, numPositivosIzquierda = 0;
    for(int i = 0; i < N-l+1; i++){
        for(int j = i; j < i+l; j++){
            if(j < i+(l/2) && v.at(j) > 0) numPositivosIzquierda++;
            else if(j >= i+(l/2) && v.at(j) > 0) numPositivosDerecha++;
        }
        if(numPositivosIzquierda >= numPositivosDerecha) numIntervalos++;
        numPositivosDerecha = 0;
        numPositivosIzquierda = 0;
    }
    return numIntervalos;
}*/

int resolverCaso(vector<int> v, int l){
    int N = v.size(), numIntervalos = 0, numPositivosDerecha = 0, numPositivosIzquierda = 0;
    for(int i = 0; i < N-l+1; i++){
        int limite = i+(l/2);
        for(int j = i; j < limite; j++){
            if(v.at(j) > 0) numPositivosIzquierda++;
        }
        for(int j = i+l-1; j > limite-1; j--){
            if(v.at(j) > 0) numPositivosDerecha++;
        }
        if(numPositivosIzquierda >= numPositivosDerecha) numIntervalos++;
        numPositivosDerecha = 0;
        numPositivosIzquierda = 0;
    }
    return numIntervalos;
}

bool resuelveCaso() {
    int size, longitud;
    cin >> size; 
    if(size == 0) return false;
    cin >> longitud;
    vector<int> v = leerVector(size);
    //Precondicion = {0 < N && 0 < l <= N}
    //Invariante = {0 <= i <= N-l+1 && i <= j <= i + l && numPositivosIzquierda = {#k : i <= k <= i+(l/2)-1 : v[k] > 0}
    //&& numPositivosDerecha = {#k : i+(l/2) <= k <= i+l-1 : v[k] > 0}
    // && numIntervalos = {#(t, s) : 0 <= t <= i && l <= s <= N : numPositivosIzquierda >= numPositivosDerecha}}
    //Funcion de cota = {N - i}
    cout << resolverCaso(v, longitud) << "\n";
    //Postcondicion = {#(t, s) : 0 <= t <= i && l <= s <= N : numPositivosIzquierda >= numPositivosDerecha}
    return true;
}
	
int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while(resuelveCaso());
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}