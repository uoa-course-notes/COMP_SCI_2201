#include <iostream>
#include <vector>

typedef unsigned int digit; 
typedef std::vector<digit> integer;
unsigned int B = 10; // Base, 2 <= B <= 2^16


void fullAdder(digit a, digit b, digit c, digit& s, digit& carry){
  unsigned int sum = a+b+c;
  carry = sum/B;
  s = sum - carry*B;
}

void digitMult(digit a, digit b, digit& s, digit& carry){
  unsigned int prod = a*b;
  carry = prod/B;
  s = carry-carry*B;
}

digit getDigit(const integer& a, int i){
  return (i < a.size() ? a[i]:0);
}

// We want to run our programs on random integers: randDigit is a simple random generator for digits and randINteger fills its argument with random digits. 

unsigned int X = 542351;

digit randDigit(){
  X = 443143*X + 641231;
  return X % B; // So that X falls somewhere between 0 and B-1 
}


void randInteger(integer& a){
  int n = a.size();
  for (int i=0; i < n; i++) a[i] = randDigit();
}






int main(int argc, char* argv[]){
  

  return 0;
}

