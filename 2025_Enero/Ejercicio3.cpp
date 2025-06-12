#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
using namespace std;


// Index es el indice de los voluntarios
/*void vueltaAtras(const int& index, const int& m, const int& n, const int& l, const vector<int>& ayuda_necesaria, const vector<vector<int>>& voluntarios, int& poblaciones_cubiertas, vector<int>& ayuda_dada,
int& max_ayuda, int& ayuda_actual, const vector<int>& max_ayuda_posible){
    if(index == n){ // Si ya se han repartido todos los voluntarios
        if(poblaciones_cubiertas >= l) max_ayuda = max(max_ayuda, ayuda_actual);
    } else {
        for(int i = 0; i < m; i++){ // Iteramos sobre las poblaciones
            int ayuda_ofrecida = min(voluntarios[index][i], ayuda_necesaria[i] - ayuda_dada[i]);
            if(ayuda_ofrecida <= 0) continue;
            ayuda_actual += ayuda_ofrecida;
            bool estaba_cubierta = ayuda_necesaria[i] <= ayuda_dada[i];
            ayuda_dada[i] += ayuda_ofrecida;
            bool esta_cubierta = ayuda_necesaria[i] <= ayuda_dada[i];
            if(!estaba_cubierta && esta_cubierta){    // Si la poblacion ya ha sido cubierta
                poblaciones_cubiertas++;
            } 
            if(max_ayuda == INT_MIN || ayuda_actual + max_ayuda_posible[index] > max_ayuda) {
                vueltaAtras(index + 1, m, n, l, ayuda_necesaria, voluntarios, poblaciones_cubiertas, ayuda_dada, max_ayuda, ayuda_actual, max_ayuda_posible);
            }
            ayuda_actual -= ayuda_ofrecida; 
            if(!estaba_cubierta && esta_cubierta){    // Si la poblacion ya ha sido cubierta
                poblaciones_cubiertas--;
            } 
            ayuda_dada[i] -= ayuda_ofrecida;
        }
        //vueltaAtras(index + 1, m, n, l, ayuda_necesaria, voluntarios, poblaciones_cubiertas, ayuda_dada, max_ayuda, ayuda_actual, max_ayuda_posible);
    }
}*/

void vueltaAtras(const int& index, const int& m, const int& n, const int& l, const vector<int>& ayuda_necesaria, 
                 const vector<vector<int>>& voluntarios, int& poblaciones_cubiertas, vector<int>& ayuda_dada,
                 int& max_ayuda, int& ayuda_actual, vector<bool>& voluntario_usado) {
    
    // Si ya hemos procesado todas las poblaciones
    if (index == m) {
        if (poblaciones_cubiertas >= l) {
            max_ayuda = max(max_ayuda, ayuda_actual);
        }
        return;
    }
    
    // Poda: Si ya hemos cubierto suficientes poblaciones y esta ya está cubierta, pasamos a la siguiente
    bool poblacion_ya_cubierta = (ayuda_dada[index] >= ayuda_necesaria[index]);
    if (poblacion_ya_cubierta) {
        vueltaAtras(index + 1, m, n, l, ayuda_necesaria, voluntarios, poblaciones_cubiertas, ayuda_dada, max_ayuda, ayuda_actual, voluntario_usado);
        return;
    }
    
    // Opción 1: Intentamos asignar voluntarios a esta población
    for (int i = 0; i < n; i++) {
        if (voluntario_usado[i]) continue; // Si el voluntario ya se usó, saltamos
        
        int ayuda_ofrecida = min(voluntarios[i][index], ayuda_necesaria[index] - ayuda_dada[index]);
        if (ayuda_ofrecida <= 0) continue;
        
        // Marcamos el voluntario como usado y actualizamos estado
        voluntario_usado[i] = true;
        ayuda_actual += ayuda_ofrecida;
        ayuda_dada[index] += ayuda_ofrecida;
        
        bool se_cubrio = (ayuda_dada[index] >= ayuda_necesaria[index]);
        if (se_cubrio) poblaciones_cubiertas++;
        
        // Recursión
        vueltaAtras(index + (se_cubrio ? 1 : 0), m, n, l, ayuda_necesaria, voluntarios, 
                   poblaciones_cubiertas, ayuda_dada, max_ayuda, ayuda_actual, voluntario_usado);
        
        // Restauramos estado
        if (se_cubrio) poblaciones_cubiertas--;
        ayuda_dada[index] -= ayuda_ofrecida;
        ayuda_actual -= ayuda_ofrecida;
        voluntario_usado[i] = false;
    }
    
    // Opción 2: No asignamos más voluntarios a esta población y pasamos a la siguiente
    // Solo si ya hemos asignado algo de ayuda o si podemos permitirnos no cubrir esta población
    if (ayuda_dada[index] > 0 || (m - index - 1 + poblaciones_cubiertas >= l)) {
        vueltaAtras(index + 1, m, n, l, ayuda_necesaria, voluntarios, poblaciones_cubiertas, ayuda_dada, max_ayuda, ayuda_actual, voluntario_usado);
    }
}


void resuelveCaso() {
    int m, n, l;
    cin >> n >> m >> l; // n - voluntarios; m - poblaciones
    
    vector<int> ayuda_necesaria(m);
    for (int i = 0; i < m; i++) cin >> ayuda_necesaria[i];
    
    vector<vector<int>> voluntarios(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> voluntarios[i][j];
        }
    }
    
    int index = 0; 
    int poblaciones_cubiertas = 0;
    vector<int> ayuda_dada(m, 0);
    int max_ayuda = INT_MIN;
    int ayuda_actual = 0;
    vector<bool> voluntario_usado(n, false);
    
    vueltaAtras(index, m, n, l, ayuda_necesaria, voluntarios, poblaciones_cubiertas, 
               ayuda_dada, max_ayuda, ayuda_actual, voluntario_usado);
    
    if (max_ayuda == INT_MIN) cout << "IMPOSIBLE\n";
    else cout << max_ayuda << '\n';
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