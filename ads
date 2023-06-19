// AGENDA
// Jose Antonio Peguero Torres
// Raul Hernandez Dias
// Samuel Eduardo Garcia Diaz
#include <iostream>
#include <locale.h>
#include <string>
using namespace std;
int main() {
	setlocale(LC_ALL,"");
	int personas = 3;
    string datos[personas][6];
    // Lectura de datos
    for(int i=0;i<personas;i++) {
        cout << "Persona " << i+1 << ": \n";
        for(int j=0;j<6;j++){
    		switch(j) {
    			case 0:
    				cout << "Nombre: ";
    				break;
    			case 1:
    				cout << "Apellido Paterno: ";
    				break;
    			case 2:
    				cout << "Apellido Materno: ";
    				break;
    			case 3:
    				cout << "Sexo: ";
    				break;
    			case 4:
    				cout << "Edad: ";
    				break;
    			case 5:
	    			cout << "Número Telefonico: ";
	    			break;
    		}
    		cin >> datos[i][j];
        }
    }
    // Busqueda del usuario
    string op ="Si",nombreB;
    int ok;
    while (op=="Si") {
        ok=0;
    	cout << "Ingrese el nombre a buscar: ";
    	cin >> nombreB;
        for(int i=0;i<personas;i++) {
        	// Impresion de los datos
        	if(nombreB==datos[i][0]) {
	    		cout<<i+1<< ". El genero de "<<datos[i][0]<<" "<<datos[i][1]<<" "<<datos[i][2]<<" es "<<datos[i][3]<<", tiene "<<datos[i][4]<<" años y su numero telefonico es "<<datos[i][5]<<endl;
        	    ok=1;
        	}
        }
        // Si no se encontro
        if (ok==0) cout << "Nombre no encontrado, revise que este escrito correctamente.\n";
        cout << "¿Deseas hacer otra busqueda? Si/No "; 
		cin >> op;
    }
    cout << "Fin del programa.";
}
