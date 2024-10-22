#include <gtest/gtest.h>
#include "../include/main.h"7

TEST(SumBelowDiagonalTest, HandlesPositiveNumbers) {
  int n = 3;
  int** matrix = new int*[n];
  for (int i = 0; i < n; ++i) {
    matrix[i] = new int[n];
  }

  matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
  matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6;
  matrix[2][0] = 7; matrix[2][1] = 8; matrix[2][2] = 9;

  EXPECT_EQ(sumBelowDiagonal(matrix, n), 19);

  for (int i = 0; i < n; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
}