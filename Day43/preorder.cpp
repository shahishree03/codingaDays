class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
             TreeNode* topNode = s.top();
            ans.push_back(topNode->val);
            s.pop();
            if(topNode->right!=NULL)
            s.push(topNode->right);
      if (topNode -> left != NULL)
     s.push(topNode->left);
        } 
        return ans;
    }
};
