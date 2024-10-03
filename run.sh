#!/bin/bash 




# Checks if the correct number of arguments was provided 
if ["$#" -ne 3]; then 
  echo "Usage: $0"
  exit 1
fi 




# Compile main.cpp 
g++ -std=c++11 -o main.out -O2 -Wall main.cpp 


# Execute the compiled program with the provided arguments
./main.out "$1"
