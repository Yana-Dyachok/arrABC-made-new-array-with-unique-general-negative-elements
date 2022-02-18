/*Завдання 2. Є 3 двовимірні масиви A, B, C.Кількість рядків і стовпців вводить користувач з клавіатури для кожного з них.
Реалізуйте:
■ Створіть одновимірний масив, який містить загальні
значення для A, B, C;
■ Створіть одновимірний масив, який містить унікальні
значення для A, B, C;
■ Створіть одновимірний масив, який містить загальні
значення для A і C;
■ Створіть одновимірний масив, який містить від'ємні
значення для A, B, C без повторень*/
#include <iostream>
#include <ctime>
using namespace std;
void divisionArr(int** arr, int n, int m);//функція, яка розподіляє динамічну память масиву
void inputArr(int** arr, int n, int m);//функція введення масиву
void outPutArr(int** arr, int n, int m);//функція виведення масивів А В С
void GeneralABC(int** A, int** B, int** C, int* Gener, int nA, int nB, int nC, int mA, int mB, int mC, int& count);//функція створення одновимірного масиву, який містить загальні значення для A, B, C;
void UniqueABC(int** A, int** B, int** C, int* Uniq, int nA, int nB, int nC, int mA, int mB, int mC, int& count);//функція створення одновимірного масиву,який містить унікальні значення для A, B, C;
void GeneralAC(int** A, int** C, int* GenerAC, int nA, int nC, int mA, int mC, int& count);//функція створення одновимірного масиву,який містить загальні значення для A і C;
void GeneralNegative(int** A, int** B, int** C, int* GenerNeg, int nA, int nB, int nC, int mA, int mB, int mC, int& count);//функція створення одновимірного масиву,який містить від'ємні значення для A, B, C без повторень
void delCommonElements(int* arr, int& size);//функція видалення елементів, які повторюються у одновимірному масиві
void outPutNewArr(int* arr, int& size);//функція введення нових масивів
void deleteArr(int** arr, int n, int m);// функція видалення масиву
int main()
{	srand(time(NULL));
	int nA = 0, nB = 0, nC = 0;//розміри рядків трьох масивів А В С
	int mA = 0, mB = 0, mC = 0;//розміри стовпців трьох масивів А В С
	int count = 0;//змінна-відповідає розмірам нових масивів
	cout << "Enter size of first A array  n and m" << endl;
	cin >> nA >> mA;
	cout << "Enter size of second B array  n and m" << endl;
	cin >> nB >> mB;
	cout << "Enter size of third C array  n and m" << endl;
	cin >> nC >> mC;
	int** A = nullptr;//вказівник на вказівник масиву А
	A = new int* [nA];//вказівник масиву А
	int** B = nullptr;//вказівник на вказівник масиву В
	B = new int* [nB];//вказівник масиву В
	int** C = nullptr;//вказівник на вказівник масиву С
	C = new int* [nC];//вказівник масиву С 
	int size1 = sizeof(A);// розмір масиву А
	int size2 = sizeof(B);// розмір масиву В
	int size3 = sizeof(C);// розмір масиву С
	int* GenerNeg = new int[size1 + size2 + size3];//масив, який містить від'ємні значення для A, B, C без повторень
	int* Uniq = new int[size1 + size2 + size3];//масив,який містить унікальні значення для A, B, C;
	int* Gener = new int[size1 + size2 + size3];//масив, який містить загальні значення для A, B, C;
	int* GenerAC = new int[size1 + size3];//масив, який містить загальні значення для A і C;
	cout << "First array's elements" << endl;
	divisionArr(A, nA, mA);
	inputArr(A, nA, mA);
	outPutArr(A, nA, mA);
	cout << "Second array's elements" << endl;
	divisionArr(B, nB, mB);
	inputArr(B, nB, mB);
	outPutArr(B, nB, mB);
	cout << "Third array's elements" << endl;
	divisionArr(C, nC, mC);
	inputArr(C, nC, mC);
	outPutArr(C, nC, mC);
	cout << "General elements of A and C arrays in new array are:" << endl;
	GeneralAC(A, C, GenerAC, nA, nC, mA, mC, count);
	delCommonElements(GenerAC, count);
	outPutNewArr(GenerAC, count);
	cout << "General elements of A, B and C arrays in new array are:" << endl;
	GeneralABC(A, B, C, Gener, nA, nB, nC, mA, mB, mC, count);
	delCommonElements(Gener, count);
	outPutNewArr(Gener, count);
	cout << "General negative elements of A, B and C arrays in new array are:" << endl;
	GeneralNegative(A, B, C, GenerNeg, nA, nB, nC, mA, mB, mC, count);
	outPutNewArr(GenerNeg, count);
	cout << "Unique elements of A, B and C arrays in new array are:" << endl;
	UniqueABC(A, B, C, Uniq, nA, nB, nC, mA, mB, mC, count);
	delCommonElements(Uniq, count);
	outPutNewArr(Uniq, count);
	deleteArr(A, nA, mA);
	deleteArr(B, nB, mB);
	deleteArr(C, nC, mC);
	delete[]A;//видаляємо 
	delete[]B;
	delete[]C;
	delete[]Gener;
	delete[]Uniq;
	delete[]GenerAC;
	delete[]GenerNeg;//масиви
}
void divisionArr(int** arr, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
}
void inputArr(int** arr, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = rand() % 50 - 10;
		}
	}
}
void outPutArr(int** arr, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
void outPutNewArr(int* arr, int& size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void GeneralABC(int** A, int** B, int** C, int* Gener, int nA, int nB, int nC, int mA, int mB, int mC, int& count) {
	int size = 0;//змінна для підрахунку кількості елементів у новому масиві
	for (int i = 0; i < nA; i++)
	{
		for (int j = 0; j < mA; j++)
		{
			for (int k = 0; k < nC; k++)
			{
				for (int f = 0; f < mC; f++)
				{
					for (int l = 0; l < nB; l++)
					{
						for (int g = 0; g < mB; g++)
						{
							if (A[i][j] == C[k][f] and A[i][j] == B[l][g]) Gener[size++] = A[i][j];//створюємо умову в шести циклах для знаходження загальних елементів в трьох масивах
						}
					}


				}
			}
		}

	}
	for (int i = 0; i < nC; i++)
	{
		for (int j = 0; j < mC; j++)
		{
			for (int k = 0; k < nB; k++)
			{
				for (int f = 0; f < mB; f++)
				{
					for (int l = 0; l < nA; l++)
					{
						for (int g = 0; g < mA; g++)
						{
							if (C[i][j] == B[k][f] and C[i][j] == A[l][g]) Gener[size++] = C[i][j];//створюємо умову в шести циклах для знаходження загальних елементів в трьох масивах
						}
					}

				}
			}
		}

	}
	for (int i = 0; i < nB; i++)
	{
		for (int j = 0; j < mB; j++)
		{
			for (int k = 0; k < nA; k++)
			{
				for (int f = 0; f < mA; f++)
				{
					for (int l = 0; l < nC; l++)
					{
						for (int g = 0; g < mC; g++)
						{

							if (B[i][j] == A[k][f] and B[i][j] == C[l][g]) Gener[size++] = B[i][j];//створюємо умову в шести циклах для знаходження загальних елементів в трьох масивах
						}
					}
				}
			}
		}

	}
	count = size;//присвоюємо size розміру нового масиву
}
void delCommonElements(int* arr, int& count) {
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			if (arr[i] == arr[j]) {// якщо елементи масиву однакові
				for (int k = j; k < count - 1; k++) {//використовуємо цикл
					arr[k] = arr[k + 1];//присвоюємо однакові елементи
				}
				count -= 1;//зменшуємо розмір елементів
				j--;//видаляємо однакові елементи
			}
		}
	}
}
void GeneralNegative(int** A, int** B, int** C, int* GenerNeg, int nA, int nB, int nC, int mA, int mB, int mC, int& count) {
	int size = 0;//змінна для підрахунку кількості елементів у новому масиві
	for (int i = 0; i < nA; i++)
	{
		for (int j = 0; j < mA; j++)
		{
			if (A[i][j] < 0) GenerNeg[size++] = A[i][j];//присвоюємо негативні елементи новому масиву
		}

	}
	for (int i = 0; i < nC; i++)
	{
		for (int j = 0; j < mC; j++)
		{
			if (C[i][j] < 0) GenerNeg[size++] = C[i][j];//присвоюємо негативні елементи новому масиву

		}

	}
	for (int i = 0; i < nB; i++)
	{
		for (int j = 0; j < mB; j++)
		{
			if (B[i][j] < 0) GenerNeg[size++] = B[i][j];//присвоюємо негативні елементи новому масиву
		}

	}
	count = size;//присвоюємо size розміру нового масиву
}
void UniqueABC(int** A, int** B, int** C, int* Uniq, int nA, int nB, int nC, int mA, int mB, int mC, int& count) {
	int size = 0;//змінна для підрахунку кількості елементів у новому масиві
	for (int i = 0; i < nA; i++)
	{
		for (int j = 0; j < mA; j++)
		{
			for (int k = 0; k < nC; k++)
			{
				for (int f = 0; f < mC; f++)
				{
					if (A[i][j] != C[k][f]) Uniq[size++] = A[i][j];

				}
			}
		}

	}
	for (int i = 0; i < nC; i++)
	{
		for (int j = 0; j < mC; j++)
		{
			for (int k = 0; k < nB; k++)
			{
				for (int f = 0; f < mB; f++)
				{
					if (C[i][j] != B[k][f] and C[i][j] != Uniq[size]) Uniq[size++] = C[i][j];

				}
			}
		}

	}
	delCommonElements(Uniq, size);//видаляємо елементи, які повторюються
	for (int i = 0; i < nB; i++)
	{
		for (int j = 0; j < mB; j++)
		{
			for (int k = 0; k < nA; k++)
			{
				for (int f = 0; f < mA; f++)
				{
					if (B[i][j] != A[k][f] and B[i][j] != Uniq[size]) Uniq[size++] = B[i][j];

				}
			}
		}

	}
	count = size;//присвоюємо size розміру нового масиву
}
void GeneralAC(int** A, int** C, int* GenerAC, int nA, int nC, int mA, int mC, int& count) {
	for (int i = 0; i < nA; i++)
	{
		for (int j = 0; j < mA; j++)
		{
			for (int k = 0; k < nC; k++)
			{
				for (int f = 0; f < mC; f++)
				{
					if (A[i][j] == C[k][f]) GenerAC[count++] = A[i][j];//присвоюємо загальні елементи масивів А і С новому масиву

				}
			}
		}
	}
}
void deleteArr(int** arr, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		delete[]arr[i];
	}
}
