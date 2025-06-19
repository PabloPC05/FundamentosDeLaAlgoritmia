//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

void preCalculoEst(const int& numComensales, const vector<vector<bool>> & allegados, vector<int>& sumaRapido) {
	// Precalculamos la suma de los minimos de las filas i+1 a numComensales-1
	vector<int> rapido(numComensales,0);
	for (int i = 0; i < allegados.size(); ++i) {
		for (int j = 0; j <=i; ++j) {
			if (allegados[i][j]) ++rapido[i];
		}
	}
	// sumaRapido[i] es la suma de los minimos de las filas i+1 a numComensales-1
	if (numComensales > 0) {
		sumaRapido[numComensales - 1] = 0;
		for (int i = numComensales - 2; i >= 0;--i) {
			sumaRapido[i] = sumaRapido[i + 1] + rapido[i + 1];
		}
	}
}

bool es_Valida(vector<vector<float>> const& distancias, vector<vector<bool>>const& allegados, int& valor, vector<int> const& sol, int index, int &incremento){
	bool valido = true;
	for (int i = 0; i < index && valido; i++) {
		if (allegados[i][index] && distancias[sol[index]][sol[i]] < 2) ++incremento; // Si son allegados y la distancia es menor a 2, incrementamos el contador de parejas
		else if (!allegados[i][index] && distancias[sol[index]][sol[i]] < 2) valido = false; // Si no son allegados y la distancia es menor a 2, no es una colocación válida
	}
	return valido;
}

// El index representa el comensal actual
void variaciones(int index, const int& numPlazas, const int& numComensales, const vector<vector<float>>& distancias, const vector<vector<bool>>& allegados, vector<bool> plazas, int numParejas, int& numParejasMax, const vector<int>& sumaRapido, bool& solucionEncontrada, vector<int>& sol){
    if(index == numComensales){
        if(numParejas > numParejasMax){
            numParejasMax = numParejas;
            solucionEncontrada = true;
        }
    } else{ // i representa el siguiente comensal
        for(int i = 0; i < numPlazas; i++){
            sol[index] = i; // Colocamos al comensal index en la posicion i
            if(!plazas[i]){ // Si la plaza i no está ocupada
                int incremento = 0;
                if(es_Valida(distancias, allegados, numParejas, sol, index, incremento)){
                    numParejas += incremento;
                    plazas[i] = true;
                    int numParejas_estimado = numParejas + sumaRapido[index];
                    if(numParejas_estimado > numParejasMax){
                        variaciones(index + 1, numPlazas, numComensales, distancias, allegados, plazas, numParejas, numParejasMax, sumaRapido, solucionEncontrada, sol);
                    }
                    plazas[i] = false;
                    numParejas -= incremento;
                }
            }
        }
    }
}

void resuelveCaso(){
    int numPlazas, numComensales;
    cin >> numPlazas >> numComensales;
    vector<vector<float>> distancias (numPlazas, vector<float>(numPlazas, 0));
    for(int i = 0; i < numPlazas; i++){
        for(int j = 0; j < numPlazas; j++){
            cin >> distancias[i][j];
        }
    }
    vector<vector<bool>> allegados (numComensales, vector<bool>(numComensales, false));
    for(int i = 0; i < numComensales; i++){
        for(int j = 0; j < numComensales; j++){
            int temp;
            cin >> temp;
            allegados[i][j] = (temp != 0);
        }
    }
    int index = 0;
    vector<bool> plazas(numPlazas, false);
    int numParejas = 0;
    int numParejasMax = 0;
    vector<int> estimacion(numComensales), sol(numComensales);
    preCalculoEst(numComensales, allegados, estimacion);
    bool solucionEncontrada = false;
    variaciones(index,  numPlazas, numComensales, distancias, allegados, plazas, numParejas, numParejasMax, estimacion, solucionEncontrada, sol);
    if(solucionEncontrada){
        cout << "PAREJAS " << numParejasMax << '\n';
    } else cout << "CANCELA\n";

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
    int numCasos;
    cin >> numCasos;
    while(numCasos--) resuelveCaso();
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    return 0;
}