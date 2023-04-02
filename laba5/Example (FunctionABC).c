#include <stdio.h>  // Библиотека для работы с функциями ввода-вывода
#include <locale.h> // Библиотека для указания локации (региональной кодировки)

void a();
void b();
void c();

int main()
{
	setlocale(LC_ALL, "Rus");

	printf("main() CALL   ->\n");
	a();
	printf("tmain() RETURN <-\n");

	return 0;
}

void a() {
	printf("\t\t   a() CALL   ->\n");
	b();
	printf("\t\t   a() RETURN <-\n");
}

void b() {
	printf("\t\t\t\t   b() CALL   ->\n");
	c();
	printf("\t\t\t\t   b() RETURN <-\n");
}

void c() {
	printf("\t\t\t\t\t\t   c() CALL   ->\n");
	printf("\t\t\t\t\t\t   c() RETURN <-\n");
}




/*
Упражнение 1.

Перепешите представленный пример в виде рекурсивного вызова функции А()
с наперёд заданной глубиной рекурсии (запрашивать у пользователя).

*/