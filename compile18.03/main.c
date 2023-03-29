#include <stdio.h>

int main(){
    char parameter[] = "";

    // Ask the user to type a parameter
    printf("Type a parameter: \n");

    // Get and save the parameter the user types
    scanf("%s", &parameter);

    printf("Hello, %s!", parameter);
    return 0;

}

/*
Задания:

    1. Скомпилируйте программу через терминал с выдачей файлов промежуточных этапов.
        (Preprocess -> Compile -> Assemble -> Link, см. help для gcc) 
        Что происходит на каждом этапе?

    2. Скомпилируйте программу в VS Code. 

    3. Сломайте эту программу.
        Удалите последовательно из кода программы символы: ;, ), {
        И попробуйте выполнить программу. 
        Проанализируйте ошибки на которые укажет компилятор
    
    4. Доработайте программу
        Обеспечьте возможность передачи аргумента при запуске Task.exe из терминала
        Используqте аргумент как имя для приветствия 
        (вместо "Hello, World!", должно быть "Hello, <Параметр>!")

*/