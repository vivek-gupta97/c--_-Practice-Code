#include<iostream>
#include"LinkedList.h"
using namespace std;

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
void sort(Queue_LL &q){
    int n = q.size();
    for (int i = 0; i < n; i++){
        int min = q.dequeue();
        for (int j = 0; j < n-i-1; j++){
            int x = q.dequeue();
            if(x<min){
                int t = min;
                min = x;
                x = t;
            }
            q.enqueue(x);
        }
        for (int k = 0; k < i;k++){
            q.enqueue(q.dequeue());
        }
        q.enqueue(min);
    }
}
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
    Queue_LL q = Queue_LL();
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(6);
    q.enqueue(1);
    q.enqueue(9);
    // Display(q);
    // cout << endl << q.dequeue();
    // cout << endl << q.front();

    sort(q);
    Display(q);

    return 0;
}