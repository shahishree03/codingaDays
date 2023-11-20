#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(): val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
     Node(int x, Node *left, Node *right): val(x), left(left), right(right) {}
   ~Node()
   {
    delete left;
    delete right;
   }
};
class Sol{
    public:
vector<int> largestValue(Node* root )
{
    if(!root) return {};
    vector<int> results;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int curr_level_size= q.size();
        int max_val = INT_MIN;
        for(int i=0;i<curr_level_size;i++)
        {
            Node* node = q.front();
            q.pop();
            max_val = max(max_val, node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        results.push_back(max_val);
    }
    return results;
}
};
int main()
{
   Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(9);

    Sol s;
    vector<int> largestValues = s.largestValue(root);

    cout << "Largest values in each level: ";
    for (int val : largestValues) {
        cout << val << " ";
    }
    cout << endl;

    // The destructor for the root node will recursively delete the entire tree.
    delete root;


}