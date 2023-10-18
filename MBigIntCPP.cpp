#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

class MBigIntCPP
{
public:

	MBigIntCPP()
	{

	}

	MBigIntCPP(std::string hexString)
	{
		setHex(hexString);
	}


	void setHex(std::string hexString)
	{
		std::string substr;
		std::stringstream ss;
		unsigned __int32 value;
		bool t = true;
		this->_digits.clear();

		for (size_t i = hexString.length(); t; i -= 8)
		{
			if (i > 8)
				substr = hexString.substr(i - 8, 8);
			else
			{
				substr = hexString.substr(0, i);
				t = false;
			}

			ss << std::hex << substr;
			ss >> value;

			ss.clear();
			this->_digits.push_back(value);
		}

		this->_remove_leading_zeros();
	}

	std::string getHex()
	{
		std::stringstream ss;
		std::string result;
		size_t pos;

		for (size_t i = this->_digits.size(); i > 0; i--)
		{
			ss << std::uppercase << std::setfill('0') << std::setw(8) << std::hex << this->_digits[i - 1];
		}

		result = ss.str();
		pos = result.find_first_not_of('0');

		if (pos != std::string::npos)
		{
			result = result.substr(pos);
		}
		else
		{
			result = "0";
		}

		return result;
	}

	std::vector<unsigned __int32> getVector()
	{
		return this->_digits;
	}

	void INV()
	{
		for (size_t i = 0; i < this->_digits.size(); i++)
		{
			this->_digits[i] = ~this->_digits[i];
		}
	}

	void shiftR(int n)
	{
		int fullShifts = n / 32;
		int bitShift = n % 32;
		size_t i;

		std::vector<unsigned __int32> result(this->_digits.size() - fullShifts, 0);

		if (fullShifts < this->_digits.size())
		{
			for (i = 0; i < (this->_digits.size() - fullShifts); i++)
			{
				result[i] = (this->_digits[i + fullShifts] >> bitShift);
			}

			if (bitShift > 0)
			{
				for (i = 0; i < (this->_digits.size() - fullShifts - 1); i++)
				{
					result[i] |= (this->_digits[i + fullShifts + 1] << 32 - bitShift);
				}
			}
		}

		this->_digits = result;

		this->_remove_leading_zeros();
	}

	void shiftL(int n)
	{
		int fullShifts = n / 32;
		int bitShift = n % 32;
		size_t i;

		std::vector<unsigned __int32> result(this->_digits.size() + fullShifts + 1, 0);

		for (i = 0; i < this->_digits.size(); i++)
		{
			result[i + fullShifts] = (this->_digits[i] << bitShift);
		}

		if (bitShift > 0)
		{
			for (i = 0; i < this->_digits.size(); i++)
			{
				result[i + fullShifts + 1] |= (this->_digits[i] >> 32 - bitShift);
			}
		}

		this->_digits = result;

		this->_remove_leading_zeros();
	}

	static MBigIntCPP XOR(MBigIntCPP a, MBigIntCPP b)
	{
		size_t max = a.getVector().size();
		MBigIntCPP *x, result;

		if (max < b.getVector().size())
		{
			result = b;
			x = &a;
		}
		else
		{
			max = b.getVector().size();
			result = a;
			x = &b;
		}

		for (size_t i = 0; i < max; i++)
		{
			result._digits[i] ^= x->_digits[i];
		}

		return result;
	}

	static MBigIntCPP OR(MBigIntCPP a, MBigIntCPP b)
	{
		size_t max = a.getVector().size();
		MBigIntCPP *x, result;

		if (max < b.getVector().size())
		{
			result = b;
			x = &a;
		}
		else
		{
			max = b.getVector().size();
			result = a;
			x = &b;
		}

		for (size_t i = 0; i < max; i++)
		{
			result._digits[i] |= x->_digits[i];
		}

		return result;
	}

	static MBigIntCPP AND(MBigIntCPP a, MBigIntCPP b)
	{
		size_t max = a.getVector().size();
		MBigIntCPP *x, result;

		if (max < b.getVector().size())
		{
			result = a;
			x = &b;
		}
		else
		{
			max = b.getVector().size();
			result = b;
			x = &a;
		}

		for (size_t i = 0; i < max; i++)
		{
			result._digits[i] &= x->_digits[i];
		}

		return result;
	}

