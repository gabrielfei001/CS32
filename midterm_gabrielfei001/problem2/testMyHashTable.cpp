#include "MyHashTable.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {
  // A sample test.
  MyHashTable ht;
  ht.insertItem("Peter Parker", 27437);
  ht.insertItem("Tony Stark", 49872);
  ht.insertItem("Bruce Banner", 39857);
  ht.insertItem("Steven Rogers", 12984);
  string expected = "0:[(Tony Stark,49872)]\n1:[]\n2:[(Peter Parker,27437)(Bruce Banner,39857)(Steven Rogers,12984)]\n3:[]\n4:[]\n";
  ASSERT_EQUALS(expected, ht.toString());
  // Write your own tests below.
  return 0;
}

