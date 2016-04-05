#include <iostream>

using namespace std;

int** AllocMemory(int);
void MatrixEllements(int**, int);
int** NewMatrix(int**, int);
int MaxElements(int**, int, int, int);
void DisplayMatrix(int**, int);
void FreeMemory(int**, int);




int main()
{
	int n;
	while (true)
	{
		cout << "Please, enter size of matrix: ";
		cin >> n;
		if (n > 0) break;
		cout << "Error!";		
	}
	system("cls");

	int** a = AllocMemory(n);
	cout << "Please, enter ellements of matrix: " << endl;
	MatrixEllements(a, n);
	system("cls");
	cout << "Sourse matrix: " << endl;
	DisplayMatrix(a, n);
	int** b = NewMatrix(a, n);
	cout << "Max matrix: " << endl;
	DisplayMatrix(b, n);
	
	system("pause");
	FreeMemory(a, n);
	
	return 0;
}

int** AllocMemory(int n)
{
	int** a = new int*[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	return a;

}

void MatrixEllements(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << (i + 1) << "][" << (j + 1) << "] = ";
			cin >> a[i][j];
		}
	}
}

int** NewMatrix(int**a, int n)
{
	int**b = AllocMemory(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = MaxElements(a, n, i, j);
		}
	}
	return b;
}

int MaxElements(int** a, int n, int k, int l)
{
	int up = k, down = k;
	int max = a[0][0];
	for (int j = l; j >= 0; j--)
	{
		for (int i = up; i <=down; i++)
		{			
			if (max < a[i][j])
				max = a[i][j];
		}
		if (up > 0) up--;
		if (down < n - 1) down++;
	}
	return max;
}

void DisplayMatrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(7);
			cout << a[i][j];
		}
		cout << endl;
	}
}

void FreeMemory(int** a, int n)
{
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
}
