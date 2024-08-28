#include <iostream>

int productoDigitos(int x) {
    int producto = 1;
    while (x > 0) {
        int digito = x % 10;
        producto *= digito;
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
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    while (n--) {
        int a, b;
        std::cin >> a >> b;

        int cuenta_primera = 0;
        int cuenta_segunda = 0;

        for (int i = a; i <= b; ++i) {
            int producto = productoDigitos(i);
            int suma_cuadrados = sumaCuadradosDigitos(i);

            if (producto > suma_cuadrados) {
                ++cuenta_primera;
            } else if (suma_cuadrados > producto) {
                ++cuenta_segunda;
            }
        }

        std::cout << cuenta_primera << " " << cuenta_segunda << "\n";
    }

    return 0;
}
