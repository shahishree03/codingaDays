#include<iostream>
using namespace std;


class BST{
    public:
    int data;
    BST *left , *right;
    
   BST() :data(0), left(NULL), right(NULL){}
    
    BST(int data)
    {
       this->data = data;
       left = right =NULL;
    }
    
   
};

BST* Insert(BST* root, int data)
{
   
    if(root==NULL) return new BST(data);
        
    
    if(root->data > data)
    {
        root->left = Insert(root->left , data);
       
    }
     else 
    {
       root->right = Insert(root->right , data);
        
    }
    
return root;
  

}

void Inorder(BST* root)
{
    if(root==NULL) return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
    
}

void Preorder(BST* root)
{
    if(root==NULL) return;
     cout<<root->data<<" ";
    Inorder(root->left);
    Inorder(root->right);
    
}
void Postorder(BST* root)
{
    if(root==NULL) return;
     
    Inorder(root->left);
    Inorder(root->right);
    cout<<root->data<<" ";
    
}

int main()
{
    BST* root= NULL;
    
   root =  Insert(root , 10);
    Insert(root , 5);
    Insert(root , 16);
    Insert(root , 1);
    Insert(root , 8);
    Insert(root , 12);
    Insert(root ,20);
   
    cout<<"Inorder Traversal .......\n";
    Inorder(root);
  
}