//CODE FOR  LINEAR QUEUE

#include<bits/stdc++.h>
#define size 5
using namespace std;
class myQueue{
    int qu[size];
    int front,rear;
public:
    myQueue()
    {
        front=rear=-1;
    }
    void enqueue(int val)
    {
       if(rear==size-1)
       {
           cout<<"overflow"<<endl;
       }
       if(front==-1) front=0;
       rear++;
       qu[rear]=val;
    }
    void dequeue()
    {
        if(front==-1)
        {
            cout<<"underflow"<<endl;
            return;
        }
        cout<<"Deleted="<<qu[front]<<endl;
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else{
            front++;
        }
                cout<<"cur front="<<qu[front]<<endl;

    }
  int Front()
  {
      if(front==-1){
        cout<<"empty"<<endl;
        return -1;
      }
      return qu[front];

  }
};
int main(){
    myQueue q1;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    ///q1.enqueue(60);

    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    ///cout<<q1.dequeue()<<endl;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    ///q1.enqueue(60);

    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue();
    ///cout<<q1.dequeue()<<endl;
}
