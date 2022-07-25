// WordCount.cpp

#include "WordCount.h"
#include <sstream>
#include <algorithm>
#include <iostream>
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
		else {
			word.erase(i);
			cout << word << endl;
		}
	}
    return word;
}

bool pairWordDescending(pair<string, int> a, pair<string, int> b) {
	return (a.first > b.first);
}

// bool pairWordAscending(pair<string, int> a, pair<string, int> b) {
// 	return (a.first > b.first);
// }

bool pairOccurancesAscending(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) {
		return (a.first < b.first);
	}
	else {
		return (a.second < b.second);
	}
}

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	vector<pair<string, int>> word;//[CAPACITY];need to create a new vector of all the vector pairs inside of the hash table, then sort them then outfile
	for (size_t i = 0; i < CAPACITY; i++) {
		for (size_t j = 0; j < table[i].size(); j++) {
			//word = table[i];
			//word[i] = table[i];
			word.push_back(table[i][j]);
		}
	}
	//for (size_t i = 0; i < CAPACITY; i++) {
		//sort(word[i].begin(), word[i].end(), pairGreater);
	sort(word.begin(), word.end(), pairWordDescending);
	//}
	for (size_t i = 0; i < word.size(); i++) {
	//for (size_t i = 0; i < CAPACITY; i++) {
		//for (size_t j = 0; j < word.size(); j++) {
		out << word[i].first << "," << word[i].second << endl;
		//cout << word[i].first << "," << word[i].second << endl;
			// out << word[i][j].first << "," << word[i][j].second << endl;
			// cout << word[i][j].first << "," << word[i][j].second << endl;
		//}
	}
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
	vector<pair<string, int>> word;
	for (size_t i = 0; i < CAPACITY; i++) {
		for (size_t j = 0; j < table[i].size(); j++) {
			word.push_back(table[i][j]);
		}
	}
	sort(word.begin(), word.end(), pairOccurancesAscending);
	for (size_t i = 0; i < word.size(); i++) {
		out << word[i].first << "," << word[i].second << endl;
		//cout << word[i].first << "," << word[i].second << endl;
	}
}

void WordCount::addAllWords(std::string text) { 
	string word;
	std::istringstream iss(text);
	while (iss >> word) {
		while (!isWordChar(word[0])) {
			word.erase(0, 1);
		}
		int x = word.length();
		while (!isWordChar(word[x - 1])) {
			word.erase(x - 1, x);
			x--;
		}
		incrWordCount(word);
	}
	return;
}
