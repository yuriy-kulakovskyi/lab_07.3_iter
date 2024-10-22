#include <iostream>
#include <iomanip>
#include "../include/main.h"

using namespace std;

int main() {
  int n;
  cout << "Введіть розмірність матриці (n x n): ";
  cin >> n;

  int** matrix = new int*[n];
  int** result = new int*[n];
  for (int i = 0; i < n; ++i) {
    matrix[i] = new int[n];
    result[i] = new int[n];
  }

  cout << "Введіть елементи матриці:\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> matrix[i][j];
    }
  }

  smoothMatrix(matrix, result, n);

  cout << "Згладжена матриця:\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << setw(4) << result[i][j];
    }
    cout << endl;
  }

  int sum = sumBelowDiagonal(result, n);
  cout << "Сума модулів елементів нижче головної діагоналі: " << sum << endl;

  for (int i = 0; i < n; ++i) {
    delete[] matrix[i];
    delete[] result[i];
  }
  delete[] matrix;
  delete[] result;

  return 0;
}
