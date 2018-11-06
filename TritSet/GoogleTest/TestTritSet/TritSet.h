#pragma once
#ifndef TRIT_TRITSET_H
#define TRIT_TRITSET_H
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <iterator>
#include "Trit.h"


class TritSet {
private:
	vector <size_t> array;
	static const size_t element = 4 * sizeof(size_t);
	int last = -1;

public:
	TritSet();
	TritSet(const TritSet &src);
	TritSet(TritSet &&src);
	TritSet(size_t n);
	~TritSet();

	class Proxy {
	private:
		size_t index;
		TritSet *Set;
	public:

		Proxy(TritSet *TSet, size_t _index);
		Proxy &operator=(Trit other);
		Proxy &operator=(Proxy &other);
		operator Trit() const;
		bool operator==(const Trit &other);
	};
	TritSet& operator=(const TritSet& other);
	TritSet& operator=(TritSet&& other);
	Proxy operator[](const size_t index);
	Trit operator[](const size_t index) const;

	TritSet operator &(TritSet &other);
	TritSet operator |(TritSet &other);
	TritSet operator ~();

	size_t length();
	const size_t capacity();
	size_t  cardinality(Trit value);
	unordered_map < Trit, int, hash<int> > cardinality();
	void shrink();
	void trim(size_t lastIndex);
};

#endif //TRIT_TRITSET_H
#pragma once
