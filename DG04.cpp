// Pablo Pardo Cotos

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool resuelveCaso() {
    int numYears;
    cin >> numYears;
    if (numYears == 0) return false;
    string nacionalidadInteres;
    vector <string> nacionalidades;
    cin >> nacionalidadInteres;
    for (int i = 0; numYears > i; i++){
        string nacionalidad;
        cin >> nacionalidad;
        nacionalidades.push_back(nacionalidad);
    }
    int j = numYears-1;
    while(j >= 0 && nacionalidades.at(j) != nacionalidadInteres){
        j--;
    }
    if(j < 0) std::cout << "NUNCA\n";
    else std::cout << numYears-j << endl;
    return true;
}


int main() {
    
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}