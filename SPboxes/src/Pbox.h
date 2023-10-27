#pragma once
#include <vector>

using std::vector;

//P-box table, 8-bit size (could be defined by user)
static const vector<short> Pbox{ 7, 4, 8, 1, 3, 5, 2, 6 };

//Function to inverse P-box. Accepts reference to vector for save inverse table
void inversePbox(vector<short>& InvPbox);

/*Function to use P-box.Accepts 8-bit data to permutate and
returns permutation result*/
uint8_t permutate(uint8_t data);

/*Function to use inverse P-box.Accepts 8-bit data to permutate
and inverse P-box table for permutation rules. Returns permutation result*/
uint8_t invPermutate(uint8_t data, vector<short>& InvPbox);