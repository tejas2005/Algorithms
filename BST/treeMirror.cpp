#include <iostream>
using namespace std;

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
void printTree(BinaryTreeNode<int>* root){
  if(root == NULL){
    return;
  }
  cout<<""<<root->data<<"is: ";
  if(root->left){
    cout<<"L->"<<root->left->data<<" ";
  }
  if(root->right){
    cout<<"R->"<<root->right->data<<" ";
  }
cout<<endl;
printTree(root->left);
printTree(root->right);
}

BinaryTreeNode<int>* inputTree(){
  int rootData;
  cout<<"Enter Data: "<<endl;
  cin>>rootData;
  if(rootData == -1){
    return NULL;
  }
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
  BinaryTreeNode<int>* left = inputTree();
  BinaryTreeNode<int>* right = inputTree();
  root->left = left;
  root->right = right;
}
void treeMirror(BinaryTreeNode<int>* root){
  if(root == NULL){
    return;
  }
  else{
    treeMirror(root->left);
    treeMirror(root->right);
    BinaryTreeNode<int>* temp=root->left;
    root->left=root->right;
    root->right=temp;
}
}
int main(){

  BinaryTreeNode<int>* root = inputTree();
  printTree(root);
  treeMirror(root);
  printTree(root);

}
