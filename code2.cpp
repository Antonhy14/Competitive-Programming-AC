#include <iostream>
#include <iomanip>
#include <locale>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

#define fore(i, l, r) for(int i = l; i < r; ++i)
#define forx(i, r, l) for(int i = r - 1; i >= 0; --i)
#define ll long long int
#define len(x) x.length()

bool isupper(char ch) {
	return ('A' <= ch && ch <= 'Z');	
}

bool islower(char ch) {
	return ('a' <= ch && ch <= 'z');
}

char toupper(char ch) {
	return ('a' <= ch && ch <= 'z') ? ch - 32: ch;	
}

char tolower(char ch) {
	return ('A' <= ch && ch <= 'Z') ? ch + 32: ch;		
}

void stoupper(string& str) {
	fore(i, 0, len(str)) str[i] = toupper(str[i]);	
}

void stolower(string& str) {
	fore(i, 0, len(str)) str[i] = tolower(str[i]);	
}

int main() {
	setlocale(LC_ALL, "");
	
	
	
  return 0;
}
