#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTreeNode{
public:
  T data;
  BinaryTreeNode* left;
  BinaryTreeNode* right;
  BinaryTreeNode(T data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
  ~ BinaryTreeNode(){
    delete left;
    delete right;
  }
};
BinaryTreeNode<int>* inputLevelWise(){
  int rootData,leftData,rightData;
  cout<<"Enter root data ";
  cin>>rootData;
  if(rootData == -1){
    return NULL;
  }

  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  while(pendingNodes.size()!=0){
    BinaryTreeNode<int>* front = pendingNodes.front();
    pendingNodes.pop();

    cout<<"Enter left child data "<<front->data <<endl;
    cin>>leftData;
    if(leftData!=-1){
      BinaryTreeNode<int>* left = new  BinaryTreeNode<int>(leftData);
      front->left = left;
      pendingNodes.push(left);
    }

    cout<<"Enter right child data of "<<front->data<<endl;
    cin>>rightData;
    if(rightData!=-1){
      BinaryTreeNode<int>* right = new  BinaryTreeNode<int>(rightData);
      front->right = right;
      pendingNodes.push(right);
    }

  }

return root;
}
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
int main(){

BinaryTreeNode<int>* root = inputLevelWise();

printTree(root);

}
