//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


bool resuelveCaso() {
    int desnivelPermitido = 0, size = 0; 
    cin >> desnivelPermitido >> size;
    if(!cin) return false;
    vector<int> v(size);
    for (int i = 0; i < size; ++i) {
        cin >> v[i];
    } 
    bool seCumple = true;
    int index = 0, i; 
    for(i = 0; i < v.size()-1 && seCumple; i++){
        // Si es estrictamente creciente se guarda durante cuantos indices lo ha sido
        if(v.at(i) < v.at(i+1)){
            index++;
        }
        else{
            seCumple = (v.at(i) - v.at(i - index) <= desnivelPermitido);
            index = 0;
        }
    }
    if(seCumple && (v.at(i) - v.at(i - index) <= desnivelPermitido)) cout << "APTA\n";
    else cout << "NO APTA\n";
    return true;
}
	
int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while(resuelveCaso());
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}