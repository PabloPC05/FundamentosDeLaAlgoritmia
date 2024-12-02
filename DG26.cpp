//Pablo Pardo Cotos

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

vector<int> merge(vector<int> v1, vector<int> v2){
    vector<int> returnVector;
    int pivote = 0;
    int i = 0, j = 0; 
    while(i < v1.size() && j < v2.size()){
        if(v1.at(i) < v2.at(j)){ 
            returnVector.push_back(v1.at(i));
            i++;
        }
        else{
           returnVector.push_back(v2.at(j)); 
           j++;
        }
    }
    if(i != v1.size()){
        for(i < v1.size(); i++;){
            returnVector.push_back(v1.at(i));
        }
    }
    if(j != v2.size()){
        for(j < v2.size(); j++;){
            returnVector.push_back(v2.at(j));
        }
    }
    return returnVector;
}

vector<int> mergeSort(vector<int> v){
    int N = v.size(); 
    if(N <= 1) return v;
    else{
        int mitad = N/2;
        vector<int> v_right(v.begin()+mitad+1, v.end());
        vector<int> v_left(v.begin(), v.begin()+mitad);
        v_right = mergeSort(v_right);
        v_left = mergeSort(v_left);
        if(v_left.at(v_left.size()) < v_right.at(0)){
            
        }
    }
    
}

bool resuelveCaso(){
    int N;
    cin >> N;
    if(!cin) return false;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
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