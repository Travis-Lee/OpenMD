#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Mat {
private:
    T x;
public:
    Mat() = default;
    virtual ~Mat() = default;

    // 1. 获取矩阵行数
    template <size_t ROWS, size_t COLS>
    size_t get_row(const T (&mat)[ROWS][COLS]) const {
        return ROWS;
    }

    // 2. 获取矩阵列数
    template <size_t ROWS, size_t COLS>
    size_t get_col(const T (&mat)[ROWS][COLS]) const {
        return COLS;
    }

    // 3. 矩阵乘法函数：模板参数必须在函数前声明（关键修正！）
    template <size_t ROWS_A, size_t COLS_A, size_t COLS_B>  // 先声明模板参数
    void multiply(
        const T (&A)[ROWS_A][COLS_A],    // 现在可正常识别 ROWS_A/COLS_A
        const T (&B)[COLS_A][COLS_B],    // 可正常识别 COLS_A/COLS_B
        T (&result)[ROWS_A][COLS_B]      // 可正常识别 ROWS_A/COLS_B
    ) const {
        // 合法性检查
        if (COLS_A != get_row(B)) {
            throw invalid_argument("矩阵乘法不合法：左矩阵列数 != 右矩阵行数");
        }

        // 初始化结果矩阵为0
        for (size_t i = 0; i < ROWS_A; ++i) {
            for (size_t j = 0; j < COLS_B; ++j) {
                result[i][j] = 0;
            }
        }

        // 核心乘法逻辑
        for (size_t i = 0; i < ROWS_A; ++i) {
            for (size_t j = 0; j < COLS_B; ++j) {
                for (size_t k = 0; k < COLS_A; ++k) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }

    // 4. 打印矩阵
    template <size_t ROWS, size_t COLS>
    void print(const T (&mat)[ROWS][COLS]) const {
        for (size_t i = 0; i < ROWS; ++i) {
            for (size_t j = 0; j < COLS; ++j) {
                cout << mat[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    // 测试矩阵乘法：2×3  × 3×2 = 2×2
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int C[2][2] = {0}; // 结果矩阵

    Mat<int> mat;  // 仅定义一次（修正重复定义错误）

    cout << "矩阵A（2×3）：" << endl;
    mat.print(A);
    cout << "\n矩阵B（3×2）：" << endl;
    mat.print(B);

    try {
        mat.multiply(A, B, C); // 调用乘法函数
        cout << "\nA × B 结果（2×2）：" << endl;
        mat.print(C);
    } catch (const exception& e) {
        cout << "\n错误：" << e.what() << endl;
    }

    return 0;
}
