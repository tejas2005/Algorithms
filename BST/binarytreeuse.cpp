#include<bits/stdc++.h>
using namespace std;
// #inlcude<binarytree.h> can use this
template <typename T>
class BinaryTreeNode{
  public:
  T data;
  BinaryTreeNode* left;
  BinaryTreeNode* right;
BinaryTreeNode(T data)
{
  this->data = data;
  left=NULL;
  right=NULL;
}
~BinaryTreeNode()
{
    delete left;
    delete right;
}

};

int main()
{
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(11);
  BinaryTreeNode<int>* left = new BinaryTreeNode<int>(10);
  BinaryTreeNode<int>* right = new BinaryTreeNode<int>(12);
  root->left = left;
  root->right = right;
  cout<<root->data<<" "<<root->left->data<<" "<<root->right->data;
}
