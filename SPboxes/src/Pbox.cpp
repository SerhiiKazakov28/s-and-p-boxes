#include "Pbox.h"

void inversePbox(vector<short>& InvPbox)
{
	// Resize inverse P-box so the size matches P-box
	InvPbox.resize(Pbox.size());

	for (size_t i = 0; i < Pbox.size(); i++) {
		InvPbox[Pbox[i] - 1] = i + 1;
	}
}

uint8_t permutate(uint8_t data)
{
	uint8_t permRes = 0;
	for (size_t i = 0; i < Pbox.size(); i++)
	{
		//Get corresponding bit from data and append to result
		permRes |= (data >> (Pbox.size() - Pbox[i]) & 1) << (Pbox.size() - 1 - i);
	}
	return permRes;
}

uint8_t invPermutate(uint8_t data, vector<short>& InvPbox)
{
	uint8_t invPermRes = 0;
	for (size_t i = 0; i < InvPbox.size(); i++)
	{
		//Same as permutate
		invPermRes |= (data >> (InvPbox.size() - InvPbox[i]) & 1) << (InvPbox.size() - 1 - i);
	}
	return invPermRes;
}