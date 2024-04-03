#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

///

TEST(test_default_constructor, default_constructor) {
  S21Matrix MatrixA;

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = 0;
  RightMatrix(0, 1) = 0;
  RightMatrix(0, 2) = 0;
  RightMatrix(1, 0) = 0;
  RightMatrix(1, 1) = 0;
  RightMatrix(1, 2) = 0;
  RightMatrix(2, 0) = 0;
  RightMatrix(2, 1) = 0;
  RightMatrix(2, 2) = 0;

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

///

TEST(test_controlled_constructor, controled_constructor) {
  S21Matrix MatrixA(3, 3);

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = 0;
  RightMatrix(0, 1) = 0;
  RightMatrix(0, 2) = 0;
  RightMatrix(1, 0) = 0;
  RightMatrix(1, 1) = 0;
  RightMatrix(1, 2) = 0;
  RightMatrix(2, 0) = 0;
  RightMatrix(2, 1) = 0;
  RightMatrix(2, 2) = 0;

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

TEST(test_controlled_constructor, controled_constructor_error) {
  ASSERT_THROW(S21Matrix MatrixA(0, 0), std::invalid_argument);
}

///

TEST(test_copy_constructor, copy_constructor) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix MatrixB(MatrixA);

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = 1;
  RightMatrix(0, 1) = 2;
  RightMatrix(0, 2) = 3;
  RightMatrix(1, 0) = 4;
  RightMatrix(1, 1) = 5;
  RightMatrix(1, 2) = 6;
  RightMatrix(2, 0) = 7;
  RightMatrix(2, 1) = 8;
  RightMatrix(2, 2) = 9;

  for (int i = 0; i < MatrixB.GetRows(); i++) {
    for (int j = 0; j < MatrixB.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixB(i, j), 1e-7);
    }
  }
}

///

TEST(test_transfer_constructor, transfer_constructor) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix MatrixB(std::move(MatrixA));

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = 1;
  RightMatrix(0, 1) = 2;
  RightMatrix(0, 2) = 3;
  RightMatrix(1, 0) = 4;
  RightMatrix(1, 1) = 5;
  RightMatrix(1, 2) = 6;
  RightMatrix(2, 0) = 7;
  RightMatrix(2, 1) = 8;
  RightMatrix(2, 2) = 9;

  for (int i = 0; i < MatrixB.GetRows(); i++) {
    for (int j = 0; j < MatrixB.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixB(i, j), 1e-7);
    }
  }
}

///

TEST(test_assignment, assignment_operator_overload) {
  S21Matrix MatrixA;
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix MatrixB(2, 2);
  MatrixB(0, 0) = 1;
  MatrixB(0, 1) = 2;
  MatrixB(1, 0) = 3;
  MatrixB(1, 1) = 4;

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = 1;
  RightMatrix(0, 1) = 2;
  RightMatrix(0, 2) = 3;
  RightMatrix(1, 0) = 4;
  RightMatrix(1, 1) = 5;
  RightMatrix(1, 2) = 6;
  RightMatrix(2, 0) = 7;
  RightMatrix(2, 1) = 8;
  RightMatrix(2, 2) = 9;

  MatrixB = MatrixA;

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

///

TEST(test_eq, eq_method_true) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix MatrixB(3, 3);
  MatrixB(0, 0) = 1;
  MatrixB(0, 1) = 2;
  MatrixB(0, 2) = 3;
  MatrixB(1, 0) = 4;
  MatrixB(1, 1) = 5;
  MatrixB(1, 2) = 6;
  MatrixB(2, 0) = 7;
  MatrixB(2, 1) = 8;
  MatrixB(2, 2) = 9;

  ASSERT_EQ(MatrixA.EqMatrix(MatrixB), 1);
}

TEST(test_eq, eq_method_false) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix MatrixB(3, 3);
  MatrixB(0, 0) = 1;
  MatrixB(0, 1) = 2;
  MatrixB(0, 2) = 3;
  MatrixB(1, 0) = 4;
  MatrixB(1, 1) = 5;
  MatrixB(1, 2) = 6;
  MatrixB(2, 0) = 7;
  MatrixB(2, 1) = 1;
  MatrixB(2, 2) = 9;

  ASSERT_EQ(MatrixA.EqMatrix(MatrixB), 0);
}

