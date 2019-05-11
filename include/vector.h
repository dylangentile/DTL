#pragma once

namespace dtl
{
	class vector
	{
	public:
		vector();
		~vector();
		virtual void push_back() = 0;
		virtual void pop_back() = 0;
		virtual void at() = 0;
		virtual unsigned int size() = 0;
		virtual unsigned int capacity() = 0;

	private:
		//unsigned int place, arraySize, dist, thresh;

	};

	class vector_int //: public vector
	{
	public:
		vector_int(unsigned int x = 4, unsigned int d = 4, unsigned int threshhold = 2);
		~vector_int();
		void push_back(int x);
		void pop_back();
		int at(unsigned int w);
		unsigned int size();
		unsigned int capacity();
		int* begin();
		int* end();
		int* rbegin();
		int* rend();
		void clear();
		void erase(unsigned int w);
	private:
		int *mArray;
		unsigned int place, arraySize, dist, thresh;
		void resize();


	};
}