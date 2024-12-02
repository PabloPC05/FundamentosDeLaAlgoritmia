//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

const vector<string> colores = {"azul", "rojo", "verde"};


bool esSolucion(int index, int longVar){ 
    return index == longVar;
}

bool esValida(vector<string> v, int index){
    bool valid = false;
    valid = v.at(0) == "rojo";
    int numVerdesConsecutivos = 0;
    for(int i = 1; i < index+1 && valid; i++){
        if(v.at(i) == "verde"){
            numVerdesConsecutivos++;
        }else{
            numVerdesConsecutivos = 0;
        }
        if(numVerdesConsecutivos > 1) valid = false;
    }
    return valid;
}


void variaciones(vector<string>& v, int index, int longVar){
    if(v.size() == 1) cout << v.at(0) << endl;
    else{
        for(int i = 0; i < colores.size() && v.size() > 1; i++){
            v[index] = colores.at(i);
            if(esValida(v, index)){
                if(esSolucion(index, longVar)){
                    for(int i = 0; i < v.size(); i++){
                        cout << v.at(i) << " ";
                    }
                    cout << endl;
                } else{ 
                    variaciones(v, index+1, longVar);
                }
            }
        }
    }
}

bool resuelveCaso(){
    int longVar; 
    cin >> longVar; 
    if(0 == longVar) return false;
    vector<string> v(longVar);
    v[0] = "rojo";
    variaciones(v, 1, longVar-1);
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