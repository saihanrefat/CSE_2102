#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Append a node at the end
void append(Node* &head, int val) {
    Node* newNode = new Node{val, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Swap two adjacent nodes (by pointer manipulation)
void swapNodes(Node* &head, Node* prev, Node* &a, Node* &b) {
    a->next = b->next;
    b->next = a;
    if (prev) {
        prev->next = b;
    } else {
        head = b; // a was head, now b becomes head
    }

    // Swap the node references for next loop iteration
    Node* temp = a;
    a = b;
    b = temp;
}

// Sort the linked list using bubble sort (by swapping links, not data)
void sortList(Node* &head) {
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        Node* prev = nullptr;
        Node* curr = head;

        while (curr && curr->next) {
            Node* next = curr->next;
            if (curr->data > next->data) {
                swapNodes(head, prev, curr, next);
                swapped = true;
            }
            prev = curr;
            curr = curr->next;
        }
    } while (swapped);
}

// Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Main function to test
int main() {
    Node* head = nullptr;

    append(head, 40);
    append(head, 10);
    append(head, 30);
    append(head, 20);

    cout << "Original List: ";
    printList(head);

    sortList(head);

    cout << "Sorted List:   ";
    printList(head);

    return 0;
}

