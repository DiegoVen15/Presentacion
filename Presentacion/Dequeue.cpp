#include<iostream>
using namespace std;

#define SIZE 10

template<typename T>
class deque
{
private:
    T que[SIZE];
    int front;
    int rear;
    int len;

    bool Full()
    {
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
            return(true);
        else
            return(false);
    }

    bool Empty()
    {
        if (front == -1)
            return(true);
        else
            return(false);
    }

public:

    deque()
    {
        front = -1;
        rear = -1;
    }

    template<class F>
    void F_Insert(F x)
    {
        if (Full())
        {
            cout << "Queue Overflow\n";
        }
        else
        {
            if (front == -1)
            {
                front = 0;
                rear = 0;
                que[front] = x;
            }
            else if (front == 0)
            {
                front = SIZE - 1;
                que[front] = x;
            }
            else
                que[--front] = x;
        }
    }

    template<class F>
    void R_Insert(F x)
    {
        if (Full())
        {
            cout << "Queue Overflow\n";
        }
        else
        {
            if (front == -1)
            {
                front = 0;
                rear = 0;
                que[front] = x;
            }
            else if (rear == SIZE - 1)
            {
                rear = 0;
                que[rear] = x;
            }
            else
            {
                que[++rear] = x;
            }
        }
    }

    template<class F>
    void F_Remove()
    {
        if (Empty())
            cout << "Queue Underflow\n";
        else
        {
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                if (front == SIZE - 1)
                    front = 0;
                else
                    front++;
            }
        }
    }

    template<class F>
    void R_Remove()
    {
        if (Empty())
            cout << "Queue Underflow\n";
        else
        {
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                if (rear == 0)
                    rear = SIZE - 1;
                else
                    rear--;
            }
        }
    }

    template<class F>
    F Front_Element()
    {
        if (Empty())
        {
            cout << "Queue Underflow\n";
            return -999;
        }
        return que[front];
    }

    template<class F>
    F Rear_Element()
    {
        if (Empty())
        {
            cout << "Queue Underflow\n";
            return -999;
        }
        return que[rear];
    }

};
