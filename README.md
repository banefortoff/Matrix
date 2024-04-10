![MATRIX](./images/matrix.jpg)

**This project is a class for work with matrices and performing various operations with them.**

* The code is written according to google style
* Handling of exceptional situations
* The program includes such operations on matrices as:
  + Checks matrices for equality with each other - `bool EqMatrix(const S21Matrix& other)`
  + Adds the second matrix to the current one - `void SumMatrix(const S21Matrix& other)`
  + Subtracts another matrix from the current one - `void SubMatrix(const S21Matrix& other)`
  + Multiplies the current matrix by a number - `void MulNumber(const double num)`
  + Multiplies the current matrix by the second matrix - `void MulMatrix(const S21Matrix& other)`
  + Creates a new transposed matrix from the current one and returns it - `S21Matrix Transpose()`
  + Calculates the algebraic addition matrix of the current one and returns it - `S21Matrix CalcComplements()`
  + Calculates and returns the determinant of the current matrix - `double Determinant()`
  + Calculates and returns the inverse matrix - `S21Matrix InverseMatrix()`
* Constructors and destructors such as:
  + A basic constructor that initialises a matrix of some predefined dimension - `S21Matrix()`
  + Parametrized constructor with number of rows and columns - `S21Matrix(int rows, int cols)`
  + Copy constructor - `S21Matrix(const S21Matrix& other)`
  + Move constructor - `S21Matrix(S21Matrix&& other)`
  + Destructor - `~S21Matrix()`
* The program includes such overloaded operators as:
  + Addition of two matrices - '+'
  + Subtraction of one matrix from another - '-'
  + Matrix multiplication and matrix multiplication by a number - '*'
  + Checks for matrices equality - '=='
  + Assignment of values from one matrix to another one - '='
  + Addition assignment - '+='
  + Difference assignment - '-='
  + Multiplication assignment - '*='
  + Indexation by matrix elements (row, column) - '(int i, int j)'

***

This project was developed by a student of School 21: banefort