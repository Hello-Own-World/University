//#include <iostream>
//
//using namespace std;
//
//struct Node {
//    int data;
//    struct Node* left;
//    struct Node* right;
//
//    Node(int val)
//    {
//        data = val;
//
//        left = NULL;
//        right = NULL;
//    }
//};
//
//struct node* search(struct node* root, int key)
//{
//    if (root == NULL || root->data == key)
//        return root;
//
//    // Key is greater than root's key
//    if (root->key < key)
//        return search(root->right, key);
//
//    // Key is smaller than root's key
//    return search(root->left, key);
//}
//
//
//int main() {
//    struct Node* root = new Node(1);
//
//    root->left = new Node(2);
//    root->right = new Node(3);
//
//
//
//    root->left->left = new Node(4);
//
//    search(root, 4);
//
//
//    return 0;
//}
