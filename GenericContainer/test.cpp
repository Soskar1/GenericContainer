#include <stdio.h>
#include <stdlib.h>
#include <iostream>


// other includes and definitions

#include "LightweightSet.h"

using namespace std;
using namespace GenericContainers;

// define your container here
typedef LightweightSet<int> tADT;

// define your value here		
typedef int tValue;


int errorCode;

// throw the following class if function is not implemented
class NotImplementedException {
};
// throw the following class if index/position out of bounds
class OutOfBoundsException {
};



void createADT(tADT& adt) {
	/* YOUR CODE HERE OR EMPTY */
}
void destroyADT(tADT& adt) {
	/* YOUR CODE HERE OR EMPTY */
}



void add(tADT& adt, tValue value, int pos) {
	/* YOUR CODE HERE */
	throw NotImplementedException();
}
void addValue(tADT& adt, tValue value) {
	adt.Insert(value);
}
void addFirst(tADT& adt, tValue value) {
	/* YOUR CODE HERE */
	throw NotImplementedException();
}
void addLast(tADT& adt, tValue value) {
	/* YOUR CODE HERE */
	throw NotImplementedException();
}



void remove(tADT& adt, int pos) {
	adt.Remove(size_t(pos));
}
void removeValue(tADT& adt, tValue value) {
	adt.Remove(value);
}
void removeFirst(tADT& adt) {
	adt.RemoveFirst();
}
void removeLast(tADT& adt) {
	adt.RemoveLast();
}



tValue get(tADT& adt, int pos) {
	return adt.Get(pos);
}
bool getValue(tADT& adt, tValue value) {
	return adt.Contains(value);
}
tValue getFirst(tADT& adt) {
	return adt.GetFirst();
}
tValue getLast(tADT& adt) {
	return adt.GetLast();
}



int getSize(tADT& adt) {
	return adt.Size();
}
int getMaxSize(tADT& adt) {
	return adt.Size();
}

// print all values of your ADT in ascending order
// all values should be in a single line separated by single spaces	
void printADT(tADT& adt) {

	for (size_t i = 0; i < adt.Size(); ++i) {
		if (i == adt.Size() - 1) {
			cout << adt.Get(i);
		}
		else {
			cout << adt.Get(i) << " ";
		}
	}
}


/* DO NOT MODIFY CODE BELOW */
class ErrorCodeException {
};

int main() {
	try {
		errorCode = 0;
		tADT adt;
		createADT(adt);

		int x = -1;
		while (1) {
			cin >> x;
			if (x == 0) {
				destroyADT(adt);
				break;
			}
			else {
				tValue val;
				int pos;
				switch (x) {
				case 11:
					printADT(adt);
					break;
				case 12:
					cout << getSize(adt) << endl;
					break;
				case 13:
					cout << getMaxSize(adt) << endl;
					break;
				case 21:
					cout << getFirst(adt) << endl;
					break;
				case 22:
					cout << getLast(adt) << endl;
					break;
				case 23:
					cin >> pos;
					cout << get(adt, pos) << endl;
					break;
				case 24:
					cin >> val;
					cout << getValue(adt, val) << endl;
					break;
				case 31:
					cin >> val;
					addFirst(adt, val);
					break;
				case 32:
					cin >> val;
					addLast(adt, val);
					break;
				case 33:
					cin >> val >> pos;
					add(adt, val, pos);
					break;
				case 34:
					cin >> val;
					addValue(adt, val);
					break;
				case 41:
					removeFirst(adt);
					break;
				case 42:
					removeLast(adt);
					break;
				case 43:
					cin >> pos;
					remove(adt, pos);
					break;
				case 44:
					cin >> val;
					removeValue(adt, val);
					break;
				}
			}
		}
		if (errorCode) {
			throw OutOfBoundsException();
		}
	}
	catch (NotImplementedException& e) {
		return 2018;
	}
	catch (ErrorCodeException& e) {
		return 1234;
	}
	catch (OutOfBoundsException& e) {
		return 4321;
	}
	catch (...) {
		return -1;
	}
	return 0;
}