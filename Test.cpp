#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>


#include "Matrix.hpp"
using namespace std;
using namespace zich;

static char result[200];
static char input[100];


/*
* The function save the stream input for mat in the static variable 'input'
* according to a specific format.
*/
void update_input(int mat_form, vector<double> arr)
{
    switch (mat_form)
    {
        case 43:  // 4x3
            sprintf(input, "[%f %f %f]\n[%f %f %f]\n[%f %f %f]\n[%f %f %f]", arr[0], arr[1], arr[2],
                                                                            arr[3], arr[4], arr[5],
                                                                            arr[6], arr[7], arr[8],
                                                                            arr[9], arr[10], arr[11]);
            break;

        case 34:  // 3x4
            sprintf(input, "[%f %f %f %f]\n[%f %f %f %f]\n[%f %f %f %f]", arr[0], arr[1], arr[2],
                                                                        arr[3], arr[4], arr[5],
                                                                        arr[6], arr[7], arr[8],
                                                                        arr[9], arr[10], arr[11]);
            break;

        case 26:  // 2x6
            sprintf(input, "[%f %f]\n[%f %f]\n[%f %f]\n[%f %f]\n[%f %f]\n[%f %f]", arr[0], arr[1], arr[2],
                                                                                    arr[3], arr[4], arr[5],
                                                                                    arr[6], arr[7], arr[8],
                                                                                    arr[9], arr[10], arr[11]);
            break;

        case 62:  // 6x2
            sprintf(input, "[%f %f %f %f %f %f]\n[%f %f %f %f %f %f]", arr[0], arr[1], arr[2],
                                                                        arr[3], arr[4], arr[5],
                                                                        arr[6], arr[7], arr[8],
                                                                        arr[9], arr[10], arr[11]);
            break;

        case 112:  // 1x12
            sprintf(input, "[%f %f %f %f %f %f %f %f %f %f %f %f]", arr[0], arr[1], arr[2],
                                                                    arr[3], arr[4], arr[5],
                                                                    arr[6], arr[7], arr[8],
                                                                    arr[9], arr[10], arr[11]);
            break;

        case 121:  // 12x1
            sprintf(input, "[%f]\n[%f]\n[%f]\n[%f]\n[%f]\n[%f]\n[%f]\n[%f]\n[%f]\n[%f]\n[%f]\n[%f]", arr[0], arr[1], arr[2],
                                                                                                    arr[3], arr[4], arr[5],
                                                                                                    arr[6], arr[7], arr[8],
                                                                                                    arr[9], arr[10], arr[11]);
            break;
    }
}

/*
* The function save the mat printing in the static variable 'result'
* according to a specific format.
*/
void update_result(int mat_form, vector<double> arr)
{
    switch (mat_form)
    {
        case 43:  // 4x3
            sprintf(result, "[%f %f %f]\n[%f %f %f]\n[%f %f %f]\n[%f %f %f]", arr[0], arr[1], arr[2],
                                                                                arr[3], arr[4], arr[5],
                                                                                arr[6], arr[7], arr[8],
                                                                                arr[9], arr[10], arr[11]);
            break;

        case 34:  // 3x4
            sprintf(result, "[%f %f %f %f]\n[%f %f %f %f]\n[%f %f %f %f]", arr[0], arr[1], arr[2],
                                                                            arr[3], arr[4], arr[5],
                                                                            arr[6], arr[7], arr[8],
                                                                            arr[9], arr[10], arr[11]);
            break;

        case 26:  // 2x6
            sprintf(result, "[%f %f]\n[%f %f]\n[%f %f]\n[%f %f]\n[%f %f]\n[%f %f]", arr[0], arr[1], arr[2],
                                                                                    arr[3], arr[4], arr[5],
                                                                                    arr[6], arr[7], arr[8],
                                                                                    arr[9], arr[10], arr[11]);
            break;

        case 62:  // 6x2
            sprintf(result, "[%f %f %f %f %f %f]\n[%f %f %f %f %f %f]", arr[0], arr[1], arr[2],
                                                                        arr[3], arr[4], arr[5],
                                                                        arr[6], arr[7], arr[8],
                                                                        arr[9], arr[10], arr[11]);
            break;

        case 112:  // 1x12
            sprintf(result, "[%f %f %f %f %f %f %f %f %f %f %f %f]", arr[0], arr[1], arr[2],
                                                                    arr[3], arr[4], arr[5],
                                                                    arr[6], arr[7], arr[8],
                                                                    arr[9], arr[10], arr[11]);
            break;

        case 121:  // 12x1
            sprintf(result, "[%f]\n[%f]\n[%f]\n[%f]\n[%f]\n[%f]\n[%f]\n[%f]\n[%f]\n[%f]\n[%f]\n[%f]", arr[0], arr[1], arr[2],
                                                                                                        arr[3], arr[4], arr[5],
                                                                                                        arr[6], arr[7], arr[8],
                                                                                                        arr[9], arr[10], arr[11]);
            break;

        case 44:  // 4x4
            sprintf(result, "[%f %f %f %f]\n[%f %f %f %f]\n[%f %f %f %f]\n[%f %f %f %f]", arr[0], arr[1], arr[2], arr[3],
                                                                                            arr[4], arr[5], arr[6], arr[7],
                                                                                            arr[8], arr[9], arr[10], arr[11],
                                                                                            arr[12], arr[13], arr[14], arr[15]);
            break;

        case 22:  // 2x2
            sprintf(result, "[%f %f]\n[%f %f]", arr[0], arr[1], arr[2], arr[3]);
              
            break;
    }
}

