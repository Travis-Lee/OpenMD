#ifndef POWER_H
#define POWER_H

template<typename T>
class Power{
public:
    Power();
   
    ~Power();

    T power(T base, int exponent);   
    
    bool equal(T num1, T num2);

    T PowerWithUnsignedExponent(T base, unsigned int exponent);

    // 添加 getter
    bool isInvalid() const { return g_InvalidInput; }

private:
    bool g_InvalidInput = false;

};

#endif

