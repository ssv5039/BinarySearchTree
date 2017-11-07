/***************************************************************
	File Name: main.cpp
	Description: Implementation of BST (CMPSC 465)
***************************************************************/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left_link;
    Node* right_link;
};

/** Method Declarations **/
Node* get_new_node(int data);
void insert(int data, Node* &root_address);
bool is_present(int data, Node* root_address);

Node* root_address = NULL; // Global for ease of use.

int main()
{
  insert(15, root_address);
  insert(10, root_address);
  insert(20, root_address);
  insert(18, root_address);

  cout<<is_present(10, root_address)<<endl;
  cout<<is_present(12, root_address)<<endl;
  cout<<is_present(18, root_address)<<endl;
}

void insert(int data, Node* &root_address)
{

  if (root_address == NULL) // check if it exists
  {
    root_address = get_new_node(data);
  }
  else if (data <= root_address -> data)
  {
    insert(data, root_address -> left_link);
  }
  else
  {
    insert(data, root_address -> right_link);
  }

}

Node *get_new_node(int data)
{

  Node* new_node_address = new Node();
  new_node_address -> data = data;
  new_node_address -> left_link = NULL;
  new_node_address -> right_link = NULL;
  return new_node_address;

}

bool is_present(int data, Node* root_address)
{
  bool search_result;

  if (root_address == NULL)
  {
    search_result = false;
  }
  else if (data == root_address -> data)
  {
    search_result = true;
  }
  else if (data < root_address -> data)
  {
    search_result = is_present(data, root_address -> left_link);
  }
  else if (data > root_address -> data)
  {
    search_result = is_present(data, root_address -> right_link);
  }
  else
  {
    search_result = false;
  }

  return search_result;
}
