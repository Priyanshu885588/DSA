#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MyCircularDeque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    MyCircularDeque(int k)
    {
        size = k;
        arr = new int[k];
        front = -1;
        rear = -1;
    }

    bool insertFront(int value)
    {
        if ((front == 0 && rear == size - 1) ||
            (front > 0 && (rear == (front - 1) % (size - 1))))
        {
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = value;
        return true;
    }

    bool insertLast(int value)
    {
        if ((front == 0 && rear == size - 1) ||
            (front > 0 && (rear == (front - 1) % (size - 1))))
        {
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    bool deleteFront()
    {
        if (front == -1)
        {
            return false;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return true;
    }

    bool deleteLast()
    {
        if (front == -1)
        {
            return false;
        }
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return true;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) ||
            (front > 0 && (rear == (front - 1) % (size - 1))))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    deque<int> d;
    d.push_front(6);
    d.push_back(7);
    cout << d.front() << endl;
    cout << d.back() << endl;
    d.pop_front();
    cout << d.front() << endl;
    cout << d.back() << endl;
    d.pop_back();

    if (d.empty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
    return 0;
}