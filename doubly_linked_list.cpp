#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
  Node* prev;
};

void insert(Node* node, int data) {
  Node* temp = node;
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  newNode->prev = temp;
  newNode->next = temp->next;
  temp->next = newNode;
}

void print_list(Node* node) {
  Node* temp = node;
  while (temp->next != NULL) {
    cout << temp->data;
    temp = temp->next;
  }
  cout << temp->data << endl;
}

void clean_up(Node* node) {
  while (node->next != NULL) {
    node = node->next;
    if (node->prev != NULL) {
      delete node->prev;
    }
  }
  delete node;
}

int main(int argc, char* argv[]) {
  Node node;
  Node* root = &node;
  bool done = false;
  int data;
  cout << "Insert:";
  cin >> data;
  root->data = data;
  root->next = NULL;
  root->prev = NULL;
  while (data != -1) {
    cout << "Insert:";
    cin >> data;
    insert(root, data);
    cout << endl;
    print_list(root);
  }
  clean_up(root->next);
  return 0;
}
