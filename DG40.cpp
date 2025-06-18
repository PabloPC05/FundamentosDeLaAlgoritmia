//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include <climits>
using namespace std;

void variaciones(int index, const vector<vector<int>>& distancias, const int& maxDistancia, const vector<int>& minSizes, const int& numMontes, const int&numVigilantes, int& minDistancia, int& distanciaTotal, bool& solucionEncontrada, vector<int> cur_sizes, int numCompletadas, const vector<int>& poda, const int& necesarios){
    for(int i = 0; i < numMontes; i++){
        if(distancias[index][i] <= maxDistancia){   // Si la distancia entre el vigilante index y el monte i es menor que la maxdistancia
            cur_sizes[i]++;
            distanciaTotal += distancias[index][i];
            if (cur_sizes[i] <= minSizes[i]) {
				++numCompletadas;
			}
            if(index == numVigilantes - 1){
                if(numCompletadas == necesarios){
                    if(distanciaTotal < minDistancia){
                        minDistancia = distanciaTotal;
                        solucionEncontrada = true;
                    }
                }
            } else{
                int distancia_estimada = distanciaTotal + poda[index];
                bool poda1 = distancia_estimada < minDistancia;
                bool poda2 = necesarios - numCompletadas <= distancias.size() - index - 1;
                if(poda1 && poda2){
                    variaciones(index + 1, distancias, maxDistancia, minSizes, numMontes, numVigilantes, minDistancia, distanciaTotal, solucionEncontrada, cur_sizes, numCompletadas, poda, necesarios);
                }
            }
            if (cur_sizes[i] <= minSizes[i]) {
				--numCompletadas;
			}
            cur_sizes[i]--;
            distanciaTotal -= distancias[index][i];
        }
    }
}

bool resuelveCaso(){
    int n, m;   // n es el numero de montes a vigilar y m es el numero de vigilantes
    cin >> n >> m;
    if(n == 0 && m == 0) return false;
    vector<int> minSizes(n, 0);
    int necesarios = 0;
    for(int i = 0; i < n; i++){
        cin >> minSizes[i];
        necesarios += minSizes[i];
    }
    int maxDistance;
    cin >> maxDistance;
    vector<vector<int>> distancias(m, vector<int>(n, 0));
    vector<int> minimos(m, INT_MAX);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> distancias[i][j];
            minimos[i] = min(minimos[i], distancias[i][j]);
        }
    }
    vector<int> poda(m ,0);
    poda[m - 1] = 0;
    for (int i = m - 2; i >= 0; --i) {
        poda[i] = poda[i + 1] + minimos[i + 1];
    }

      bool solucionEncontrada = false;
    int minDistancia = INT_MAX;
    int distanciaTotal = 0;
    int numCompletadas = 0;
    vector<int> cur_sizes(n, 0);

    variaciones(0, distancias, maxDistance, minSizes, n, m,
        minDistancia, distanciaTotal, solucionEncontrada, cur_sizes,
        numCompletadas, poda, necesarios);

    if (solucionEncontrada) cout << minDistancia << '\n';
    else cout << "IMPOSIBLE\n";


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
    while(resuelveCaso());
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    return 0;
}