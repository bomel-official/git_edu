#include <stdio.h>  // Библиотека для работы с функциями ввода-вывода
#include <locale.h> // Библиотека для указания локации (региональной кодировки)
#include <math.h> // Библиотека с математическими функциями


int diadonal_higher_right(double, double); // Возващает True, если точка находится выше и правее, чем линия y = x, или совпадает с ней
int rev_diadonal_higher_right(double, double); // Возващает True, если точка находится выше и правее, чем линия y = -x, или совпадает с ней
int diadonal_higher_right_not_included_line(double, double); // Возващает True, если точка находится выше и правее, чем линия y = x
int rev_diadonal_higher_right_not_included_line(double, double); // Возващает True, если точка находится выше и правее, чем линия y = -x
int vertical_right(double, double, double); // Возващает True, если точка находится правее, чем линия x = x0, или совпадает с ней
int horizontal_higher(double, double, double); // Возващает True, если точка находится выше, чем линия y = y0, или совпадает с ней
int vertical_right_not_included_line(double, double, double); // Возващает True, если точка находится правее, чем линия x = x0
int horizontal_higher_not_included_line(double, double, double); // Возващает True, если точка находится выше, чем линия y = y0
int in_round_not_included_line(double, double, double, double, double); // Возващает True, если точка находится внутри окружности (x - x0)^2 + (y - y0)^2 = r, или совпадает с ней

int a(double, double); // Функция для решения задачи А
int b(double, double); // Функция для решения задачи Б


void main() {
	setlocale(LC_ALL, "Rus");

	// Решение А
	// Точка проверяющая пустую зону
	int x1 = 1;
	int y1 = 1; 

	// Точка проверяющая зону в правом верхнем углу
	int x2 = 5;
	int y2 = 5;

	// Точка проверяющая зону ниже линии y = 3, и внутри зоны ниже линии y = -x
	int x3 = -1;
	int y3 = -1;

	// Точка проверяющая зону выше линии y = 3, но внутри зоны ниже линии y = -x
	int x4 = -5;
	int y4 = 4;

	printf("For point x = %d, y = %d the result for func A = %d\n", x1, y1, a(x1, y1));
	printf("For point x = %d, y = %d the result for func A = %d\n", x2, y2, a(x2, y2));
	printf("For point x = %d, y = %d the result for func A = %d\n", x3, y3, a(x3, y3));
	printf("For point x = %d, y = %d the result for func A = %d\n", x4, y4, a(x4, y4));

	// Решение B
	// Точка проверяющая заполненную зону
	int x5 = 1;
	int y5 = 1; 

	// Точка проверяющая зону ниже линий x = 0 и y = 0, не входящую в окружность
	int x6 = -1;
	int y6 = -1;
	
	// Точка проверяющая зону в окружности
	int x7 = 5;
	int y7 = 5;
	
	printf("For point x = %d, y = %d the result for func B = %d\n", x5, y5, b(x5, y5));
	printf("For point x = %d, y = %d the result for func B = %d\n", x6, y6, b(x6, y6));
	printf("For point x = %d, y = %d the result for func B = %d\n\n", x7, y7, b(x7, y7));


	int ux;
	int uy;
	printf("Input x: ");
	scanf("%d", &ux);

	printf("Input y: ");
	scanf("%d", &uy);
	
	printf("For point x = %d, y = %d the result for func A = %d\n", ux, uy, a(ux, uy));
	printf("For point x = %d, y = %d the result for func B = %d\n", ux, uy, b(ux, uy));
}

int a(double x, double y) {
	int res = -1;
	res = (!rev_diadonal_higher_right_not_included_line(x, y) && !horizontal_higher(x, y, 3)) || (vertical_right_not_included_line(x, y, 4) && horizontal_higher_not_included_line(x, y, 3));
	return res;
}

int b(double x, double y) {
	int res = -1;
	res = (vertical_right(x, y, 0) && horizontal_higher(x, y, 0) && !in_round_not_included_line(x, y, 5, 5, 5));
	return res;
}


int diadonal_higher_right(double x, double y) {
	int res = -1;
	res = (y >= x);
	return res;
}

int rev_diadonal_higher_right(double x, double y) {
	int res = -1;
	res = (y >= -x);
	return res;
}

int diadonal_higher_right_not_included_line(double x, double y) {
	int res = -1;
	res = (y > x);
	return res;
}

int rev_diadonal_higher_right_not_included_line(double x, double y) {
	int res = -1;
	res = (y > -x);
	return res;
}

int vertical_right(double x, double y, double x0) {
	int res = -1;
	res = (x >= x0);
	return res;
}

int horizontal_higher(double x, double y, double y0) {
	int res = -1;
	res = (y >= y0);
	return res;
}

int vertical_right_not_included_line(double x, double y, double x0) {
	int res = -1;
	res = (x > x0);
	return res;
}

int horizontal_higher_not_included_line(double x, double y, double y0) {
	int res = -1;
	res = (y > y0);
	return res;
}

int in_round_not_included_line(double x, double y, double x0, double y0, double r) {
	int res = -1;
	res = (pow(x - x0, 2) + pow(y - y0, 2)) < pow(r, 2);
	return res;
}