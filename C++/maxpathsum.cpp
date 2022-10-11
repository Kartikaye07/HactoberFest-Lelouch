class Solution {
public:
    int f(TreeNode* root,int &maxx){
        if(root==NULL){
            return 0;
        }
        int leftsum=max(0,f(root->left,maxx));
        int rightsum=max(0,f(root->right,maxx));
        maxx=max(maxx,leftsum+rightsum+root->val);
        cout<<rightsum<<endl;
        return root->val+max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int maxx=INT_MIN;
        f(root,maxx);
        return maxx;
    }
};