	static MBigIntCPP ADD(MBigIntCPP a, MBigIntCPP b)
	{
		size_t i, max = a.getVector().size();
		MBigIntCPP *x, *y, result;
		bool over = 0;

		if (max < b.getVector().size())
		{
			result = b;
			x = &a;
			y = &b;
		}
		else
		{
			max = b.getVector().size();
			result = a;
			x = &b;
			y = &a;
		}

		result._digits.resize(result._digits.size() + 1);

		for (i = 0; i < max; i++)
		{
			result._digits[i] += x->_digits[i] + over;
			over = 0;

			if (result._digits[i] < x->_digits[i] || result._digits[i] < y->_digits[i])
			{
				over = 1;
			}
		}

		for (i; i < result._digits.size() - 1; i++)
		{
			result._digits[i] += over;
			over = 0;

			if (result._digits[i] < y->_digits[i])
			{
				over = 1;
			}
		}

		if (over == 1)
			result._digits[i] += over;

		return result;
	}

	static MBigIntCPP SUB(MBigIntCPP a, MBigIntCPP b)
	{
		size_t i, max = a.getVector().size();
		MBigIntCPP *x, *y, result;
		bool borrow = 0;
		bool invert = 0;

		if (max < b.getVector().size())
		{
			result = b;
			x = &a;
			y = &b;
			invert = 1;
		}
		else
		{
			max = b.getVector().size();
			result = a;
			x = &b;
			y = &a;
		}

		for (i = 0; i < max; i++)
		{
			if (result._digits[i] < x->_digits[i] || (result._digits[i] == x->_digits[i] && borrow))
			{
				result._digits[i] += (0xFFFFFFFF - x->_digits[i]) - borrow + 0x1;
				borrow = 1;
			}
			else
			{
				result._digits[i] -= x->_digits[i] + borrow;
				borrow = 0;
			}
		}

		for (i; i < result._digits.size(); i++)
		{
			if (result._digits[i] >= borrow)
			{
				result._digits[i] -= borrow;
				borrow = 0;
			}
		}

		if (invert)
		{
			for (i = 0; i < result._digits.size(); i++)
			{
				result._digits[i] -= 0x1;
			}
			result.INV();
		}

		result._remove_leading_zeros();

		return result;
	}

	static MBigIntCPP MUL(MBigIntCPP a, MBigIntCPP b)
	{
		size_t sizeA = a._digits.size();
		size_t sizeB = b._digits.size();
		MBigIntCPP resultAdd1;
		MBigIntCPP resultAdd2;
		MBigIntCPP result;
		resultAdd1._digits = std::vector<unsigned __int32>(a._digits.size() + b._digits.size(), 0);
		unsigned __int32 tmpMul[8];
		unsigned __int32 over = 0;

		for (size_t i = 0; i < sizeA; i++)
		{
			resultAdd1._digits = std::vector<unsigned __int32>(a._digits.size() + b._digits.size(), 0);
			resultAdd2._digits = std::vector<unsigned __int32>(a._digits.size() + b._digits.size(), 0);

			for (size_t j = 0; j < sizeB; j++)
			{
				tmpMul[0] = (a._digits[i] << 16) >> 16;
				tmpMul[1] = a._digits[i] >> 16;
				tmpMul[2] = (b._digits[j] << 16) >> 16;
				tmpMul[3] = b._digits[j] >> 16;

				tmpMul[4] = tmpMul[0] * tmpMul[2];
				tmpMul[5] = tmpMul[0] * tmpMul[3];
				tmpMul[6] = tmpMul[1] * tmpMul[2];
				tmpMul[7] = tmpMul[1] * tmpMul[3];

				tmpMul[1] = (tmpMul[5] << 16) >> 16;
				tmpMul[2] = (tmpMul[6] << 16) >> 16;
				tmpMul[3] = (tmpMul[4] >> 16) + tmpMul[1] + tmpMul[2];

				over = (tmpMul[3] >> 16);

				resultAdd1._digits[i + j] = ((tmpMul[4] << 16) >> 16) + (tmpMul[3] << 16);

				tmpMul[1] = tmpMul[5] >> 16;
				tmpMul[2] = tmpMul[6] >> 16;
				resultAdd2._digits[i + j + 1] = tmpMul[7] + tmpMul[1] + tmpMul[2] + over;

				over = 0;

			}
			result = MBigIntCPP::ADD(result, MBigIntCPP::ADD(resultAdd1, resultAdd2));
			resultAdd1._digits.clear();
			resultAdd2._digits.clear();
		}

		result._remove_leading_zeros();

		return result;
	}

private:
	std::vector<unsigned __int32> _digits;

	void _remove_leading_zeros()
	{
		while (this->_digits.size() > 1 && this->_digits.back() == 0)
		{
			this->_digits.pop_back();
		}
	}
};

