#include<bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int arr[10000];
    int front, rear, Size;
public:

    Queue()
    {
        front = -1;
        rear = -1;
        Size= 0;
    }

    bool isEmpty()
    {
        return (front == -1 and rear == -1);
    }

    bool isFull()
    {
        if(((rear + 1) % (10000)) == front)
        {
            return 1;
        }

        return 0;
    }

    void Enqueue(int a)
    {
        if(isFull())
        {
            cout << "Queue is Full!"<<endl;
            return;
        }

        if(isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % (10000);
        }

        ++Size;
        //cout<<Size<<"b"<<endl;
        arr[rear] = a;
    }


    int Dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue is empty!"<<endl;
        }
        else if(front == rear)
        {
            int val = arr[front];
            rear = front = -1;
            Size--;
            return val;
        }
        else
        {
            int val = arr[front];
            Size--;
            front = (front + 1) % (10000);
            return val;
        }


    }

    int size()
    {
        if(isEmpty())
        {
            return 0;
        }
        else
        {
            return Size;
        }
    }

    int get_front()
    {
        return arr[front];
    }

    int get_rear()
    {
        return arr[rear];
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    //cout << q.size() << endl;
    q.Dequeue();
    //cout << q.size() << endl;
    q.Enqueue(3);
    q.Enqueue(4);
    cout << q.size() << "\n";
    q.Dequeue();
    //q.Dequeue();
    //q.Dequeue();
    cout<<q.get_front()<<endl;
    cout<<q.get_rear()<<endl;
    cout << q.size() << endl;
    if(q.isEmpty())
    {
        cout<<"The Queue is empty"<<endl;
    }
    if(q.isFull())
    {
        cout<<"The Queue is full"<<endl;
    }
    //cout << q.isEmpty() << endl;
    //cout << q.isFull() << endl;
    return 0;
}
