//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

struct tJugador{
    string nombre;
    int canicas;
};

tJugador ganador(vector<tJugador> jugadores){
    if(jugadores.size() == 2){
        if(jugadores.at(0).canicas >= jugadores.at(1).canicas){ 
            jugadores.at(0).canicas += jugadores.at(1).canicas/2; 
            return jugadores.at(0); 
        }
        else{ 
            jugadores.at(1).canicas += jugadores.at(0).canicas/2; 
            return jugadores.at(1);
        }
    }
    int mitad = jugadores.size()/2;
    tJugador ganador1 = ganador(vector<tJugador>(jugadores.begin(), jugadores.begin() + mitad));
    tJugador ganador2 = ganador(vector<tJugador>(jugadores.begin() + mitad, jugadores.end()));
    if(ganador1.canicas >= ganador2.canicas){ 
        ganador1.canicas += ganador2.canicas/2;
        return ganador1;
    }
    else{ 
        ganador2.canicas += ganador1.canicas/2;
        return ganador2;
    }
}

bool resuelveCaso(){
    int N; 
    cin >> N; 
    if(!cin) return false;
    vector<tJugador> jugadores(N);
    for(int i = 0; i < N; i++){
        cin >> jugadores[i].nombre >> jugadores[i].canicas; 
    }
    tJugador Ganador = ganador(jugadores);
    cout << Ganador.nombre << ' ' << Ganador.canicas << endl;
    return true;
}


	
int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    // Resolvemos
    while(resuelveCaso());
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}