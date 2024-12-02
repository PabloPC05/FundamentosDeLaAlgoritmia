//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;
using matriz = vector<vector<int>>;


int diagonalPrincipal(matriz m, int ini_filas, int ini_cols, int dim){
    int diagonal = 1;
    for(int i = 0; i < dim; i++){
        diagonal *= m.at(ini_filas+i).at(ini_cols+i);
    }
    return diagonal;
}

int diagonalSecundaria(matriz m, int ini_filas, int ini_cols, int dim){
    int diagonalSecun = 1;
    for(int i = 0; i < dim; i++){
        diagonalSecun *= m.at(ini_filas+i).at(ini_cols-i);
    }
    return diagonalSecun;
}

int esEquidiagonal(matriz m, int ini_filas, int ini_cols, int dim){
    if(dim <= 1) return m.at(0).at(0);
    int newDim = dim/2;
    //Calcular si la matriz derecha superior es equidiagonal
    bool e1 = esEquidiagonal(m, ini_filas, ini_cols, newDim) != -1;
    //Calcular si la matriz derecha inferior es equidiagonal
    bool e2 = esEquidiagonal(m, ini_filas+newDim, ini_cols, newDim) != -1;
    //Calcular si la matriz izquirda superior es equidiagonal
    bool e3 = esEquidiagonal(m, ini_filas, ini_cols+newDim, newDim) != -1;
    //Calcular si la matriz izquierda inferior es equidiagonal
    bool e4 = esEquidiagonal(m, ini_filas+newDim, ini_cols+newDim, newDim) != -1;
    int diagonal = diagonalPrincipal(m, ini_filas, ini_cols, dim); 
    int diagonalSecun = diagonalSecundaria(m, ini_filas, ini_cols+dim-1, dim);
    if(diagonal == diagonalSecun && e1 && e2 && e3 && e4) return diagonal; 
    return -1;
}

void resuelveCaso(){
    int dim;
    cin >> dim; 
    matriz m(dim, vector<int>(dim));
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            cin >> m.at(i).at(j);
        }
    }
    int ini_filas = 0, ini_cols = 0;
    int res = esEquidiagonal(m, ini_filas, ini_cols, dim);
    if(res != -1) cout << "SI " << res << endl;
    else cout << "NO" << endl; 
}


	
int main() {
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
    system("PAUSE");
#endif
    return 0;
}