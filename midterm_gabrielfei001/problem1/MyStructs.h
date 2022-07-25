#ifndef MYSTRUCTS_H
#define MYSTRUCTS_H

struct CreditCard1 {
  unsigned long long int cardNumber;
  char firstNameInitial;
  unsigned int expirationDate;
  char lastNameInitial;
  unsigned long long int linkedCheckingAccountNumber;
  char bankNameInitial;
  bool isActive;
  int cvv;
};

struct CreditCard2 {
  unsigned long long int cardNumber;
  char firstNameInitial;
  unsigned long long int expirationDate;
  char lastNameInitial;
  unsigned long long int linkedCheckingAccountNumber;
  char bankNameInitial;
  bool isActive;
  int cvv;
};

struct CreditCard3 {
  unsigned long int cardNumber;
  char firstNameInitial;
  unsigned int expirationDate;
  char lastNameInitial;
  unsigned short int linkedCheckingAccountNumber;
  char bankNameInitial;
  bool isActive;
  int cvv;
};

#endif
