#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void InsertAtHead(Node *&head, int d)
{
    // New Node Create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void printLinkedList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node *&tail, int d)
{
    // Create new node to insert
    Node *temp = new Node(d);

    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}

void insertAtPosition(Node *&head, int d, int position, Node *&tail)
{
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    Node *p = head;

    int count = 1;
    while (count < position - 1)
    {
        p = p->next;
        count++;
    }

    if (p->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *temp = new Node(d);

    temp->next = p->next;
    p->next = temp;
}

// Deletion of Nodes

void deleteAtPos(Node *&head, int position, Node *&tail)
{

    Node *temp = head;

    // for head case

    if (position == 1)
    {
        head = temp->next;
        temp->next = NULL;
        delete (temp);
        return;
    }

    // for any middle

    Node *p = head;
    int count = 1;
    while (count != position - 1)
    {
        temp = temp->next;
        p = p->next;
        count++;
    }
    p = temp->next;

    // for tail case

    if (p->next == NULL)
    {
        temp->next = NULL;
        tail = temp;
        delete (temp, p);
        return;
    }

    temp->next = p->next;
    p->next = NULL;

    delete (temp, p);
}

void deleteByValue(Node *&head, int value, Node *&tail)
{
    Node *temp = head;
    // for the head
    if (temp->data == value)
    {
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    Node *prev = NULL;
    while (temp->data != value)
    {

        prev = temp;
        if (temp->next == NULL)
        {
            tail = temp;
            break;
        }
        temp = temp->next;
    }

    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
}

// Linked List reversal in K groups

Node *kReversal(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }

    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;

    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL)
    {
        head->next = kReversal(next, k);
    }

    return prev;
}

int main()
{
    Node *node1 = new Node(10); /*using the constructor to give
    the data while creating the node*/
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    // head pointed to node1

    Node *tail = node1;
    Node *head = node1;
    printLinkedList(head);

    insertAtTail(tail, 12);

    printLinkedList(head);

    insertAtTail(tail, 15);

    printLinkedList(head);

    insertAtPosition(head, 11, 4, tail);
    printLinkedList(head);

    deleteAtPos(head, 4, tail);
    printLinkedList(head);

    deleteByValue(head, 12, tail);
    printLinkedList(head);
}