TEST(test_eq, eq_operator_overload_true) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix MatrixB(3, 3);
  MatrixB(0, 0) = 1;
  MatrixB(0, 1) = 2;
  MatrixB(0, 2) = 3;
  MatrixB(1, 0) = 4;
  MatrixB(1, 1) = 5;
  MatrixB(1, 2) = 6;
  MatrixB(2, 0) = 7;
  MatrixB(2, 1) = 8;
  MatrixB(2, 2) = 9;

  ASSERT_EQ(MatrixA == MatrixB, 1);
}

TEST(test_eq, eq_operator_overload_false) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix MatrixB(3, 3);
  MatrixB(0, 0) = 1;
  MatrixB(0, 1) = 2;
  MatrixB(0, 2) = 3;
  MatrixB(1, 0) = 4;
  MatrixB(1, 1) = 5;
  MatrixB(1, 2) = 6;
  MatrixB(2, 0) = 7;
  MatrixB(2, 1) = 8;
  MatrixB(2, 2) = 0;

  ASSERT_EQ(MatrixA == MatrixB, 0);
}

///

TEST(test_sum, sum_method) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix MatrixB(3, 3);
  MatrixB(0, 0) = 9;
  MatrixB(0, 1) = 8;
  MatrixB(0, 2) = 7;
  MatrixB(1, 0) = 6;
  MatrixB(1, 1) = 5;
  MatrixB(1, 2) = 4;
  MatrixB(2, 0) = 3;
  MatrixB(2, 1) = 2;
  MatrixB(2, 2) = 1;

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = 10;
  RightMatrix(0, 1) = 10;
  RightMatrix(0, 2) = 10;
  RightMatrix(1, 0) = 10;
  RightMatrix(1, 1) = 10;
  RightMatrix(1, 2) = 10;
  RightMatrix(2, 0) = 10;
  RightMatrix(2, 1) = 10;
  RightMatrix(2, 2) = 10;

  MatrixA.SumMatrix(MatrixB);

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

TEST(test_sum, sum_error) {
  S21Matrix MatrixA(4, 4);

  S21Matrix MatrixB(2, 2);
  MatrixB(0, 0) = 9;
  MatrixB(0, 1) = 8;
  MatrixB(1, 0) = 7;
  MatrixB(1, 1) = 6;

  ASSERT_THROW(MatrixA + MatrixB, std::invalid_argument);
}

TEST(test_sum, sum_operator_overload) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix MatrixB(3, 3);
  MatrixB(0, 0) = 9;
  MatrixB(0, 1) = 8;
  MatrixB(0, 2) = 7;
  MatrixB(1, 0) = 6;
  MatrixB(1, 1) = 5;
  MatrixB(1, 2) = 4;
  MatrixB(2, 0) = 3;
  MatrixB(2, 1) = 2;
  MatrixB(2, 2) = 1;

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = 10;
  RightMatrix(0, 1) = 10;
  RightMatrix(0, 2) = 10;
  RightMatrix(1, 0) = 10;
  RightMatrix(1, 1) = 10;
  RightMatrix(1, 2) = 10;
  RightMatrix(2, 0) = 10;
  RightMatrix(2, 1) = 10;
  RightMatrix(2, 2) = 10;

  S21Matrix result(MatrixA + MatrixB);

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), result(i, j), 1e-7);
    }
  }
}

///

TEST(test_sub, sub_method) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix MatrixB(3, 3);
  MatrixB(0, 0) = 9;
  MatrixB(0, 1) = 8;
  MatrixB(0, 2) = 7;
  MatrixB(1, 0) = 6;
  MatrixB(1, 1) = 5;
  MatrixB(1, 2) = 4;
  MatrixB(2, 0) = 3;
  MatrixB(2, 1) = 2;
  MatrixB(2, 2) = 1;

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = -8;
  RightMatrix(0, 1) = -6;
  RightMatrix(0, 2) = -4;
  RightMatrix(1, 0) = -2;
  RightMatrix(1, 1) = 0;
  RightMatrix(1, 2) = 2;
  RightMatrix(2, 0) = 4;
  RightMatrix(2, 1) = 6;
  RightMatrix(2, 2) = 8;

  MatrixA.SubMatrix(MatrixB);

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

