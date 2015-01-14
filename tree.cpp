#include <iostream>

using namespace std;

struct Node {
  int data; 
  Node* left;
  Node* right;
};

void insert(Node* node, int data) {
  if (data > node->data) {
    if (node->right == NULL) {
      Node* newNode = new Node;
      node->right = newNode;
      newNode->data = data;
      newNode->left = NULL;
      newNode->right = NULL;
    } else {
      insert(node->right, data);
    }
  } else {
    if (node->left == NULL) {
      Node* newNode = new Node;
      node->left = newNode;
      newNode->data = data;
      newNode->left = NULL;
      newNode->right = NULL;
    } else {
      insert(node->left, data);
    }
  }
}

void print_tree(Node* node) {
  cout << node->data << endl;
  if (node->left != NULL) {
    print_tree(node->left);
  } else {
    return;
  }
  if (node->right != NULL) {
    print_tree(node->right);
  } else {
    return;
  }
}

void clean_up(Node* node) {
  if (node->right != NULL) {
    clean_up(node->right);
  }
  if (node->left != NULL) {
    clean_up(node->left);
  }
  if (node->left == NULL && node->right ==NULL) {
    delete node;
    return;
  }
}
    

int main(int argc, char* argv[]) {
  bool done = false;
  int to_insert;
  Node node;
  Node* root;
  root = &node;
  root->left = NULL;
  root->right = NULL;
  cout << "Input data:";
  cin >> to_insert; 
  root->data = to_insert;
  while (!done) {
    cout << "Input data:";
    cin >> to_insert; 
    if (to_insert == -100) {
      done = true;
    }
    insert(root, to_insert);
    print_tree(root);
  }
  clean_up(root);
  return 0;
}
