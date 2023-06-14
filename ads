#include <iostream>
#include <locale.h>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL,"");
    string datos[20][6];
    for(int i=0;i<3;i++) {
        cout << "Persona " << i+1 << ": \n";
        cout << "Nombre: "; cin >> datos[i][0];
        cout << "Apellido Paterno: "; cin >> datos[i][1];
        cout << "Apellido Materno: "; cin >> datos[i][2];
        cout << "Sexo: "; cin >> datos[i][3];
        cout << "Edad: "; cin >> datos[i][4];
        cout << "Teléfono: "; cin >> datos[i][5];
    }
    cout<<"El genero de "<<datos[0][0]<<" "<<datos[0][1]<<" "<<datos[0][2]<<" es "<<datos[0][3]<<", tiene "<<datos[0][4]<<" años y su numero telefonico es "<<datos[0][5];
}
