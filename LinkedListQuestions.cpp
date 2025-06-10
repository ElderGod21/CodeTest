#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Value deleted is: " << value << endl;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void insertAtHead(Node *&head, int d)
{
    // New Node Create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void reverse(Node *&head)
{
    // My code

    // Node *forward = head->next;
    // Node *curr = head;
    // Node *temp;

    // curr->next = NULL;
    // while (forward->next != NULL)
    // {
    //     temp = forward->next;
    //     forward->next = curr;
    //     curr = forward;
    //     forward = temp;
    // }

    // head = forward;
    // forward->next = curr;

    if (head == NULL || head->next == NULL)
        return;

    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next; // store next node
        curr->next = prev; // reverse the link
        prev = curr;       // move prev one step forward
        curr = next;       // move curr one step forward
    }

    head = prev; // new head
}


//  Bahut hi bhayankar recursion solution

//Node* reversal1(Node* head){

//     if(head == NULL || head->next = NULL){
//         return head;
//     }

//     Node* chotaHead = reversal1(head->next);
//     head->next->next = head;
//     head->next = NULL;

//     return chotaHead;
// }

void reversal(Node *&head, Node* curr, Node* prev)
{
    //base condition
    if(curr==NULL){
        head = prev;
        return;
    }

    Node* forward = curr->next;
    reversal(head, forward, curr);
    curr->next = prev;
    
}

void reverseByRecursion(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;

    reversal(head, curr, prev);
}

int main()
{
    Node *node1 = new Node(40);

    Node *head = node1;
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    print(head);
    cout << endl;
    cout << head->data << endl;
    cout << endl;

    // reverse(head);
    reverseByRecursion(head);
    print(head);
    cout << endl;
    cout << head->data << endl;

    //
}