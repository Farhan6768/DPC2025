#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree() {
    int val;
    cout << "Enter root value (-1 for NULL): ";
    cin >> val;
    if (val == -1) return NULL;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        int leftVal, rightVal;
        cout << "Enter left child of " << node->val << " (-1 for NULL): ";
        cin >> leftVal;
        if (leftVal != -1) {
            node->left = new TreeNode(leftVal);
            q.push(node->left);
        }

        cout << "Enter right child of " << node->val << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1) {
            node->right = new TreeNode(rightVal);
            q.push(node->right);
        }
    }
    return root;
}

bool isBSTUtil(TreeNode* root, long minVal, long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;

    return isBSTUtil(root->left, minVal, root->val) &&
           isBSTUtil(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isBSTUtil(root, LONG_MIN, LONG_MAX);
}

int main() {
    TreeNode* root = buildTree();

    if (isValidBST(root))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
/*
Enter root value (-1 for NULL): 2
Enter left child of 2 (-1 for NULL): 1
Enter right child of 2 (-1 for NULL): 3
Enter left child of 1 (-1 for NULL): -1
Enter right child of 1 (-1 for NULL): -1
Enter left child of 3 (-1 for NULL): -1
Enter right child of 3 (-1 for NULL): -1
true
*/
