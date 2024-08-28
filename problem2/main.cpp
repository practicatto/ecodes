#include <iostream>

using namespace std;

int productoDigitos(int x) {
    if (x == 0) return 0;
    int producto = 1;
    while (x > 0) {
        int digito = x % 10;
        if (digito != 0) {
            producto *= digito;
        }
        x /= 10;
    }
    return producto;
}

int sumaCuadradosDigitos(int x) {
    int suma = 0;
    while (x > 0) {
        int digito = x % 10;
        suma += digito * digito;
        x /= 10;
    }
    return suma;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;

        int cuentaPrimera = 0;
        int cuentaSegunda = 0;

        for (int i = a; i <= b; ++i) {
            int producto = productoDigitos(i);
            int sumaCuadrados = sumaCuadradosDigitos(i);

            if (producto > sumaCuadrados) {
                ++cuentaPrimera;
            } else if (sumaCuadrados > producto) {
                ++cuentaSegunda;
            }
        }

        cout << cuentaPrimera << " " << cuentaSegunda << "\n";
    }

    return 0;
}