/*
* The function creates a vector with SIZE random double numbers.
*/
vector<double> getRandom_arr(int size) {
    int integer_num = 0;
    int after_dot_num = 0;
    double num = 0;
    
    vector<double> arr;

    for (size_t i = 0; i < size; ++i) {
        integer_num = rand() % 1000;  // number between 0-999
        after_dot_num = rand() % 10; // number between 0-9
        num = integer_num + after_dot_num*0.1;
        
        arr.push_back(num);
    }

    return arr;
}




/*
* A matrix which contains double numbers (by random).
*The function checks that the matrix printing works as required.
*
* Check for matrix: 3x4, 4x3, 2x6, 6x2, 12x1, 1x12.
* Total tests: 60
*/
TEST_CASE("Good input for operator<<") {

    for (size_t i = 0; i < 20; ++i)
    {
        vector<double> rand_arr = getRandom_arr(12);
        stringstream out;
        int format[] = { 43, 34, 26, 62, 121, 112 }; // it means: 4x3, 3x4, 2x6, 6x2, 12x1, 1x12

        for (size_t j = 0; j < 6; ++j)  // check for all the 6 format
        {
            int row = format[j] / 10;
            int col = format[j] % 10;
            Matrix mat{ rand_arr, row, col };

            out << mat;  // 'out' is hold the mat printing 
            update_result(format[j], rand_arr);  // 'result' is how the mat printing should be
            CHECK(out.str() == result);
        }
    }

}

/*
* A matrix which contains double numbers (by random) enters as input into a given matrix.
* The function checks that after input of the matrix its printing works as required.
*
* Check for matrix: 3x4, 4x3, 2x6, 6x2, 12x1, 1x12.
* Total tests: 60
*/
TEST_CASE("Good input for operator>>") {
    for (size_t i = 0; i < 20; ++i)
    {
        vector<double> rand_arr = getRandom_arr(12);
        stringstream out, input;
        Matrix mat;
        int format[] = { 43, 34, 26, 62, 121, 112 }; // it means: 4x3, 3x4, 2x6, 6x2, 12x1, 1x12

        for (size_t j = 0; j < 6; ++j)  // check for all the 6 format
        {
            update_input(format[j], rand_arr);  // input is the correct format for how an input for matrix should be

            input >> mat;
            out << mat;  // 'out' is hold the mat printing 

            update_result(format[j], rand_arr);  // 'result' is how the mat printing should be
            CHECK(out.str() == result);
        }
    }
}




