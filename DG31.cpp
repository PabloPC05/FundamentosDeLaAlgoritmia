//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;
struct tColor{
    string color;
    int numVeces;
};
// Apariciones del azul, rojo y verde, respectivamente
const vector<string> colores = {"azul", "rojo", "verde"};
bool solucionEncontrada = false;

bool esValida(vector<string> v, int index, vector<int> apariciones){
    bool valid = false;
    valid = v.at(0) == "rojo";
    if(apariciones[2] > 0) {
        valid = apariciones[0] >= apariciones[2];
    }
    int numVerdesConsecutivos = 0;
    for(int i = 1; i < index+1 && valid && apariciones[2] > 0; i++){
        if(v.at(i) == "verde"){
            numVerdesConsecutivos++;
        }else{
            numVerdesConsecutivos = 0;
        }
        if(numVerdesConsecutivos > 1) valid = false;
    }
    return valid;
}

void printVector(vector<string> v){
    solucionEncontrada = true;
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
}


void variaciones(vector<string>& v, int index, int longVar, const vector<int> numColores, vector<int> coloresUsados) {
    if(v.size() == 1 && v.at(0) == "rojo") cout << "rojo" << endl;
    else{
        if(index-1 == longVar){
            if(coloresUsados.at(1) > coloresUsados.at(0) + coloresUsados.at(2)){
                printVector(v);
            }
        }
        else{
            for(int i = 0; i < colores.size(); i++){
               if(numColores.at(i) > 0 && numColores.at(i) - coloresUsados.at(i) > 0){
                    v.at(index) = colores.at(i);
                    coloresUsados.at(i)++;
                    if(esValida(v, index, coloresUsados)){
                        variaciones(v, index+1, longVar, numColores, coloresUsados);
                        v.at(index) = "";
                        coloresUsados.at(i)--;
                    }
               }
            }
        }
    }
    }

bool resuelveCaso(){
    int longVar, numAzules, numRojos, numVerdes; 
    cin >> longVar >> numAzules >> numRojos >> numVerdes;
    if(0 == longVar) return false;
    vector<string> v(longVar);
    v[0] = "rojo";
    solucionEncontrada = false;
    variaciones(v, 1, longVar-1, {numAzules, numRojos, numVerdes}, {0, 1, 0});
    if(!solucionEncontrada) cout << "SIN SOLUCION" << endl;
    cout << endl; 
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