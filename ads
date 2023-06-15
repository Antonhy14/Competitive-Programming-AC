// AGENDA
// Jose Antonio Peguero Torres
// Raul Hernandez Dias
// Samuel Eduardo 
#include <iostream>
#include <locale.h>
#include <string>
#define personas 1
using namespace std;
int main() {
    setlocale(LC_ALL,"");
    string datos[20][6];
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
    		getline(cin,datos[i][j]);
        }
    }
	string nombreB;
	cout << "Ingrese el nombre a buscar: ";
	getline(cin,nombreB);
    for(int i=0;i<personas;i++) {
    	if(nombreB==datos[i][0]) {
			 cout<<i+1<< ". El genero de "<<datos[i][0]<<" "<<datos[i][1]<<" "<<datos[i][2]<<" es "<<datos[i][3]<<", tiene "<<datos[i][4]<<" años y su numero telefonico es "<<datos[i][5]<<endl;
    	}
    }
}