/*
* The function takes 2 matrices by random and calculates their sum.
* 
* Check for matrix: 3x4, 4x3, 2x6, 6x2, 12x1, 1x12.
* Total tests: 12
*/
TEST_CASE("Good input for operator+")
{
    for (size_t i = 0; i < 2; ++i)
    {
        vector<double> rand_arr1 = getRandom_arr(12);
        vector<double> rand_arr2 = getRandom_arr(12);
        vector<double> sum;
        for (size_t k = 0; k < 12; k++)
        {
            sum.push_back(rand_arr1[k] + rand_arr2[k]);
        }

        
        stringstream out;
        int format[] = { 43, 34, 26, 62, 121, 112 }; // it means: 4x3, 3x4, 2x6, 6x2, 12x1, 1x12

        for (size_t j = 0; j < 6; ++j)  // check for all the 6 format
        {
            int row = format[j] / 10;
            int col = format[j] % 10;
            Matrix mat1{ rand_arr1, row, col };
            Matrix mat2{ rand_arr2, row, col };

            Matrix mat3 = mat1 + mat2;
            out << mat3;  // 'out' is hold the mat printing 
            update_result(format[j], sum);  // 'result' is how the mat printing should be
            CHECK(out.str() == result); 
        }
    }
}

/*
* The function takes 2 matrices: mat1, mat2 by random and insert for
* mat1 the sum of the 2 matrices, and then checks the
* correctness of operator+=, which means that mat1 = mat1 + mat2,
* and mat 2 has not change.
*
* Check for matrix: 3x4, 4x3, 2x6, 6x2, 12x1, 1x12.
* Total tests: 24
*/
TEST_CASE("Good input for operator+=")
{
    for (size_t i = 0; i < 2; ++i)
    {
        vector<double> rand_arr1 = getRandom_arr(12);
        vector<double> rand_arr2 = getRandom_arr(12);
        vector<double> sum;
        for (size_t k = 0; k < 12; k++)
        {
            sum.push_back(rand_arr1[k] + rand_arr2[k]);
        }


        stringstream out;
        int format[] = { 43, 34, 26, 62, 121, 112 }; // it means: 4x3, 3x4, 2x6, 6x2, 12x1, 1x12

        for (size_t j = 0; j < 6; ++j)  // check for all the 6 format
        {
            int row = format[j] / 10;
            int col = format[j] % 10;
            Matrix mat1{ rand_arr1, row, col };
            Matrix mat2{ rand_arr2, row, col };

            mat1 += mat2;
            out << mat1;  // 'out' is hold the mat printing 
            update_result(format[j], sum);  // 'result' is how the mat printing should be
            CHECK(out.str() == result);  // check thar mat1 is mat1+mat2

            out << mat2; 
            update_result(format[j], rand_arr2);
            CHECK(out.str() == result);  // check that mat2 has not changed
        }
    }
}

/*
* Check for matrix: 3x4, 4x3, 2x6, 6x2, 12x1, 1x12.
* Total tests: 24
*/
TEST_CASE("Good input for operator++")
{
    for (size_t i = 0; i < 2; ++i)
    {
        vector<double> rand_arr = getRandom_arr(12);
        vector<double> sum1;
        for (size_t k = 0; k < 12; k++)
        {
            sum1.push_back((rand_arr[k]+1));  // to check mat++
        }

        vector<double> sum2;
        for (size_t k = 0; k < 12; k++)
        {
            sum2.push_back((rand_arr[k] + 2));  // after check mat++ we check ++mat
        }
        stringstream out;

        int format[] = { 43, 34, 26, 62, 121, 112 }; // it means: 4x3, 3x4, 2x6, 6x2, 12x1, 1x12

        for (size_t j = 0; j < 6; ++j)  // check for all the 6 format
        {
            int row = format[j] / 10;
            int col = format[j] % 10;
            Matrix mat{ rand_arr, row, col };
            
            mat++;
            out << mat;  // 'out' is holding the mat printing 
            update_result(format[j], sum1);  // 'result' is how the mat printing should be
            CHECK(out.str() == result);

            ++mat;
            out << mat;  // 'out' is holding the mat printing 
            update_result(format[j], sum2);  // 'result' is how the mat printing should be
            CHECK(out.str() == result);
        }
    }
}

/*
* Check for matrix: 3x4, 4x3, 2x6, 6x2, 12x1, 1x12.
* Total tests: 6
*/
TEST_CASE("Good input for unari+")
{
        vector<double> rand_arr = getRandom_arr(12);
        stringstream out;

        int format[] = { 43, 34, 26, 62, 121, 112 }; // it means: 4x3, 3x4, 2x6, 6x2, 12x1, 1x12

        for (size_t j = 0; j < 6; ++j)  // check for all the 6 format
        {
            int row = format[j] / 10;
            int col = format[j] % 10;
            Matrix mat{ rand_arr, row, col };

            out << +mat;  // 'out' is holding the mat printing 
            update_result(format[j], rand_arr);  // 'result' is how the mat printing should be
            CHECK(out.str() == result);
        }
}




