//Pablo Pardo
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void PicosYValles(vector<int> const& v, int& picos, int& valles) {
    for (int i = 1; i < v.size() - 1; i++) {
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) picos++;
        else if (v[i] < v[i - 1] && v[i] < v[i + 1]) valles++;
    }
}

vector<int> leerCaso() {
    int size;
    cin >> size;
    vector<int> returnValue(size);
    for (int i = 0; i < size; i++) {
        cin >> returnValue[i];
    }
    return returnValue;
}

void resuelveCaso() {
    int picos = 0, valles = 0;
    PicosYValles(leerCaso(), picos, valles);
    cout << picos << " " << valles << '\n';
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    unsigned int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}

