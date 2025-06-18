#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int posicion(vector<int>const& a, int k) {
	int puntuacion = a[0]; int pmax = a[0]; int posicion = 0; int cont = 1; int maximo = a[0]; int p = 0;
	for (int i = 1; i < a.size();i++) {
		if (cont < k) { 
			cont++; 
			puntuacion += a[i];
			if (cont < k) {
				maximo = max(maximo, a[i]); 
				p = i;
			}
		}
		if (cont == k) {
			if (a[i] > maximo) {
				maximo = a[i];
				pmax = puntuacion;
				posicion = i - cont + 1;
				p = i;
			}
			else if (a[i] == maximo) {
				p = i;
				if (pmax <= puntuacion) {
					pmax = puntuacion;
					posicion = i - cont + 1;
				}
				
			}
			else if (p >= (i - cont + 1) && pmax <= puntuacion) {
				pmax = puntuacion;
				posicion = i - cont + 1;
			}
			puntuacion -= a[i-cont + 1];
			--cont;
		}
	}
	return posicion;
}

bool resuelveCaso() {
	int elementos; int l;
	cin >> elementos; cin >> l;
	if (elementos == 0 && l == 0)return false;
	vector<int>nums(elementos);
	for (int i = 0; i < elementos;i++)
		cin >> nums[i];
	int pos = 0;
	pos = posicion(nums, l);
	cout << pos << '\n';
	return true;
}

int main() {
	while(resuelveCaso());
}