#include<iostream>
using namespace std;
/*
Program to implement Stacks using stacks
*/
class Stack {
    int *s, t, N; 
  public:
    Stack(int n = 10){
        /*
            Constructor
            Arguments:
                n (int) : Size of the stack , default 10
        */
        t = -1;
        N = n;
        s = new int[N];
    }

    bool isEmpty(){
        /*
            Checks if the stack is empty or not
        */
        return t == -1;
    }
    int size(){
        /*
            Returns the size of the Stack
        */
        return t + 1;
    }
    void push(int data){
        /*
            Pushes an element to the top of the stack
            Arguments:
            data (int) : data to be pushed in the stack
        */

        if(t==N-1){
            throw string("Stack Full");
            // throw runtime_error("Stack Full");
        }
        s[++t] = data;
    }

    int pop(){
        /*
            Removes an element from the top of the stack
            return (int) : element deleted from the stack
        */
        if(isEmpty()){
            throw string("Stack Empty");
        }
        return s[t--];
    }
    int top(){
        /*
            Gives the element at the top of the stack
            return (int) : element at the top of the stack
        */
        if(isEmpty()){
            throw string("Stack Empty");
        }
        return s[t];
    }
};
void Display(Stack &s){
    /*
        Function to Display the elements of the Stack
    */
    Stack temp = Stack(s.size());
    while (!s.isEmpty())
    {
        cout << s.top() << endl;
        temp.push(s.pop());
    }
     while (!temp.isEmpty())
    {
        s.push(temp.pop());
    }
}
int main(){
    int choice;
    Stack s = Stack(3);
    do{
        cout << "\n---------------------------------------------";
        cout << "\n\t1. Push\n\t2. Pop\n\t3.Top\n\t4. Is Empty\n\t5. Size\n\t6. Display\n\t0. Exit\n";
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
                x = s.pop();
                cout << "\nElement Deleted => " << x;
                break;
            case 3:
                x = s.top();
                cout << "\nElement At top => " << x;
                break;
            case 4:
                if(s.isEmpty())
                    cout << "\nStack Empty";
                else
                    cout << "\nStack not Empty";
                break;
            case 5:
                cout << "\nSize of the Stack => " << s.size();
                break;
            case 6:
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
            cout << "\nOperation failed => "<<s;
        }
    } while (choice != 0);
    return 0;

}