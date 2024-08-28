#include <iostream>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int tecnica, estilo, presentacion;
  std::cin >> tecnica >> estilo >> presentacion;

  int suma = tecnica + estilo + presentacion;
  std::cout << suma << '\n';

  return 0;
}
