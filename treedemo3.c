






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
    vector<Node<T>*> GetVector() {
        return children;
    }

//******
    ~Node() {  }


private:
    T data
    vector<Node<T>*> children;
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
        vector<Node<T>*> tempVector = selection->GetVector();
        if (tempVector.size > 0) {
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
    ~Tree() {
        curr = head;
        while (head != nullptr) {

        }
    }

private:
    Node<T>* head;
    Node<T>* curr;
    int treeSize;

}







