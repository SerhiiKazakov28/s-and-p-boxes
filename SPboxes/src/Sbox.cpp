#include <iostream>
#include "Sbox.h"

void inverseSbox(vector<vector<uint8_t>>& InvSbox)
{
	// Resize inverse S-box so the size matches S-box
	InvSbox.resize(Sbox.size());
	for (size_t i = 0; i < InvSbox.size(); i++)
		InvSbox[i].resize(Sbox[0].size());

	for (size_t i = 0; i < Sbox.size(); i++)
	{
		for (size_t j = 0; j < Sbox[0].size(); j++)
		{
			/*Value in table becomes the index of cell in inversed,
			index of table becomes the value in this cell*/
			InvSbox[(int)Sbox[i][j] >> 4][(int)Sbox[i][j] & lessTetradMask] = (i << 4) | j;
		}
	}
}

uint8_t substitute(uint8_t data)
{
	/*Getting value from table:
	4 most significant bits - index of row
	4 less significant bits - index of column */
	return Sbox[(int)data >> 4][(int)data & lessTetradMask];
}

uint8_t invSubstitute(uint8_t data, vector<vector<uint8_t>>& InvSbox)
{
	//Same as substitute
	return InvSbox[(int)data >> 4][(int)data & lessTetradMask];
}