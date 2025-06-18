#include <iostream>
#include <fstream>
using namespace std;

void calcularComplementarioInverso(int n, long long& complemento, long long& inverso, long long& factor) {
    if (n < 10) {
        int comp = 9 - n;
        complemento = comp;
        inverso = comp;
        factor = 10;
    } else {
        int dig = n % 10;
        int comp = 9 - dig;
        int resto = n / 10;

        long long complementoAnterior, inversoAnterior, factorAnterior;
        calcularComplementarioInverso(resto, complementoAnterior, inversoAnterior, factorAnterior);

        complemento = complementoAnterior * 10 + comp;
        inverso = comp * factorAnterior + inversoAnterior;
        factor = factorAnterior * 10;
    }
}

void resuelveCaso() {
    int n;
    cin >> n;

    long long complemento, inverso, factor;
    calcularComplementarioInverso(n, complemento, inverso, factor);

    cout << complemento << ' ' << inverso << '\n';
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
    for(int i = 0; i < numCasos; i++) resuelveCaso();
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}