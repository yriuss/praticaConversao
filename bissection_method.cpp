#include <iostream>
#include <math.h>

using namespace std;
typedef double(*Function)(double);


double MyFunction(double x){
	double C = 4700*10^-6;
	double R = 789.34;
	double omega = 2*M_PI*60;
	double theta = 0.499772408013*M_PI;
	
	double y = sin(x) - sin(theta) * exp(-(2*M_PI+x-theta)/(omega*R*C));
	return y;
}

void BissectionMethod(Function function, double x0, double x1, double error){
	//arranja os valores em ordem
	
	double y0 = function(x0);
	double y1 = function(x1);
	
	if(y1 < y0){
		double aux = x0;
		x0 = x1;
		x1 = aux;
	}
	double xn;//ponto médio
	double yn = function(xn);
	int i = 0;
	double actual_error = abs(yn);
	while(actual_error > error){
		if(i > 10000)
		{
			cout << "[Warning]: Numero de iteracoes maior que "<< i << endl;
			break;
		}
		xn = (x0 + x1)/2;
		y0 = function(x0);
		y1 = function(x1);
		yn = function(xn);
		cout<<"y0 =" << y0 << "; y1 =" << y1 << "; yn =" << yn << endl;
		if(yn < 0 && y1 > 0){
			x0 = xn;
		}else{
			if(y0 < 0 && yn > 0){
				x1 = xn;
			}
		}		
		actual_error = abs(yn);
		
		i++;
	}
	
	cout<<"O ponto desejado eh "<< xn << " com erro de " << actual_error << endl;
}



int main() {
	double x0 = 0, x1 = 0.5*M_PI, error= 0.00001;
	
	Function function = MyFunction;
	
	
	BissectionMethod(function, x0, x1, error);
	
	return 0; 
}
