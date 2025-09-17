#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    int inputSize;
    Node* head;
    LinkedList() : head(nullptr), inputSize(0) {}

    ~LinkedList() {
        refreshList();
    }

    void insertNode(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        inputSize++;
    }

    void deleteNode() {
        if (head == nullptr) {
            cout << "THE LIST IS ALREADY EMPTY" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        inputSize--;
    }

    void refreshList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        inputSize = 0;
    }
    void searchList(int val){
      Node* current = head; 
        while (current != nullptr) { 
            if (current->data == val) {
            cout << "VALUE FOUND" << endl;
                 return; 
            }
            current = current->next; 
        }
        cout<<"VALUE NOT FOUND"<< endl;
}

    void printList() const {
        cout << "[" << inputSize << "]";
        if (inputSize > 0) cout << " ";
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList* list = new LinkedList(); 
    char command;
    int num;

    while (cin >> command >> num) {
        if (command == 'i') {
            list->insertNode(num);  
            list->printList();      
        } else if (command == 'd') {
            if (list->head == nullptr) {  
                cout << "THE LIST IS ALREADY EMPTY" << endl;
            } else {
                list->deleteNode();  
                list->printList();   
            }
        } else if (command == 'r') {
            list->refreshList();   
            list->printList();    
        } else if(command == 's'){
           list->searchList(num);
        } 
        else {
            cout << "INVALID COMMAND" << endl;
        }
    }

    delete list;  
    return 0;
}
