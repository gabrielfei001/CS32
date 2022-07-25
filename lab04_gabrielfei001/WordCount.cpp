// WordCount.cpp

#include "WordCount.h"
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int total = 0;
	for (size_t i = 0; i < CAPACITY; i++) {
		for (size_t j = 0; j < table[i].size(); j++) {
			total = total + table[i][j].second;
		}
	} 
	return total;
}

int WordCount::getNumUniqueWords() const {
	int total = 0;
	for (size_t i = 0; i < CAPACITY; i++) {
		total = total + table[i].size();
	}
	return total;
}

int WordCount::getWordCount(std::string word) const {
	//int total = 0;
	string temp = "";
	temp = makeValidWord(word);
	if (temp == "") {
		return 0;
	}
	size_t index = hash(temp);
	for (size_t i = 0; i < table[index].size(); i++) {
		pair<string, int> p = table[index][i];
		if(p.first == temp) {
			return p.second;
		}
	}
	return 0;
}
	
int WordCount::incrWordCount(std::string word) {
	string temp = makeValidWord(word);
	if (temp == "") {
		return 0;
	}
	size_t index = hash(temp);
	for (size_t i = 0; i < table[index].size(); i++) {
		pair<string, int> p = table[index][i];
		if (p.first == temp) {
			p.second ++;
			table[index][i] = p;
			return p.second;
		}
	}
	pair<string, int> q;
	q.first = temp;
	q.second = 1;
	table[index].push_back(q);
	return 1;
}

int WordCount::decrWordCount(std::string word) {
	string temp = makeValidWord(word);
	if (temp == "") {
		return -1;
	}
	size_t index = hash(temp);
	for (size_t i = 0; i < table[index].size(); i++) {
		pair<string, int> p = table[index][i];
		if (p.first == temp && p.second > 1) {
			p.second --;
			table[index][i] = p;
			return p.second;
		}
		else if (p.first == temp && p.second == 1) {
			table[index].erase(table[index].begin() + i);
			return 0;
		}
	}
	return -1;
}

bool WordCount::isWordChar(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
		return true;
	}
	return false;
}

std::string WordCount::makeValidWord(std::string word) {
    for(size_t i = 0; i < word.size(); i++) {
        if(isWordChar(word.at(i))) {
            continue;
		}
        if(i == 0 || i == word.size() - 1) {
            word.erase(i, 1);
            i --;
        }
        else {
            if(word.at(i) == '\'' || word.at(i) == '-') {
                continue;
			}
            word.erase(i, 1);
            i --;
        }
    }
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	for(int i = word.size() - 1; i > -1; i--) {
		if(isWordChar(word.at(i))) {
            break;
		}
		/*
		for(size_t j = 0; j < word.size(); j ++) {
			if(isWordChar(word.at(j))) {
            	break;
			}
		}
		*/
		//if (isWordChar(word.at(i)) != true) {
		else {
			word.erase(i);
			cout << word << endl;
		}
	}
    return word;
}
