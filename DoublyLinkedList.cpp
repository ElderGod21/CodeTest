#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node(){
        int value = this->data;
        if(next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free for node with data: "<< value<<endl;

    }
};

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node *&head)
{
    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void appointingTail(Node *&tail)
{
    Node *temp = tail;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    tail = temp;
}

void insertAtHead(Node *&head, int d)
{

    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);

        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);

        tail->next = temp;
        temp->prev = tail;
        temp->next = NULL;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, int d, int position, Node *&tail)
{

    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        // temp->prev = temp; No use of temp prev
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *newNode = new Node(d);

    newNode->next = temp->next; // newNode ke next ko temp ke next ko point krwadiya

    temp->next->prev = newNode; // phir temp next ke prev ki value update krdi

    temp->next = newNode; // phir temp next ko newNode pr daaldiya

    newNode->prev = temp; // aur newNode ka prev ko temp pr krwadiya
}

void deleteNode(Node *&head, int position)
{

    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        //memory free
        temp->next = NULL;
        delete temp;
    }

    else{
        int count = 1;
        Node* curr = head;
        Node* prev = NULL;

        while(count< position-1){
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->prev = NULL;
        curr->next = NULL;
        
        delete curr;
    }

    //Not handling tail in this

}

int main()
{

    Node *node1 = new Node(40);
    Node *head = node1;
    Node *tail = node1;
    appointingTail(tail);

    print(head);
    cout << "The length is: " << getLength(head) << endl;

    insertAtHead(head, 30);
    print(head);
    cout << "The length is: " << getLength(head) << endl;

    insertAtHead(head, 20);
    print(head);

    insertAtTail(tail, 50);
    print(head);

    insertAtPosition(head, 99, 3, tail);
    print(head);
}