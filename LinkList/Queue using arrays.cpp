#include<iostream>
using namespace std;
/*
Program to implement Queues using arrays
*/
class Queue {
    int *q, f,r, N; 
  public:
    Queue(int n = 10){
        /*
            Constructor
            Arguments:
                n (int) : Max Size of the Queue , default 10
        */
        f=r= 0;
        N = n;
        q = new int[N];
        // q = (int *)malloc(sizeof(int) * 10);
    }

    bool isEmpty(){
        /*
        Checks if the Queue is empty or not
        Return (boolean) : true if empty else false
        */
        return f == r;
    }
    int size(){
        /*
        Returns the size of the Queue
        */
        return (N + r - f) % N;
    }
    void enqueue(int data){
        /*
            Inserts an element at the end of the Queue
            Arguments:
            data (int) : data to be inserted
        */
        if(f==(r+1)%N){
            throw string("Queue Full");
        }
        q[r] = data;
        r = (r + 1) % N;
    }

    int dequeue(){
        /*
            Removes an element from the fromt of the queue
            return (int) : element removed from the queue
        */
        if(isEmpty()){
            throw string("Queue Empty");
        }
        int data = q[f];
        f = (f + 1) % N;
        return data;
    }
    int front(){
        /*
            Gives the element at the front of the queue
            return (int) : element at the front of the queue
        */
        if(isEmpty()){
            throw string("Queue Empty");
        }
        return q[f];
    }
};
void Display(Queue &q){
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
    Queue q = Queue(5);
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
                cout << "\nElement At front => " << q.front();
                break;
            case 4:
                if(q.isEmpty())
                    cout << "\nQueue Empty";
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
            cout << "\nOperation failed => "<<s;
        }
    } while (choice != 0);
    return 0;

}