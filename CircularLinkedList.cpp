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
        cout << "Value deleted: " << value << endl;
    }
};

void insertAfterElement(Node *&tail, int element, int d)
{

    // for empty list
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        temp->next = temp;
        tail = temp;
    }

    // For a single node
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *&tail)
{

    if(tail == NULL){
        cout<<"List is empty";
        return ;
    }
    Node *temp = tail;

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    
    //dont worry about tail it comes back to its starting point
}

void deleteByValue(Node* &tail, int d){

    if(tail == NULL){
        cout<<"List is Empty";
        return ;
    }

    //assuming the value to be deleted is present in the LL

    Node* prev = tail;
    Node* curr = prev->next;

    while(curr->data!= d){
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;

    //if only 1 node exists
    if(curr == prev){
        tail = NULL;
    }

    //making sure tail doesnt get deleted
    
    if(curr == tail){
        tail = prev;
    }
    curr->next = NULL;

    delete curr;


}

int main()
{

    // In circular LL tail is much more beneficial than head

    Node *tail = NULL;

    insertAfterElement(tail, 00, 10);
    insertAfterElement(tail, 10, 20);
    // insertAfterElement(tail, 20, 30);

    deleteByValue(tail, 10);

    print(tail);
}