#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create_(int* a, const int size, const int Low, const int High, int i) 
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create_(a, size, Low, High, i + 1);
}

void Print_(int* a, const int size, int i) 
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print_(a, size, i + 1);
    else
        cout << endl;

}

int Count_(int* a, const int size, int i) 
{
    if (i == size) 
    {
        return 0;
    }
    if (a[i] < 0 && abs(a[i]) % 2 == 0) 
    {
        return Count_(a, size, i + 1) + 1;
    }
    return Count_(a, size, i + 1);
}

void Zero_(int* a, const int size, int i) 
{
    if (i == size) 
    {
        return;
    }
    if (a[i] < 0 && abs(a[i]) % 2 == 0) 
    {
        a[i] = 0;
    }
    Zero_(a, size, i + 1);
}

int Sum_(int* a, const int size, int i) 
{
    if (i < size)
    {
        if (a[i] < 0 && abs(a[i]) % 2 == 0)
            return Sum_(a, size, i + 1) + a[i];
        else
            return Sum_(a, size, i + 1);
    }
    else
        return 0;
}

int main() 
{
    srand((unsigned)time(NULL));
    const int n = 24;
    int a[n];

    int Low = -15;
    int High = 75;

    Create_(a, n, Low, High, 0);
    Print_(a, n, 0);

    cout << "Sum = " << Sum_(a, n, 0) << endl;
    cout << "Count = " << Count_(a, n, 0) << endl;

    Zero_(a, n, 0);
    Print_(a, n, 0);

    return 0;
}