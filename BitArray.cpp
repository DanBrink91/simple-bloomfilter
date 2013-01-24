#include "BitArray.h"
#include <iostream>

BitArray::BitArray(void)
{
	bits = std::vector<char>();
	reset();
}

BitArray::BitArray(size_t initSize)
{
	bits = std::vector<char>(initSize);
}
bool BitArray::get(int index)
{
	int charIndex  = index/8;
	int bitIndex = index % 8;
	if(charIndex >= bits.size())
		return false;
	return (bits.at(charIndex) & (1 << bitIndex)); 
}
void BitArray::set(size_t index)
{
	if(index > bits.capacity())
	{
		std::cout << "Resizing... " << index/8 << std::endl;
		bits.resize(index, 0);
	}
	int charIndex  = index/8;
	int bitIndex = index % 8;
	bits[charIndex] = bits[charIndex] | 1 << bitIndex;
}
void BitArray::reset()
{
	for (auto it = bits.begin(); it != bits.end(); it++)
	{
		*it = 0;
	}
}
//Doesn't print the actual bits, only the integer representation
void BitArray::print()
{
	for (auto it = bits.begin(); it != bits.end(); it++)
	{
		std::cout << int(*it) << std::endl;
	}
	std::cout << std::endl;
}
BitArray::~BitArray(void)
{
}
