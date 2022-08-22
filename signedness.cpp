#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int b = 1; // signed integers work with 2's complement see here: https://www.electronics-tutorials.ws/binary/signed-binary-numbers.html#:~:text=In%20two's%20complement%20form%2C%20a,complement%20is%20one's%20complement%20%2B%201.
	cout << ~b << endl;
	unsigned int a = -1; // unsigned int simply flips all bits, giving a very large number in this case: max because of underflow
	cout << a << endl;

	unsigned long long f = pow(2,60);
	int masksize = 16;
	int bitmask = 0xFFFF;
	long long parity = f >> (3*masksize);
	cout << parity;
	int8_t bb = 0b10010011 & 0b11111111;
	cout << bb;

	return 0;
}