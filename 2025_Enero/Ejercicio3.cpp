#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
using namespace std;

void vueltaAtras(int index, const int& numVoluntarios, const int& numPoblaciones, const int& numPoblacionesMinimas, const vector<vector<int>>& voluntarios, const vector<int>& necesidades, int& ayudaActual, int& maxAyuda, int& numCompletas, vector<int>& ayuda_recibida, bool& solucionEncontrada, const vector<int>& cota){
	if(numPoblacionesMinimas - numCompletas > numVoluntarios - index) return;
	if(index == numVoluntarios){
		if(numCompletas >= numPoblacionesMinimas){
			maxAyuda = max(maxAyuda, ayudaActual);
			solucionEncontrada = true;
		}
		return;
	}

	for(int i = 0; i < numPoblaciones; i++){
		if(ayuda_recibida[i] < necesidades[i]) {
			int ayuda_dada = min(voluntarios[index][i], max(necesidades[i] - ayuda_recibida[i], 0));
			bool estaba_completa = (ayuda_recibida[i] >= necesidades[i]);
			
			ayudaActual += ayuda_dada;
			ayuda_recibida[i] += ayuda_dada;
			if(!estaba_completa && ayuda_recibida[i] >= necesidades[i]) numCompletas++;

			if(ayudaActual + cota[index] > maxAyuda){
				vueltaAtras(index + 1, numVoluntarios, numPoblaciones, numPoblacionesMinimas, voluntarios, necesidades, ayudaActual, maxAyuda, numCompletas, ayuda_recibida, solucionEncontrada, cota);
			}
			
			if(!estaba_completa && ayuda_recibida[i] >= necesidades[i]) numCompletas--;
			ayuda_recibida[i] -= ayuda_dada;
			ayudaActual -= ayuda_dada;
		}
	}
}

void resuelveCaso() {
    int numVoluntarios, numPoblaciones, numPoblacionesMinimas;
    cin >> numVoluntarios >> numPoblaciones >> numPoblacionesMinimas;
	int ayuda_total_necesaria = 0;

    vector<int> necesidades(numPoblaciones);
    for (int& x : necesidades){ 
		cin >> x;
		ayuda_total_necesaria += x;
	}

    // voluntarios[i][j] = lo que el voluntario i puede aportar a la población j
    vector<vector<int>> voluntarios(numVoluntarios, vector<int>(numPoblaciones));
    vector<int> maximos(numVoluntarios, 0); // Para calcular la cota

    for (int i = 0; i < numVoluntarios; i++) {
        for (int j = 0; j < numPoblaciones; j++) {
            cin >> voluntarios[i][j];
            maximos[i] = max(maximos[i], voluntarios[i][j]);
        }
    }

    // Cota acumulada de ayuda máxima que podrían dar los siguientes voluntarios
	vector<int> cota(numVoluntarios);
	cota[numVoluntarios-1] = maximos[numVoluntarios-1];
	for(int i = numVoluntarios-2; i >= 0; --i)
		cota[i] = maximos[i] + cota[i+1];

    int ayudaActual = 0;
    int maxAyuda = 0;
    int numCompletas = 0;
    vector<int> ayuda_recibida(numPoblaciones, 0);
    bool solucionEncontrada = false;
	vector<bool> voluntarios_asignados(numVoluntarios, false);

    vueltaAtras(0, numVoluntarios, numPoblaciones, numPoblacionesMinimas, voluntarios,
                necesidades, ayudaActual, maxAyuda, numCompletas, ayuda_recibida,
                solucionEncontrada, cota);

    if (solucionEncontrada)
        cout << maxAyuda << "\n";
    else if(!solucionEncontrada && numPoblacionesMinimas == 0) cout << 0 << '\n';
	else  cout << "IMPOSIBLE\n";
}

int main() {
    #ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    int numCasos;
    cin >> numCasos;
    while(numCasos--) resuelveCaso();
    #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
    #endif
    return 0;
}