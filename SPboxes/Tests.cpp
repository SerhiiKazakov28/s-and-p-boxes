#include <iostream>
#include "src/Sbox.h"
#include "src/Pbox.h"

using namespace std;

int main() {
	//creating inverse P-box and S-box to decrypt in future
	vector<vector<uint8_t>> InvSbox;
	inverseSbox(InvSbox);
	vector<short> InvPbox;
	inversePbox(InvPbox);

	string message = "Encrypt this message", sboxStr, pboxStr, decrypted;
	cout << "Encrypting:\nInitial message: " << message << endl;

	//loop for put message through S-box symbol by symbol
	for (size_t i = 0; i < message.size(); i++)
	{
		sboxStr += substitute(message[i]);
	}
	cout << "Message after Sbox: " << sboxStr << endl;

	//loop for put message through P-box symbol by symbol
	for (size_t i = 0; i < sboxStr.size(); i++)
	{
		pboxStr += permutate(sboxStr[i]);
	}
	cout << "Message after Sbox and Pbox (Encrypted message): " << pboxStr << "\n\nDecrypting:\n";
	sboxStr.clear();

	//loop for put message through inverse P-box symbol by symbol
	for (size_t i = 0; i < pboxStr.size(); i++)
	{
		sboxStr += invPermutate(pboxStr[i], InvPbox);
	}
	cout << "Encrypted message after Pbox: " << sboxStr << endl;

	//loop for put message through inverse S-box symbol by symbol
	for (size_t i = 0; i < pboxStr.size(); i++)
	{
		decrypted += invSubstitute(sboxStr[i], InvSbox);
	}
	cout << "Encrypted message after Sbox (Decrypted message): " << decrypted << endl;
	if (!message.compare(decrypted))
	{
		cout << "Initial and decrypted messages are equal" << endl;
	}
	else cout << "Initial and decrypted messages are not equal" << endl;
	return 0;
}