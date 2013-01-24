#pragma once

#include <vector>
class BitArray
{
public:
	BitArray(void);
	BitArray(size_t initSize);
	~BitArray(void);

	bool get(int index);
	void set(size_t index);
	void reset();
	void print();
private:
	std::vector<char> bits;
};

