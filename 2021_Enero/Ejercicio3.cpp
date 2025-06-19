#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
using namespace std;


void vueltaAtras(
    int puesto, // ahora recursivo por puesto
    const int& numHabitantes, const int& numPuestos, const int& numHadaMala,
    const vector<vector<int>>& satisfacciones,
    bool& solucionEncontrada, int& numSoluciones,
    int& satisfaccionActual, int& satisfaccionMaxima,
    vector<bool>& habitantes_ocupados, int& contSupersticiosos,
    bool& hadaMalaPresente, vector<int>& sol, vector<int>& solMejor,
    const vector<int>& sumaRapida
) {
    if (puesto == numPuestos) {
        // todos los puestos asignados
        if (hadaMalaPresente) {
            if (satisfaccionActual > satisfaccionMaxima) {
                satisfaccionMaxima = satisfaccionActual;
                solMejor = sol;
                numSoluciones = 1;
                solucionEncontrada = true;
            } else if (satisfaccionActual == satisfaccionMaxima) {
                numSoluciones++;
            }
        }
        return;
    }

    for (int habitante = 0; habitante < numHabitantes; ++habitante) {
        if (!habitantes_ocupados[habitante]) {
            int satisfaccion = satisfacciones[puesto][habitante];
            if (satisfaccion < 0) continue;

            // asigna habitante a puesto
            habitantes_ocupados[habitante] = true;
            sol[puesto] = habitante;
            satisfaccionActual += satisfaccion;
            if (puesto == habitante) contSupersticiosos++;
            bool hadaEstaba = hadaMalaPresente;
            if (habitante == numHadaMala) hadaMalaPresente = true;

            // Poda supersticiosos y optimalidad
            if (contSupersticiosos <= numPuestos/3 && satisfaccionActual + sumaRapida[puesto] >= satisfaccionMaxima) {
                vueltaAtras(puesto + 1, numHabitantes, numPuestos, numHadaMala,
                            satisfacciones, solucionEncontrada, numSoluciones,
                            satisfaccionActual, satisfaccionMaxima,
                            habitantes_ocupados, contSupersticiosos,
                            hadaMalaPresente, sol, solMejor, sumaRapida);
            }

            if (puesto == habitante) contSupersticiosos--;
            if (habitante == numHadaMala) hadaMalaPresente = hadaEstaba;
            satisfaccionActual -= satisfaccion;
            sol[puesto] = -1;
            habitantes_ocupados[habitante] = false;
        }
    }
}

bool resuelveCaso() {   
    int numHabitantes, numPuestos, numHadaMala; //n, m, hada
    cin >> numHabitantes >> numPuestos >> numHadaMala;
    if(numHabitantes == 0) return false;

    vector<vector<int>> satisfacciones(numPuestos, vector<int>(numHabitantes));
    vector<int> maximos (numPuestos, INT_MIN);
    for(int i = 0; i < numPuestos; i++){
        for(int j = 0; j < numHabitantes; j++){
            cin >> satisfacciones[i][j];
        }
    }

    vector<int> rapido(numPuestos, INT_MIN);
    for (int i = 0; i < numPuestos; ++i)
        for (int j = 0; j < numHabitantes; ++j)
            rapido[i] = max(rapido[i], satisfacciones[i][j]);

    vector<int> sumaRapida(numPuestos, 0);
    sumaRapida[numPuestos-1] = 0;
    for (int i = numPuestos-2; i >= 0; --i)
        sumaRapida[i] = sumaRapida[i+1] + rapido[i+1];


    vector<int> cota(numPuestos, 0);
    for(int i = numPuestos - 2; i >= 0; i--){
        cota[i] = cota[i + 1] + maximos[i + 1];
    }
    // Inicialización de variables para backtracking
    bool solucionEncontrada = false;
    int numSoluciones = 0;
    int satisfaccionActual = 0;
    int satisfaccionMaxima = INT_MIN;
    vector<bool> puestos_ocupados(numPuestos, false);
    int contSupersticiosos = 0;
    bool hadaMalaPresente = false;
    vector<int> sol (numPuestos, -1), solMejor(numPuestos, -1);
    int habitantes_repartidos = 0;

    // Llama al backtracking para cada posible habitante inicial
    // Tu algoritmo hace un recorrido "por habitante" (index), para lo que hay que elegir exactamente m habitantes de n
    // Así que llamamos solo con index = 0
    vueltaAtras(
        0,
        numHabitantes,
        numPuestos,
        numHadaMala,
        satisfacciones,
        solucionEncontrada,
        numSoluciones,
        satisfaccionActual,
        satisfaccionMaxima,
        puestos_ocupados,
        contSupersticiosos,
        hadaMalaPresente, 
        sol, 
        solMejor,
        sumaRapida
    );

    // Imprime el resultado según si hay solución o no
    if (solucionEncontrada && satisfaccionMaxima != INT_MIN){
        cout << satisfaccionMaxima << " " << numSoluciones << '\n';
    } else cout << "No\n";

    return true;
}




int main() {
    #ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    #endif
    while(resuelveCaso()) ;
    #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
    #endif
    return 0;
}