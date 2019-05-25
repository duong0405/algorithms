#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

// Inserts a value while preserving the BST invariant.
// Duplicate values are ignored.
TreeNode* bst_insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode{value};
    }

    if (value < root->value) {
        root->left = bst_insert(root->left, value);
    } else if (value > root->value) {
        root->right = bst_insert(root->right, value);
    }

    return root;
}

// Recursively searches only the subtree that can contain target.
bool bst_search(TreeNode* root, int target) {
    if (root == nullptr) {
        return false;
    }

    if (root->value == target) {
        return true;
    }

    if (target < root->value) {
        return bst_search(root->left, target);
    }

    return bst_search(root->right, target);
}

// Iterative search avoids recursive call-stack growth.
bool bst_search_iterative(TreeNode* root, int target) {
    TreeNode* current = root;

    while (current != nullptr) {
        if (current->value == target) {
            return true;
        }

        current = target < current->value ? current->left : current->right;
    }

    return false;
}

// Inorder traversal of a BST prints values in ascending order.
void inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    std::cout << root->value << ' ';
    inorder(root->right);
}

// Deletes children before their parent to release every allocated node.
void destroy_tree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    destroy_tree(root->left);
    destroy_tree(root->right);
    delete root;
}

int main() {
    TreeNode* root = nullptr;

    for (int value : {8, 3, 10, 1, 6}) {
        root = bst_insert(root, value);
    }

    std::cout << "inorder: ";
    inorder(root);
    std::cout << '\n';

    std::cout << std::boolalpha;
    std::cout << "recursive search 6 = " << bst_search(root, 6) << '\n';
    std::cout << "recursive search 7 = " << bst_search(root, 7) << '\n';
    std::cout << "iterative search 6 = " << bst_search_iterative(root, 6) << '\n';
    std::cout << "iterative search 7 = " << bst_search_iterative(root, 7) << '\n';

    destroy_tree(root);
    root = nullptr;

    return 0;
}
