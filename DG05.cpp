//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> leerVector(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    return v;
}

bool seCumple(vector<int> v, int pos){
    if(v.size() <= pos+1) return true;
    int min = v.at(pos+1), max = v.at(pos); 
    for(int i = 0; i < v.size(); i++){
        //[0, pos]
        if(i <= pos){
            if(v.at(i) > max) max = v.at(i);
        }
        //(pos, v.size()-1]
        else{
            if(v.at(i) < min) min = v.at(i);
        }
    }
    return max < min;
}

void resuelveCaso() {
    int vectorSize, pos; 
    cin >> vectorSize >> pos;
    vector<int> v = leerVector(vectorSize);
    if(seCumple(v, pos)) cout << "SI\n";
    else cout << "NO\n";
}
	
int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        //Precondicion = {N >= 0 && 0 <= pos < N}
        //Invariante = {0 <= i <= N && max = max(v[0, pos]) && min = min(v[pos+1, N-1])}
        //Funcion cota = {N - i}
		resuelveCaso();
        //Postcondicion = max(v[0, pos]) < min(v[pos+1, N-1])
    }
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}