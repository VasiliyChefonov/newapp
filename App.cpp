// Massiv.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale.h>
#include "conio.h"
#include <clocale>
#include "stdlib.h"
#include "time.h"

void output(int stroka, int stolb, float **massiv)//����� ������� �� �����
{

	for (int i = 0; i < stroka; i++)
	{
		printf("\n(%d) ", i);
		for (int g = 0; g < stolb; g++)
		{

			printf("|%.2f| ", massiv[i][g]);
			printf("     ");

		}
		printf("\n");
	}

}

float work(int stroka, int stolb, float **massiv) //massive's sorting
{
	float x;
	printf("\n ������� ����������... \n");
	for (int i = 0; i <stroka; i++)
	{
		for (int g = stolb - 1; g >= 0; g--)
		{
			for (int j = 0; j< g; j++)
			{
				if (massiv[i][j] > massiv[i][j + 1])
				{
					x = massiv[i][j];
					massiv[i][j] = massiv[i][j + 1];
					massiv[i][j + 1] = x;
				}
			}
		}
	}
	return **massiv;
}



float random_massiv(int stroka, int stolb, float **massiv)//filling in massive with random numbers
{

	srand(time(NULL));
	for (int i = 0; i < stroka; i++)
	{
		for (int g = 0; g < stolb; g++)
		{

			massiv[i][g] = rand();

		}

	}
	return **massiv;
}

float write_massiv(int stroka, int stolb, float **massiv)//filling in massive by hands
{
	float element;
	for (int i = 0; i < stroka; i++)
	{
		for (int g = 0; g < stolb; g++)
		{
			printf("\n ������� ������� ������� � [%d] [%d]: ", i, g);
			scanf("%f", &element);
			massiv[i][g] = element;

		}

	}
	return **massiv;
}

void menu()//user's menu
{
	int int_m, int_m1, stroka = 0, stolb = 0;
	float **massiv = NULL;



	do
	{
		printf("\n\t __���� �����������__\n");
		printf("1. ���� ������ \n");
		printf("2. ��������� ������ \n");
		printf("3. ����� ���������� �� ����� \n");
		printf("4. ����� \n");

		printf("\n \t ������� ����� ����: ");
		scanf("%d", &int_m);
		switch (int_m)
		{
		case 1:
			if (massiv != NULL)
			{
				for (int i = 0; i < stroka; i++)
				{
					delete[] massiv[i];
				}
				delete[] massiv;
			}

			do
			{
				printf("\n ������� ���������� ����� � �������: ");
				scanf("%d", &stroka);
				if (stroka <= 0)
					printf("\n\t__���������� ����� �� ����� ���� <= 0!__\n");
			} while (stroka <= 0);
			do
			{
				printf("\n ������� ���������� �������� � �������: ");
				scanf("%d", &stolb);
				if (stolb <= 0)
					printf("\n\t__���������� �������� �� ����� ���� <= 0!__\n");
			} while (stolb <= 0);

			massiv = new float*[stroka];
			for (int i = 0; i < stroka; i++)
			{
				massiv[i] = new float[stolb];
			}
			do
			{
				printf("\n 1. ��������� ������ ���������� �������\n");
				printf("\n 2. ������ ����� ��������������\n");
				printf("\n \t ������� ����� ����: ");
				scanf("%d", &int_m1);
				switch (int_m1)
				{
				case 1:
					**massiv = random_massiv(stroka, stolb, massiv);
					break;
				case 2:
					**massiv = write_massiv(stroka, stolb, massiv);
					break;

				default:
					printf("\t\n__�� ���������� ������ ������ ����!__\n");
				}
			} while (int_m1 < 1 || int_m1 > 2);
			break;
		case 2:
			if (massiv == NULL)
			{
				printf("\n\t__������� ������� �������� ��������� �������!__\n");
			}
			else
			{
				**massiv = work(stroka, stolb, massiv);
			}
			break;
		case 3:
			if (massiv == NULL)
			{
				printf("\n\t__������� ������� �������� ��������� �������!__\n");
			}
			else
			{
				output(stroka, stolb, massiv);
			}
			break;
		case 4:

			if (massiv != NULL)
			{
				for (int i = 0; i < stroka; i++)
				{
					delete[] massiv[i];
				}
				delete[] massiv;
			}
			break;
		default:
			printf("\t\n__�� ���������� ����� ������ ����!__\n");
		}
	} while (int_m != 4);
	return;
}




int _tmain(int argc, _TCHAR* argv[])//it calls function with menu
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_ALL, "ru");
	menu();

	return 0;
}