TEST(test_sub, sub_error) {
  S21Matrix MatrixA(4, 4);

  S21Matrix MatrixB(2, 2);
  MatrixB(0, 0) = 9;
  MatrixB(0, 1) = 8;
  MatrixB(1, 0) = 7;
  MatrixB(1, 1) = 6;

  ASSERT_THROW(MatrixA - MatrixB, std::invalid_argument);
}

TEST(test_sub, sub_operator_overload) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix MatrixB(3, 3);
  MatrixB(0, 0) = 9;
  MatrixB(0, 1) = 8;
  MatrixB(0, 2) = 7;
  MatrixB(1, 0) = 6;
  MatrixB(1, 1) = 5;
  MatrixB(1, 2) = 4;
  MatrixB(2, 0) = 3;
  MatrixB(2, 1) = 2;
  MatrixB(2, 2) = 1;

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = -8;
  RightMatrix(0, 1) = -6;
  RightMatrix(0, 2) = -4;
  RightMatrix(1, 0) = -2;
  RightMatrix(1, 1) = 0;
  RightMatrix(1, 2) = 2;
  RightMatrix(2, 0) = 4;
  RightMatrix(2, 1) = 6;
  RightMatrix(2, 2) = 8;

  S21Matrix result(MatrixA - MatrixB);

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), result(i, j), 1e-7);
    }
  }
}

///

TEST(test_mul_num, mul_num_method) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = 2;
  RightMatrix(0, 1) = 4;
  RightMatrix(0, 2) = 6;
  RightMatrix(1, 0) = 8;
  RightMatrix(1, 1) = 10;
  RightMatrix(1, 2) = 12;
  RightMatrix(2, 0) = 14;
  RightMatrix(2, 1) = 16;
  RightMatrix(2, 2) = 18;

  MatrixA.MulNumber(2);

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

TEST(test_mul_num, mul_num_operator_overload) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = 2;
  RightMatrix(0, 1) = 4;
  RightMatrix(0, 2) = 6;
  RightMatrix(1, 0) = 8;
  RightMatrix(1, 1) = 10;
  RightMatrix(1, 2) = 12;
  RightMatrix(2, 0) = 14;
  RightMatrix(2, 1) = 16;
  RightMatrix(2, 2) = 18;

  S21Matrix result(MatrixA * 2);

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), result(i, j), 1e-7);
    }
  }
}

///

