#ifndef MAT_H
#define MAT_H

#include <vector>
#include <cassert>

template<typename T>
class Mat {
public:
    
    Mat(size_t rows, size_t cols);

    inline size_t rows() const { return rows_; }
    inline size_t cols() const { return cols_; }

    inline T& operator()(size_t r, size_t c);
    inline const T& operator()(size_t r, size_t c) const;

    inline T* data();
    inline const T* data() const;

    inline size_t size() const { return data_.size(); }

private:
    size_t rows_, cols_;
    std::vector<T> data_;
};

#include "Mat.tpp"
#endif // MAT_H

