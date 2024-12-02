//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

const vector<char> fichas = {'T', 'R'};

struct tFicha{
    int col;
    char tipo;
};

vector<std::pair<int, int>> casillasInvalidas;

bool esValida(vector<tFicha>& fichasUsadas, int index, vector<int> apariciones){
    bool valid = true; 
}

int variaciones(vector<tFicha>& fichasUsadas, int index, const int longVar, const vector<int> numFichas, vector<int> numFichasUsadas) {
    if(index == longVar){
        if(numFichas.at(0) == 0 && numFichas.at(1) == 0){
            return 1 + variaciones(fichasUsadas, index-1, longVar, numFichas, numFichasUsadas);
        }
    }
    else{
        for(int i = 0; i < longVar; i++){
            for(int j = 0; j < fichas.size(); j++){
                if(numFichas.at(j) > 0 && numFichas.at(j) - numFichasUsadas.at(j) > 0){
                    fichasUsadas.at(index) = {i, fichas.at(j)};
                    numFichasUsadas.at(j)++;
                    if(esValida(fichasUsadas, index, numFichasUsadas)){
                        variaciones(fichasUsadas, index+1, longVar, numFichas, numFichasUsadas);
                    }
                    fichasUsadas.at(index) = {0, '\s'};
                    numFichasUsadas.at(j)--;
                }
            }
        }
    }
}


bool resuelveCaso(){
    int numTorres, numReinas, numCasillasInvalidas;
    cin >> numTorres >> numReinas;
    if(!cin) return false;
    cin >> numCasillasInvalidas;
    int size = numTorres + numReinas;
    vector<tFicha> fichas(size);
    for(int i = 0; i < numCasillasInvalidas; i++){
        int x, y;
        cin >> x >> y;
        casillasInvalidas[i] = {x, y};
    }
    cout << variaciones(fichas, 0, size, {numTorres, numReinas}, {0, 0}) << endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    // Resolvemos
    while(resuelveCaso());
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}