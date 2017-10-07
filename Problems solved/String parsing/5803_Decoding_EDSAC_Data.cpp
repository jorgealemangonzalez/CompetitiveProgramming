#include <iostream>
#include <string>
using namespace std;

string info = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV";

string fraction(char prefix, unsigned int memoria, char suffix) {
	int pos;
	bool esPositivo;
	unsigned short number;
	long long resultado = 0;
	// Valor mas pequeño en el que se van incrementando numeros sucesivamente
	long long step = 152587890625;
	string res;
	for(pos = 0; pos < info.size();++pos) {
		if(prefix == info[pos]) break;
	}
	if(pos >= 0x10) {
		number = pos-0x10;
		esPositivo = false;
	}
	else {
		number = pos;
		esPositivo = true;
	}
	// Ya tengo los 5 bits del opcode.
	number <<= 12;
	number += (memoria << 1);

	// suffix puede ser F o D
	if(suffix == 'D') number++;

	// CASO POSITIVO
	if(esPositivo) {
		for(int i = 1; i <= 16; ++i) {
			if((number & 1) == 1) {
				resultado += step;
			}
			number >>= 1;
			step <<= 1;
		}
	}
	// CASO NEGATIVO
	else {
		number--;
		for(int i = 1; i <= 16; ++i) {
			if((number & 1) == 0) {
				resultado += step;
			}
			number >>= 1;
			step <<= 1;
		}
		// GUARDAR EL RESULTAT
	}
	// GUARDAR RESULTADO POSITIVO, CON 16 MAXIMO, 1 MINIMO
	if(esPositivo) res = "0." + string(16-(to_string(resultado).size()),'0').append(to_string(resultado));		 
	else res = "-0." + string(16-(to_string(resultado).size()),'0').append(to_string(resultado)); 
	// CASO EXTREMOS: Si el resultado es -0.0000000000000000 pasarlo a -1.0
	if(res == "-0.0000000000000000") res = "-1.0";

	//res.erase(res.find_last_not_of('0') +1, std::string::npos);
	// ELIMINO LOS TRAILING ZEROS (sacado de stack)
	else {
		if(esPositivo) {
			for(int i = 17; i > 2; i--) {
				if(res[i] == '0') res[i] = '\0';
				else break;
			}
		}
		else {
			for(int i = 18; i > 3; i--) {
				if(res[i] == '0') res[i] = '\0';
				else break;
			}
		}
	}
	return res;
}

int main() {
	// 5 bit opcode
	// 11 bit memory position
	// 1 bit fullword/double word
	// ADD: 11100
	// SUBSTRACT: 01100
	// PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV
	// P = 00000 | Q = 00001 | ... | V = 11111
	int P;
	cin >> P;
	while(P--) {
		int n;
		char c;
		unsigned int d;
		char s;
		cin >> n >> c >> d >> s;
		cout << n << " " << fraction(c,d,s);
		if(P) cout << endl;
	}
}