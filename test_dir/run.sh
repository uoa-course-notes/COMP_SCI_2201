#!/bin/bash



# Check if the correct number of arguments is provided 
if [ "$#" -ne 3 ]; then
  echo "Usage: $0 <arg1> <arg2> <arg3>"
  exit 1 
fi 

# Compile the main.cpp 
g++ -std=c++11 -o main.out -O2 -Wall main.cpp

# Execute the compiled program with the procided arguments 
./main.out "$1" "$2" "$3"
