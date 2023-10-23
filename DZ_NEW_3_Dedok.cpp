#include <iostream>
using namespace std;
const int MAX_ROWS = 100;
const int MAX_COLS = 100;
const int ROWS = 5;
const int COLS = 5;
//функция к заданию 1
void addColumn(int arr_1[MAX_ROWS][MAX_COLS], int rows, int cols, int newColumn[MAX_ROWS], int position) {
    if (position < 0 || position > cols) {
        cout << "Неверная позиция для вставки столбца." << "\n";
        return;
    }

    if (cols >= MAX_COLS) {
        cout << "Превышен максимальный размер столбцов." << "\n";
        return;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = cols; j > position; --j) {
            arr_1[i][j] = arr_1[i][j - 1];
        }
        arr_1[i][position] = newColumn[i];
    }
}
//функция к заданию 2
void deleteColumn(int myArray[ROWS][COLS], int columnToDelete, int numRows) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = columnToDelete; j < COLS - 1; ++j) {
            myArray[i][j] = myArray[i][j + 1];
        }
    }
}
int main()
{
    //Task_1
    int arr_1[MAX_ROWS][MAX_COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int newColumn[MAX_ROWS] = { 10, 11, 12 };
    int rows = 3;
    int cols = 3;
    int position = 1;
    addColumn(arr_1, rows, cols, newColumn, position);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols + 1; ++j) {
            cout << arr_1[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    //Task_2
    int myArray[ROWS][COLS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };
    int columnToDelete = 2;
    deleteColumn(myArray, columnToDelete, ROWS);
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS - 1; ++j) {
            cout << myArray[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

