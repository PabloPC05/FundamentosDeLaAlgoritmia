#include <iostream>
#include <vector>
#include <fstream>
#include <climits>

using namespace std;

int min_vigilante(vector<vector<int>> const& distancias, int k) {
    int minimum = distancias[k][0];
    for (int i = 1; i < distancias[k].size(); ++i) {
        minimum = min(minimum, distancias[k][i]);
    }
    return minimum;
}

// Index es el indice de los vigilantes
void vueltaAtras(int index, const int m, const int& n, const vector<int>& minSize, const int& maxDist, const vector<vector<int>>& distancias, int& distancia_actual, int& distancia_min , vector<int>& cur_sizes, int& numCompletadas, int& necesarios, const vector<int>& dMinAcumulada){
        for(int i = 0; i < n; i++){
            if(maxDist >= distancias[index][i]){
                cur_sizes[i]++;
                distancia_actual+= distancias[index][i];
                if(cur_sizes[i] == minSize[i]) ++numCompletadas;
                if(minSize[i] >= cur_sizes[i]) --necesarios;
                if(index == m - 1){
                    if(numCompletadas == n){
                        if(distancia_min == -1 || distancia_actual < distancia_min){
                            distancia_min = distancia_actual;
                        }
                    }
                } else{
                    if((distancia_actual + dMinAcumulada[index + 1] < distancia_min || distancia_min == -1) && (m - index - 1 >= necesarios)){
                        vueltaAtras(index + 1, m, n, minSize, maxDist, distancias, distancia_actual, distancia_min, cur_sizes, numCompletadas, necesarios, dMinAcumulada);
                    }
                }
                distancia_actual -= distancias[index][i];
                if(cur_sizes[i] == minSize[i]) --numCompletadas;
                if(minSize[i] >= cur_sizes[i]) ++necesarios;
                cur_sizes[i]--;
            }
        }
}


bool resuelveCaso() {
    int n, m; // n: número de brigadas (montes), m: número de vigilantes
    cin >> n >> m;
    if (n == 0 && m == 0) return false;
    
    // Leer tamaños mínimos de las brigadas
    vector<int> tamMinimo(n);
    for(int i = 0; i < n; i++) {
        cin >> tamMinimo[i];
    }
    
    // Leer distancia máxima permitida
    int distMaxima;
    cin >> distMaxima;
    
    // Leer matriz de distancias
    vector<vector<int>> distancias(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> distancias[i][j];
        }
    }
    vector<int> dMin_por_vigilante(m);
    for (int i = 0; i < m; ++i)
        dMin_por_vigilante[i] = min_vigilante(distancias, i);

    vector<int> dMinAcumulada(m);
    dMinAcumulada[m - 1] = dMin_por_vigilante[m - 1];
    for (int i = m - 2; i >= 0; --i)
        dMinAcumulada[i] = dMin_por_vigilante[i] + dMinAcumulada[i + 1];

    int necesarios = 0;
    for (int i = 0; i < n; ++i)
        necesarios += tamMinimo[i];

    int sol_global = -1;
    int sol_actual = 0;
    int num_completadas = 0;
    vector<int> cur_sizes(n, 0);



    int index = 0; 
    vueltaAtras(index, m, n, tamMinimo, distMaxima, distancias, sol_actual, sol_global, cur_sizes, num_completadas, necesarios, dMinAcumulada);

    if (sol_global == -1)
        cout << "IMPOSIBLE\n";
    else
        cout << sol_global << "\n";

    // TODO: Resolver el problema
    
    return true;
}

int main() {
    // Ajustes para entrada por fichero
#ifndef PROXUS
    ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // Restablecimiento de la entrada
#ifndef PROXUS 
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}