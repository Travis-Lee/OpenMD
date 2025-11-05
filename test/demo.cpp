#include <iostream>
#include <vector>
#include <cassert>

// 模板类：封装卷积操作，支持任意数据类型
template <typename T>
class Conv3x3 {
public:
    // 构造函数：初始化卷积核和偏置
    // 输入参数：
    // - weights: 卷积核，形状为 [out_channels, in_channels, 3, 3]
    // - bias: 偏置，形状为 [out_channels]
    Conv3x3(const std::vector<std::vector<std::vector<std::vector<T>>>>& weights,
            const std::vector<T>& bias,
            int stride = 1,
            int padding = 1) 
        : weights_(weights), bias_(bias), stride_(stride), padding_(padding) {
        // 校验参数合法性
        assert(weights.size() > 0);  // 输出通道数 > 0
        assert(bias.size() == weights.size());  // 偏置数 = 输出通道数
        assert(weights[0].size() > 0);  // 输入通道数 > 0
        assert(weights[0][0].size() == 3 && weights[0][0][0].size() == 3);  // 确保 3x3 卷积核
        assert(stride == 1);  // MobileNet-SSD 中 3x3 卷积常用 stride=1
        assert(padding == 1);  // 配合 stride=1 保持输入输出尺寸一致
    }

    // 卷积操作：输入张量 -> 输出张量
    // 输入张量形状：[N, C_in, H_in, W_in]
    // 输出张量形状：[N, C_out, H_out, W_out]
    // 其中：H_out = (H_in + 2*padding - 3) / stride + 1
    //       W_out = (W_in + 2*padding - 3) / stride + 1
    std::vector<std::vector<std::vector<std::vector<T>>>> operator()(
        const std::vector<std::vector<std::vector<std::vector<T>>>>& input) const {
        // 解析输入张量维度
        int N = input.size();
        if (N == 0) return {};
        int C_in = input[0].size();
        int H_in = input[0][0].size();
        int W_in = input[0][0][0].size();
        int C_out = weights_.size();

        // 计算输出维度
        int H_out = (H_in + 2 * padding_ - 3) / stride_ + 1;
        int W_out = (W_in + 2 * padding_ - 3) / stride_ + 1;

        // 初始化输出张量
        std::vector<std::vector<std::vector<std::vector<T>>>> output(
            N, std::vector<std::vector<std::vector<T>>>(
                C_out, std::vector<std::vector<T>>(
                    H_out, std::vector<T>(W_out, 0)
                )
            )
        );

        // 对每个样本进行卷积
        for (int n = 0; n < N; ++n) {
            // 对每个输出通道
            for (int c_out = 0; c_out < C_out; ++c_out) {
                // 对输出特征图的每个位置 (h, w)
                for (int h = 0; h < H_out; ++h) {
                    for (int w = 0; w < W_out; ++w) {
                        // 计算输入区域的起始坐标（考虑 padding）
                        int h_start = h * stride_ - padding_;
                        int w_start = w * stride_ - padding_;

                        T sum = bias_[c_out];  // 初始值为偏置

                        // 3x3 卷积核滑动窗口
                        for (int kh = 0; kh < 3; ++kh) {
                            for (int kw = 0; kw < 3; ++kw) {
                                // 输入空间坐标（考虑 padding，超出边界则为 0）
                                int h_in = h_start + kh;
                                int w_in = w_start + kw;

                                // 对每个输入通道累加
                                for (int c_in = 0; c_in < C_in; ++c_in) {
                                    // 边界处理：超出输入范围的位置按 0 计算
                                    if (h_in >= 0 && h_in < H_in && w_in >= 0 && w_in < W_in) {
                                        sum += input[n][c_in][h_in][w_in] * weights_[c_out][c_in][kh][kw];
                                    }
                                }
                            }
                        }

                        output[n][c_out][h][w] = sum;
                    }
                }
            }
        }

        return output;
    }

private:
    std::vector<std::vector<std::vector<std::vector<T>>>> weights_;  // 卷积核 [C_out][C_in][3][3]
    std::vector<T> bias_;                                           // 偏置 [C_out]
    int stride_;                                                     // 步长（默认为 1）
    int padding_;                                                    // 填充（默认为 1）
};

// 辅助函数：打印张量形状（调试用）
template <typename T>
void printTensorShape(const std::vector<std::vector<std::vector<std::vector<T>>>>& tensor, const std::string& name) {
    if (tensor.empty()) {
        std::cout << name << " shape: empty" << std::endl;
        return;
    }
    int N = tensor.size();
    int C = tensor[0].size();
    int H = tensor[0][0].size();
    int W = tensor[0][0][0].size();
    std::cout << name << " shape: [N=" << N << ", C=" << C << ", H=" << H << ", W=" << W << "]" << std::endl;
}

// 测试示例：模拟 MobileNet-SSD 中的 3x3 卷积层
int main() {
    // 1. 定义输入张量：[N=1, C_in=3, H_in=224, W_in=224]（MobileNet-SSD 输入通常为 224x224x3）
    // 为简化测试，这里用 4x4 代替 224x224
    int N = 1;
    int C_in = 3;
    int H_in = 4;
    int W_in = 4;
    std::vector<std::vector<std::vector<std::vector<float>>>> input(
        N, std::vector<std::vector<std::vector<float>>>(
            C_in, std::vector<std::vector<float>>(
                H_in, std::vector<float>(W_in, 1.0f)  // 输入值全为 1
            )
        )
    );

    // 2. 定义卷积核：[C_out=16, C_in=3, 3, 3]（MobileNet-SSD 第一层始卷积通常输出 16 通道）
    int C_out = 16;
    std::vector<std::vector<std::vector<std::vector<float>>>> weights(
        C_out, std::vector<std::vector<std::vector<float>>>(
            C_in, std::vector<std::vector<float>>(
                3, std::vector<float>(3, 0.1f)  // 卷积核值全为 0.1（模拟权重）
            )
        )
    );

    // 3. 定义偏置：[C_out=16]
    std::vector<float> bias(C_out, 0.0f);  // 偏置为 0

    // 4. 创建卷积层（stride=1, padding=1，保持尺寸）
    Conv3x3<float> conv(weights, bias, 1, 1);

    // 5. 执行卷积
    auto output = conv(input);

    // 6. 打印输入输出形状（验证尺寸是否正确）
    printTensorShape(input, "Input");   // 应为 [1, 3, 4, 4]
    printTensorShape(output, "Output"); // 应为 [1, 16, 4, 4]（因 stride=1, padding=1）

    return 0;
}