/*
* The function takes 2 matrices by random and calculates their subtraction.
*
* Check for matrix: 3x4, 4x3, 2x6, 6x2, 12x1, 1x12.
* Total tests: 12
*/
TEST_CASE("Good input for operator-")
{
    for (size_t i = 0; i < 2; ++i)
    {
        vector<double> rand_arr1 = getRandom_arr(12);
        vector<double> rand_arr2 = getRandom_arr(12);
        vector<double> sum;
        for (size_t k = 0; k < 12; k++)
        {
            sum.push_back(rand_arr1[k] - rand_arr2[k]);
        }


        stringstream out;
        int format[] = { 43, 34, 26, 62, 121, 112 }; // it means: 4x3, 3x4, 2x6, 6x2, 12x1, 1x12

        for (size_t j = 0; j < 6; ++j)  // check for all the 6 format
        {
            int row = format[j] / 10;
            int col = format[j] % 10;
            Matrix mat1{ rand_arr1, row, col };
            Matrix mat2{ rand_arr2, row, col };

            Matrix mat3 = mat1 - mat2;
            out << mat3;  // 'out' is holding the mat printing 
            update_result(format[j], sum);  // 'result' is how the mat printing should be
            CHECK(out.str() == result);
        }
    }
}

/*
* The function takes 2 matrices: mat1, mat2 by random and insert for
* mat1 the subtraction of the 2 matrices, and then checks the
* correctness of operator-=, which means that mat1 = mat1 - mat2,
* and mat 2 has not change.
*
* Check for matrix: 3x4, 4x3, 2x6, 6x2, 12x1, 1x12.
* Total tests: 24
*/
TEST_CASE("Good input for operator-=")
{
    for (size_t i = 0; i < 2; ++i)
    {
        vector<double> rand_arr1 = getRandom_arr(12);
        vector<double> rand_arr2 = getRandom_arr(12);
        vector<double> sum;
        for (size_t k = 0; k < 12; k++)
        {
            sum.push_back(rand_arr1[k] - rand_arr2[k]);
        }


        stringstream out;
        int format[] = { 43, 34, 26, 62, 121, 112 }; // it means: 4x3, 3x4, 2x6, 6x2, 12x1, 1x12

        for (size_t j = 0; j < 6; ++j)  // check for all the 6 format
        {
            int row = format[j] / 10;
            int col = format[j] % 10;
            Matrix mat1{ rand_arr1, row, col };
            Matrix mat2{ rand_arr2, row, col };

            mat1 -= mat2;
            out << mat1;  // 'out' is hold the mat printing 
            update_result(format[j], sum);  // 'result' is how the mat printing should be
            CHECK(out.str() == result);  // check thar mat1 is mat1+mat2

            out << mat2;
            update_result(format[j], rand_arr2);
            CHECK(out.str() == result);  // check that mat2 has not changed
        }
    }
}

/*
* Check for matrix: 3x4, 4x3, 2x6, 6x2, 12x1, 1x12.
* Total tests: 24
*/
TEST_CASE("Good input for operator--")
{
    for (size_t i = 0; i < 2; ++i)
    {
        vector<double> rand_arr = getRandom_arr(12);
        vector<double> sum1;
        for (size_t k = 0; k < 12; k++)
        {
            sum1.push_back((rand_arr[k] - 1));  // to check mat++
        }

        vector<double> sum2;
        for (size_t k = 0; k < 12; k++)
        {
            sum2.push_back((rand_arr[k] - 2));  // after check mat++ we check ++mat
        }
        stringstream out;

        int format[] = { 43, 34, 26, 62, 121, 112 }; // it means: 4x3, 3x4, 2x6, 6x2, 12x1, 1x12

        for (size_t j = 0; j < 6; ++j)  // check for all the 6 format
        {
            int row = format[j] / 10;
            int col = format[j] % 10;
            Matrix mat{ rand_arr, row, col };

            mat--;
            out << mat;  // 'out' is holding the mat printing 
            update_result(format[j], sum1);  // 'result' is how the mat printing should be
            CHECK(out.str() == result);

            --mat;
            out << mat;  // 'out' is holding the mat printing 
            update_result(format[j], sum2);  // 'result' is how the mat printing should be
            CHECK(out.str() == result);
        }
    }
}

