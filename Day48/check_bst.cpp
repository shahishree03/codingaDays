class Solution {
  public:
    bool isBSTUtil(Node* root, Node* minNode, Node* maxNode) {
    if (root == NULL) return true;

    if (minNode != NULL && root->data <= minNode->data) return false;
    if (maxNode != NULL && root->data >= maxNode->data) return false;

    return isBSTUtil(root->left, minNode, root) && isBSTUtil(root->right, root, maxNode);
}

    bool isBST(Node* root) {
      return isBSTUtil(root, NULL, NULL);
    }
};
