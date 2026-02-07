#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = nullptr;
    }
    

};
void insertNode(Node* & root, int data) {
    if (!root) {
        root = new Node(data);
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (!curr->left) {
            curr->left = new Node(data);
            return;
        } else {
            q.push(curr->left);
        }

        if (!curr->right) {
            curr->right = new Node(data);
            return;
        } else {
            q.push(curr->right);
        }
    }
    }
    void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
    void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
    void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
    void levelOrder(Node* root){
        if(!root)return;
        queue<Node*>Q;
        Q.push(root);
        while(!Q.empty()){
            Node* curr=Q.front();
            Q.pop();
            cout<<curr->data<<" ";
            if(curr->left)Q.push(curr->left);
            if(curr->right)Q.push(curr->right);
        }
    }
    void printLeaves(Node* root) {
    if (!root) return;

    if (!root->left && !root->right) {
        cout << root->data << " ";
        return;
    }

    printLeaves(root->left);
    printLeaves(root->right);
}
    void leftBoundary(Node* root) {
    if (!root || (!root->left && !root->right)) return;

    cout << root->data << " ";
    if (root->left)
        leftBoundary(root->left);
    else
        leftBoundary(root->right);
}
    void rightBoundary(Node* root) {
    if (!root || (!root->left && !root->right)) return;

    if (root->right)
        rightBoundary(root->right);
    else
        rightBoundary(root->left);

    cout << root->data << " ";
}
    void boundaryTraversal(Node* root) {
    if (!root) return;

    cout << root->data << " ";

    leftBoundary(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    rightBoundary(root->right);
}
void flattern(Node* root){
    if(!root)return;
    flattern(root->left);
    flattern(root->right);
    if(root->left){
        Node* temp=root->right;
        root->right=root->left;
        root->left=nullptr;
        Node* curr=root->right;
        while(curr->right)curr=curr->right;
        curr->right=temp;
    }
}

int main() {
    Node* root = nullptr;

    // Dynamic insert
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 8);

    cout << "Inorder: ";
    inorder(root); cout << endl;

    cout << "Preorder: ";
    preorder(root); cout << endl;

    cout << "Postorder: ";
    postorder(root); cout << endl;

    cout << "Level Order: ";
    levelOrder(root); cout << endl;

    cout << "Leaves: ";
    printLeaves(root); cout << endl;

    cout << "Boundary: ";
    boundaryTraversal(root); cout << endl;

    flattern(root);
    cout << "Flattened (Preorder): ";
    while (root) {
        cout << root->data << " ";
        root = root->right;
    }
}
