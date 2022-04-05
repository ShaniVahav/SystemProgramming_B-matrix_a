#include "Matrix.hpp"
#include "Matrix.hpp"
using namespace std;


namespace zich {
	vector<double> a = { 0 };
	Matrix mat(a, 1, 1);

	Matrix Matrix::operator+(const Matrix&) { return mat; }
	Matrix& Matrix::operator+=(const Matrix&) { return *this; }
	Matrix& Matrix::operator+() { return *this; }

	Matrix Matrix::operator-(const Matrix&) { return mat; }
	Matrix& Matrix::operator-=(const Matrix&) { return *this; }
	Matrix& Matrix::operator-() { return *this; }

	bool Matrix::operator>(const Matrix&) { return true; }
	bool Matrix::operator>=(const Matrix&) { return true; }

	bool Matrix::operator<(const Matrix&) { return true; }
	bool Matrix::operator<=(const Matrix&) { return true; }

	bool Matrix::operator==(const Matrix&) { return true; }
	bool Matrix::operator!=(const Matrix&) { return true; }

	Matrix& Matrix::operator++() { return *this; }
	Matrix& Matrix::operator++(int) { return *this; }
	Matrix& Matrix::operator--() { return *this; }
	Matrix& Matrix::operator--(int) { return *this; }

	Matrix Matrix::operator*(const Matrix&) { return mat; }
	Matrix Matrix::operator*(const double) { return mat; }
	Matrix operator*(double, Matrix&) { return mat; }
	Matrix& Matrix::operator*=(const Matrix&) { return *this; }
	Matrix& Matrix::operator*=(const double) { return *this; }


	ostream& operator<<(ostream& os, Matrix const&) { return os; }
	istream& operator>>(istream& is, Matrix&) { return is; }


	void Matrix::setMatrix(const vector<double>& m, int row, int col)
	{
		this->_members = m;
		this->_row = row;
		this->_col = col;
	}


}