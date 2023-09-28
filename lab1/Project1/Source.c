#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

int main() {
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	// Task 1 
	int count;
	printf("Введите размер массива: ");
	scanf("%d", &count);
	int *arr = (int*) malloc(count * sizeof(int));
	for (int i = 0; i < count; i++) {
		arr[i] = rand() % 100;
	}

	int min = arr[0];
	int max = arr[0];

	for (int i = 0; i < count; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	int difference = max - min;
	for (int i = 0; i < count; i++) {
		printf("%d ", arr[i]);
	}
	printf("\nDifference max and min: %d", difference);

	printf("\n_____________\n");

	//Task2
	count = 10;
	int** arr1 = (int**)malloc(count * sizeof(int*));
	for (int i = 0; i < count; i++)
	{	
		arr1[i] = (int*)malloc(count * sizeof(int));
	}
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			arr1[i][j] = rand() % 100;
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}

	int sum = 0;

	for (int i = 0; i < count; i++)
	{
		sum += arr1[i][i];
		
	}
	for (int i = 0; i < count; i++)
	{
		printf("   ");
	}
	printf("%d", sum);

	printf("\nПосчитать по строке - 1 \nПосчитать по столбцу - 2\n");
	int check;
	scanf("%d", &check);


	if (check == 1) {
		//Строка
		int sum;
		for (int i = 0; i < count; i++)
		{
			sum = 0;
			for (int j = 0; j < count; j++)
			{
				sum += arr1[i][j];
			}
			printf("%d строка: %d\n", i+1, sum);
		}
	}
	else {
		//Столбец
		int sum;
		for (int i = 0; i < count; i++)
		{
			sum = 0;
			for (int j = 0; j < count; j++)
			{
				sum += arr1[j][i];
			}
			printf("%d столбец: %d\n", i + 1, sum);
		}
	}


	/*задание5*/
	

	struct student {
		char famil[20];
		char name[20], facult[20];
		int Nomzach;
	} stud[3];

	// Ввод данных о студентах
	for (int i = 0; i < 3; i++) {
		printf("Введите фамилию студента %d:\n", i + 1);
		scanf("%s", stud[i].famil);

		printf("Введите имя студента %d:\n", i + 1);
		scanf("%s", stud[i].name);

		printf("Введите название факультета студента %d:\n", i + 1);
		scanf("%s", stud[i].facult);

		printf("Введите номер зачётной книжки студента %d:\n", i + 1);
		scanf("%d", &stud[i].Nomzach);
	}

	for (int iii = 0; iii < 2; iii++) {
		// Поиск структуры с заданными параметрами
		char searchFamil[20] = "";
		char searchName[20] = "";
		int searchNomzach = 0;

		printf("Введите 1 для поиска по фамилии, 2 для поиска по имени, 3 для поиска по зачетке\n");
		int asd = 0;
		scanf("%d", &asd);

		if (asd == 1) {
			printf("Введите фамилию для поиска:\n");
			scanf("%s", searchFamil);
		}
		else if (asd == 2) {
			printf("Введите имя для поиска:\n");
			scanf("%s", searchName);
		}
		else if (asd == 3) {
			printf("Введите номер зачётной книжки для поиска:\n");
			scanf("%d", &searchNomzach);
		}
		else {
			printf("поиска не будет");
			return;
		}

		int found = 0; // Флаг для обозначения, было ли найдено совпадение

		for (int i = 0; i < 3; i++) {
			if ((asd == 1 && !strcmp(stud[i].famil, searchFamil)) ||
				(asd == 2 && !strcmp(stud[i].name, searchName)) ||
				(asd == 3 && stud[i].Nomzach == searchNomzach))
				
			{
				printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d\n",
					stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);

				found = 1; // Устанавливаем флаг, что нашли совпадение
			}
		}
		if (!found) {
			printf("Студенты с заданными параметрами не найдены.\n");
		}
	}
}