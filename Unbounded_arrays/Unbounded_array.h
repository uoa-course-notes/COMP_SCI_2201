#ifndef __UNBOUNDED_ARRAYS__
#define __UNBOUNDED_ARRAYS__
#include <assert.h>
#include <iostream>


class Unbounded_Array{
  private:
    // Constants 
    int alpha = 2;
    int beta = 4;

    int w = 1;
    int n = 0;

    int *b = new int[w-1]; // array of integers
  public:
    // Overloading [] operator to access elements in the array 
    int size(){return n;}
    // Utility function to print contents 
    void print() const{
      std::cout << "<";
      
      for (int i = 0; i < n; i++){
        if (i == n-1) std::cout << b[i] << std::endl;
        else std::cout << b[i] << ", ";
      }
      std::cout << "<";
    }
    int& operator[](int i){
      assert(0 <= i && i < n);
      return b[i];
    }

    void reallocate(int w_prime){
      w = w_prime;
      int* b_prime = new int[w];
      for (int i = 0; i < n; i++){
        b_prime[i] = b[i];
      }
      delete[] b;
      b = b_prime;
    }
    // Procedures 
    void push_back(int e){
      if (n == w) reallocate(beta * n);
      // Else 
      b[n] = e;
      n++;
    }
    
    void pop_back(){
      assert(n > 0);
      n--;
      if (alpha * n <= w && n > 0){
          reallocate(beta*n);
      }
    }


};




#endif 

