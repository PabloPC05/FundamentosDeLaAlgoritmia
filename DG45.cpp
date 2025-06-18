#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;


int busquedaBinariaX(const int& ini, const int& fin, const int& tamY){
    if(ini == fin) return ini;
    int mid = (fin + ini)/2;
    cout << "? " << mid << ' ' << tamY << '\n';
    bool edificio;
    cin >> edificio; 
    if(edificio) return busquedaBinariaX(ini, mid, tamY);
    else return busquedaBinariaX(mid + 1, fin, tamY);
}


int busquedaBinariaY(const int& ini, const int& fin, const int& tamX){
    if(ini == fin) return ini;
    int mid = (fin + ini)/2;
    cout << "? " << tamX << ' ' << mid << '\n'; 
    bool edificio;
    cin >> edificio; 
    if(edificio) return busquedaBinariaY(ini, mid, tamX);
    else return busquedaBinariaY(mid + 1, fin, tamX);
}


bool resuelveCaso() {
	int tamX, tamY;
	cin >> tamX >> tamY;
	if (tamX == 0 && tamY == 0) return false;
    int X = busquedaBinariaX(1, tamX, tamY);
    int Y = busquedaBinariaY(1, tamY, tamX);
    cout << "Respuesta: " << X << ' ' << Y << '\n';
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