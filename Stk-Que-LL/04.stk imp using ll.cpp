//STACK WITH LINKLIST IMPLEMENTATION

#include<iostream>
using namespace std;

class NODE
{
public:
    int x;
    NODE* next;

    NODE()
    {
        this->x = 0;
        this->next = NULL;
    }

    NODE(int value)
    {
        this->x = value;
        this->next = NULL;
    }
};

NODE* top = NULL;


// PUSH
void push(int value)
{
    NODE* newItem = new NODE(value);

    newItem->next = top;
    top = newItem;
}


// POP
void pop()
{
    if(top == NULL)
    {
        cout << "Stack is Empty" << endl;
        return;
    }

    NODE* temp = top;

    top = top->next;
    cout<<"deleted:"<<temp->x<<endl;
    delete temp;
}


// PEEK
int peek()
{
    if(top == NULL)
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }

    return top->x;
}


// PRINT
void printStack()
{
    if(top == NULL)
    {
        cout << "Stack is Empty" << endl;
        return;
    }

    NODE* cur = top;

    while(cur != NULL)
    {
        cout << cur->x << " ";
        cur = cur->next;
    }

    cout << endl;
}


int main()
{
    int ch, value;

    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Print" << endl;
    cout << "0. Exit" << endl;

    while(1)
    {
        cin >> ch;

        switch(ch)
        {
        case 1:
            cin >> value;
            push(value);
            break;

        case 2:
             pop();
            break;

        case 3:
            cout << "Top: " << peek() << endl;
            break;

        case 4:
            printStack();
            break;

        case 0:
            return 0;
        }
    }
}