TEST(test_mul_matrix, mul_matrix_method) {
  S21Matrix MatrixA(2, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;

  S21Matrix MatrixB(3, 2);
  MatrixB(0, 0) = 1;
  MatrixB(0, 1) = 2;
  MatrixB(1, 0) = 3;
  MatrixB(1, 1) = 4;
  MatrixB(2, 0) = 5;
  MatrixB(2, 1) = 6;

  S21Matrix RightMatrix(2, 2);
  RightMatrix(0, 0) = 22;
  RightMatrix(0, 1) = 28;
  RightMatrix(1, 0) = 49;
  RightMatrix(1, 1) = 64;

  MatrixA.MulMatrix(MatrixB);

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

TEST(test_mul_matrix, mul_matrix_error) {
  S21Matrix MatrixA(4, 4);

  S21Matrix MatrixB(2, 2);
  MatrixB(0, 0) = 9;
  MatrixB(0, 1) = 8;
  MatrixB(1, 0) = 7;
  MatrixB(1, 1) = 6;

  ASSERT_THROW(MatrixA * MatrixB, std::invalid_argument);
}

TEST(test_mul_matrix, mul_matrix_operator_overload) {
  S21Matrix MatrixA(2, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;

  S21Matrix MatrixB(3, 2);
  MatrixB(0, 0) = 1;
  MatrixB(0, 1) = 2;
  MatrixB(1, 0) = 3;
  MatrixB(1, 1) = 4;
  MatrixB(2, 0) = 5;
  MatrixB(2, 1) = 6;

  S21Matrix RightMatrix(2, 2);
  RightMatrix(0, 0) = 22;
  RightMatrix(0, 1) = 28;
  RightMatrix(1, 0) = 49;
  RightMatrix(1, 1) = 64;

  S21Matrix result(MatrixA * MatrixB);

  for (int i = 0; i < result.GetRows(); i++) {
    for (int j = 0; j < result.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), result(i, j), 1e-7);
    }
  }
}

///

TEST(test_transpose, transpose) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = 1;
  RightMatrix(0, 1) = 4;
  RightMatrix(0, 2) = 7;
  RightMatrix(1, 0) = 2;
  RightMatrix(1, 1) = 5;
  RightMatrix(1, 2) = 8;
  RightMatrix(2, 0) = 3;
  RightMatrix(2, 1) = 6;
  RightMatrix(2, 2) = 9;

  MatrixA = MatrixA.Transpose();

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

///

TEST(test_calc_complements, calc_complemets) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 5;
  MatrixA(0, 1) = 7;
  MatrixA(0, 2) = 10;
  MatrixA(1, 0) = 1;
  MatrixA(1, 1) = 67;
  MatrixA(1, 2) = 25;
  MatrixA(2, 0) = 13;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = 403;
  RightMatrix(0, 1) = 316;
  RightMatrix(0, 2) = -863;
  RightMatrix(1, 0) = 17;
  RightMatrix(1, 1) = -85;
  RightMatrix(1, 2) = 51;
  RightMatrix(2, 0) = -495;
  RightMatrix(2, 1) = -115;
  RightMatrix(2, 2) = 328;

  MatrixA = MatrixA.CalcComplements();

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

TEST(test_calc_complements, calc_complemets_error) {
  S21Matrix MatrixA(2, 3);

  ASSERT_THROW(MatrixA.CalcComplements(), std::invalid_argument);
}

///

TEST(test_determinant, determinant) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 5;
  MatrixA(0, 1) = 7;
  MatrixA(0, 2) = 10;
  MatrixA(1, 0) = 1;
  MatrixA(1, 1) = 67;
  MatrixA(1, 2) = 25;
  MatrixA(2, 0) = 13;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  ASSERT_EQ(MatrixA.Determinant(), -4403);
}

TEST(test_determinant, determinant_error) {
  S21Matrix MatrixA(2, 3);

  ASSERT_THROW(MatrixA.Determinant(), std::invalid_argument);
}

///

TEST(test_inverse_matrix, inverse_matrix) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 2;
  MatrixA(0, 1) = 5;
  MatrixA(0, 2) = 7;
  MatrixA(1, 0) = 6;
  MatrixA(1, 1) = 3;
  MatrixA(1, 2) = 4;
  MatrixA(2, 0) = 5;
  MatrixA(2, 1) = -2;
  MatrixA(2, 2) = -3;

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = 1;
  RightMatrix(0, 1) = -1;
  RightMatrix(0, 2) = 1;
  RightMatrix(1, 0) = -38;
  RightMatrix(1, 1) = 41;
  RightMatrix(1, 2) = -34;
  RightMatrix(2, 0) = 27;
  RightMatrix(2, 1) = -29;
  RightMatrix(2, 2) = 24;

  MatrixA = MatrixA.InverseMatrix();

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

TEST(test_inverse_matrix, inverse_matrix_error) {
  S21Matrix MatrixA(2, 3);

  ASSERT_THROW(MatrixA.InverseMatrix(), std::invalid_argument);
}

TEST(test_inverse_matrix, inverse_matrix_error_determ) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  ASSERT_THROW(MatrixA.InverseMatrix(), std::invalid_argument);
}

///

TEST(test_sum_assignment, sum_assignment_operator_overload) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix MatrixB(3, 3);
  MatrixB(0, 0) = 9;
  MatrixB(0, 1) = 8;
  MatrixB(0, 2) = 7;
  MatrixB(1, 0) = 6;
  MatrixB(1, 1) = 5;
  MatrixB(1, 2) = 4;
  MatrixB(2, 0) = 3;
  MatrixB(2, 1) = 2;
  MatrixB(2, 2) = 1;

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = 10;
  RightMatrix(0, 1) = 10;
  RightMatrix(0, 2) = 10;
  RightMatrix(1, 0) = 10;
  RightMatrix(1, 1) = 10;
  RightMatrix(1, 2) = 10;
  RightMatrix(2, 0) = 10;
  RightMatrix(2, 1) = 10;
  RightMatrix(2, 2) = 10;

  MatrixA += MatrixB;

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

