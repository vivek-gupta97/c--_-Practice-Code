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

class Stack_LL{
    LL ll;
public:
    Stack_LL(){
        /*
            Constructor
        */
        ll = LL();
    }
    bool isEmpty(){
        /*
            Checks if the stack is empty or not
        */
        return ll.isEmpty();
    }
    int size(){
        /*
            Returns the size of the Stack
        */
        return ll.length();
    }
    void push(int el){
        /*
            Pushes an element to the top of the stack
            Arguments:
            data (int) : data to be pushed in the stack
        */
        ll.insertAtHead(el);
    }
    int pop(){
        /*
            Removes an element from the top of the stack
            return (int) : element deleted from the stack
        */
        try{
            return ll.removeFromHead();
        }
        catch(string s){
            throw "Stack Empty";
        }
    }
    int top(){
        /*
            Gives the element at the top of the stack
            return (int) : element at the top of the stack
        */
        int el = ll.removeFromHead();
        ll.insertAtHead(el);
        return el;
    }
};
void Display(Stack_LL s){
    Stack_LL temp = Stack_LL();
    int x;
    while (!s.isEmpty()){
        x = s.pop();
        cout << x << endl;
        temp.push(x);
    }
    while (!temp.isEmpty()){
        s.push(temp.pop());
    }
}
int main(){
    int choice;
    Stack_LL s = Stack_LL();
    do{
        cout << "\n---------------------------------------------";
        cout << "\n\t1. Push\n\t2. Pop\n\t3. Is Empty\n\t4. Size\n\t5. Display\n\t0. Exit\n";
        cout << "---------------------------------------------";
        cout << "\nEnter Your choice: ";
        cin >> choice;
        try{
        switch (choice){
        case 1:
            int x;
            cout << "\nEnter Number: ";
            cin >> x;
            s.push(x);
            break;
        case 2:
            cout << "\nElement Deleted => " << s.pop();
            break;
        case 3:
            if(s.isEmpty())
                cout << "\nStack Empty";
            else
                cout << "\nStack not Empty";
            break;
        case 4:
            cout << "\nSize of the Stack => " << s.size();
            break;
        case 5:
            Display(s);
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