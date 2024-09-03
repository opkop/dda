#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* newNode(int item) {
    Node* temp = new Node();
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(Node* root, int& total_steps) {
    if (root != NULL) {
        inorder(root->left, total_steps);
        total_steps++;
        cout << root->key << " ";
        inorder(root->right, total_steps);
    }
}

Node* insert(Node* root, int key, int& total_steps) {
    if (root == NULL) {
        total_steps++;
        return newNode(key);
    }

    total_steps++;
    if (key < root->key) {
        root->left = insert(root->left, key, total_steps);
    } else if (key > root->key) {
        root->right = insert(root->right, key, total_steps);
    }

    return root;
}

Node* search(Node* root, int key, int& total_steps) {
    if (root == NULL || root->key == key) {
        total_steps++;
        return root;
    }

    total_steps++;
    if (root->key < key) {
        return search(root->right, key, total_steps);
    }

    return search(root->left, key, total_steps);
}

Node* deleteNode(Node* root, int key, int& total_steps) {
    if (root == NULL) {
        total_steps++;
        return root;
    }

    total_steps++;
    if (key < root->key) {
        root->left = deleteNode(root->left, key, total_steps);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key, total_steps);
    } else {
        total_steps++;
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;
        while (temp && temp->left != NULL) {
            total_steps++;
            temp = temp->left;
        }

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key, total_steps);
    }

    return root;
}

int main() {
    Node* root = NULL;
    int total_steps = 0;

    // Insert new set of keys into the BST
    root = insert(root, 60, total_steps);
    insert(root, 20, total_steps);
    insert(root, 8, total_steps);
    insert(root, 74, total_steps);
    insert(root, 37, total_steps);
    insert(root, 41, total_steps);
    insert(root, 96, total_steps);

    

    // Ask user to input a key to search
    int key_to_search;
    cout << "Enter the key to search in the BST: ";
    cin >> key_to_search;
    cout << "Inorder traversal of the BST: ";
    inorder(root, total_steps);
    cout << endl;
    
    Node* result = search(root, key_to_search, total_steps);
    if (result != NULL) {
        cout << "Key " << key_to_search << " found in the BST." << endl;
    } else {
        cout << "Key " << key_to_search << " not found in the BST." << endl;
    }

    // Delete a specific key
    int key_to_delete;
    cout << "Enter the key to delete in the BST: ";
    cin>> key_to_delete;
    root = deleteNode(root, key_to_delete, total_steps);
    cout << "Inorder traversal after deleting key " << key_to_delete << ": ";
    inorder(root, total_steps);
    cout << endl;

    // Print the total number of steps
    cout << "Total number of steps: " << total_steps << endl;

    return 0;
}
