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

//namespace test
//{
	template <class T>
	class dVector
	{
	public:
		dVector(unsigned int x = 4, unsigned int d = 4, unsigned int threshhold = 2)
		{
			if(x <= 1)
				throw "cannot have an array with blocking of 1 or less";
			mArray = new T[x];
			place = 0;
			arraySize = x;
			dist = d;
			thresh = threshhold;
		}

		~dVector(){ delete  mArray;}

		T at(unsigned w) 
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
		void push_back(T x)
		{
			if (place == arraySize)
				resize();

			mArray[place] = x;
			place++;
		}

		void pop_back()
		{
			place--;
			mArray[place] = 0;
			if(arraySize - place > dist + thresh)
				resize();
		}

		unsigned size()
		{
			return place;
		}


		T* begin()
		{
			return mArray;
		}
		T* end()
		{
			return mArray + place;
		}

		void clear()
		{
			T *trash;
			trash = mArray;
			mArray = new T[dist];
			place = 0;
			arraySize = dist;
			delete trash;
		}

	private:
		T *mArray;
		unsigned int place, arraySize, dist, thresh;
		void resize()
		{
			T *nArray = new T[place + dist];
			for(unsigned int i = 0; i < place; i++)
			{
				nArray[i] = mArray[i];
			}
			T *oldArray;
			oldArray = mArray;
			mArray = nArray;
			delete oldArray;
			std::cout << "\nResized array from sizeof: '" << arraySize << "' to a sizeof: '" << place + dist << "'\nPlace == '" << place << "'\n";
			arraySize = place + dist;
		}


	};	
//}