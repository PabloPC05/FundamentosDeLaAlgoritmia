//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using par = std:: pair <int, int>;

vector<int> leerVector() {
    int size; 
    cin >> size;
    vector<int> v(size);
    for (int i = 0; i < size; ++i) {
        cin >> v[i];
    }
    return v;
}


void resuelveCaso() {
    vector<int> v = leerVector();
    int min = v.at(0), numMin = 0, numSuma = 0;
    long long int suma = 0; 
    for(int i = 0; i < v.size(); i++){
        if(v.at(i) < min){
            suma += (min * numMin);
            numSuma += numMin;
            min = v.at(i);
            numMin = 1;
        }
        else if(v.at(i) == min) numMin++;
        else{
            suma += v.at(i);
            numSuma++;
        }
    }
    cout << suma << " " << numSuma << '\n';
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
		resuelveCaso();
    }
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}