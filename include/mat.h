#ifndef MAT_H
#define MAT_H

#include <vector>
#include <cassert>

template<typename T>
class Mat {
public:
    
    Mat(size_t rows, size_t cols);

// 二维数组初始化构造函数（写在类里）
    template<size_t R, size_t C>
    Mat(const T (&arr)[R][C]) : rows_(R), cols_(C), data_(R * C) {
        for (size_t i = 0; i < R; ++i)
            for (size_t j = 0; j < C; ++j)
                (*this)(i, j) = arr[i][j];
    }

    inline size_t rows() const { return rows_; }
    inline size_t cols() const { return cols_; }

    inline T& operator()(size_t r, size_t c);
    inline const T& operator()(size_t r, size_t c) const;

    inline T* data();
    inline const T* data() const;

    inline size_t size() const { return data_.size(); }

    // ===================== 矩阵乘法接口 =====================
    Mat<T> multiply(const Mat<T>& other) const;
    // ==================== 静态矩阵乘法 ====================
    static Mat<T> mat_multiply(const Mat<T>& A, const Mat<T>& B);

    // convert matrix to array
    std::vector<T> mat2vec() const;

private:
    size_t rows_, cols_;
    std::vector<T> data_;
};

#include "mat.tpp"
#endif // MAT_H

