#pragma once
#include <ctime>
#include <iostream>
#include <cstdlib>

double mse_inner(double answer, double out_answer); // Вычисляет % ошибки

double  sigmoid(double x); // функция активации

class Network
{
private:
    const unsigned int out_size = 33;
    const unsigned int input_size = 784;
    const unsigned int hidden_size = 128;
    double** w1;
    double** w2;
    double** w_out;
    double* out;
    double*  input;
    double* hidden1;
    double* hidden2;
    void init_array2d(const int size_i,const int size_j, double* arr[]);
    void free_array2d(const int size_i, double* arr[]);
    void withdraw(const int size_i, const int size_j , double* arr[]);
    void excute(int size_layer_out, int size_layer_in, double out_[], double input_[], double* w[]);
    
public:
    Network(/* args */);
    ~Network();
};
