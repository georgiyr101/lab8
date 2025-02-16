#include <stdio.h>
#include "functions.h"
#include <locale.h>
#include <conio.h>


int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    const char* filename = argv[1];
    fillFile(filename);
    setlocale(LC_ALL, "russian");
    puts("Выберите задание:\n2. Найти сумму минимального и максимального элементов.\n3. Занулить элементы по следующему принципу : начальный элемент, затемсдвинуться на столько элементов вправо, какое значение было указано в ячейкедо зануления, занулить элемент в новой позиции и так далее, пока указательтекущей позиции файла находится в пределах файла и не указывает на нулевойэлемент.\n4. Удалить все нули\n0. Выйти из программы\n");
    while (1)
    {
        char task = _getch();
        if (task == '2') findMinMaxSum(filename);
        else if (task == '3') {
            zeroElements(filename);
            printFile(filename);
        }
        else if (task == '4') {
            removeZeros(filename);
            printFile(filename);
        }
        else if (task == '0') return 0;
        puts(" ");
    }

    return 0;
}

