//STACK IMPLEMENTATION WITH ARRAY

#include<iostream>
#define size 5
using namespace std;

class myStack{
  int stk[size];
  int top;
  public:
  myStack(){
     top=-1;
  }
  void push(int val)
  {
      if(top==size-1)
      {
          cout<<"Overflow"<<endl;
          return;
      }
      top++;
      stk[top]=val;
  }
  void pop()
  {
      if(top==-1)
      {
            cout<<"Underflow"<<endl;

      }
      cout<<"Deleted="<<stk[top]<<endl;
      top--;
            cout<<"current top="<<stk[top]<<endl;

  }
  int tops(){
     if(top==-1)
      {
            cout<<"Stack empty"<<endl;
            return -1;

      }
      return stk[top];
  }
     void print()
     {
          if(top==-1)
      {
            cout<<"Stack empty"<<endl;
            return ;

      }
          cout<<"Stack: ";

         for(int i=top;i>=0;i--)
         {
             cout<<stk[i]<<" ";
         }
         cout<<endl;
     }
};
int main()
{
    myStack s;
    s.push(10);
     s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.print();
    for(int i=0;i<5;i++)
    {

       int pops=s.tops();
       s.pop();
           s.print();


    }


}
