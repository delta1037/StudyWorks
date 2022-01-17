#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    string s;
    TreeNode *NE;
    TreeNode *NW;
    TreeNode *SW;
    TreeNode *SE;
    TreeNode(string s) : s(s), NE(NULL), NW(NULL), SW(NULL), SE(NULL) {}
};
int maxDepth(TreeNode* root) {
    if(root == NULL){
        return 0;
    }

    return max(max(maxDepth(root->NE), maxDepth(root->NW)),
            max(maxDepth(root->SW), maxDepth(root->SE))) + 1;
}
void readOneNode(TreeNode* root, const string &valUpRead){
    string vec;
    string val;
    for(int i = 0; i < 4; ++i){
        if(i == 0 && !valUpRead.empty()){
            vec = valUpRead;
        }else{
            cin >> vec;
        }
        cin >> val;
        if(vec == "NE"){
            root->NE = new TreeNode("");
            if(val == "0" || val =="x"){
                root->NE->s = val;
            }else{
                readOneNode(root->NE, val);
            }
        }else if(vec == "NW"){
            root->NW = new TreeNode("");
            if(val == "0" || val =="x"){
                root->NW->s = val;
            }else{
                readOneNode(root->NW, val);
            }
        }else if(vec == "SW"){
            root->SW = new TreeNode("");
            if(val == "0" || val =="x"){
                root->SW->s = val;
            }else{
                readOneNode(root->SW, val);
            }
        }else{
            root->SE = new TreeNode("");
            if(val == "0" || val =="x"){
                root->SE->s = val;
            }else{
                readOneNode(root->SE, val);
            }
        }
    }
}
void printMap(TreeNode* root, vector<vector<char>> &map,
        int hight, int width, int top_left_x, int top_left_y){
    if(root->NE){
        for(int i = top_left_x; i < top_left_x + width; ++i){
            for(int j = top_left_y; j < top_left_y + hight; ++j){

            }
        }
    }
}
void print(TreeNode* root){
    int treeDepth = maxDepth(root);
    int row = 3, col = 5;
    for(int i = 0; i < treeDepth; ++i){
        row = row * 2 - 1;
        col = col * 2 - 1;
    }

    vector<vector<char>> map(row, vector<char>(col, '\0'));

}

int main() {
    TreeNode *root = new TreeNode("root");
    readOneNode(root, "");

    print(root);

    return 0;
}