#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

/*COSTE (caso peor):
*
* k                         n = 0
* T(n): T(n/10) + k'        n >= 1
*
*
* O(log10 n)
*/

struct auxiliar {
    int mayor;
    int menor;
    int pos;
};

int calcularCodigo(int n, auxiliar& aux) {
    int suma = 0;

    if (n > 0) {

        int op = 0;

        int digito = n % 10; // Obtiene el dígito menos significativo
        n = n / 10; // Elimina el dígito menos significativo

        if (aux.pos % 2 == 0) { // Posición par

            if (aux.menor > digito) aux.menor = digito;
            aux.pos++;
            suma = calcularCodigo(n, aux);
            op = digito * 2;
            op += aux.mayor;
            if (aux.mayor < digito) aux.mayor = digito;
            suma += op;
            return suma;
        }
        else { // Posición impar

            op = digito * 3;
            op += aux.menor;
            if (aux.menor > digito) aux.menor = digito;
            aux.pos++;
            suma = calcularCodigo(n, aux);
            if (aux.mayor < digito) aux.mayor = digito;
            suma += op;
            return suma;
        }
    }
    else {

        return suma;
    }
}

void tratar_caso() {
    int numero;
    cin >> numero;

    auxiliar aux;

    aux.mayor = 0;
    aux.pos = 0;
    aux.menor = numero % 10;

    int codigo = calcularCodigo(numero, aux);

    cout << codigo << endl;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int i;
    cin >> i;
    for (int j = 0; j < i; j++) { tratar_caso(); }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}