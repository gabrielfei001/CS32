#include "MySorting.h"
#include "tddFuncs.h"
using namespace std;

int main() {


  // Test case #1
  string a[] {"If", "music", "be", "the", "food", "of", "love", "play", "on"};
  size_t a_size = 9;
  string expected_1 = "BE,IF,OF,ON,THE,FOOD,LOVE,PLAY,MUSIC";
  ASSERT_EQUALS(expected_1, customSort(a, a_size));

  // Test case #2
  string b[] {"Shall", "I" ,"compare", "thee", "to" ,"a" ,"summers", "day"};
  size_t b_size = 8;
  string expected_2 = "A,I,TO,DAY,THEE,SHALL,COMPARE,SUMMERS";
  ASSERT_EQUALS(expected_2, customSort(b, b_size));

  // Write your own test cases below


  return 0;
}
