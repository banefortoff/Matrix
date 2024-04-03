#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() { initialization_matrix(3, 3); }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::invalid_argument("Invalid matrix size");
  }

  initialization_matrix(rows_, cols_);
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  initialization_matrix(other.rows_, other.cols_);
  copy_matrix(other);
}

S21Matrix::S21Matrix(S21Matrix &&other) {
  initialization_matrix(other.rows_, other.cols_);
  copy_matrix(other);
  other.remove_matrix();
}

S21Matrix::~S21Matrix() { remove_matrix(); }

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool result = FAILURE;
  if (cols_ == other.cols_ && rows_ == other.rows_) {
    bool flag = 1;
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) {
          result = FAILURE;
          flag = 0;
        } else {
          if (flag) {
            result = SUCCESS;
          }
        }
      }
    }
  }
  return result;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Different matrix dimensions");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Different matrix dimensions");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "The number of columns of the first matrix "
        "is not equal to the number of rows of the second matrix");
  }

  S21Matrix result(rows_, other.cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < other.rows_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = result;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_ || rows_ < 2) {
    throw std::invalid_argument(
        "The matrix is not square or its size is less than 2");
  }

  S21Matrix result(rows_, cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix minor_matrix = MinorMatrix(i, j);
      result.matrix_[i][j] = minor_matrix.Determinant() * pow(-1, i + j);
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix is not square");
  }

  double determinant = 0;
  if (rows_ == 1) {
    determinant = matrix_[0][0];
  } else if (rows_ == 2) {
    determinant = matrix_[0][0] * matrix_[1][1] - matrix_[1][0] * matrix_[0][1];
  } else {
    for (int k = 0; k < rows_; k++) {
      S21Matrix minor = MinorMatrix(0, k);
      determinant += pow(-1, k + 2) * matrix_[0][k] * minor.Determinant();
    }
  }
  return determinant;
}

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = Determinant();
  if (determinant == 0 || cols_ != rows_) {
    throw std::invalid_argument(
        "The matrix is not square or the determinant of the matrix is 0");
  }

  S21Matrix calcComp = CalcComplements();
  S21Matrix inverse = calcComp.Transpose();
  inverse.MulNumber(1 / determinant);
  return inverse;
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Different matrix dimensions");
  }

  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Different matrix dimensions");
  }

  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "The number of columns of the first matrix"
        "is not equal to the number of rows of the second matrix");
  }

  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    remove_matrix();
    initialization_matrix(other.rows_, other.cols_);
    copy_matrix(other);
  }
  return *this;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Different matrix dimensions");
  }

  SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Different matrix dimensions");
  }

  SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "The number of columns of the first matrix"
        "is not equal to the number of rows of the second matrix");
  }

  MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

const double &S21Matrix::operator()(int i, int j) const {
  if (i >= rows_ || i < 0 || j >= cols_ || j < 0) {
    throw std::invalid_argument("Index outside the matrix");
  }

  return matrix_[i][j];
}

double &S21Matrix::operator()(int i, int j) {
  if (i >= rows_ || i < 0 || j >= cols_ || j < 0) {
    throw std::invalid_argument("Index outside the matrix");
  }

  return matrix_[i][j];
}

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int num) {
  if (num <= 0) {
    throw std::invalid_argument("Impossible meaning");
  }

  S21Matrix new_matrix(num, cols_);
  int count_rows = 0;

  if (rows_ <= num) {
    count_rows = rows_;
  } else {
    count_rows = num;
  }

  for (int i = 0; i < count_rows; i++) {
    for (int j = 0; j < cols_; j++) {
      new_matrix.matrix_[i][j] = matrix_[i][j];
    }
  }

  *this = new_matrix;
}

void S21Matrix::SetCols(int num) {
  if (num <= 0) {
    throw std::invalid_argument("Impossible meaning");
  }

  S21Matrix new_matrix(rows_, num);
  int count_cols = 0;

  if (cols_ <= num) {
    count_cols = cols_;
  } else {
    count_cols = num;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < count_cols; j++) {
      new_matrix.matrix_[i][j] = matrix_[i][j];
    }
  }

  *this = new_matrix;
}

S21Matrix S21Matrix::MinorMatrix(int rows, int cols) {
  S21Matrix result(rows_ - 1, cols_ - 1);

  int m = 0;
  int n = 0;
  for (int i = 0; i < rows_; i++) {
    if (i == rows) continue;
    n = 0;
    for (int j = 0; j < cols_; j++) {
      if (j == cols) continue;
      result.matrix_[m][n] = matrix_[i][j];
      n++;
    }
    m++;
  }
  return result;
}

void S21Matrix::initialization_matrix(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double *[rows_];

  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}

void S21Matrix::copy_matrix(const S21Matrix &other) {
  rows_ = other.rows_;
  cols_ = other.cols_;

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::remove_matrix() {
  if (cols_ != -1 || rows_ != -1) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    rows_ = -1;
    cols_ = -1;
  }
}
