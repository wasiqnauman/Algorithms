#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


struct node {
    int val;
    node* left;
    node* right;

    node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

node* insertNode(node* ptr, int val) {
    if(ptr == nullptr)
        return new node(val);
    if(val < ptr->val)
        ptr->left = insertNode(ptr->left, val);
    else                                            // invariant: left < n <= right
        ptr->right = insertNode(ptr->right, val);
    return ptr;
}
void inOrder(node* ptr) {
    if(ptr == nullptr)
        return;
    inOrder(ptr->left);
    cout << ptr->val << " ";
    inOrder(ptr->right);
}
void preOrder(node* ptr) {
    if(ptr == nullptr)
        return;
    cout << ptr->val << " ";
    preOrder(ptr->left);
    preOrder(ptr->right);
}
void postOrder(node* ptr) {
    if(ptr == nullptr)
        return;
    postOrder(ptr->left);
    postOrder(ptr->right);
    cout << ptr->val << " ";
}
vector<int> inOrderIterative(node* root) {
    if(root == nullptr)
        return {};
    vector<int>inOrder;
    stack<node*>nodes;

    while(!nodes.empty() || root) {
        while(root) {
            nodes.push(root);
            root = root->left;
        }
        root = nodes.top(); nodes.pop();
        inOrder.push_back(root->val);
        root = root->right;
    }
    return inOrder;
}
vector<int> preOrderIterative(node* root) {
    if(root == nullptr)
        return {};
    vector<int>preOrder;
    stack<node*>nodes;
    nodes.push(root);
    while(!nodes.empty()) {
        node* curr = nodes.top();nodes.pop();
        if(curr != nullptr) {
            preOrder.push_back(curr->val);
            nodes.push(curr->right);
            nodes.push(curr->left);
        }
    }
    return preOrder;
}
vector<int> postOrderIterative(node* root) {
    if(root == nullptr)
        return {};
    vector<int>postOrder;
    stack<node*>nodes;
    stack<int>res;
    nodes.push(root);
    while(!nodes.empty()) {
        node* curr = nodes.top(); nodes.pop();
        if(curr != nullptr) {
            postOrder.insert(postOrder.begin(), curr->val);   // we can also use a stack instead of inserting at the beginning
            //res.push(curr->val);
            /*
             * reason to push left first is that we're constructing the asnwer array from right to left,
             * instead of the usual left to right,
             * if you read it from left to right like normaly, it will seeem as if we visited nodes left, right, node.
             */
            nodes.push(curr->left);
            nodes.push(curr->right);
        }
    }
    // if we use a stack instead of inserting at the beggining of the array
//    while(!res.empty()) {
//        postOrder.push_back(res.top());
//        res.pop();
//    }
    return postOrder;
}