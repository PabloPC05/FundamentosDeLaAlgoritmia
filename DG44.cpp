#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int busquedaBinaria(const int& ini, const int& fin){
    if(ini == fin) return ini;
    int mid = (fin + ini)/2;
    cout << "? " << mid << '\n';
    string respuesta;
    cin >> respuesta;
    if(respuesta == ">"){
        return busquedaBinaria(mid + 1, fin);
    } else if(respuesta == "<="){
        return busquedaBinaria(ini, mid);
    }
}


bool resuelveCaso() {
	int ini, fin;
	cin >> ini >> fin;
	if (ini == 0 && fin == 0) return false;
    int sol = busquedaBinaria(ini, fin);
    cout << "Respuesta: " << sol << '\n';
	return true;
}

int main() {
    while(resuelveCaso());
    return 0;
    // Para la entrada por fichero.
/*#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    // Resolvemos
    while(resuelveCaso()) ;
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    return 0;*/
}