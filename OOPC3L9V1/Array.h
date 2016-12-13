#pragma once
#include <ostream>
#include <istream>

class Array {
	int size;
	int* element;
public:
	Array(int size);
	Array(Array& arr);
	Array();

	void setSize(int newSize);
	void setElement(int index, int value);
	int getSize();
	int getElement(int index);
	~Array();

	friend std::ostream &operator<< (std::ostream& out, Array& arr) {
		out << "[";
		for (int i = 0; i < arr.getSize(); i++) {
			out << arr.getElement(i);
			if (i != arr.getSize() - 1) {
				out << ", ";
			}
		}
		out << "]";
		return out;
	}

	friend std::istream &operator>> (std::istream& in, Array& arr) {
		for (int i = 0; i < arr.getSize(); i++) {
			int value;
			in >> value;
			arr.setElement(i, value);
		}
		return in;
	}
};
