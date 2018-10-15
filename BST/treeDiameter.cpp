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
int treeHeight(BinaryTreeNode<int>* root){
  if(root == NULL){
    return 0;
  }
  return 1+max(treeHeight(root->left),treeHeight(root->right));
}

int main(){
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int>* root1 = new BinaryTreeNode<int>(10);
      BinaryTreeNode<int>* root2 = new BinaryTreeNode<int>(10);
        BinaryTreeNode<int>* root3 = new BinaryTreeNode<int>(10);
          BinaryTreeNode<int>* root4 = new BinaryTreeNode<int>(10);
            BinaryTreeNode<int>* root5 = new BinaryTreeNode<int>(10);

    root->left = root1;
    root1->left = root2;
    root2->left = root3;
    root->right = root4;
    root4->right = root5;
    cout<<treeHeight(root) <<" "<<treeHeight(root->left)<<" "<<treeHeight(root->right)<<endl;
    cout<<max(treeHeight(root->left)+treeHeight(root->right),max(treeHeight(root->left),treeHeight(root->right)));


    //complexity comparissions:  O(NlogN) vs O(N^2)
}
