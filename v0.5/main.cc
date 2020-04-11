#include <iostream>
#include <string>
#include <chrono>
#include "includes/voraldo/v.h"


/*
Conditional Operator (inline if statment)
-----------------------------------------
  x ? y : z
  works like
  if(x) y else z
Just a note, this:
------------------
  a = x ? : y;
  is the same as:
  a = x ? x : y;
*/


//stream class shit
using std::cout;
using std::endl;
using std::cin;


//Chrono class aliases
using Clock=std::chrono::high_resolution_clock;
using milliseconds=std::chrono::milliseconds;

int init_x = 257;
int init_y = 257;
int init_z = 257;

Voraldo *main_block;

int main()
{
 main_block = new Voraldo();
}
