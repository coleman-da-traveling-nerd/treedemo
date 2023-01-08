






#include <vector>
#include <iostream>
#include <iomanip>

//************************************************

const std::string FORMATTING[3] = {"\\-", "| ", "  "};

//************************************************

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
        iterCheck = false;
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
    T GetData() {
        return data;
    }

//******
    void SetData(T input) {
        data = input;
    }

//******
    bool GetIterCheck() {
        return iterCheck;
    }

//******
    void SetIterCheck(bool selection) {
        iterCheck = selection;
    }

//******
    void CloneNode(Node<T>* nodeCopy) {

        nodeCopy.SetData(data);
    }

//******
    ~Node() {  }


private:
    T data;
    std::vector<Node<T>*> children;
    Node* parent;
    bool iterCheck;
};

//************************************************

template <class T>
class Tree {
public:

    Tree() {
        head = nullptr;
        curr = head;
        treeSize = 0;
    }
/*
//******
    Tree(Tree otherTree) {                                              //NEED COPY CONSTRUCTOR IMPLEMENTATION
        otherTree.ResetCurr();
        CopyTree(otherTree);
    }

//******
    void CopyTree(Tree otherTree) {                                     //NEED ALGORITHM TO COPY EACH NODE AND SET LINKS (SETTING LINKS IS THE DIFFICULT PART)
        Node<T>* temp;
        Node<T>* tempParent;
        Node<T>* otherTemp = otherTree.GetCurr();
        std::vector<Node<T>*> tempVector = otherTemp->GetVector();
        if (tempVector.size() > 0) {
            for (int iter = 0; iter > tempVector.size(); iter++) {
                if (!(tempVector[iter]->GetIterCheck()))
                    otherTree.MoveDown(iter);
                    CopyTree(tempVector[iter]);
            }
        }
        else {
           if (selection != nullptr)
            Node<T>* temp = new Node<T>(otherTemp.GetData()));
        }
        if (selection != nullptr)
            Copy;
    }
*/

//******
    Tree(T root) {
        head = new Node<T>(root, nullptr);
        curr = head;
        treeSize = 1;
    }

//******
    Tree(Node<T>* root) {
        head = root;
        curr = head;
        treeSize = 1;
    }

//******
    Tree(Node<T>* root, int nodeCount) {
        head = root;
        curr = head;
        treeSize = nodeCount;
    }

//******
    void NewNode(T input, Node<T>* parentInput) {
        Node<T>* temp = new Node<T>(input, parentInput);
        curr->SetChild(temp);
        treeSize++;
    }

//******
    void MoveDown(int selection) {
        curr = curr->GetChild(selection);
    }

//******
    Node<T>* GetHead() {
        return head;
    }

//******
    Node<T>* GetCurr() {
        return curr;
    }

//******
    std::vector<bool> SetContinuation() {                                   //NEED TO IMPLEMENT GETNODECOUNT FUNCTION
        std::vector<bool> vectorOut(treeSize);
        int temp = head.ChildCount();
        int nodeCount = 0;
        temp =- 1;
        for(int iter = 0; iter < treeSize; iter++) {

        }

    }

//******
    int GetNodeCount(Node<T>* selection, int input); {                      //NEED TO IMPLEMENT ITER SWITCH
        int temp = input;
        tempVector = selection->GetVector();
        int tempSize = tempVector.size();
        if (tempSize > 0) {
            for (int iter = 0; iter < tempSize; iter++) {
                temp = temp + GetNodeCount(tempVector[iter], temp);
            }
        }

    }

//******
    void MoveUp() {
        curr = curr->GetParent();
    }

//******
    void ResetCurr() {
        curr = head;
    }

//******
    void DeleteNode() {
        if (curr->GetParent() != nullptr) {
            curr = curr->GetParent();
            int temp = curr->GetVector().size();
            curr->GetChildren().clear();
            curr->GetChildren().shrink_to_fit();
            treeSize =- temp;
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
        treeSize = 0;
    }

//******
    void PrintTraversal(Node<T>* selection){                                //ERROR WITH PRINTLINE FUNCTION
        Node<T>* temp = selection;
        std::vector<Node<T>*> tempVector = selection->GetVector();
        if (selection != nullptr) {
            if (!(selection->GetIterCheck())) {
                selection->SetIterCheck(true);
                PrintLine(selection);
            }

            if (tempVector.size() > 0) {
                for (int iter = 0; iter < tempVector.size(); iter++) {
                    if (!(tempVector[iter]->GetIterCheck()))
                        PrintTraversal(tempVector[iter]);
                }
            }
            else {
                PrintTraversal(selection.GetParent());
            }
        }
    }

//******
    void IterTraversal(Node<T>* selection) {                                    //NEED TO FIGURE OUT HOW TO DISCERN IF A NODE HAS BEEN TRAVERSED ALREADY
        Node<T>* temp;
        std::vector<Node<T>*> tempVector = selection->GetVector();
        if (tempVector.size() > 0) {
            IterTraversal(tempVector[0]);
        }
        else if (selection != nullptr) {
            selection.SetIterCheck(false);
        }
    }

//******
    void PrintLine(T data, int nodeDepth,                                       //ERROR WITH THIS FUNCTION'S IMPLEMENTATION - PARAMETERS???
                   std::vector<bool> prevContinuations) {
        if (nodeDepth == 0) {
            std::cout << data;
        }
        else {
            for (int currDepth = 0; currDepth > nodeDepth; currDepth++) {
                if (prevContinuations[currDepth]) {
                    if (currDepth == nodeDepth - 1)
                        std::cout << FORMATTING[0];
                    else
                        std::cout << FORMATTING[1];
                }
                else
                    std::cout << FORMATTING[2];
            }
        }
        std::cout << data << std::endl;
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
    int childNum;
    int treeSize;

};

//************************************************

int main() {

    Tree<int> myTree(1);
    Node<int>* temp;

    temp = myTree.GetCurr();
    myTree.NewNode(2, temp);
    myTree.NewNode(3, temp);

    myTree.MoveDown(0);
    temp = myTree.GetCurr();
    myTree.NewNode(4, temp);
    myTree.NewNode(5, temp);

    myTree.MoveUp();
    myTree.MoveDown(1);
    temp = myTree.GetCurr();
    myTree.NewNode(6, temp);
    myTree.NewNode(7, temp);

    myTree.ResetCurr();
    temp = myTree.GetCurr();

    myTree.PrintTraversal(temp);

    return 0;
}




