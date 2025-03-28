#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
    double real, image; // 复数的实部与虚部
public:
    Complex(double r = 0, double i = 0); // 构造函数
    Complex(const Complex &other);       // 拷贝构造函数
    void print();                        // 打印复数

    Complex operator+(const Complex &other); // 重载加法运算符（二元）
    Complex operator-(const Complex &other); // 重载减法运算符（二元）
    Complex operator-();                     // 重载求负运算符（一元）
    Complex operator=(const Complex &other); // 重载赋值运算符（二元）

    Complex &operator++();   // 重载前置++
    Complex operator++(int); // 重载后置++
    Complex &operator--();   // 重载前置--
    Complex operator--(int); // 重载后置--
};
#endif