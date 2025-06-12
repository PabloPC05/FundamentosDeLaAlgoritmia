#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

bool esValida(const int& i, const bool& usada, const int& prerrequisitos,const vector<bool>& aprobadas){
    if(!usada && !aprobadas[i]){
        if(prerrequisitos >= 0) return aprobadas[prerrequisitos];
        else return true;
    } else return false;
}

bool esSolucion(const int& ects_cur, const int& ects_min){
    return ects_min <= ects_cur;
}

// Index marca el índice por el que van las aisgnaturas
void vueltaAtras(const int& longVar, const vector<bool>& aprobadas, const vector<int>& prerrequisitos, const vector<int>& ectsS, const vector<int>& costes, const int& min_ects, int& ects, int& coste, int& min_coste, bool& solucionEncontrada, vector<bool>& usadas){
    for(int i = 0; i < longVar; i++){
        // Si la asignatura está ya aprobada, o su prerequisito (si es que existe) no está aprobado, hay que descartar
        if(esValida(i, usadas[i], prerrequisitos[i], aprobadas) && ects < min_ects){
            ects += ectsS[i]; // Sumamos la cantidad de créditos de la asignatura a los créditos actuales
            coste += costes[i]; // Sumamos los costes de la asignatura a los costes actuales
            usadas[i] = true;
            if(esSolucion(ects, min_ects)){ // Si ya hemos superado el numero de créditos necesarios
                solucionEncontrada = true;
                min_coste = min(min_coste, coste); // Tomamos el minimo del coste minimo y el coste actual, para actualizarlo
            }
            vueltaAtras(longVar, aprobadas, prerrequisitos, ectsS, costes, min_ects, ects, coste, min_coste, solucionEncontrada, usadas); // Si aun no se ha alcanzado el minimo de créditos se vuelve a llamar a la funcion
            ects -= ectsS[i]; // Sumamos la cantidad de créditos de la asignatura a los créditos actuales
            coste -= costes[i]; // Sumamos los costes de la asignatura a los costes actuales
            usadas[i] = false;
        }
    }
}

void resuelveCaso(){
    int numAsignaturas, numECTSmin;
    cin >> numAsignaturas >> numECTSmin;
    vector<bool> aprobadas(numAsignaturas);
    for(int i = 0; i < numAsignaturas; i++){
        char c;
        cin >> c;
        aprobadas[i] = (c == 'A');
    }
    vector<int> prerrequisitos(numAsignaturas);
    for(int i = 0; i < numAsignaturas; i++){
        int num;
        cin >> num;
        prerrequisitos[i] = num;
    }
    vector<int> ects(numAsignaturas);
    for(int i = 0; i < numAsignaturas; i++){
        int cred;
        cin >> cred;
        ects[i] = cred;
    }
    vector<int> costes(numAsignaturas);
    for(int i = 0; i <numAsignaturas; i++){
        int coste;
        cin >> coste;
        costes[i] = coste;
    }
    int index = 0;
    int ects_cur = 0; 
    int coste = 0;
    int min_coste = INT_MAX;
    bool solucionEncontrada = false;
    vector<bool> usadas(numAsignaturas, false);
    vueltaAtras(numAsignaturas, aprobadas, prerrequisitos,ects,costes, numECTSmin, ects_cur, coste, min_coste, solucionEncontrada, usadas);
    if(solucionEncontrada) cout << min_coste << '\n';
    else cout << "NO\n";
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