TEST(test_sum_assignment, sum_assignment_operator_overload_error) {
  S21Matrix MatrixA(3, 3);

  S21Matrix MatrixB(2, 3);

  ASSERT_THROW(MatrixA += MatrixB, std::invalid_argument);
}

///

TEST(test_sub_assignment, sub_assignment_operator_overload) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;
  MatrixA(2, 0) = 7;
  MatrixA(2, 1) = 8;
  MatrixA(2, 2) = 9;

  S21Matrix MatrixB(3, 3);
  MatrixB(0, 0) = 9;
  MatrixB(0, 1) = 8;
  MatrixB(0, 2) = 7;
  MatrixB(1, 0) = 6;
  MatrixB(1, 1) = 5;
  MatrixB(1, 2) = 4;
  MatrixB(2, 0) = 3;
  MatrixB(2, 1) = 2;
  MatrixB(2, 2) = 1;

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = -8;
  RightMatrix(0, 1) = -6;
  RightMatrix(0, 2) = -4;
  RightMatrix(1, 0) = -2;
  RightMatrix(1, 1) = 0;
  RightMatrix(1, 2) = 2;
  RightMatrix(2, 0) = 4;
  RightMatrix(2, 1) = 6;
  RightMatrix(2, 2) = 8;

  MatrixA -= MatrixB;

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

TEST(test_sub_assignment, sub_assignment_operator_overload_error) {
  S21Matrix MatrixA(3, 3);

  S21Matrix MatrixB(2, 3);

  ASSERT_THROW(MatrixA -= MatrixB, std::invalid_argument);
}

///

