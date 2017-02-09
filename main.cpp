#include <bits/stdc++.h>
using namespace std;

class zespolona{
	public:
	double re;
	double im;
	
	
	zespolona(double a, double b){
		re = a;
		im = b;
	}
	
	double modul(){
		return pow(re*re + im*im, 0.5);
	}
	
	void krok();
	
};



zespolona c(-0.1, 0.65);

void zespolona::krok(){
		double a = re, b = im;
		re = a*a - b*b + c.re;
		im = 2*a*b+ c.im;
	}

int MAX_ITER = 300;


bool test(zespolona z);

int SIZE_X = 1000;
int SIZE_Y = 1000;

int main(){
	fstream plik;
	plik.open( "test.pbm", ios::out );
	plik << "P1" << endl;
	plik << SIZE_X << " " << SIZE_Y << endl;
	double a;
	double b;
	double a0 = -2;
	double b0 = -2;
	
	for(int i=0; i < SIZE_X; ++i){
		a=a0+4.0*(double)i/SIZE_X;
		for(int j = 0; j < SIZE_Y; ++j){
			b=b0+4.0*(double)j/SIZE_Y;
			zespolona z(a,b);
			bool test = true;
			z.krok();
			for(int k=0; k < MAX_ITER; ++k){
				if(z.modul() >= 2) {test = false; break;}
				z.krok();
			}
			if(test) plik<<"1";
			else plik<<"0";
		}
		plik << endl;
	}
	
	plik.close();
	return 0;
}
