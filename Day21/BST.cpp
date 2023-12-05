#include <iostream>
#include<queue>
using namespace std;

class BST
{
public:
    int data;
    BST *left;
    BST *right;

    BST(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

BST *Insert(BST *root, int data)
{
    if (!root)
    {
        return new BST(data);
    }

    if (root->data > data)
    {
        root->left = Insert(root->left, data);
    }
    else if (root->data <= data)
    {
        root->right = Insert(root->right, data);
    }

    return root;
}

void Inorder(BST *root)
{
    if (!root)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

BST *search_elem(BST *root, int key)
{
    if (root == nullptr || key == root->data)
        return root;

    if (key < root->data)
        return search_elem(root->left, key);

    else
        return search_elem(root->right, key);
}

vector<vector<int>> levelOrder(BST* root)
{
    vector<vector<int>> ans;
    if(!root) return ans;
    queue<BST*> q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++)
        {
            BST* node= q.front();
            q.pop();
            if(node->left!=nullptr) q.push(node->left);
            if(node->right!=nullptr) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}


BST *findLastChild(BST* root)
{
    if(root->right==nullptr)
    {
        return root;
    }
    return findLastChild(root->right);
}



BST* helper(BST* root)
{
    if(root->left==nullptr) 
      return root->right;

    else if(root->right==nullptr)
     return root->left;

    BST* rightChild = root->right;
    BST* lastChild =findLastChild(root->left);
    lastChild->right =rightChild;
    return root->left;
}

BST* deleteNode(BST* root, int key)
{
if(root==nullptr) 
 return nullptr;
if(root->data==key) 
 return helper(root);
BST* dummy =root;
while(root)
{
    if(root->data>key)
    {
        if(root->left!=nullptr && root->left->data==key)
        {
            root->left=helper(root->left);
            break;
        }
        else{
            root=root->left;
        }
    }
    else{

        if(root->right!=nullptr && root->right->data ==key)
        {
            root->right =helper(root->right);
            break;
        }
        else{
            root=root->right;
        }
    }
}

return dummy;
}



int main()
{
    BST *root = nullptr;
    root = Insert(root, 50);
    Insert(root, 30);
    Insert(root, 20);
    Insert(root, 40);
    Insert(root, 70);
    Insert(root, 60);
    Insert(root, 80);

    Inorder(root);

    int key = 6;

  /* // Searching in a BST
    if (!search_elem(root, key))
        cout <<"\n"<< key << " not found" << endl;
    else
        cout <<"\n"<< key << " found" << endl;
*/
    

    root= deleteNode(root,70);
    cout<<"\nAfter deletion\n";
    Inorder(root);
}
