#include <iostream>
#pragma once

template <class T>
class Raid
{
private:
	T* Array;
	size_t Capacity, Size;
	int Degree;
public:
	Raid() :Array{ new T[0] }, Degree{ 0 }, Size{ 0 }, Capacity{ 0 } {}

	Raid(T num, size_t size)
	{
		this->SizeOverride(size);
		for (int i = 0; i < size; i++) {
			Array[i] = num;
		}
	}

	void SizeOverride(size_t size) {
		int CountDegree = 1;
		size_t capacity = static_cast<int>(pow(2, CountDegree));
		while (capacity < size) { //Переопределение размера массива в формате степени двойки
			CountDegree += 1;
			capacity = static_cast<int>(pow(2, CountDegree));
		}
		T* oldArray = new T[Size];
		for (int i = 0; i < Size; i++)
			oldArray[i] = Array[i];
		//this->erase();
		Array = new T[capacity];
		for (int i = 0; i < Size; i++)
			Array[i] = oldArray[i];
		Capacity = capacity;
		Degree = CountDegree;
		Size = size;
	}

	void erase() { 
		delete[] Array; 
		Capacity = 0;
		Size = 0;
		Degree = 0;
	}

	size_t size() { return Size; }
	size_t capacity() { return Capacity; }

	void display()
	{
		for (int i = 0; i < Size; i++) {
			std::cout << Array[i] << " ";
		}
		std::cout << std::endl;
	}
	
	void push_back(T val) {
		if (Size < Capacity) {
			Array[Size] = val;
			Size += 1;
		}
		else {
			this->SizeOverride(Size+1);
			Array[Size-1] = val;
		}
	}

	T pop_back() {
		T last = Array[Size];
		this->SizeOverride(Size - 1);
		return last;
	}

	T operator[](int index) {
		return Array[index];
	}

	
};