/*
* Check for matrix: 3x4, 4x3, 2x6, 6x2, 12x1, 1x12.
* Total tests: 6
*/
TEST_CASE("Good input for unari-")
{
    vector<double> rand_arr = getRandom_arr(12);
    vector<double> rand_arr_negative;
    for (size_t i = 0; i < 12; ++i)
    {
        rand_arr_negative.push_back((rand_arr[i]*(-1)));
    }
    stringstream out;

    int format[] = { 43, 34, 26, 62, 121, 112 }; // it means: 4x3, 3x4, 2x6, 6x2, 12x1, 1x12

    for (size_t j = 0; j < 6; ++j)  // check for all the 6 format
    {
        int row = format[j] / 10;
        int col = format[j] % 10;
        Matrix mat{ rand_arr, row, col };

        out << -mat;  // 'out' is holding the mat printing 
        update_result(format[j], rand_arr_negative);  // 'result' is how the mat printing should be
        CHECK(out.str() == result);
    }
}




/*
* Check for matrix: 3x4, 4x3, 2x6, 6x2, 12x1, 1x12.
* Total tests: 24
*/
TEST_CASE("Good input for operator>")
{
    for (size_t i = 0; i < 2; ++i)
    {
        stringstream out;
        bool flag;
        vector<double> rand_arr1 = getRandom_arr(12);
        vector<double> rand_arr2 = getRandom_arr(12);
        
        double sum1 = 0;
        double sum2 = 0;
        for (size_t k = 0; k < 12; k++)
        {
            sum1 += rand_arr1[k];  // sum of rand_arr1
            sum2 += rand_arr2[k];  // sum of rand_arr2
        }
        if (sum1 == sum2) continue;

        if (sum1 < sum2)  // we want rand_arr1 to be bigger
        {
            vector<double> temp = rand_arr1;
            rand_arr1 = rand_arr2;
            rand_arr2 = temp;
        }

       
        int format[] = { 43, 34, 26, 62, 121, 112 }; // it means: 4x3, 3x4, 2x6, 6x2, 12x1, 1x12

        for (size_t j = 0; j < 6; ++j)  // check for all the 6 format
        {
            int row = format[j] / 10;
            int col = format[j] % 10;
            Matrix mat1{ rand_arr1, row, col };
            Matrix mat2{ rand_arr2, row, col };

            flag = mat1 > mat2;  // need to be true
            CHECK(flag);
        }
    }
}

/*
* Check for matrix: 3x4, 4x3, 2x6, 6x2, 12x1, 1x12.
* Total tests: 24
*/
TEST_CASE("Good input for operator>=")
{
    for (size_t i = 0; i < 2; ++i)
    {
        stringstream out;
        bool flag;
        vector<double> rand_arr1 = getRandom_arr(12);
        vector<double> rand_arr2 = getRandom_arr(12);

        double sum1 = 0;
        double sum2 = 0;
        for (size_t k = 0; k < 12; k++)
        {
            sum1 += rand_arr1[k];  // sum of rand_arr1
            sum2 += rand_arr2[k];  // sum of rand_arr2
        }

        if (sum1 < sum2)  // we want rand_arr1 to be bigger
        {
            vector<double> temp = rand_arr1;
            rand_arr1 = rand_arr2;
            rand_arr2 = temp;
        }


        int format[] = { 43, 34, 26, 62, 121, 112 }; // it means: 4x3, 3x4, 2x6, 6x2, 12x1, 1x12

        for (size_t j = 0; j < 6; ++j)  // check for all the 6 format
        {
            int row = format[j] / 10;
            int col = format[j] % 10;
            Matrix mat1{ rand_arr1, row, col };
            Matrix mat2{ rand_arr2, row, col };

            flag = mat1 >= mat2;  // need to be true
            CHECK(flag);
        }
    }
}

