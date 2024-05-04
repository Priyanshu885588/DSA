#include <iostream>
using namespace std;

class stack
{
public:
    int *arr;
    int top;
    int size;

    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
            top--;
        else
        {
            cout << "Stack is empty" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    cout << st.peek() << endl;
    if (st.isEmpty())
    {
        cout << "Stack is Empty mere dost " << endl;
    }
    else
    {
        cout << "Stack is not Empty mere dost " << endl;
    } /*
 //creation of stack
 stack<int> s;

 //push operation
 s.push(2);
 s.push(3);

 //pop
 s.pop();

 cout << "Printing top element " << s.top() << endl;

 if(s.empty()){
     cout << "Stack is empty " << endl;
 }
 else{
     cout << "stack is not empty " << endl;
 }

 cout << "size of stack is " << s.size() << endl;

 */
    return 0;
}