#include "../include/main.h"
#include <cmath>
#include <algorithm>

using namespace std;

void smoothMatrix(int** matrix, int** result, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int sum = 0, count = 0;
      for (int k = max(0, i - 1); k <= min(n - 1, i + 1); ++k) {
        for (int l = max(0, j - 1); l <= min(n - 1, j + 1); ++l) {
          sum += matrix[k][l];
          count++;
        }
      }
      result[i][j] = sum / count;
    }
  }
}

int sumBelowDiagonal(int** matrix, int n) {
  int sum = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      sum += abs(matrix[i][j]);
    }
  }
  return sum;
}