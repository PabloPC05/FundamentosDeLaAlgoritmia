#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;


bool esPosible(const int& limite, const int& MaxViajes, const vector<int>& pesos){
    int n = pesos.size();
    int viajes_necesarios = 0;
    int suma = 0;
    int cont = 1;
    for(int i = 0; i < n; i++){
        if(suma + pesos[i] <= limite){
            suma += pesos[i];
        } else{
            suma = pesos[i];
            cont++;
        }
    }
    return cont <= MaxViajes;
}



int busqueda_binaria(const int& ini, const int& fin, const int& maxViajes, const vector<int>& pesos){
    if(ini > fin) return ini;
    int mid = (ini + fin)/2;
    if(esPosible(mid, maxViajes, pesos)){
        return busqueda_binaria(ini, mid - 1, maxViajes, pesos);
    } else {
        return busqueda_binaria(mid + 1, fin, maxViajes, pesos);
    }
}

bool resuelveCaso() {
	int numObras, numMaxViajes;
	cin >> numObras >> numMaxViajes;
	if (numObras == 0 && numMaxViajes == 0) return false;
	vector<int> pesos(numObras);
	for (int i = 0; i < numObras;i++)
		cin >> pesos[i];
    int fin = 0;
    for(const int& p : pesos) fin += p;
	int ini = *max_element(pesos.begin(), pesos.end());
    cout << busqueda_binaria(ini, fin, numMaxViajes, pesos) << '\n';
	return true;
}

int main() {
    /*while(resuelveCaso());
    return 0;*/
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    // Resolvemos
    while(resuelveCaso()) ;
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    return 0;
}