#include <iostream>
#include <vector>

void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void ordenarBurbuja(std::vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            
            if (arr[j] > arr[j + 1]) {
                intercambiar(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    std::vector<int> arreglo = {64,34,25,12,22,11,90,10,82,46,94,2,6,8,38,42,48,92,96,98,90,20,24,28,5,68,72,74,78,70};

    std::cout << "original:" << std::endl;
    for (int i = 0; i < arreglo.size(); i++) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;

    ordenarBurbuja(arreglo);

    std::cout << "ordenado:" << std::endl;
    for (int i = 0; i < arreglo.size(); i++) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
