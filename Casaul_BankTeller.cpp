//CASAUL BANK TELLER
#include <iostream>
using namespace std;

//for VIPS
string* vipQueue;
int vipFront = 0, vipRear = 0;

//FOR reg
string* regularQueue;
    int regFront = 0, regRear = 0;

string* tempStack;
    int stackTop = -1;


void enqueueVIP(string name) {
    vipQueue[vipRear++] = name;
    }

void enqueueRegular(string name) {
    regularQueue[regRear++] = name;
    }

bool isVIPEmpty() {
    return vipFront >= vipRear;
    }

bool isRegularEmpty() {
    return regFront >= regRear;
    }

string dequeueVIP() {
    return vipQueue[vipFront++];
    }

string dequeueRegular() {
    return regularQueue[regFront++];
    }

void push(string name) {
    tempStack[++stackTop] = name;
    }

string pop() {
    return tempStack[stackTop--];
    }

bool isStackEmpty() {
    return stackTop == -1;
    }

int main() {
    int n;
    cin >> n;
    
    vipQueue = new string[n];
    regularQueue = new string[n];
    tempStack = new string[n];
    
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "ARRIVE") {
            int customerType;
            string name;
            cin >> customerType >> name;
            
            if (customerType == 1) {
                enqueueVIP(name);
            } else {
                enqueueRegular(name);
            }
        } 
        else if (operation == "SERVE") {
            if (!isVIPEmpty()) {
                cout << dequeueVIP() << endl;
            } 
            else if (!isRegularEmpty()) {
                cout << dequeueRegular() << endl;
            } 
            else {
                cout << "EMPTY" << endl;
            }
        }
    }
    
    delete[] vipQueue;
    delete[] regularQueue;
    delete[] tempStack;
    
    return 0;
}