/*
* Check for matrix: 3x4, 4x3, 2x6, 6x2, 12x1, 1x12.
* Total tests: 24
*/
TEST_CASE("Good input for operator<")
{
    for (size_t i = 0; i < 2; ++i)
    {
        stringstream out;
        bool flag;
        vector<double> rand_arr1 = getRandom_arr(12);
        vector<double> rand_arr2 = getRandom_arr(12);

        double sum1 = 0;
        double sum2 = 0;
        for (size_t k = 0; k < 12; k++)
        {
            sum1 += rand_arr1[k];  // sum of rand_arr1
            sum2 += rand_arr2[k];  // sum of rand_arr2
        }
        if (sum1 == sum2) continue;

        if (sum1 > sum2)  // we want rand_arr1 to be smaller
        {
            vector<double> temp = rand_arr1;
            rand_arr1 = rand_arr2;
            rand_arr2 = temp;
        }


        int format[] = { 43, 34, 26, 62, 121, 112 }; // it means: 4x3, 3x4, 2x6, 6x2, 12x1, 1x12

        for (size_t j = 0; j < 6; ++j)  // check for all the 6 format
        {
            int row = format[j] / 10;
            int col = format[j] % 10;
            Matrix mat1{ rand_arr1, row, col };
            Matrix mat2{ rand_arr2, row, col };

            flag = mat1 < mat2;  // need to be true
            CHECK(flag);
        }
    }
}

/*
* Check for matrix: 3x4, 4x3, 2x6, 6x2, 12x1, 1x12.
* Total tests: 24
*/
TEST_CASE("Good input for operator<=")
{
    for (size_t i = 0; i < 2; ++i)
    {
        stringstream out;
        bool flag;
        vector<double> rand_arr1 = getRandom_arr(12);
        vector<double> rand_arr2 = getRandom_arr(12);

        double sum1 = 0;
        double sum2 = 0;
        for (size_t k = 0; k < 12; k++)
        {
            sum1 += rand_arr1[k];  // sum of rand_arr1
            sum2 += rand_arr2[k];  // sum of rand_arr2
        }

        if (sum1 < sum2)  // we want rand_arr1 to be smaller
        {
            vector<double> temp = rand_arr1;
            rand_arr1 = rand_arr2;
            rand_arr2 = temp;
        }


        int format[] = { 43, 34, 26, 62, 121, 112 }; // it means: 4x3, 3x4, 2x6, 6x2, 12x1, 1x12

        for (size_t j = 0; j < 6; ++j)  // check for all the 6 format
        {
            int row = format[j] / 10;
            int col = format[j] % 10;
            Matrix mat1{ rand_arr1, row, col };
            Matrix mat2{ rand_arr2, row, col };

            flag = mat1 <= mat2;  // need to be true
            CHECK(flag);
        }
    }
}

/*
* Check for matrix: 3x4, 4x3, 2x6, 6x2, 12x1, 1x12.
* Total tests: 24
*/
TEST_CASE("Good input for operator== and operator !=")
{
    for (size_t i = 0; i < 2; ++i)
    {
        stringstream out;
        bool is_equal;
        bool is_not_equal;
        vector<double> rand_arr = getRandom_arr(12);
        vector<double> rand_arr_differ;
        rand_arr_differ = rand_arr;
        rand_arr_differ[0] = rand_arr[0] + 1;


        int format[] = { 43, 34, 26, 62, 121, 112 }; // it means: 4x3, 3x4, 2x6, 6x2, 12x1, 1x12

        for (size_t j = 0; j < 6; ++j)  // check for all the 6 format
        {
            int row = format[j] / 10;
            int col = format[j] % 10;
            Matrix mat{ rand_arr, row, col };
            Matrix mat_equal{ rand_arr, row, col };
            Matrix mat_differ{ rand_arr_differ, row, col };

            is_equal = (mat == mat_equal);  // need to be true
            is_not_equal = (mat != mat_differ);  // need to be true
            CHECK(is_equal);
            CHECK(is_not_equal);
        }
    }
}




/*
* The function takes 2 matrix by random and a double
* and calculates their multiplication.
*
* Check for matrix: 3x4, 4x3, 2x6, 6x2, 12x1, 1x12.
* Total tests: 12
*/
TEST_CASE("Good input for operator* with double")
{
    for (size_t i = 0; i < 2; ++i)
    {
        vector<double> rand_arr = getRandom_arr(12);
        double num = rand_arr[0];
        vector<double> sum;
        for (size_t k = 0; k < 12; k++)
        {
            sum.push_back(rand_arr[k] * num);
        }


        stringstream out;
        int format[] = { 43, 34, 26, 62, 121, 112 }; // it means: 4x3, 3x4, 2x6, 6x2, 12x1, 1x12

        for (size_t j = 0; j < 6; ++j)  // check for all the 6 format
        {
            int row = format[j] / 10;
            int col = format[j] % 10;
            Matrix mat{ rand_arr, row, col };

            Matrix mat2 = num * mat;
            out << mat2;  // 'out' is hold the mat printing 
            update_result(format[j], sum);  // 'result' is how the mat printing should be
            CHECK(out.str() == result);
        }
    }
}

