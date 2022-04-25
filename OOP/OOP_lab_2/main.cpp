#include <iostream>
#include "bin_tree.h"

using namespace std;


int main() {

//    Node *root1 = BST::create_bin_search_tree(5, 3, 4, 2, 7, 8);
    Node *root1 = BST::create_bin_search_tree(10, 5, 3, 4, 2, 1, 6, 7, 9, 8, 11);

    BST::place_node(root1, 10);

    BST::travel_in_order(root1);
    cout << '\n';
    BST::travel_pre_order(root1);
    cout << '\n';
    BST::travel_post_order(root1);
    cout << '\n';



    Node *res;
    res = BST::search_elem(root1, 6);
    BST::print_node(res);

    res = BST::search_elem(root1, 15);
    BST::print_node(res);

    BST::del_node(root1, 5);
    BST::travel_in_order(root1);
    cout << '\n';
    res = BST::search_elem(root1, 5);

    BST::print_node(res);
    return 0;
}
