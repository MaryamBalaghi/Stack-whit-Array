#include <iostream>
using namespace std;
class Stack
{
    private:
    int *arr;          // pointer to a dynamic array.
    int topindex;         //index for top element.
    int capacity;      //maximum size of the stack
    public:
    Stack(int size);
    ~Stack();
    bool isempty();
    bool isfull();
    int Size();
    void push(int x);
    int pop();
    int top();
};
Stack::Stack(int size)
{
    arr=new int[size];
    capacity=size;
    topindex = -1;
}
Stack::~Stack()
{
    delete []arr;
}
bool Stack::isempty()
{
    if (topindex==-1) return true;
    else return false;
}
bool Stack::isfull()
{
    if(topindex==capacity-1) return true;
    else return false;
}
int Stack::Size()
{
    return topindex+1;
}
void Stack::push(int x)
{
    if(isfull()) {
        cout<<"Stack Overflow! can not push.";
        return;
    }
    topindex++;
    arr[topindex]=x;
}
int Stack::pop()
{
    if(isempty()){
        cout<<"Stack Underflow! can not pop.";
        return -1 ;
    }
    return arr[topindex--];
}
int Stack::top()
{
    if(isempty())
    {
        cout<<"Stack is Empty.";
        return -1;
    }
    return arr[topindex];
}
int main() {
    int n, m, x;
    char c;
    bool Continue = true;

    cout << "Enter the stack size: ";
    cin >> n;

    Stack s(n);

    // Display menu
    cout << "\n+++++++ Guide: +++++++\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Top\n";
    cout << "4. Is stack empty?\n";

    while (Continue) {
        cout << "\nPlease enter your choice: ";
        cin >> m;

        switch (m) {
        case 1: // Push
            cout << "Enter the value to push: ";
            cin >> x;
            s.push(x);
            break;

        case 2: { // Pop
            int popvalue = s.pop();
            if (popvalue != -1) {
                cout << "Popped element: " << popvalue << ".\n";
            }
            break;
        }

        case 3: { // Top
            int topvalue = s.top();
            if (topvalue != -1) {
                cout << "Top element is: " << topvalue << ".\n";
            }
            break;
        }

        case 4: // Check if the stack is empty
            if (s.isempty()) {
                cout << "The stack is empty.\n";
            } else {
                cout << "The stack is not empty.\n";
            }
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }

        cout << "\nDo you want to continue? (Y/N): ";
        cin >> c;
        Continue = (c == 'y' || c == 'Y');
    }

    cout << "Exiting program.\n";
    return 0;
}