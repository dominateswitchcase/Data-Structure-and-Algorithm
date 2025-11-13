//CASAUL LIBRARY CATALOG
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int M, N;
    cin >> M >> N;

    vector<int> hashTable(M, -1); // -1 to mark empty slots
    vector<int> books(N);

    for (int i = 0; i < N; i++) {
        cin >> books[i];
    }

    for (int i = 0; i < N; i++) {
        int x = books[i];
        int index = x % M;  // for hash function
        bool inserted = false;

        for (int j = 0; j < M; j++) {
            int probe = (index + j) % M;
            if (hashTable[probe] == -1) { // this is if the empty slot found
                hashTable[probe] = x; //THIS CHANGES THE EMPTY TO BOOKS
                inserted = true;
                break;
            }
        }
        // if full, the book is discarded
    }

    
    for (int i = 0; i < M; i++) {// Outputs the hash table
        cout << hashTable[i];
        if (i != M - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
