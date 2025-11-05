#include "mat.h"
#pragma once

template<typename T>
Mat<T>::Mat(size_t rows, size_t cols)
    : rows_(rows), cols_(cols), data_(rows * cols) {}

template<typename T>
inline T& Mat<T>::operator()(size_t r, size_t c) {
    assert(r < rows_ && c < cols_);
    return data_[r * cols_ + c];
}

template<typename T>
inline const T& Mat<T>::operator()(size_t r, size_t c) const {
    assert(r < rows_ && c < cols_);
    return data_[r * cols_ + c];
}

template<typename T>
inline T* Mat<T>::data() {
    return data_.data();
}

template<typename T>
inline const T* Mat<T>::data() const {
    return data_.data();
}

// ------------------- 静态矩阵乘法 -------------------
template<typename T>
Mat<T> Mat<T>::mat_multiply(const Mat<T>& A, const Mat<T>& B) {
    assert(A.cols() == B.rows() && "Incompatible matrix dimensions");

    Mat<T> C(A.rows(), B.cols());

    for (size_t i = 0; i < A.rows(); ++i) {
        for (size_t j = 0; j < B.cols(); ++j) {
            T sum = 0;
            for (size_t k = 0; k < A.cols(); ++k)
                sum += A(i, k) * B(k, j);
            C(i, j) = sum;
        }
    }

    return C;
}


// convert2vec
template<typename T>
std::vector<T> Mat<T>::mat2vec() const{
    return std::vector<T>(data_.begin(),data_.end());
}



