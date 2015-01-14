#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

void insert(Node* node, int data) {
  Node* temp = node;
  while (temp->next != NULL) {
    temp = temp->next;
  }  
  Node* newNode = new Node;
  newNode->data = data; 
  newNode->next = NULL;
  temp->next = newNode;
}

void print(Node* node) {
  Node* temp = node;
  while (temp->next != NULL) {
    cout << temp->data;
    cout << "<--";
    temp = temp->next;
  }
  if (temp->next == NULL) {
    cout << temp->data << endl;
  }
}

void clear(Node* node) {
  Node* temp = node;
  Node* prev = node;
  while (temp->next != NULL) {
    node = temp;
    temp = temp->next;
    delete node;
  }
  delete temp;
}

Node* remove(Node* node, int data) { 
  Node* temp = node;
  Node* prev = NULL;
  while (temp->data != data && temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }
  if (prev == NULL && temp->data == data) {
    node = temp->next;
    delete temp;
    return node;
  }
  if (temp->data == data) {
    prev->next = temp->next;
    delete temp;
  }
  return node;
}
    
int main(int argc, char* argv[]) {
  bool done = false;
  string cmd;
  int data;
  Node* root = new Node;
  cout << "item:";
  cin >> data;
  root->data = data;
  while (!done) {
    cout << "i for insert\nr for remove \nq for quit\noption:" << endl;
    cin >> cmd;
    if (cmd == "i" || cmd == "r") {
      cout << "item:";
      cin >> data;
      if (cmd == "i") {
        insert(root, data);
        print(root);
      } else {
        root = remove(root, data);   
        print(root);
      }
    } else {
      done = true;
    }
  }
  clear(root);
  return 0;
}
