#ifndef MATRIX_HPP
#define MATRIX_HPP
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

namespace zich {
    class Matrix {
    private:
        vector<double> _members;
        int _row;
        int _col;


    public:
        Matrix() {} // defaule instructor
        Matrix(const vector<double> members, int row, int col)
        {
            this->setMatrix(members, row, col);
        }

        Matrix operator+(const Matrix&);
        Matrix& operator+=(const Matrix&);
        Matrix& operator+();  // unari+

        Matrix operator-(const Matrix&);
        Matrix& operator-=(const Matrix&);
        Matrix operator-() const;  // unari-

        bool operator>(const Matrix&) const;
        bool operator>=(const Matrix&) const;

        bool operator<(const Matrix&) const;
        bool operator<=(const Matrix&) const;

        bool operator==(const Matrix&) const;
        bool operator!=(const Matrix&) const;

        Matrix& operator++();  // prefix increment operator.
        Matrix& operator++(int);  // postfix increment operator.
        Matrix& operator--();
        Matrix& operator--(int);

        Matrix operator*(const Matrix&) const;
        Matrix operator*(const double) const;
        friend Matrix operator*(double, Matrix&);
        Matrix& operator*=(const Matrix&);
        Matrix& operator*=(const double);

        friend ostream& operator<<(ostream&, Matrix const&);
        friend istream& operator>>(istream&, Matrix&);

        void setMatrix(const vector<double>& v, int row, int);
    };
}

#endif