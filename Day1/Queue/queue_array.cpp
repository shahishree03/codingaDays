#include<iostream>
using namespace std;

class Queue
{
    
    int front, rear, currsize, max_size;
    int* array;
public:
    Queue(unsigned max_Size)
    {
    (*this).max_size = max_size;
    array = new int[max_size];
  front=-1;
  rear=-1;
  currsize=0;
    }
    ~Queue()
    {
        delete[] array;
    }

    bool isFull()
    {
        return currsize == max_size;
    }
    bool isEmpty()
    {
     return front == -1;
    }

    void push(int ele)
    {
        if(isFull())
        {
            cout<<"My queue size is full\n Exiting\n";
            exit(1);
        }
        if(rear ==-1)
        {
            front =0;
            rear=0;
        }
        else
        rear =(rear+1)%max_size;
    
    array[rear] = ele;
    cout<<"The element pushed is "<<ele<<endl;
    currsize++;
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty\n Exiting\n";
        }
        int poppedValue = array[front];
        if(currsize==1)
        {
           front =-1;
           rear=-1;
        }
        else
        front=(front+1)%max_size;
        currsize--;
        return poppedValue;
    }

    int top()
    {
        if(front == -1)
        {
            cout<<"Queue is empty "<<endl;
            exit(1);
        }
        return array[front];
    }
    int size()
    {
        return currsize;
    }
};

int main()
{
    Queue q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.top() << endl;
  cout << "The size of the queue before deletion " << q.size() << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element " << q.top() << endl;
  cout << "The size of the queue after deleting an element " << q.size() << endl;
}