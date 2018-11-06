#include "TritSet.h"

TritSet::TritSet()
{

}

TritSet::TritSet(size_t n)
{
	array.reserve(n / element);
}

TritSet::~TritSet()
{
	array.clear();
}

TritSet::TritSet(const TritSet &src)
{
	last = src.last;
	array.reserve(src.array.capacity());
	array.assign(src.array.begin(), src.array.end());
}

TritSet::TritSet(TritSet &&src)
{
	last = src.last;
	array.assign(src.array.begin(), src.array.end());
	array.reserve(src.array.capacity());
	src.array.clear();
}

////////////////////////////______ T R I T S E T _____/////////////////////////////////////

TritSet& TritSet::operator=(const TritSet& other)
{
	last = other.last;
	array.assign(other.array.begin(), other.array.end());
	return *this;
}

TritSet& TritSet::operator=(TritSet&& other)
{
	last = other.last;
	array = other.array;
	array.reserve(other.array.capacity());
	other.array.clear();
	return *this;
}

TritSet::Proxy TritSet::operator[](const size_t index)
{
	return TritSet::Proxy::Proxy(this, index);
}

Trit TritSet::operator[](const size_t index) const
{
	if (index / element >= array.size())
		return UNKNOWN;
	size_t num_of_trit = index % element;
	size_t num_of_array = index / element;
	Trit answer = static_cast<Trit>(array[num_of_array] & (0b11 << (2 * element - num_of_trit - 2)));
	return answer;
}

TritSet TritSet::operator&(TritSet &other)
{
	Trit first_trit = UNKNOWN;
	Trit second_trit = UNKNOWN;
	size_t n = this->length() > other.length() ? this->length() : other.length();
	TritSet answer;
	answer.array.reserve(this->array.capacity() > other.array.capacity() ? this->array.capacity() : other.array.capacity());
	for (size_t i = 0; i < n; ++i)
	{
		if (this->array.size() == 0 || i / element >= this->array.size())
		{
			first_trit = UNKNOWN;
		}
		else
		{
			first_trit = static_cast<Trit>((array[i / element] << 2 * i) >> 30);
		}

		if (other.array.size() == 0 || i / element >= other.array.size())
		{
			second_trit = UNKNOWN;
		}
		else
		{
			second_trit = static_cast<Trit>((other.array[i / element] << 2 * i) >> 30);
		}
		answer[i] = first_trit & second_trit;
	}
	return answer;
}


TritSet TritSet::operator|(TritSet &other)
{
	Trit first_trit = UNKNOWN;
	Trit second_trit = UNKNOWN;
	size_t n = this->length() > other.length() ? this->length() : other.length();
	TritSet answer;
	answer.array.reserve(this->array.capacity() > other.array.capacity() ? this->array.capacity() : other.array.capacity());
	for (size_t i = 0; i < n; ++i)
	{
		if (this->array.size() == 0 || i / element >= this->array.size())
		{
			first_trit = UNKNOWN;
		}
		else
		{
			first_trit = static_cast<Trit>((array[i / element] << 2 * i) >> 30);
		}

		if (other.array.size() == 0 || i / element >= other.array.size())
		{
			second_trit = UNKNOWN;
		}
		else
		{
			second_trit = static_cast<Trit>((other.array[i / element] << 2 * i) >> 30);
		}
		answer[i] = first_trit | second_trit;
	}
	return answer;
}


TritSet TritSet::operator~()
{
	Trit one_trit = UNKNOWN;
	TritSet answer(this->capacity());
	for (size_t i = 0; i < this->length(); ++i)
	{
		one_trit = (*this)[i];
		answer[i] = ~(one_trit);
	}
	return answer;
}



size_t TritSet::length()
{
	if (array.size() > 0)
	{
		size_t num_of_array = (array.size() - 1) * 16;
		size_t answer = num_of_array;
		size_t unit = (array.size() == 0 || num_of_array / element >= array.size()) ? UNKNOWN : array[num_of_array / element];
		int i = 15;
		while (i >= 0 && (((unit << 30) >> 30) == UNKNOWN))
		{
			--i;
			unit >>= 2;
		}
		if (i > 0)
			answer += i + 1;
		return answer;
	}
	else 
		return 0;
}

const size_t TritSet::capacity()
{
	return array.capacity() * element;
}

