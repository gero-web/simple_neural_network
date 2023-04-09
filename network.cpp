#include "./network.h"
#include <cmath>
#define M_E   2.7182818284590452354


double mse_inner(double answer, double y){
    return sqrt(pow((answer - y),2));

}

double sigmoid(double x ){
    int numerator = 1;
    double denominator =  1 + pow(M_E, -x);
    return numerator / denominator;
}


void Network::init_array2d(const int size_i,const int size_j, double* arr[]){

    for (size_t i = 0; i < size_i; i++)
        {
            arr[i] = new double[size_j];
            for (size_t j = 0; j < size_j; j++)
            {
                
                arr[i][j] =  1 / ( 1 + ((double)rand() / 20)) ;
              
            }
            
        }
}

void Network::free_array2d(const int size_i, double* arr[]){
      for (size_t i = 0; i < size_i; i++)
        {
            delete[] arr[i];        
        }
    delete[] arr;
}


Network::Network(/* args */)
{
        srand((unsigned)time(NULL));

        w1= new double* [input_size];
        w2 = new double* [hidden_size];
        w_out = new double* [out_size];

        // Рандомное заполнение для тринеровки 
        init_array2d(input_size, hidden_size, w1);
        init_array2d(hidden_size,hidden_size, w2);
        init_array2d(out_size,hidden_size, w_out);
        /////
        
        input = new double[input_size];
        hidden1 = new double[hidden_size];
        hidden1 = new double[hidden_size];
        out = new double[out_size];
     

}

void Network::excute( int size_layer_out, int size_layer_in, double out_[], double input_[], double* w[]){
    
    for (size_t j = 0; j < size_layer_out; j++)
    {
      
        for (size_t i = 0; i < size_layer_in; i++)
        {
            out_[i] += input_[i] * w[i][j];
        }
  
    }

    for (size_t i = 0; i < size_layer_in; i++)
    {
        out_[i] = sigmoid(out_[i]);
    }
    
}
void Network::withdraw(const int size_i, const int size_j , double* arr[]){
    for (size_t i = 0; i < size_i; i++)
    {
        for (size_t j = 0; j < size_j; j++)
        {
           std::cout << arr[i][j] << "|";
        }
         std::cout << std::endl;
    }
    
}

Network::~Network()
{
    free_array2d(input_size, w1);
    free_array2d(hidden_size, w2);
    free_array2d(out_size, w_out);
    delete[] input;
    delete[] hidden1;
    delete[] hidden2;
}
