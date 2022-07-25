#include <string>
#include "studentRoll.h"
#include <sstream>

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node *p = new Node;
  if(!tail || !head) {
    head = tail = p;
  }
  else {
    tail->next = p;
  }
  p->s = new Student(s.getName(), s.getPerm());
  p->next = NULL;
  tail = p;
  delete p;
}

std::string StudentRoll::toString() const { 
  if (head == NULL || tail == NULL) {
    return "[]";
  }
  std::ostringstream oss;
  Node *p = head;
  oss << "[";
  while(p) {
    oss << p->s->toString();
      if(p != tail) {
        oss << ",";
      }
      p = p->next;
  }
  oss << "]";
  delete p;
  return oss.str();
}

StudentRoll::StudentRoll(const StudentRoll &orig) { 
  head = tail = NULL;
  if(!orig.head||!orig.tail) {
    return;
  }
  Node *p = head;
  for(Node *q = orig.head; q != NULL; q = q->next) {
    p = new Node;
    p->s = new Student(p->s->getName(), p->s->getPerm());
    tail = p;
    p = p->next;
  }
  delete p;
}

StudentRoll::~StudentRoll() {
  Node *p = head;
  while(p != NULL) {
    Node *q = p->next;
    delete p;
    p = q;
    delete q;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  head = tail = NULL;
  Node *p = right.head;
  Node *q = this->head;
  while(p != NULL) {
    q = new Node;
    q->s = new Student(p->s->getName(), p->s->getPerm());
    tail = q;
    q = q->next;
    p = p->next;
  }
  q = NULL;
  delete p;
  delete q;
  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
}





