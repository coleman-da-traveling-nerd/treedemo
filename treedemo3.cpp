






#include <vector>
#include <iostream>
#include <iomanip>

template <class T>
class Node {
public:

    Node(T input, Node* parentInput){
        data = input;
        parent = parentInput;
        if (parent != nullptr) {
            parent.SetChild(this);
        }
        children.clear();
    }

//******
    void SetChild(Node* child) {
        children.push_back(child);
    }

//******
    Node* GetChild(int selection) {
        return children[selection];
    }

//******
    int ChildCount() {
        return children.size();
    }

//******
    Node* GetParent() {
        return parent;
    }

//******
    std::vector<Node<T>*> GetVector() {
        return children;
    }

//******
    ~Node() {  }


private:
    T data;
    std::vector<Node<T>*> children;
    Node* parent;
};

//************************************************

template <class T>
class Tree {
public:

    Tree(Node<T>* root, int nodeCount) {
        head = root;
        curr = head;
        treeSize = nodeCount;
    }

//******
    void NewNode(T input, Node<T>* parentInput) {
        Node<T>* temp = new Node<T>(input, parentInput);
        curr->SetChild(temp);
    }

//******
    void MoveDown(int selection) {
        curr = curr->GetChild(selection);
    }

//******
    void MoveUp() {
        curr = curr->GetParent();
    }

//******
    void DeleteNode() {
        if (curr->GetParent() != nullptr) {
            curr = curr->GetParent();
            curr->GetChildren().clear();
            curr->GetChildren().shrink_to_fit();
        }
    }

//******
    void DeletionTraversal(Node<T>* selection) {
        Node<T>* temp;
        std::vector<Node<T>*> tempVector = selection->GetVector();
        if (tempVector.size() > 0) {
            DeletionTraversal(tempVector[0]);
        }
        else if (selection != nullptr){
            temp = selection.GetParent();
            tempVector = temp->GetVector();
            delete tempVector[0];
            tempVector.pop_front();
            DeletionTraversal(temp);
        }
    }

//******
    void PrintTraversal(Node<T>* selection) {
        vector<Node<T>> tempVector;
        std::string tempString;
        int depth = 0;
        bool continued = true;




    }

//******
    void PrintLine(T data, int depth, bool continued) {
        const std::string FORMATTING[2] = {"\\-", "|", " "};
        if (depth = 0) {
            std::cout << data;
        }
        else if (depth = 1) {
            std::cout << FORMATTING[0] << data << std::endl;
        }
        else if (depth > 1) {
            if (continued) {
                std::cout << FORMATTING[1]
                          << std::setw(depth - 1)
                          << FORMATTING[0] << data;
            }
            else {
                std::cout << FORMATTING[2]
                          << std::setw(depth - 1)
                          << FORMATTING[0] << data;
            }
        }
    }

//******
    ~Tree() {
        curr = head;
        while (head != nullptr) {
            DeletionTraversal(curr);
        }
    }

private:
    Node<T>* head;
    Node<T>* curr;
    int treeSize;

};







