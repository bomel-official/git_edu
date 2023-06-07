#include <stdio.h>
#include <math.h>
#include <locale.h>


#define ARR_SIZE 6000

double CalcVa(double rA, double mu, double rP);
double CalcVw(double rA, double omegaE, double fi);
double CalcRp(double omegaE, double rA, double i, double mu);

int main() {
	setlocale(LC_ALL, "Russian");

	double mu = 398600.4;
	double omegaE = 7.2921159 * pow(10, -5);
	double i = 63.4;
	double rA = 45000;

	double rP = CalcRp(omegaE, rA, i, mu);

	FILE *my_file = fopen("data.csv", "w");
    fprintf(my_file, "rA;Va;Vw\n");

	for (int j = 1; j < ARR_SIZE; j++) {
		int rA = j * 10;

		double cvw = CalcVw(rA, omegaE, i);
		double cva = CalcVa(rA, mu, rP);

		char str[200];

		if (cvw <= cva) {
            snprintf(str, 200, "%d;%.2f;%.2f\n", rA, cva, cvw);
		} else {
            snprintf(str, 200, "%d;%.2f;None\n", rA, cva);
		}
		fprintf(my_file, str);
	}

	fclose(my_file);
	return 1;
}


double CalcVa(double rA, double mu, double rP) {
	return sqrt(2 * mu * rP / (rA * (rA + rP)));
}

double CalcVw(double rA, double omegaE, double i) {
	return omegaE * rA * cos(i);
}

double CalcRp(double omegaE, double rA, double i, double mu) {
	return pow(omegaE, 2) * pow(rA, 4) * pow(cos(i), 2) / (2 * mu - pow(omegaE, 2) * pow(rA, 3) * pow(cos(i), 2));
}