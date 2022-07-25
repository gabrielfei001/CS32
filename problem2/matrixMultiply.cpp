#include "matrixMultiply.h"
#include <iostream>
#include <numeric>
#include <vector>
#include <sstream>
#include <functional>
#include <algorithm>
using namespace std;

// Part 1, done
Matrix matrixMultiply1(const Matrix & matrix_1, const Matrix & matrix_2) {
    if (matrix_1.empty() || matrix_2.empty()) {
        throw std::invalid_argument("-1");
    }
    for (size_t i = 0; i < matrix_1.size(); i++) {
        if ((matrix_1.size() == 0) || (matrix_1[i].size() == 0) || (matrix_2.size() == 0) || (matrix_2[i].size() == 0)) {
            throw std::invalid_argument("-1");
        }
    }
    for (size_t i = 0; i < matrix_1.size(); i++) {
        if (matrix_1[i].size() != matrix_2.size()) {
            throw std::invalid_argument("-1");
        }
    }

    Matrix matrix_3(matrix_1.size(), std::vector<int>(matrix_2[0].size()));   
    for (size_t i = 0; i < matrix_1.size(); i++) {
        for (size_t k = 0; k < matrix_3[0].size(); k++) {
            matrix_3[i][k] = 0;
            for (size_t j = 0; j < matrix_2.size(); j++) {
                matrix_3[i][k] += matrix_1[i][j] * matrix_2[j][k];
            }
        }
    }
    return matrix_3;
}

//Part 2, done
Matrix matrixMultiply2(const Matrix & matrix_1, const Matrix & matrix_2) {
    if (matrix_1.empty() || matrix_2.empty()) {
        throw std::invalid_argument("-1");
    } 
    for (size_t i = 0; i < matrix_1.size(); i++) {
        if ((matrix_1.size() == 0) || (matrix_1[i].size() == 0) || (matrix_2.size() == 0) || (matrix_2[i].size() == 0)) {
            throw std::invalid_argument("-1");
        }
    }
    for (size_t i = 0; i < matrix_1.size(); i++) {
        if (matrix_1[i].size() != matrix_2.size()) {
            throw std::invalid_argument("-1");
        }
    }
    Matrix matrix_3(matrix_1.size(), std::vector<int>(matrix_2[0].size())); 
    Matrix matrix_4(matrix_2[0].size(), std::vector<int>(matrix_1[0].size()));
    for (size_t i = 0; i < matrix_4.size(); i++) {
        for (size_t j = 0; j < matrix_4[0].size(); j++) {
            matrix_4[i][j] = matrix_2[j][i];
        }
    }
    for (size_t i = 0; i < matrix_1.size(); i++) { 
        for (size_t j = 0; j < matrix_2[0].size(); j++) {
            matrix_3[i][j] = std::inner_product(matrix_1[i].begin(), matrix_1[i].end(), matrix_4[j].begin(), 0);
        }
    }
    return matrix_3;
    
}

//Part 3, one error
Matrix matrixMultiply3(const Matrix & matrix_1, const Matrix & matrix_2){
    if (matrix_1.empty() || matrix_2.empty()) {
        throw std::invalid_argument("-1");
    }
    for (size_t i = 0; i < matrix_1.size(); i++) {
        if ((matrix_1.size() == 0) || (matrix_1[i].size() == 0) || (matrix_2.size() == 0) || (matrix_2[i].size() == 0)) {
            throw std::invalid_argument("-1");
        }
    }
    for (size_t i = 0; i < matrix_1.size(); i++) {
        if (matrix_1[i].size() != matrix_2.size()) {
            throw std::invalid_argument("-1");
        }
    } 
    Matrix matrix_3(matrix_1.size(), std::vector<int>(matrix_2[0].size()));
    Matrix matrix_4(matrix_2[0].size(), std::vector<int>(matrix_1[0].size()));
    Array array_1(matrix_2[0].size());
    for (size_t i = 0; i < matrix_4.size(); i++) {
        for (size_t j = 0; j < matrix_4[0].size(); j++) {
            matrix_4[i][j] = matrix_2[j][i];
        }
    }
    for (size_t i = 0; i < matrix_1.size(); i++) { 
        for (size_t j = 0; j < matrix_2[0].size(); j++) {
            std::transform(matrix_1[i].begin(), matrix_1[i].end(), matrix_4[j].begin(), array_1.begin(), multiplies<int>()); //need to make 4th arg an iterator
            int x = std::accumulate(array_1.begin(), array_1.end(), 0);
            matrix_3[i][j] = x;
            std::fill(array_1.begin(), array_1.end(), 0);
        }
    }
    return matrix_3;
}