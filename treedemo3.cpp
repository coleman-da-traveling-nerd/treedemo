






#include <vector>
#include <iostream>
#include <iomanip>

//************************************************

const std::string FORMATTING[4] = {"  ", "| ", "\\-", "|-"};

//************************************************

template <class T>
class Node {
public:

    Node(T input, Node* parentInput, int depthIn){
        data = input;
        parent = parentInput;
        depth = depthIn;

        if (parent != nullptr) {
            parent->SetChild(this);
        }
        else {
            branchCheck.resize(0);
        }
        children.clear();
        std::cout << "Size of child check: " << children.size();
        iterCheck = false;
        lastChild = -1;
    }

//******
    void SetChild(Node* child) {
        children.push_back(child);
        lastChild++;
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
    int GetDepth() {
        return depth;
    }

//******
    void SetData(T input) {
        data = input;
    }

//******
    void SetLastChild(int input) {
        lastChild = input;
    }

//******
    int GetLastChild() {
        return lastChild;
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
    std::vector<bool> GetBranchVector() {
        return branchCheck;
    }

//******
    void SetBranchVector(Node<T>* selection, std::vector<bool>& branch, int pos) {
        int tempPos = pos;
        int tempDepth = selection->GetDepth();
        int tempPosInput;
        int tempSize = 0;
        if (selection->GetParent() != nullptr) {
            tempSize = parent->ChildCount();
            Node<T>* parent = selection->GetParent();
            branch.resize(branch.size() + 1);
            for (int iter = 0; iter < parent->ChildCount(); iter++) {
                if (parent->GetChild(iter) == selection) {
                    tempPosInput = iter;
                }
            }
            SetBranchVector(parent, branch, tempPosInput);
        }
        if (tempPos == tempSize - 1)
            branch[depth] = false;
        else
            branch[depth] = true;

    }

//******
    void CloneNode(Node<T>* nodeCopy) {

        nodeCopy.SetData(data);
    }

//******
    ~Node() {  }


private:
    T data;
    int depth;
    int lastChild;
    std::vector<Node<T>*> children;
    Node* parent;
    bool iterCheck;
    std::vector<bool> branchCheck;
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
        head = new Node<T>(root, nullptr, 0);
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
        int tempInt = parentInput->GetDepth();
//        int tempPos = parentInput->ChildCount();
        Node<T>* temp = new Node<T>(input, parentInput, (tempInt + 1));
//        curr->SetChild(temp);
//        std::cout << "\n\nSize of child vector check:   " << curr->ChildCount() << "\n\n";
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
    int GetNodeCount(Node<T>* selection, int input) {                      //NEED TO IMPLEMENT ITER SWITCH
        int temp = input;
        std::vector<Node<T>*> tempVector = selection->GetVector();
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
    void DeletionTraversal(Node<T>* selection, int prevSize) {
        Node<T>* temp;
        std::vector<Node<T>*> tempVector = selection->GetVector();
        int tempSize = tempVector.size();
        if (tempVector.size() > 0) {
            DeletionTraversal(tempVector[tempSize - 1], tempSize - 1);
        }
        else if (selection != nullptr){
            tempSize = prevSize;
            temp = selection->GetParent();
            tempVector = temp->GetVector();
            delete tempVector[prevSize - 1];
            tempVector.pop_back();
            tempSize = tempVector.size();
            DeletionTraversal(temp, tempSize);
        }
    }

//******
    void PrintTraversal(Node<T>* selection){                                //ERROR WITH PRINTLINE FUNCTION
        Node<T>* temp = selection;
        std::vector<Node<T>*> tempVector = selection->GetVector();
        if (selection != nullptr) {
            if (!(selection->GetIterCheck())) {
                selection->SetIterCheck(true);
                int tempTest = selection->GetBranchVector().size();
//                std::cout << "\n\n" << "Branch count: " << tempTest << "\n";
                int tempTest2 = selection->GetVector().size();
//                std::cout << "\n\n" << "Child count: " << tempTest2 << "\n";
                std::vector<bool> tempBranch = selection->GetBranchVector();
                int pos = 0;
                if (selection->GetParent() != nullptr)
                    pos = ((selection->GetParent()->ChildCount()) - 1);
                selection->SetBranchVector(selection, tempBranch, pos);
                PrintLine(selection, tempBranch);
            }

            if (tempVector.size() > 0) {
                for (int iter = 0; iter < tempVector.size(); iter++) {
                    if (!(tempVector[iter]->GetIterCheck()))
                        PrintTraversal(tempVector[iter]);
                }
            }
//            else {
//                PrintTraversal(selection.GetParent());
//            }
        }
    }

//******
    void IterTraversal(Node<T>* selection) {                                    //NEED TO FIGURE OUT HOW TO DISCERN IF A NODE HAS BEEN TRAVERSED ALREADY
        Node<T>* temp;
        std::vector<Node<T>*> tempVector = selection->GetVector();
        if (selection != nullptr) {
            if (tempVector.size() > 0) {
                for(int iter = 0; iter < tempVector.size(); iter++) {
                    if (tempVector[iter].GetIterCheck()) {
                        IterTraversal(tempVector[iter]);
                    }
                }
            }
        selection.SetIterCheck(false);
        }
    }

//******
    void PrintLine(Node<T>* selection, std::vector<bool> prevContinuations) {                                       //ERROR WITH THIS FUNCTION'S IMPLEMENTATION - PARAMETERS???
        int nodeDepth = prevContinuations.size();
        if (nodeDepth > 0) {
            for (int currDepth = 0; currDepth < nodeDepth; currDepth++) {
                if (prevContinuations[currDepth]) {
                    if (currDepth == nodeDepth - 1)
                        std::cout << FORMATTING[3];
                    else
                        std::cout << FORMATTING[1];
                }
                else
                    if (currDepth == nodeDepth - 1)
                        std::cout << FORMATTING[2];
                    else
                        std::cout << FORMATTING[0];
            }
        }
        std::cout << selection->GetData() << '\n';
    }

//******
    ~Tree() {
        curr = head;
        while (head != nullptr) {
            DeletionTraversal(curr, 0);
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

    std::cout << "\n\nTest 1\n\n";
    Tree<int> myTree(1);
    std::cout << "\n\nTest 2\n\n";
    Node<int>* temp;
    std::cout << "\n\nTest 3\n\n";
    temp = myTree.GetCurr();
    std::cout << "\n\nTest 4\n\n";
    myTree.NewNode(2, temp);
    std::cout << "\n\nTest 5\n\n";
    myTree.NewNode(3, temp);
    std::cout << "\n\nTest 6\n\n";

    myTree.MoveDown(0);
    std::cout << "\n\nTest 7\n\n";
    temp = myTree.GetCurr();
    std::cout << "\n\nTest 8\n\n";
    myTree.NewNode(4, temp);
    std::cout << "\n\nTest 9\n\n";
    myTree.NewNode(5, temp);
    std::cout << "\n\nTest 10\n\n";

    myTree.MoveUp();
    std::cout << "\n\nTest 11\n\n";
    myTree.MoveDown(1);
    std::cout << "\n\nTest 12\n\n";
    temp = myTree.GetCurr();
    std::cout << "\n\nTest 13\n\n";
    myTree.NewNode(6, temp);
    std::cout << "\n\nTest 14\n\n";
    myTree.NewNode(7, temp);
    std::cout << "\n\nTest 15\n\n";

    myTree.ResetCurr();
    std::cout << "\n\nTest 16\n\n";
    temp = myTree.GetCurr();
    std::cout << "\n\nTest 17\n\n";

    myTree.PrintTraversal(temp);
    std::cout << "\n\nTest 18\n\n";

    return 0;
}




