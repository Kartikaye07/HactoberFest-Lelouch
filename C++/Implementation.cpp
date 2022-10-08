#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    
    //Constructor
    TreeNode() {
        left = NULL;
        right = NULL;
    }

    //Parametrized Constructor
    TreeNode(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* Build_Tree() {
    int data ;
    cin>>data;
    TreeNode* head = NULL;

    if(data!=-1) {
        head = new TreeNode(data);
        head->left = Build_Tree();
        head->right = Build_Tree();
    }
    return head;
}

void inorder(TreeNode* root) {
    if(!root) {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(TreeNode* root) {
    if(!root) {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if(!root) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int Height(TreeNode* root) {
    if(!root) {
        return 0;
    }
    return 1+max(Height(root->left),Height(root->right));
}

void Level_Order(TreeNode* root) {
    if(!root) {
        return;
    }
    queue<TreeNode*> temp_queue;
    temp_queue.push(root);
    while(!temp_queue.empty()) {
        TreeNode* curr_node = temp_queue.front();
        cout<<curr_node->data<<" ";
        temp_queue.pop();
        if(curr_node->left) {
            temp_queue.push(curr_node->left);
        }
        if(curr_node->right) {
            temp_queue.push(curr_node->right);
        }
    }
    return;
}

void Level_Order_Line(TreeNode* root) {
    if(!root) {
        return;
    }
    queue<TreeNode*> temp_queue;
    temp_queue.push(root);
    temp_queue.push(NULL);
    while(temp_queue.size()>1) {
        TreeNode* queue_front = temp_queue.front();
        temp_queue.pop();
        if(queue_front==NULL) {
            temp_queue.push(NULL);
            cout<<endl;
            continue;
        }
        cout<<queue_front->data<<"  ";
        if(queue_front->left) {
            temp_queue.push(queue_front->left);
        }
        if(queue_front->right) {
            temp_queue.push(queue_front->right);
        }
    }
    return;
}

int Size(TreeNode* root) {
    if(!root) {
        return 0;
    }
    return 1+Size(root->left)+Size(root->right);
}

void print_k_nodes(TreeNode* root,int k) {
    if(!root) {
        return;
    }
    if(k==1) {
        cout<<root->data<<"  ";
    }
    print_k_nodes(root->left,k-1);
    print_k_nodes(root->right,k-1);
}

int Maximum_in_Binary_Tree(TreeNode* root) {
    if(!root) {
        return INT_MIN;
    }
    int curr_val = root->data;
    int left_max = Maximum_in_Binary_Tree(root->left);
    int right_max = Maximum_in_Binary_Tree(root->right);
    return max(curr_val,max(left_max,right_max));
}

int max_level = 0;
void Print_Left_Tree(TreeNode* root,int level) {
    if(!root) {
        return;
    }
    if(max_level<level) {
        cout<<root->data<<"  ";
        max_level = level;
    }
    Print_Left_Tree(root->left,level+1);
    Print_Left_Tree(root->right,level+1);
    return;
}

int right_max_level = 0;
void Print_Right_Tree(TreeNode* root,int level) {
    if(!root) {
        return;
    }
    if(right_max_level<level) {
        cout<<root->data<<" ";
        right_max_level = level;
    }
    Print_Right_Tree(root->right,level+1);
    Print_Right_Tree(root->left,level+1);
}

bool Children_Sum(TreeNode* root) {
    if(!root) {
        return true;
    }
    if(!root->right and !root->left) {
        return true;
    }
    int sum = 0;
    if(root->left) {
        sum+= root->left->data;
    }
    if(root->right) {
        sum+= root->right->data;
    }
    bool left_children_sum = Children_Sum(root->left);
    bool right_children_sum = Children_Sum(root->right);
    // cout<<left_val<<" + "<<right_val<<" = "<<root->data<<endl;
    return sum==root->data && left_children_sum==true && right_children_sum==true;
}

int Maximum_Width(TreeNode* root) {
    queue<TreeNode*> temp_queue;
    temp_queue.push(root);
    int count = 0;
    int max_size = INT_MIN;
    while(!temp_queue.empty()) {
        count = temp_queue.size();
        max_size = max(max_size,count);
        for(int counter = 0;counter<count;counter++) {
            TreeNode* queue_front = temp_queue.front();
            temp_queue.pop();
            if(queue_front->left) {
                temp_queue.push(queue_front->left);
            }
            if(queue_front->right) {
                temp_queue.push(queue_front->right);
            }
        }        
    }
    return max_size;
}

bool Height_Balanced(TreeNode* root) {
    //Base Case
    if(!root) {
        return true;
    }
    //Recursive Case
    int Height_Left = Height(root->left);
    int Height_Right = Height(root->right);
    bool Left_Balanced = Height_Balanced(root->left);
    bool Right_Balanced = Height_Balanced(root->right);
    if(abs(Height_Left-Height_Right)<=1) {
        if(Left_Balanced && Right_Balanced) {
            return true;
        }
    }
    return false;
}
int res = 0;
int Diameter(TreeNode* root) {
    if(!root) {
        return 0;
    }
    int lh = Height(root->left);
    int rh = Height(root->right);
    res = max(res,lh+rh+1);
    return 1+max(lh,rh);
}

int main() {
    TreeNode* root = Build_Tree();   
    // inorder(root);cout<<endl;
    // preorder(root);cout<<endl;
    // postorder(root);cout<<endl;
    // Level_Order(root);cout<<endl;
    // Level_Order_Line(root);cout<<endl;
    // cout<<"Size of the Tree is "<<Size(root)<<endl;
    // print_k_nodes(root,2);
    // int max_in_binary_tree = Maximum_in_Binary_Tree(root);
    // cout<<"The maximum in the binary tree is : "<<max_in_binary_tree<<endl;
    // Print_Left_Tree(root,1);cout<<endl;
    // Print_Right_Tree(root,1);cout<<endl;
    if(Children_Sum(root)) {
        cout<<"Following children sum property "<<endl;
    }
    else {
        cout<<"Not following children sum property "<<endl;
    }
    int max_width = Maximum_Width(root);
    cout<<"The maximum width of the binary tree is : "<<max_width<<endl;
    if(Height_Balanced(root)) {
        cout<<"Yes it is Height balanced "<<endl;
    }
    else {
        cout<<"No it not Height Balanced "<<endl;
    }
    int diameter = Diameter(root);
    cout<<"Diameter is : "<<diameter<<endl;
}
//1 2 3 4 -1 -1 5 -1 -1 6 -1 -1 7 8 9 10 -1 -1 11 -1 -1 12 -1 -1 13 -1 -1 
// 10 8 -1 -1 2 2 -1 -1 -1 
//20 8 3 -1 -1 5 -1 -1 12 -1 -1 
// 3 4 5 -1 -1 -1 -1 
// 8 4 -1 -1 20 13 -1 -1 70 -1 -1 
// 30 40 50 -1 -1 70 20 -1 -1 10 -1 -1 80 5 -1 -1 -1 
