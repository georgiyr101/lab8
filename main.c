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
    puts("�������� �������:\n2. ����� ����� ������������ � ������������� ���������.\n3. �������� �������� �� ���������� �������� : ��������� �������, ��������������� �� ������� ��������� ������, ����� �������� ���� ������� � �������� ���������, �������� ������� � ����� ������� � ��� �����, ���� ���������������� ������� ����� ��������� � �������� ����� � �� ��������� �� ��������������.\n4. ������� ��� ����\n0. ����� �� ���������\n");
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

