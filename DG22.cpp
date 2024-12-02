//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

//debe devolver el caracter que falta en el vector de forma recursiva, usando la búsqueda binaria
char caracterFaltante(vector<char> v, char ini, char fin){
    if(fin-ini == 1){
        if(v.at(0) == ini) return fin;
        else return ini;
    }
    // Calculamos la mitad del rango de caracteres
    char mitadSupuesta = (((ini-'a')+(fin-'a'))/2) + 'a';
    // Calculamos la mitad del rango de indicees
    int mitad_index = v.size()/2;
    char mitadReal = v.at(mitad_index);
    // Si el caracter de la mitad del rango de caracteres es menor 
    if(mitadSupuesta < mitadReal){
        return caracterFaltante(vector<char>(v.begin(), v.begin()+mitad_index), ini, mitadSupuesta);
    }
    return caracterFaltante(vector<char>(v.begin()+mitad_index, v.end()), mitadSupuesta, fin);
}


void resuelveCaso() {
    char ini, fin; 
    cin >> ini >> fin; 
    int N = fin - ini;
    vector <char> v(N);
    for(int i = 0; i < N; i++){
        char c;
        cin >> c;
        v[i] = c;
    }
    cout << caracterFaltante(v, ini, fin) << endl;
}
	
int main() {
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
    system("PAUSE");
#endif
    return 0;
}