TEST(test_mul_matrix_assignment, mul_matrix_assignment_operator_overload) {
  S21Matrix MatrixA(2, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;

  S21Matrix MatrixB(3, 2);
  MatrixB(0, 0) = 1;
  MatrixB(0, 1) = 2;
  MatrixB(1, 0) = 3;
  MatrixB(1, 1) = 4;
  MatrixB(2, 0) = 5;
  MatrixB(2, 1) = 6;

  S21Matrix RightMatrix(2, 2);
  RightMatrix(0, 0) = 22;
  RightMatrix(0, 1) = 28;
  RightMatrix(1, 0) = 49;
  RightMatrix(1, 1) = 64;

  MatrixA *= MatrixB;

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

TEST(test_mul_matrix_assignment,
     mul_matrix_assignment_operator_overload_error) {
  S21Matrix MatrixA(3, 3);

  S21Matrix MatrixB(2, 3);

  ASSERT_THROW(MatrixA *= MatrixB, std::invalid_argument);
}

///

TEST(test_mul_num_assignment, mul_num_assignment_operator_overload) {
  S21Matrix MatrixA(3, 3);
  MatrixA(0, 0) = 12;
  MatrixA(0, 1) = 3;
  MatrixA(0, 2) = 6;
  MatrixA(1, 0) = 3;
  MatrixA(1, 1) = 10;
  MatrixA(1, 2) = 0;
  MatrixA(2, 0) = 15;
  MatrixA(2, 1) = 13;
  MatrixA(2, 2) = -100;

  S21Matrix RightMatrix(3, 3);
  RightMatrix(0, 0) = 84;
  RightMatrix(0, 1) = 21;
  RightMatrix(0, 2) = 42;
  RightMatrix(1, 0) = 21;
  RightMatrix(1, 1) = 70;
  RightMatrix(1, 2) = 0;
  RightMatrix(2, 0) = 105;
  RightMatrix(2, 1) = 91;
  RightMatrix(2, 2) = -700;

  MatrixA *= 7;

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

///

TEST(test_index, index) {
  S21Matrix MatrixA(3, 3);

  ASSERT_EQ(MatrixA(2, 2), 0);
  MatrixA(2, 2) = 101;
  ASSERT_EQ(MatrixA(2, 2), 101);
}

TEST(test_index, index_error) {
  S21Matrix MatrixA(3, 3);

  ASSERT_THROW(MatrixA(-1, -1), std::invalid_argument);
  ASSERT_THROW(MatrixA(3, 3), std::invalid_argument);
}

///

TEST(test_set_row, set_row_1) {
  S21Matrix MatrixA(2, 2);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(1, 0) = 3;
  MatrixA(1, 1) = 4;

  MatrixA.SetRows(3);

  S21Matrix RightMatrix(3, 2);
  RightMatrix(0, 0) = 1;
  RightMatrix(0, 1) = 2;
  RightMatrix(1, 0) = 3;
  RightMatrix(1, 1) = 4;
  RightMatrix(2, 0) = 0;
  RightMatrix(2, 1) = 0;

  for (int i = 0; i < RightMatrix.GetRows(); i++) {
    for (int j = 0; j < RightMatrix.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

TEST(test_set_row, set_row_2) {
  S21Matrix MatrixA(2, 2);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(1, 0) = 3;
  MatrixA(1, 1) = 4;

  MatrixA.SetRows(2);

  S21Matrix RightMatrix(2, 2);
  RightMatrix(0, 0) = 1;
  RightMatrix(0, 1) = 2;
  RightMatrix(1, 0) = 3;
  RightMatrix(1, 1) = 4;

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

TEST(test_set_row, set_row_3) {
  S21Matrix MatrixA(3, 2);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(1, 0) = 3;
  MatrixA(1, 1) = 4;
  MatrixA(2, 0) = 5;
  MatrixA(2, 1) = 6;

  MatrixA.SetRows(2);

  S21Matrix RightMatrix(2, 2);
  RightMatrix(0, 0) = 1;
  RightMatrix(0, 1) = 2;
  RightMatrix(1, 0) = 3;
  RightMatrix(1, 1) = 4;

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

TEST(test_set_row, set_row_error) {
  S21Matrix MatrixA(3, 3);

  ASSERT_THROW(MatrixA.SetRows(0), std::invalid_argument);
  ASSERT_THROW(MatrixA.SetRows(-1), std::invalid_argument);
}

///

TEST(test_set_col, set_col_1) {
  S21Matrix MatrixA(2, 2);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(1, 0) = 3;
  MatrixA(1, 1) = 4;

  MatrixA.SetCols(3);

  S21Matrix RightMatrix(2, 3);
  RightMatrix(0, 0) = 1;
  RightMatrix(0, 1) = 2;
  RightMatrix(0, 2) = 0;
  RightMatrix(1, 0) = 3;
  RightMatrix(1, 1) = 4;
  RightMatrix(1, 2) = 0;

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

TEST(test_set_col, set_col_2) {
  S21Matrix MatrixA(2, 2);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(1, 0) = 3;
  MatrixA(1, 1) = 4;

  MatrixA.SetCols(2);

  S21Matrix RightMatrix(2, 2);
  RightMatrix(0, 0) = 1;
  RightMatrix(0, 1) = 2;
  RightMatrix(1, 0) = 3;
  RightMatrix(1, 1) = 4;

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

TEST(test_set_col, set_col_3) {
  S21Matrix MatrixA(2, 3);
  MatrixA(0, 0) = 1;
  MatrixA(0, 1) = 2;
  MatrixA(0, 2) = 3;
  MatrixA(1, 0) = 4;
  MatrixA(1, 1) = 5;
  MatrixA(1, 2) = 6;

  MatrixA.SetCols(2);

  S21Matrix RightMatrix(2, 2);
  RightMatrix(0, 0) = 1;
  RightMatrix(0, 1) = 2;
  RightMatrix(1, 0) = 4;
  RightMatrix(1, 1) = 5;

  for (int i = 0; i < MatrixA.GetRows(); i++) {
    for (int j = 0; j < MatrixA.GetCols(); j++) {
      ASSERT_NEAR(RightMatrix(i, j), MatrixA(i, j), 1e-7);
    }
  }
}

TEST(test_set_col, set_col_error) {
  S21Matrix MatrixA;

  ASSERT_THROW(MatrixA.SetCols(0), std::invalid_argument);
  ASSERT_THROW(MatrixA.SetCols(-1), std::invalid_argument);
}

///

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
