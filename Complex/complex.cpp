#include <iostream>
#include "complex.hpp"
using namespace std;
Complex::Complex(double r, double i):real(r),image(i){} // 构造函数
Complex::Complex(const Complex &other):real(other.real),image(other.image){}       // 拷贝构造函数
void Complex::print(){
    if(real>0){
        if(image>0) cout << real << '+' << image << 'i' << endl;
        if(image==0) cout << real << endl;
        if(image<0) cout << real << '-' << image << 'i' << endl;
    }
    if(real==0){
        if(image>0) cout << image << 'i' << endl;
        if(image==0) cout << real << endl;
        if(image<0) cout << '-' << image << 'i' << endl;
    }
    if(real<0){
        if(image>0) cout << '-' << real << '+' << image << 'i' << endl;
        if(image==0) cout << '-' << real << endl;
        if(image<0) cout << '-' << real << '-' << image << 'i' << endl;
    }
}                        // 打印复数

Complex Complex::operator+(const Complex &other){
    return Complex(real+other.real, image+other.image);
} // 重载加法运算符（二元）
Complex Complex::operator-(const Complex &other){
    return Complex(real-other.real, image-other.image);
} // 重载减法运算符（二元）
Complex Complex::operator-(){
    return Complex(-real, -image);
}                     // 重载求负运算符（一元）
Complex Complex::operator=(const Complex &other){
    return Complex(other);
} // 重载赋值运算符（二元）

Complex &Complex::operator++(){
    ++real;++image;
    return *this;
}   // 重载前置++
Complex Complex::operator++(int){
    return Complex(real++, image++);
} // 重载后置++
Complex &Complex::operator--(){
    --real;--image;
    return *this;
}   // 重载前置--
Complex Complex::operator--(int){
    return Complex(real--, image--);
} // 重载后置--