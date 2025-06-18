#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
using namespace std;

bool esValida(const int& index, const vector<vector<bool>>& coincidencias, const int& numRutas, const vector<int>& sol, const int& j){
    bool result = true;
    for(int i = 0; i < sol.size() && result; i++){
        if(sol[i] != -1 && coincidencias[sol[i]][index]){
            result = (abs(j - i) >= 3 || abs(j - i) == 0);
        }
    }
    return result;
}

void vueltaAtras(int index, const int& numRutas, const int& numDias, const vector<vector<bool>>& coincidencias, const vector<int>& puntuaciones, int& puntuacionTotal, int& puntuacionMaxima, vector<int>& sol, vector<int>& mejor_sol, bool& solucionEncontrada, vector<bool>& dias_ocupados, int& numCompletados){
    if(index == numRutas){
        if(numCompletados == numDias){
            if(puntuacionTotal > puntuacionMaxima ||
            (puntuacionTotal == puntuacionMaxima && sol < mejor_sol)){
                puntuacionMaxima = puntuacionTotal;
                solucionEncontrada = true;
                mejor_sol = sol;
            }
            return;
        }
    }

    for(int i = 0; i < numDias; i++){
        if(!dias_ocupados[i]){   // Si la ruta index no ha sido usada
            int puntuacion = puntuaciones[index]; // Tomamos la puntuacion de la ruta index;

            puntuacionTotal += puntuacion;
            sol[i] = index;
            dias_ocupados[i] = true;
            numCompletados++;

            if(esValida(index, coincidencias, numRutas, sol, i)){  // Si la ruta es valida
                vueltaAtras(index + 1, numRutas, numDias, coincidencias, puntuaciones, puntuacionTotal, puntuacionMaxima, sol, mejor_sol, solucionEncontrada, dias_ocupados, numCompletados);
            }

            dias_ocupados[i] = false;
            sol[i] = -1;
            puntuacionTotal -= puntuacion;
            numCompletados--;
        }
    }
    vueltaAtras(index + 1, numRutas, numDias, coincidencias, puntuaciones, puntuacionTotal, puntuacionMaxima, sol, mejor_sol, solucionEncontrada, dias_ocupados, numCompletados);
}

void resuelveCaso() {   
    int numRutas, numDias;
    cin >> numRutas >> numDias;
    vector<vector<bool>> coincidencias(numRutas, vector<bool>(numRutas, false));
    for(int i = 0; i < numRutas; i++){
        for(int j = 0; j < numRutas; j++){
            int elem;
            cin >> elem;
            coincidencias[i][j] = (elem != 0);
        }
    }
    vector<int> puntuaciones(numRutas, 0);
    for(int i = 0; i < numRutas; i++){
        cin >> puntuaciones[i];
    }

    // Preparar estructuras auxiliares
    int puntuacionTotal = 0, puntuacionMaxima = INT_MIN;
    vector<int> sol(numDias, -1);         // Solución parcial
    vector<int> mejor_sol(numDias, -1);   // Mejor solución encontrada
    vector<bool> dias_ocupados(numDias, false);

    bool solucionEncontrada = false;

    // Llamada al backtracking
    int numCompletados = 0;
    vueltaAtras(0, numRutas, numDias, coincidencias, puntuaciones, puntuacionTotal, puntuacionMaxima, sol, mejor_sol, solucionEncontrada, dias_ocupados, numCompletados);

    // Imprimir resultados
    if(solucionEncontrada){
        cout << puntuacionMaxima << ' ';
        for(int i = 0; i < numDias; i++){
            if(mejor_sol[i] != -1)
                cout << mejor_sol[i] << ' ';
        }
        cout << '\n';
    }else{
        cout << "IMPOSIBLE\n";
    }
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