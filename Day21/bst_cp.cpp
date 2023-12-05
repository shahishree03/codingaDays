#include<iostream>
using namespace std;

class Node{
 public:
  Node* left;
  Node* right;
  
  int val;
  Node(int val)
  {
      left=right=NULL;
      this->val=val;
  }
}; 
 Node* insertion(Node* root, int val)
 {
     if(root == NULL) return new Node(val);
    // Node* temp =root;
    
         if(root->val <=val)
         {
             root->right = insertion(root->right, val);
         }
         else
         {
             root->left = insertion(root->left, val);
         }
     
     return root;
 }
 /*
Node* deleteInBST(Node* root, int key)
{
    if(key<root->data)
    {
        root->left = deleteInBST(root->left ,key);
    }
    else
    {
        root->right = deleteInBST(root->right, key);
    }
    else
    {
        if(root->left == NULL)
        {
            Node* temp = root->right;
            
        }
    }
}*/

Node* helper(Node*);
Node* findLastLeft(Node*);
Node* deleteNode(Node* root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->val==key) return helper(root);
    //Node* temp =root;
    if(root->val>key) 
    {
        root->left = deleteNode(root->left, key);
    }
    else{
        root->right =deleteNode(root->right, key);
    }
    return root;
}


Node* helper(Node* root)
{
    if(root->left==NULL) return root->right;
    else if(root->right==NULL) return root->left;
    Node* leftChild = root->left;
    Node* lastChild = findLastLeft(root->right);
    lastChild->left =leftChild;
    return root->right;
}


Node* findLastLeft(Node* root)
{
    if(root->left ==NULL)
    {
        return root;
    }
    return findLastLeft(root->left);
}
 void inorder(Node* root)
 {
     if(root==NULL) return;
     inorder(root->left);
     cout<<root->val<<" ";
     inorder(root->right);
 }
 
 void preorder(Node* root)
 {
     if(root==NULL) return;
     cout<<root->val<<" ";
     preorder(root->left);
     preorder(root->right);
 }
 

  void postorder(Node* root)
 {
     if(root==NULL) return;
     
     postorder(root->left);
     postorder(root->right);
     cout<<root->val<<" ";
 }
int searchBST(Node* root , int key, Node*& res, int level)
{
    if(root==NULL) return 0;
    if(root->val==key) {
    res= root;
    return level;
    }
    if(root->val>key) {
        return searchBST(root->left, key, res ,level+1);}
        
    return searchBST(root->right, key,res, level+1);

}

int main()
{
    Node* root=NULL;
    root=insertion(root, 8);
    insertion(root,3);
    insertion(root,10);
    insertion(root, 1);
    insertion(root, 4);
    insertion(root, 5);
    insertion(root,9);
    
    cout<<".....MENU DRIVEN PROGRAM....\n";
   cout<<"\nElement i s\n:";
   inorder(root);
   
    char c='Y';
    while(c!='N')
    {
         cout<<"\n1-Deletion\n2-Search-given-element\n3-Print tree using Preorder\n4-Print Post Order Traversal \n5-Print Inorder Traversa\n";
   
        int x;
        cin>>x;
        switch(x)
        {
            case 1:
            {  cout<<"\n\ndeletion\n";
            int node_to_delete;
            cout<<"Type node to be deleted\n ";
            cin>>node_to_delete;
            deleteNode(root, node_to_delete);
            cout<<"Deleted\n";
                break;
            }
            case 2:
            {
                 cout<<"\nSesarching .........\n";
    Node* result=nullptr;
    int ele;
    cout<<"which element is to search.......   ";
    cin>>ele;
   int level= searchBST(root,ele,result,1 );
   if(result)
   {
       cout<<"Found: "<<result->val<<" found at level"<<level<<endl;
   }
   else{
       cout<<"No found"<<endl;;
   }
    cout<<endl;
                break;
            }
            case 3:
            {
             cout<<"\npreorder........\n";
    preorder(root);
   
                break;
            }
            case 4:
            {
                cout<<"\npostorder........\n";
    postorder(root);
                break;
            }
            case 5:
            {
                 cout<<"\n inorder\n"<<endl;   
      inorder(root);
                break;
            }
            default:
            {
                cout<<"\nno element found\n";
                break;
            }
        }
       cout<<"\nchoose Y to continueand  N to exit...\n";
       
       cin>>c;
    }
   
   
     
   

    
}