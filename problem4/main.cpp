#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int numeroParticipantes;
    cin >> numeroParticipantes;

    int numeroPatrones = numeroParticipantes / 2;

    vector<string> patrones(numeroPatrones);
    for (int i = 0; i < numeroPatrones; ++i) {
        cin >> patrones[i];
    }

    unordered_map<string, string> mitadAMNombre;
    vector<pair<string, string>> personas(numeroParticipantes);

    for (int i = 0; i < numeroParticipantes; ++i) {
        string mitad, nombre;
        cin >> mitad >> nombre;
        mitadAMNombre[mitad] = nombre;
    }

    vector<pair<string, string>> parejasResultado;

    for (const auto& patron : patrones) {
        int longitudMitad = patron.size() / 2;
        string primeraMitad = patron.substr(0, longitudMitad);
        string segundaMitad = patron.substr(longitudMitad);

        if (mitadAMNombre.find(primeraMitad) != mitadAMNombre.end() &&
            mitadAMNombre.find(segundaMitad) != mitadAMNombre.end()) {
            string nombrePrimeraMitad = mitadAMNombre[primeraMitad];
            string nombreSegundaMitad = mitadAMNombre[segundaMitad];
            parejasResultado.push_back({nombrePrimeraMitad, nombreSegundaMitad});
        }
    }

    sort(parejasResultado.begin(), parejasResultado.end());

    for (const auto& pareja : parejasResultado) {
        cout << pareja.first << " " << pareja.second << endl;
    }

    return 0;
}
