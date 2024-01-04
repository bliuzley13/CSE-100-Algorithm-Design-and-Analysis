#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

//Represents the nodes in a binary tree
struct Node {
    //Stores a character symbol associated with node
    char symbol;
    //Stores the frequency/occurrence count of the symbol
    int frequency;
    //Pointers of left and right child nodes that connect in a binary tree structure
    Node* left;
    Node* right;
    //Node is a constructor, takes in sym and freq
    //Sym and freq initializes variables with values passed to constructor
    //Sets left and right pointers to nullptr as they initially have no children
    Node(char sym, int freq) : symbol(sym), frequency(freq), left(nullptr), right(nullptr) {}
};

//Declares a structure designed to be used as a comparator for nodes in a priority queue
struct CmprNode {
    //Defines function call operator inside structure. Makes objects callable, treats instances like functions
    bool operator()(Node* lhs, Node* rhs) {
        //lhs accesses freqency of left hand side
        //rhs accesses frequency of right hand side
        //Returns true if frequency of left node is greater than frequency of right node
        return lhs->frequency > rhs->frequency;
        //Meant to order elements based on teheir frequencies
        //With Huffman coding, nodes with lower frequencies are given higher priority in the priority queue
        //Priority queue will dequeue nodes with lowest frequency first
    }
};

//Recursive function which traverses Huffman tree
//Root is root node of Huffman tree to traverse
//String code is current Huffman code being generated
//Reference to a map that stores generated Huffman codes for each symbol
void generHuffCodes(Node* root, string code, map<char, string>& huffCode) {
    //Traverses Huffman Tree and generates Huffman codes for each symbol
    //Checks if current node is leaf node by verifying if both left and right child nodes are nullptr
    if (root->left == nullptr && root->right == nullptr) {
        //If its a leaf node, assignes generated code to root->symbol
        huffCode[root->symbol] = code;
        return;
    }
    //Appended to code when moving to left child
    generHuffCodes(root->left, code + "0", huffCode);
    //Appended to code when moving to right child 
    generHuffCodes(root->right, code + "1", huffCode);
}
//Traverses tress recursively, builds Huffman codes as it moves down the tree from root towards leaves
//For each node encountered, it appends '0' when moving to left child and appends '1' when moving to
//right child, forming unique binary codes for each symbol based on position in the tree
//Assigns unique binary codes to each symbol based on frequency and position in tree, stores codes
//in huffCode map

int main() {
    //Stores input frequencies
    int freqs[6];
    //Stores corresponding symbols for which frequencies will be provided
    char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    //Reads input frequencies for symbols 'A' through 'F' from standard input
    for (int i = 0; i < 6; ++i) {
        cin >> freqs[i];
    }

    // Priority queue builds Huffman Tree
    priority_queue<Node*, vector<Node*>, CmprNode> pq;

    //Creates initial nodes, each with a symbol with its frequency
    for (int i = 0; i < 6; ++i) {
        pq.push(new Node(symbols[i], freqs[i]));
    }

    //Builds Huffman Tree
    while (pq.size() > 1) {
        //Dequeues 2 nodes with lowest frequency
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        //Combines those into internal node
        Node* inNode = new Node('$', left->frequency + right->frequency);
        //Enqueues internal node into priority queue
        inNode->left = left;
        inNode->right = right;
        //Continues until only one node is in the priority queue
        pq.push(inNode);
    }

    Node* root = pq.top();

    //Generate Huffman Codes
    map<char, string> huffCodes;
    //Generates Huffman Codes for each symbol in the tree and stored in map
    generHuffCodes(root, "", huffCodes);

    //Output Huffman Codes in intended format
    for (const auto& pair : huffCodes) {
        cout << pair.first << ":" << pair.second << endl;
    }

    return 0;
}
