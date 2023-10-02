#include<iostream>
#include<stack>
using namespace std;
class Queue_stack{
stack<int> in,out;
void Push(int data)
{
    while(!in.empty())
    {
        out.push(in.top());
        in.pop();
    }

    cout<<"The elem pushed is "<<data<<endl;
    in.push(data);

    while(!out.empty())
    {
        in.push(out.top());
        out.pop();
    }
}

int Pop()
{
if (in.empty()) {
      cout << "Stack is empty";
      exit(0);
    }
    int val = in.top();
    in.pop();
    return val;
  }
  // Return the Topmost element from the Queue
  int Top() {
    if (in.empty()) {
      cout << "Stack is empty";
      exit(0);
    }
    return in.top();
  }
  // Return the size of the Queue
  int size() {
    return in.size();
  }
};
};

class Stack{
  int size;
  int *arr;
  int top;

  public:
  Stack(int size)
  {
    top =-1;
    size= 1000;
    arr= new int [size];
  }
bool isFull_()
{
return top == size-1;
}

bool isEmpty_()
{
  return top==-1;
}
  void push_(int value)
  {
     if(isFull_())
     {
   
        cout<<"FULL Stack......for arary"<<endl;
     }
     top++;
     arr[top]=value;
  }
  int pop_()
  {
    int x=arr[top];
    top--;
    return x; 
  }

  int top_ele()
  {
    return arr[top];
  }

  int size_of_stack()
  {
    return top+1;
  }
};
  class Queue{
    private:
   Stack s1;
  Stack s2;

   public:
   Queue(int size) : s1(size), s2(size){}
   void enqueue(int value)
   {
   s1.push_(value);
   }
   int dequeue()
   {
    if(s2.isEmpty_())
    {
        if(s1.isEmpty_())
        {
            cout<<"Queue is empty can't dequeu"<<endl;
            return -1;
        }
        while(!s1.isEmpty_())
        {
            s2.push_(s1.pop_());
        }
    }
    return s2.pop_();
   }

   int top_element()
   {
    if(s2.isEmpty_())
    {
        if(s1.isEmpty_())
        {
            cout<<"Queue is empty no top element"<<endl;
            return -1;
        }
        while(!s1.isEmpty_())
        {
            s2.push_(s1.pop_());
        }
    }
    return s2.top_ele();
   }

  };

int main()
{
  Queue queue(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout<<"\ntop most element "<<queue.top_element()<<" "<<endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    queue.enqueue(4);
    queue.enqueue(5);
 cout<<"\ntop most element "<<queue.top_element()<<" "<<endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl; // This will print an error message because the queue is empty
    cout<<"\ntop most element "<<queue.top_element()<<" "<<endl;
}