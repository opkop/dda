#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq) {
        left = right = nullptr;
        this->ch = ch;
        this->freq = freq;
    }
};

// Compare class for priority queue
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print Huffman Codes
void printCodes(Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    printCodes(root->left, str + "0", huffmanCode);
    printCodes(root->right, str + "1", huffmanCode);
}

// Function to build the Huffman Tree and generate codes
void buildHuffmanTree(string text) {
    // Count frequency of each character
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Create a priority queue to store nodes of Huffman tree
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create leaf nodes for each character and add to priority queue
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Iterate until the size of the priority queue becomes 1
    while (pq.size() != 1) {
        // Remove the two nodes of highest priority (lowest frequency)
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        // Create a new internal node with these two nodes as children
        // and with frequency equal to the sum of the two nodes' frequencies
        Node *sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;

        // Add the new node to the priority queue
        pq.push(sum);
    }

    // Root of the Huffman Tree
    Node* root = pq.top();

    // Traverse the Huffman Tree and store Huffman Codes in a map
    unordered_map<char, string> huffmanCode;
    printCodes(root, "", huffmanCode);

    // Print Huffman Codes
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " " << pair.second << "\n";
    }

    // Encode the input text
    string encodedStr = "";
    for (char ch : text) {
        encodedStr += huffmanCode[ch];
    }

    cout << "\nEncoded String:\n" << encodedStr << "\n";

    // Decode the encoded string
    string decodedStr = "";
    Node* curr = root;
    for (char bit : encodedStr) {
        if (bit == '0') {
            curr = curr->left;
        } else {
            curr = curr->right;
        }

        // If we reach a leaf node
        if (!curr->left && !curr->right) {
            decodedStr += curr->ch;
            curr = root;
        }
    }

    cout << "\nDecoded String:\n" << decodedStr << "\n";
}

int main() {
    string text = "Asian College of computer studies";
    buildHuffmanTree(text);

    return 0;
}
