#include<iostream>

using namespace std;

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

class Queue_LL{
    LL ll;
public:
    Queue_LL(){
        /*
            Constructor
        */
        ll = LL();
    }
    bool isEmpty(){
        /*
            Checks if the Queue is empty or not
        */
        return ll.isEmpty();
    }
    int size(){
        /*
            Returns the size of the Queue
        */
        return ll.length();
    }
    void enqueue(int el){
        /*
            inserts an element at the end of the queue
            Arguments:
            data (int) : data to be inserted in the queue
        */
        ll.insertAtTail(el);
    }
    int dequeue(){
        /*
            Removes an element from the front of the queue
            return (int) : element deleted from the queue
        */
        try{
            return ll.removeFromHead();
        }
        catch(string s){
            throw "Stack Empty";
        }
    }
    int front(){
        /*
            Gives the element at the front of the queue
            return (int) : element at the front of the queue
        */
        int el = ll.removeFromHead();
        ll.insertAtHead(el);
        return el;
    }
};
void Display(Queue_LL &q){
    /*
        Function to display the elements of the queue
    */
   for (int i = 0; i < q.size(); i++){
       int x = q.dequeue();
       cout << x << " , ";
       q.enqueue(x);
   }
}
int main(){
    int choice;
    Queue_LL q = Queue_LL();
    do{
        cout << "\n---------------------------------------------";
        cout << "\n\t1. Enqueue\n\t2. Dequeue\n\t3. Front\n\t4. Is Empty\n\t5. Size\n\t6. Display\n\t0. Exit\n";
        cout << "---------------------------------------------";
        cout << "\nEnter Your choice: ";
        cin >> choice;
        try{
        switch (choice){
        case 1:
            int x;
            cout << "\nEnter Number: ";
            cin >> x;
            q.enqueue(x);
            break;
        case 2:
            cout << "\nElement Deleted => " << q.dequeue();
            break;
        case 3:
            cout << "\nElement At front => " << q.dequeue();
            break;
        case 4:
            if(q.isEmpty())
                cout << "\Queue Empty";
            else
                cout << "\nQueue not Empty";
            break;
        case 5:
            cout << "\nSize of the Queue => " << q.size();
            break;
        case 6:
            Display(q);
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
    return 0;

}