#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createList() {
    Node *currentNode, *head = NULL;
    char exit;
    do {
        if (!head) {
            currentNode = new Node;
            head = currentNode;
        } else {
            currentNode->next = new Node;
            currentNode = currentNode->next;
        }
        cout << "Please enter a number.\n";
        cin >> currentNode->data;
        currentNode->next = NULL;
        cout << "Press any key to continue or 'y' to exit\n";
        cin >> exit;
    } while (exit != 'y' && exit != 'Y');
    return head;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to reverse the linked list without modifying the original list
Node* reverseListWithoutModifying(Node* head) {
    Node* newHead = NULL;
    while (head != NULL) {
        Node* newNode = new Node();
        newNode->data = head->data;
        newNode->next = newHead;
        newHead = newNode;
        head = head->next;
    }
    return newHead;
}

bool ListsEqual(Node* list1, Node* list2) {
    if (list1 == NULL && list2 == NULL) {
        return true;
    }
    if (list1 == NULL || list2 == NULL) {
        return false;
    }
    return (list1->data == list2->data) && ListsEqual(list1->next, list2->next);
}

bool mirror(Node* list1, Node* list2) {
    Node* reversedList2 = reverseListWithoutModifying(list2);
    bool result = ListsEqual(list1, reversedList2);
    deleteList(reversedList2); // Clean up the temporary reversed list
    return result;
}

int main() {
    // Create the first hardcoded linked list: 1 -> 2 -> 3 -> 5
    Node* list1 = new Node();
    list1->data = 1;
    list1->next = new Node();
    list1->next->data = 2;
    list1->next->next = new Node();
    list1->next->next->data = 3;
    list1->next->next->next = new Node();
    list1->next->next->next->data = 5;

    cout << "First list: ";
    printList(list1);

    // Create the second hardcoded linked list: 5 -> 3 -> 2 -> 1
    Node* list2 = new Node();
    list2->data = 5;
    list2->next = new Node();
    list2->next->data = 3;
    list2->next->next = new Node();
    list2->next->next->data = 2;
    list2->next->next->next = new Node();
    list2->next->next->next->data = 1;

    // Create the third hardcoded linked list: 5 -> 3 -> 4 -> 1
    Node* list3 = new Node();
    list3->data = 5;
    list3->next = new Node();
    list3->next->data = 3;
    list3->next->next = new Node();
    list3->next->next->data = 4;
    list3->next->next->next = new Node();
    list3->next->next->next->data = 1;

    cout << "Second list: ";
    printList(list2);

    // Check if the lists are mirrors of each other
    if (mirror(list1, list2)) {
        cout << "The lists are mirrors of each other." << endl;
    } else {
        cout << "The lists are not mirrors of each other." << endl;
    }

    cout << endl;
    cout << "Second list: ";
    printList(list2);

    cout << "Third list: ";
    printList(list3);

    if (mirror(list1, list3)) {
        cout << "The lists are mirrors of each other." << endl;
    } else {
        cout << "The lists are not mirrors of each other." << endl;
    }

    // Delete the linked lists to free memory
    deleteList(list1);
    deleteList(list2);
    deleteList(list3);

    return 0;
}