#include <sstream>
#include "MyHashTable.h"
#include <utility>
#include <iterator>
#include <list>

using namespace std;

// Default constructor. Do not modiify.
MyHashTable::MyHashTable() {
  for (size_t i = 0; i < CAPACITY; i++) {
    table[i] = new vector<pair<string, int>>;
  }	
}

// Simple hash function. Do not modify.
size_t MyHashTable::hash(string name) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < name.size(); i++) {
		accumulator += name.at(i);
	}
	return accumulator % CAPACITY;
}

void MyHashTable::insertItem(string name, int perm) {
	int index = hash(name);
	pair <string, int> a (name, perm);
	table[index]->push_back(a);
	return;
}

void MyHashTable::deleteItem(string name) {
	int index = hash(name);
	for (unsigned int i = 0; i < CAPACITY; i++) {
		if (table[i] == table[index]) {
			delete table[i];
		}
		else {
			return;
		}
	}
	return;
}

string MyHashTable::toString() const {
	string result;
	for (size_t i = 0; i < CAPACITY; i++) {
		result = result + to_string(i) + ":[";
		for (size_t x = 0; x < table[i]->size(); x++) {
			result = result + "(" + table[i]->at(x).first + "," + to_string(table[i]->at(x).second) + ")";
		}
		result = result +  "]\n";
	}
  	return result;
}


MyHashTable::MyHashTable(const MyHashTable &orig) {
	for (unsigned int i = 0; i < CAPACITY; i++) {
		this->table[i] = new vector<pair<string, int>>();
		for (unsigned int j = 0; j < orig.table[i]->size(); j++) {
			this->table[i]->push_back((*orig.table[i])[j]);
		}
	}
}

MyHashTable::~MyHashTable() {
	for(unsigned int i = 0; i < CAPACITY; i++) {
		delete(this->table[i]);
	}
}
