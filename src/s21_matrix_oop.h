#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#define SUCCESS 1
#define FAILURE 0

#include <cmath>
#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double **matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix &other);
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double num);

  const double &operator()(int i, int j) const;
  double &operator()(int i, int j);

  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  S21Matrix MinorMatrix(int rows, int cols);
  double Determinant();
  S21Matrix InverseMatrix();

  int GetRows() const;
  int GetCols() const;
  void SetRows(int num);
  void SetCols(int num);

  void initialization_matrix(int rows, int cols);
  void copy_matrix(const S21Matrix &other);
  void remove_matrix();
};

#endif  // SRC_S21_MATRIX_OOP_H_
