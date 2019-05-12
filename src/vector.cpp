#include "vector.h"
#include <iostream>






































dtl::vector::vector()
{
	dVector<int> a;
	
}

dtl::vector::~vector()
{

}


dtl::vector_int::vector_int(unsigned int x, unsigned int d, unsigned int threshhold)
{
	if(x <= 1)
		throw "cannot have an array with blocking of 1 or less";
	mArray = new int[x];
	place = 0;
	arraySize = x;
	dist = d;
	thresh = threshhold;
	std::cout << "\nConstructed with sizeof: " << x << " dist of: " << d << " and threshhold of: " << threshhold << "\n";
}

dtl::vector_int::~vector_int()
{
	delete mArray;
}

void
dtl::vector_int::push_back(int x)
{
	if(place == arraySize)
		resize();

	mArray[place] = x;
	place++;
}


void
dtl::vector_int::pop_back()
{
	place--;
	mArray[place] = 0;
	if(arraySize - place > dist + thresh)
		resize();
}

int
dtl::vector_int::at(unsigned int w)
{
	if(w >= place)
	{
		throw "Unaccessable!";
	}
	else
	{
		return mArray[w];
	}
	
	return 666;
}

unsigned int
dtl::vector_int::size()
{
	return place;
}

unsigned int
dtl::vector_int::capacity()
{
	return arraySize;
}


int*
dtl::vector_int::begin()
{
	return mArray;
}

int*
dtl::vector_int::end()
{
	return mArray+place;
}

int*
dtl::vector_int::rbegin()
{
	
}

int*
dtl::vector_int::rend()
{
	
}

void
dtl::vector_int::clear()
{
	int *trash;
	trash = mArray;
	mArray = new int[dist];
	place = 0;
	arraySize = dist;
	delete trash;
}

void 
dtl::vector_int::erase(unsigned int w)
{
	if(w >= place)
		throw "cannot erase non-existent element";
	else
	{
		int *nArray = new int[(place + dist) - 1];
		unsigned int nIt = 0;
		for(unsigned int i = 0; i < place; i++)
		{
			if(i != w)
			{
				nArray[nIt] = mArray[i];
				nIt++;
			}
		}
		int *oldArray; 
		oldArray = mArray;
		mArray = nArray;
		delete oldArray;
		
		arraySize = (place + dist) - 1;
		place--;

	}
}

void
dtl::vector_int::resize()
{
	if (arraySize < place)
	{
		throw "Array smaller than array.end()!";
	}
	else
	{
		int *nArray = new int[place + dist];
		for(unsigned int i = 0; i < place; i++)
		{
			nArray[i] = mArray[i];
		}
		int *oldArray;
		oldArray = mArray;
		mArray = nArray;
		delete oldArray;
		std::cout << "\nResized array from sizeof: '" << arraySize << "' to a sizeof: '" << place + dist << "'\nPlace == '" << place << "'\n";
		arraySize = place + dist;
	}
}