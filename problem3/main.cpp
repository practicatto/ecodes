#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

bool esPrimo(int numero) {
    if (numero <= 1) return false;
    if (numero <= 3) return true;
    if (numero % 2 == 0 || numero % 3 == 0) return false;
    for (int i = 5; i * i <= numero; i += 6) {
        if (numero % i == 0 || numero % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> puntuaciones(N);

    for (int i = 0; i < N; ++i) {
        cin >> puntuaciones[i];
    }

    unordered_set<int> sumasPosibles;
    sumasPosibles.insert(0);

    for (int puntuacion : puntuaciones) {
        vector<int> nuevasSumas;
        for (int suma : sumasPosibles) {
            nuevasSumas.push_back(suma + puntuacion);
        }
        for (int nuevaSuma : nuevasSumas) {
            sumasPosibles.insert(nuevaSuma);
        }
    }

    int maximoPrimo = 0;
    for (int suma : sumasPosibles) {
        if (suma > maximoPrimo && esPrimo(suma)) {
            maximoPrimo = suma;
        }
    }

    cout << maximoPrimo << "\n";
    return 0;
}
