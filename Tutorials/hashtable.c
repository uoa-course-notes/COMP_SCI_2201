#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_NAME 256
#define TABLE_SIZE 10 



typedef struct {
  char name[MAX_NAME];
  int age;
}person;

person* hash_table[TABLE_SIZE];

unsigned int hash(char* name){
  int length = strnlen(name, MAX_NAME);
  unsigned int hash_value = 0;
  for (int i=0; i<length; i++){
    hash_value += name[i];
    hash_value = (hash_value * name[i]) % TABLE_SIZE;
  }
  return hash_value;
}


void init_hash_table(){
  for (int i=0; i<TABLE_SIZE; i++){
    hash_table[i] = NULL;
  }
  // table is empty 

}

void print_table(){
  printf("Start\n");
  for (int i=0; i<TABLE_SIZE; i++){
    if (hash_table[i] == NULL)
      printf("\t%i\t---\n", i);
    else{
      printf("\t%i\t%s\n", i, hash_table[i] -> name);
    }
  }
  printf("End\n");
}

bool hash_table_insert(person* p){
  if (p == NULL) return false;
  int index = hash(p -> name);
  if (hash_table[index] != NULL) return false;
  
  hash_table[index] = p;
  return true;
}


person* hash_table_lookup (char* name){
  int index = hash(name);
  if (hash_table[index] != NULL && strncmp(hash_table[index]->name, name, MAX_NAME) == 0) return hash_table[index];
  else return NULL;
}

int main(int argc ,char* argv[]){
  init_hash_table();
  print_table();
  person jacob = {.name = "jacob", .age=256};
  person kate = {.name = "kate", .age=56};
  person kelly = {.name = "kelly", .age=26};
  
  hash_table_insert(&jacob);
  hash_table_insert(&kate);
  hash_table_insert(&kelly);
  print_table();


  person* tmp = hash_table_lookup("kate");
  if (tmp == NULL){
    printf("Not found\n");
  }
  else{
    printf("Found %s.\n", tmp -> name);
  }
  // char* name[] = {
  //   "Jacob",
  //   "Seth",
  //   "Roberto",
  //   "Jean",
  //   "Siv",
  //   "Natalie",
  //   "Bob",
  //   "K"
  // };

  // for (int i=0; i<7; i++){
  //   printf("%s --> %d\n", name[i],hash(name[i]));
  // }

  return 0;
}
