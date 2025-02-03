// Name: Lev Sakaju; ID: 209266667
// Name: Aviv Raz; ID: 206775959

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNewNode(Node* head, int num);
void deleteList(Node* head);
void printList(Node* head);
Node* reverseList(Node* head);
bool mirror(Node* list1, Node* list2);
Node* sumList(Node* head);

int main()
{
    bool res;

    // Create Node list1: 1 → 2 → 3 → 5
    Node* list1 = NULL;
    list1 = createNewNode(list1, 1);
    list1 = createNewNode(list1, 2);
    list1 = createNewNode(list1, 3);
    list1 = createNewNode(list1, 5);

    // Create Node list2: 5 → 3 → 2 → 1
    Node* list2 = NULL;
    list2 = createNewNode(list2, 5);
    list2 = createNewNode(list2, 3);
    list2 = createNewNode(list2, 2);
    list2 = createNewNode(list2, 1);

    // Create Node list3: 5 → 3 → 4 → 1
    Node* list3 = NULL;
    list3 = createNewNode(list3, 5);
    list3 = createNewNode(list3, 3);
    list3 = createNewNode(list3, 4);
    list3 = createNewNode(list3, 1);

    // Create Node list4: 1 → 2 → 3 → 0 → 4 → 6 → 3 → 0 → 7 → 1
    Node* list4 = NULL;
    list4 = createNewNode(list4, 1);
    list4 = createNewNode(list4, 2);
    list4 = createNewNode(list4, 3);
    list4 = createNewNode(list4, 0);
    list4 = createNewNode(list4, 4);
    list4 = createNewNode(list4, 6);
    list4 = createNewNode(list4, 3);
    list4 = createNewNode(list4, 0);
    list4 = createNewNode(list4, 7);
    list4 = createNewNode(list4, 1);

    // Check if list1 and list2 are mirrors
    res = mirror(list1, list2);
    if (res) {
        cout << "List1 and list2 after run the function are mirror" << endl;
    }
    else {
        cout << "List1 and list2 after run the function are not mirror" << endl;
    }

    // Check if list2 and list3 are mirrors
    res = mirror(list2, list3);
    if (res) {
        cout << "List2 and list3 after run the function are mirror" << endl;
    }
    else {
        cout << "List2 and list3 after run the function are not mirror" << endl;
    }

    // Process list4 with sumList function
    printList(list4);
    cout << endl;
    list4 = sumList(list4);
    printList(list4);
    cout << endl;

    // Free allocated memory
    deleteList(list1);
    deleteList(list2);
    deleteList(list3);
    deleteList(list4);

    return 0;
}

// Create a new node and append it to the linked list
Node* createNewNode(Node* head, int num) {
    Node* p;

    Node* item = new Node();
    if (item == NULL) {
        cout << "Memory allocation failed!"; // Check for allocation failure
        return NULL;
    }
    item -> data = num;
    item -> next = NULL;

    if (head == NULL) {
        return item;
    }

    p = head;
    while (p -> next) {
        p = p -> next;
    }
    p -> next = item;

    return head;
}

// Free memory allocated for the linked list
void deleteList(Node* head) {
    Node* temp;

    while (head) {
        temp = head;
        head = head -> next;
        delete temp;
    }
}

// Print linked list
void printList(Node* head) {
    while (head) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

// Reverse a linked list
Node* reverseList(Node* head) {
    Node* current = head;
    Node* next = NULL;
    Node* newHead = NULL;

    while (current != NULL) {
        next = current -> next;
        current -> next = newHead;
        newHead = current;
        current = next;
    }

    return newHead;
}

// Check if two linked lists are mirrors of each other
bool mirror(Node* list1, Node* list2) {
    list1 = reverseList(list1);

    while (list1 && list2) {
        if (list1 -> data != list2 -> data) {
            return false;
        }
        list1 = list1 -> next;
        list2 = list2 -> next;
    }

    return true;
}

// Sum consecutive non-zero values until encountering a zero, storing the sum in the zero node.
// If the linked list does not end with 0, so sum is added to the last node.
Node* sumList(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* tempNode = NULL;
    int sum = 0;

    while (head -> next && head -> data != 0) {
        sum += head -> data;
        tempNode = head;
        head = head -> next;
        delete tempNode; // Delete processed node
    }

    // It does not matter if the value of Node is 0 or not, the sum can still be added to it.
    head -> data += sum;

    // In case the list contains only one node (So we cannot define a previous node and a current node).
    if (head -> next == NULL) {
        return head;
    }

    Node* prevNode = head;
    Node* currentNode = head -> next;
    sum = 0;

    while (currentNode -> next) {
        if (currentNode -> data == 0) {
            currentNode -> data = sum;
            sum = 0;
            prevNode = currentNode;
            currentNode = currentNode -> next;
        }
        else {
            sum += currentNode -> data;
            tempNode = currentNode;
            prevNode -> next = currentNode -> next;
            delete tempNode; // Remove summed node
            currentNode = prevNode -> next;
        }
    }

    if (sum > 0) {
        currentNode -> data += sum;
    }

    return head;
}
