#include <iostream>
using namespace std;

struct Node{
  int value;
  Node *next;
  Node():value(0),next(nullptr){}
};

int main(){
  Node *a = new Node();
  Node *head = a;
  Node *n = new Node();
  n->value = 5;
  a->next = n;
  while(a != nullptr){
    cout << a->value << endl;
    a = a->next;
  }
  return 0;
}