/*
* Check for matrix: 4x3 * 3x4, 2x6 * 6x2.
* Total tests: 2
*/
TEST_CASE("Good input for operator* between matrices")
{
    for (size_t i = 0; i < 2; ++i)
    {
        vector<double> rand_arr1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
        vector<double> rand_arr2 = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
        vector<double> ans;
        int format, row, col;
        stringstream out;

        {
            format = 43;
            row = format / 10;
            col = format % 10;
            Matrix mat1{ rand_arr1, row, col };

            format = 34;
            row = format / 10;
            col = format % 10;
            Matrix mat2{ rand_arr2, row, col };

            ans = { 40, 34, 28, 22, 112, 97, 82, 67, 184, 160, 136, 112, 256, 223, 190, 157 };

            Matrix mat_ans = mat1 * mat2;
            out << mat_ans;  // 'out' is hold the mat printing 
            update_result(44, ans);  // 'result' is how the mat printing should be
            CHECK(out.str() == result);
        }


        {
            format = 26;
            row = format / 10;
            col = format % 10;
            Matrix mat1{ rand_arr1, row, col };

            format = 62;
            row = format / 10;
            col = format % 10;
            Matrix mat2{ rand_arr2, row, col };

            ans = { 161, 182, 377, 434 };

            Matrix mat_ans = mat1 * mat2;
            out << mat_ans;  // 'out' is hold the mat printing 
            update_result(22, ans);  // 'result' is how the mat printing should be
            CHECK(out.str() == result);
        }
        
    }
}

/*
* The function takes 2 matrices: mat1, mat2 and insert for
* mat1 the multiplication of the 2 matrices, and then checks the
* correctness of operator*=, which means that mat1 = mat1 * mat2,
* and mat2 has not change.
*
* Check for matrix: 4x3 * 3x4, 2x6 * 6x2.
* Total tests: 2
*/
TEST_CASE("Good input for operator*=")
{
    for (size_t i = 0; i < 2; ++i)
    {
        vector<double> rand_arr1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
        vector<double> rand_arr2 = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
        vector<double> ans;
        int format, row, col;
        stringstream out;

        {
            //======== 4x3 * 3x4  ========
            format = 43;
            row = format / 10;
            col = format % 10;
            Matrix mat1{ rand_arr1, row, col };

            format = 34;
            row = format / 10;
            col = format % 10;
            Matrix mat2{ rand_arr2, row, col };

            ans = { 40, 34, 28, 22, 112, 97, 82, 67, 184, 160, 136, 112, 256, 223, 190, 157 };

            mat1 *= mat2;
            out << mat1;  // 'out' is hold the mat printing 
            update_result(44, ans);  // 'result' is how the mat printing should be
            CHECK(out.str() == result);

            update_result(34, rand_arr2);
            out << mat2;
            CHECK(out.str() == result);  // check that mat2 has not change
        }

        {
            //======== 2x6 * 6x2  ========
            format = 26;
            row = format / 10;
            col = format % 10;
            Matrix mat1{ rand_arr1, row, col };

            format = 62;
            row = format / 10;
            col = format % 10;
            Matrix mat2{ rand_arr2, row, col };

            ans = { 161, 182, 377, 434 };

            mat1 *= mat2;
            out << mat1;  // 'out' is hold the mat printing 
            update_result(22, ans);  // 'result' is how the mat printing should be
            CHECK(out.str() == result);

            update_result(62, rand_arr2);
            out << mat2;
            CHECK(out.str() == result);  // check that mat2 has not change
        }

    }
}



/*
* Go over all the invalid characters
*/
TEST_CASE("Bad input")
{
    vector<double> arr;
    double ch;
    for (int i = 0; i <= 47; ++i)
    {
        ch = i;
        arr = { ch };
        CHECK_THROWS(Matrix mat(arr, 1, 1));
    }

    for (int i = 58; i <= 177; ++i)
    {
        ch = i;
        arr = { ch };
        CHECK_THROWS(Matrix mat(arr, 1, 1));
    }
}