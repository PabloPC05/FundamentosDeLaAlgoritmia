//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
using namespace std;

void resuelveCaso() {
	int temp, max, numMaxs;
	cin >> max;
	numMaxs = 1;
	cin >> temp;
	while (temp != 0) {
		if(temp > max){ max = temp; numMaxs = 1;}
		else if(temp == max) numMaxs++;
		cin >> temp;
	}
	cout << max << ' ' << numMaxs << '\n';
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
		resuelveCaso();
    }
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}