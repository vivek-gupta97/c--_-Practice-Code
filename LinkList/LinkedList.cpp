#include<iostream>
using namespace std;
/*
    Program to implement Linked Lists
*/
class Node{
public:
    int data;
    Node *next;
    Node(int el){
        data = el;
        next = NULL;
    }
};

class LL{
    Node *head, *tail;
    int size;
public:
    LL(){
        /*
            Constructor
        */
        head = tail = NULL;
        size = 0;
    }
    bool isEmpty(){
        /*
            Returns true if list is empty else returns false
        */
        return head == NULL;
    }
    void insertAtHead(int el){
        /*
            Inserts element at the front of the list
            Arguments:
                el (int) : the element to insert
        */
        Node *n = new Node(el);
        n->next = head;
        head = n;
        if(tail==NULL){
            tail = head;
        }
        size++;
    }
    void insertAtTail(int el){
        /*
            Inserts element at the end of the list
            Arguments:
                el (int) : the element to insert
        */
        Node *n = new Node(el);
        size++;
        if(tail==NULL){
            head = n;
            tail = head;
            return;
        }
        tail->next = n;
        tail = tail->next;
    }
    int removeFromHead(){
        /*
            Removes an element from the front of the list
            Return (int) : element removed from the list
        */
        int el;
        if(isEmpty()){
            throw string("Linked List is Empty");
        }
        if (head==tail){
            el = head->data;
            head = tail = NULL;
        }
        else{
            el = head->data;
            head = head->next;
        }
        size--;
        return el;
    }
    int removeFromTail(){
        /*
            Removes an element from the end of the list
            Return (int) : element removed from the list
        */
        int el;
        if(isEmpty()){
            throw string("Linked List is Empty");
        }
        if (head==tail){
            el = head->data;
            head = tail = NULL;
        }
        else{
            Node *n;
            for (n = head; n->next != tail; n=n->next)
                ;
            el = tail->data;
            tail = n;
        }
        size--;
        return el;
    }
    int length(){
        return size;
    }
};
void display(LL &ll){
    /*
        Displays the elements of the list
    */
    int x;
    for (int i = 0; i < ll.length();i++){
        x = ll.removeFromHead();
        cout << x << " -> ";
        ll.insertAtTail(x);
    }
    cout << "Null";
}

int main(){
    int choice;
    LL ll = LL();
    do{
        cout << "\n---------------------------------------------";
        cout<<"\n\t1. Insert At Head"
            <<"\n\t2. Insert At Tail"
            <<"\n\t3. Remove from Head"
            <<"\n\t4. Remove from Tail"
            <<"\n\t5. Length of the List"
            <<"\n\t6. Is Empty"
            <<"\n\t7. Display"
            <<"\n\t0. Exit\n";
        cout << "---------------------------------------------";
        cout << "\nEnter Your choice: ";
        cin >> choice;
        try{
            switch (choice){
            case 1:
                int x;
                cout << "\nEnter Number: ";
                cin >> x;
                ll.insertAtHead(x);
                break;
            case 2:
                cout << "\nEnter Number: ";
                cin >> x;
                ll.insertAtTail(x);
                break;
            case 3:
                cout << "\nElement Deleted => " << ll.removeFromHead();
                break;
            case 4:
                cout << "\nElement Deleted => " << ll.removeFromTail();
                break;
            case 5:
                cout << "\nSize of the List => " << ll.length();
                break;
            case 6:
                if(ll.isEmpty())
                    cout << "\nList Empty";
                else
                    cout << "\nList not Empty";
                break;
            case 7:
                display(ll);
                break;
            case 0:
                    break;
            default:
                cout << "\nInvalid Choice";
                break;
            }
        }
        catch(string s){
            cout << "\nOperation failed\nReason => "<<s;
        }
    } while (choice != 0);
}