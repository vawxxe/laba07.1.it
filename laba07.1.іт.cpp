
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Прототипи функцій
void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High);

void Print(int** a, const int rowCount, const int colCount);

void Sort(int** a, const int rowCount, const int colCount);

void Change(int** a, const int col1, const int col2,
    const int rowCount);

void Calc(int** a, const int rowCount, const int colCount,
    int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    // Межі діапазону випадкових чисел
    int Low = -21;
    int High = 24;

    // Розмір матриці
    int rowCount = 9;
    int colCount = 6;

    // Створення динамічної матриці
    int** P = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        P[i] = new int[colCount];

    // Формування та виведення початкової матриці
    Create(P, rowCount, colCount, Low, High);

    cout << "Original matrix P:";
    Print(P, rowCount, colCount);

    // Сортування стовпців
    Sort(P, rowCount, colCount);

    cout << "Sorted matrix P:";
    Print(P, rowCount, colCount);

    // Обчислення кількості та суми потрібних елементів
    int S = 0;
    int k = 0;

    Calc(P, rowCount, colCount, S, k);

    cout << "Sum S = " << S << endl;
    cout << "Count k = " << k << endl;

    // Виведення матриці після заміни елементів нулями
    cout << "Modified matrix P:";
    Print(P, rowCount, colCount);

    // Звільнення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] P[i];

    delete[] P;

    return 0;
}

// Формування матриці випадковими числами
void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Виведення матриці
void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];

        cout << endl;
    }

    cout << endl;
}

// Сортування стовпців методом обміну
void Sort(int** a, const int rowCount, const int colCount)
{
    for (int j0 = 0; j0 < colCount - 1; j0++)
        for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
            if ((a[0][j1] < a[0][j1 + 1])
                ||
                (a[0][j1] == a[0][j1 + 1] &&
                    a[1][j1] < a[1][j1 + 1])
                ||
                (a[0][j1] == a[0][j1 + 1] &&
                    a[1][j1] == a[1][j1 + 1] &&
                    a[2][j1] > a[2][j1 + 1]))
                Change(a, j1, j1 + 1, rowCount);
}

// Обмін двох стовпців місцями
void Change(int** a, const int col1, const int col2,
    const int rowCount)
{
    int tmp;

    for (int i = 0; i < rowCount; i++)
    {
        tmp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = tmp;
    }
}

// Обчислення суми, кількості та заміна елементів нулями
void Calc(int** a, const int rowCount, const int colCount,
    int& S, int& k)
{
    S = 0;
    k = 0;

    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (a[i][j] % 3 == 0 && a[i][j] >= 0)
            {
                S += a[i][j];
                k++;
                a[i][j] = 0;
            }
}
