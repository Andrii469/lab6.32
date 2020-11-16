//Рекурсивний
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}
void Print(int* a, const int size, int i)
{
	cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
int IFirst(int* a, const int size, int& min, int i)
{
	if ((a[size] % 2) != 0)
	{
		min = a[i]; 
		return i;
	} 

	if (i < size - 1)
		return IFirst(a, size, min, i + 1);
	else
		return -1;
}

int Min(int* a, const int size, int min, int i)
{
	if (a[i] < min && ((a[size] % 2) != 0))
		min = a[i];
	if (i < size - 1)
		return Min(a, size, min, i + 1);
	else
		return min;
}
int main()
{
	srand((unsigned)time(NULL));
	const int n = 5;
	int a[n];
	int Low = -10;
	int High = 10;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	int min; 
	int imin = IFirst(a, n, min, 0); 
	if (imin == -1)
		cerr << "nemaye elementiv, yaki zadovilnayut umovi" << endl;
	else
		cout << "min = " << Min(a, n, min, imin + 1) << endl;
	return 0;
}