size_t  TritSet::cardinality(Trit value)
{
	size_t count = 0, last = 0, notUnknown = 0;
	for (size_t i = 0; i < array.size() * element; ++i)
	{
		Trit t = (*this)[i];
		if (value != UNKNOWN && static_cast<size_t>(t) == value)
			count++;
		if (value == UNKNOWN && static_cast<size_t>(t) != value)
		{
			last = i;
			notUnknown++;
		}
	}
	if (value == UNKNOWN)
		count = last - notUnknown + 1;
	return count;
}

unordered_map < Trit, int, hash<int> > TritSet::cardinality()
{
	unordered_map < Trit, int, hash<int> > answer;
	answer[TRUE] = this->cardinality(TRUE);
	answer[FALSE] = this->cardinality(FALSE);
	answer[UNKNOWN] = this->cardinality(UNKNOWN);
	return answer;
}

void TritSet::shrink()
{
	if (array.size() == 0)
	{
		array.clear();
		last = -1;
		return;
	}
	last = 0;
	for (size_t i = 0; i < array.size() * element; ++i)
	{
		if (i / element >= array.size() || array[i / element] == 0)
			i += element - 1;
		else {
			Trit t = (*this)[i];
			if (static_cast<size_t>(t) != 0)
				last = i;
		}
	}
	if (last > 0)
		array.erase(array.begin() + last / element + 1, array.end());
	else
		array.clear();
	array.shrink_to_fit();

	return;
}

void TritSet::trim(size_t lastIndex)
{
	if (array.size() > 0 && lastIndex / element <= array.size()) {
		for (size_t i = lastIndex % element; i < element; ++i)
		{
			size_t value = 2 * i;
			size_t shift = sizeof(size_t) * 8 - value - 2;
			size_t mask = 0 ^ (0b11 << shift);
			mask ^= ULONG_MAX;
			array[lastIndex / element] &= mask;
		}
		array.erase(array.begin() + lastIndex / element + 1, array.end());
	}
	return;
}

//////////////////////////////_______ P R O X Y ______///////////////////////////////////////

TritSet::Proxy::Proxy(TritSet *TSet, size_t _index)
{
	Set = TSet;
	index = _index;
}

TritSet::Proxy &TritSet::Proxy::operator=(Trit other)
{
	if (other != UNKNOWN)
	{
		size_t value = (index % element) * 2;
		if (index / element + 1 > Set->array.size())
		{
			Set->last = index / element;
			size_t allocLength = Set->array.capacity();
			Set->array.resize(index / element + 1);
			Set->array.shrink_to_fit();
			if (allocLength < index / element + 1)
				Set->array.reserve(index / element + 1);
			else
				Set->array.reserve(allocLength);
		}
		size_t shift = sizeof(size_t) * 8 - value - 2;
		size_t mask = 0 ^ (0b11 << shift);
		mask ^= ULONG_MAX;
		Set->array[index / element] &= mask;
		mask = (other) << shift;
		Set->array[index / element] ^= mask;
	}
	else
	{
		size_t shift = element * 2 - 2 * (index%element) - 2;
		if ((index / element + 1 <= Set->array.size()) && (static_cast<size_t>(other) != (Set->array[index / element] >> shift)))
		{
			size_t mask = -1 ^ (0b11 << shift);
			Set->array[index / element] &= mask;
		}
	}
	return *this;
}

TritSet::Proxy &TritSet::Proxy::operator=(Proxy &other)
{
	return (*this);
}

TritSet::Proxy::operator Trit() const
{
	if (Set->array.size() > 0 && index / element < Set->array.size()) {
		size_t num_of_trit = index % element;
		size_t num_of_array = index / element;
		size_t shift = 2 * element - 2 * num_of_trit - 2;
		Trit answer = static_cast<Trit>((Set->array[num_of_array] & (0b11 << shift)) >> shift);
		return answer;
	}
	return UNKNOWN;
}


bool TritSet::Proxy::operator==(const Trit &other)
{
	if (index / element >= Set->array.size())
		return other == UNKNOWN ? true : false;
	size_t answer_trit = Set->array[index / element];
	size_t shift = (2 * element - 2*(index % element) - 2);
	answer_trit = (answer_trit & (0b11 << shift)) >> shift;
	if (other == answer_trit)
		return true;
	return false;
}
