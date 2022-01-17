#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> ans;
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
    }
}

TreeNode* buildTree(int H, vector<int> &treeVal){
    if(H < 2){
        return new TreeNode(treeVal[0]);
    }

    TreeNode *root = new TreeNode(treeVal[0]);
    vector<TreeNode*> Queue;
    Queue.push_back(root);
    int rootIndex = 0, buildIndex = 1, treeSize = treeVal.size();

    while(buildIndex < treeSize){
        Queue.push_back(new TreeNode(treeVal[buildIndex]));
        Queue.push_back(new TreeNode(treeVal[buildIndex+1]));
        Queue[rootIndex]->left = Queue[buildIndex];
        Queue[rootIndex]->right = Queue[buildIndex+1];

        buildIndex += 2;
        ++rootIndex;
    }

    return root;
}


int main() {
    int H = 0;
    cin >> H;
    int treeSize = (1 << H) - 1;
    vector<int> tree(treeSize, 0);
    for(int i = 0; i < treeSize; ++i){
        cin >> tree[i];
    }

    TreeNode *root = buildTree(H, tree);

    inorderTraversal(root);

    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i];
    }

    return 0;
}
