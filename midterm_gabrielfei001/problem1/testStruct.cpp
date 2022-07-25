#include "MyStructs.h"
#include "structFuncs.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {

  // Sample
  CreditCard1 a;
  unsigned long sizeCreditCard1 = 40;
  ASSERT_EQUALS(sizeof(a), sizeCreditCard1);
  cout << "CreditCard 1 has " << getPadding(a) << " bytes" << endl;
  //You should write your own tests below.
  CreditCard2 b;
  unsigned long sizeCreditCard2 = 48;
  ASSERT_EQUALS(sizeof(b), sizeCreditCard2);
  cout << "CreditCard 2 has " << getPadding(b) << " bytes" << endl;
  CreditCard3 c;
  unsigned long sizeCreditCard3 = 32;
  ASSERT_EQUALS(sizeof(c), sizeCreditCard3);
  cout << "CreditCard 3 has " << getPadding(c) << " bytes" << endl;
  return 0;
}
