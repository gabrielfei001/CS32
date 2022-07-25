#ifndef STRUCTFUNCS_H
#define STRUCTFUNCS_H
#include "MyStructs.h"
template<typename S>
unsigned long getPadding(S s) {
  int padding = 0;
  int sumOfTypes = 0;
  sumOfTypes = sizeof(s.cardNumber) + sizeof(s.firstNameInitial) + sizeof(s.expirationDate) + 
               sizeof(s.lastNameInitial) + sizeof(s.linkedCheckingAccountNumber) +
               sizeof(s.bankNameInitial) + sizeof(s.isActive) + sizeof(s.cvv);
  padding = sizeof(s) - sumOfTypes;
  return padding;
}

#endif
