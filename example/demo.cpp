#include <iostream>
using namespace std;

// 类模板仅需 typename T
template <typename T>
class Mat {
private:
    T x;
    int c;
public:
    Mat() = default;  // 实现默认构造函数，避免链接错误
    virtual ~Mat() = default;

    // 函数模板：自动推导二维数组的 ROWS 和 COLS
    template <size_t ROWS, size_t COLS>
    size_t get_row(const T (&mat)[ROWS][COLS]) {  // 函数模板参数推导维度
        size_t total_bytes = sizeof(mat);
        size_t element_bytes = sizeof(mat[0][0]);
        size_t total_elements = total_bytes / element_bytes;
        size_t rows = ROWS;  // 直接使用函数推导的行数
        size_t cols = COLS;  // 直接使用函数推导的列数

        cout << "Total bytes: " << total_bytes << endl;
        cout << "Element bytes: " << element_bytes << endl;
        cout << "Total elements: " << total_elements << endl;
        cout << "Rows: " << rows << endl;
        cout << "Cols: " << cols << endl;
        c=cols;
        std::cout<<"c:"<<c<<std::endl;    
        return rows;
    }
    size_t get_cols(){
        return c;
    }
    
    void multiply(
        const T (&A)[ROWS_A][COLS_A],    // 左矩阵：ROWS_A行，COLS_A列
        const T (&B)[COLS_A][COLS_B],    // 右矩阵：COLS_A行（必须等于左矩阵列数），COLS_B列
        T (&result)[ROWS_A][COLS_B]      // 结果矩阵：ROWS_A行，COLS_B列（输出参数）
    ) const {
        // 检查乘法合法性：左矩阵列数必须等于右矩阵行数（由模板参数保证，此处二次验证）
        if (COLS_A != get_row(B)) {
            throw invalid_argument("矩阵乘法不合法：左矩阵列数 != 右矩阵行数");
        }

        // 初始化结果矩阵为0
        for (size_t i = 0; i < ROWS_A; ++i) {
            for (size_t j = 0; j < COLS_B; ++j) {
                result[i][j] = 0;
            }
        }

        // 矩阵乘法核心逻辑
        for (size_t i = 0; i < ROWS_A; ++i) {         // 结果矩阵的行（=左矩阵行）
            for (size_t j = 0; j < COLS_B; ++j) {     // 结果矩阵的列（=右矩阵列）
                for (size_t k = 0; k < COLS_A; ++k) { // 累加：左矩阵行 × 右矩阵列
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
};

int main() {
    /*
    int matrix1[2][3] = {{1, 4, 2}, {3, 6, 8}};  // 2行3列
    int matrix2[3][4] = {{1,2}, {3,4}, {5,6}};   // 3行4列（部分元素省略，自动补0）

    Mat<int> mat;  // 类模板仅需指定元素类型 T=int

    cout << "处理 matrix1：" << endl;
    mat.get_row(matrix1);  // 函数自动推导 ROWS=2, COLS=3

    cout << "\n处理 matrix2：" << endl;
    mat.get_row(matrix2);  // 函数自动推导 ROWS=3, COLS=4
    std::cout<<"cols:"<<mat.get_cols()<<std::endl;  // 函数自动推导 ROWS=3, COLS=4
    */
    // 测试矩阵乘法：2×3 矩阵 × 3×2 矩阵 = 2×2 矩阵
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int C[2][2] = {0}; // 存储结果

    Mat<int> mat;

    cout << "矩阵A（2×3）：" << endl;
    mat.print(A);
    cout << "\n矩阵B（3×2）：" << endl;
    mat.print(B);

    try {
        mat.multiply(A, B, C); // 执行乘法
        cout << "\nA × B 的结果（2×2）：" << endl;
        mat.print(C);
    } catch (const exception& e) {
        cout << "\n错误：" << e.what() << endl;
    }

    return 0;
}
