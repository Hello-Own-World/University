//
// Created by yushc on 30.03.2022.
//

#ifndef OOP_LAB_2_BIN_TREE_H
#define OOP_LAB_2_BIN_TREE_H

class Node {
public:
    int value;
    Node *left = nullptr, *right = nullptr;

    explicit Node(int value) { // default constructor
        this->value = value;
    }

    static Node *add_node(int data) { // returns pointer to new node
        Node *node = new Node(data);
        node->value = data;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }
};

class BST : public Node {
public:
    static Node *create_bin_search_tree(int n, ...) { // create new BST with given arguments. Returns ptr to root
        int *ptr = &n+2;
        Node *root = add_node(*ptr);

        for (int i = 2; i < 2 * n; i += 2) {
            place_node(root, ptr + i);
        }
        return root;
    }

    static void place_node(Node *root, const int *data) { // place node in BST, used for variable arg func (takes ptr)
        if (*data < root->value) {
            if (root->left == nullptr) {
                root->left = add_node(*data);
                return;
            }
            place_node(root->left, data);
        } else {
            if (root->right == nullptr) {
                root->right = add_node(*data);
                return;
            }
            place_node(root->right, data);
        }
    }


    static void place_node(Node *root, int data) { //place node in BST, takes int
        if (data < root->value) {
            if (root->left == nullptr) {
                root->left = add_node(data);
                return;
            }
            place_node(root->left, data);
        } else {
            if (root->right == nullptr) {
                root->right = add_node(data);
                return;
            }
            place_node(root->right, data);
        }
    }

    static Node *search_elem(Node *root, int elem) { // returns found elem or nullptr
        Node *temp = root;
        while (temp != nullptr) {
            if (temp->value == elem) {
                return temp;
            }
            if (elem < temp->value) {
                if (temp->left!= nullptr){
                    temp = temp->left;
                } else return nullptr;
            } else {
                if (temp->right!= nullptr){
                    temp = temp->right;
                } else{
                    return nullptr;
                }
            }
        }
        return nullptr;
    }

    static void del_node(Node *root, int val) {
        Node *temp, *temp1, *prev;
        temp = search_elem(root, val);
        temp1 = temp;
        if (temp != nullptr) {
            if (temp->left != nullptr) {
                temp = temp->left;//one step left and then look for far right elem
                while (temp->right != nullptr) {
                    prev = temp;
                    temp = temp->right;
                }
            } else {
                if (temp->right != nullptr) {
                    temp = temp->right;
                    while (temp->left != nullptr) {
                        prev = temp;
                        temp = temp->left;
                    }
                } else return;
            }
        } else return;

        temp1->value = temp->value;
        if (temp->right != nullptr) {
            temp1->right = temp->right;
        }
        if (temp->left != nullptr) {
            temp1->left = temp->left;
        }

        if (prev->left== temp){
            prev->left= nullptr;
        } else{
            prev->right= nullptr;
        }
        delete temp;
    }

    static void travel_pre_order(Node *root) {
        if (root != nullptr) {
            std::cout << " " << root->value;
            travel_pre_order(root->left);
            travel_pre_order(root->right);
        }
    }

    static void travel_in_order(Node *root) {
        if (root != nullptr) {
            travel_in_order(root->left);
            std::cout << " " << root->value;
            travel_in_order(root->right);
        }
    }

    static void travel_post_order(Node *root) {
        if (root != nullptr) {
            travel_post_order(root->left);
            travel_post_order(root->right);
            std::cout << " " << root->value;
        }
    }

    static void print_node(Node* node){
        if(node!= nullptr){
            std::cout << node->value << '\n';
        } else{
            std::cout << "Node doesn't exist"<<'\n';
        }
    }

};

#endif //OOP_LAB_2_BIN_TREE_H
