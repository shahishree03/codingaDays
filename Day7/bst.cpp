#include<iostream>
using namespace std;
class BST{
  int data;
  BST* left;
  BST* right;
  public:
    BST();
    BST(int);
    BST* insert(BST* , int);
    void Inorder(BST*);
    BST* deleteNode(BST* , int);
    BST* helper(BST*);
    BST* findLastLeft(BST*);


};
BST::BST():data(0),left(NULL),right(NULL){}
BST::BST(int value){
    data=value;
    left=right=NULL;
}

BST* BST::insert(BST* root , int value){
    if(!root)
    return new BST(value);

    if(root->data<value){
        root->right=insert(root->right,value);
    }
    else if(root->data> value){
        root->left=insert(root->left, value);
    }
    return root;
}
void BST::Inorder(BST* root)
{
    if(!root)
    return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

BST* BST:: deleteNode(BST* root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data==key) {return helper(root);}
    if(root->data>key) {root->left =deleteNode(root->left, key);}
    else{
        root->right =deleteNode(root->right,key);
    }
    return root;
}
BST* BST::helper(BST* root)
{
    if(root->left ==NULL)
    return root->right;
    else if(root->right==NULL) return root->left;
    BST* leftChild = root->left;
    BST* lastChild =findLastLeft(root->right);
    lastChild->left = leftChild;
    return root->right;
}

BST* BST::findLastLeft(BST* root)
{
    if(root->left==NULL) return root;
    return findLastLeft(root->left);
}
int main()
{
   BST b, *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);
 cout<<"Inorder Traversal......\n";
    b.Inorder(root);
    printf("\nAFTER DELETION PRINT\n");
    b.deleteNode(root , 40);
    b.Inorder(root);
} 