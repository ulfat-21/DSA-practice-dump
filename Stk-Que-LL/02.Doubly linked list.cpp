//CODE FOR DOUBLY LINKLIST

#include <iostream>
using namespace std;

class NODE
{
public:
    int val;
    NODE* next;
    NODE* prev;

    NODE(int x)
    {
        this->val = x;
        this->next = NULL;
        this->prev = NULL;
    }
};

NODE* head = NULL;
NODE* tail = NULL;


// INSERT BEFORE HEAD
void insertFirst(int x)
{
    NODE* newitem = new NODE(x);

    if(head == NULL)
    {
        head = newitem;
        tail = newitem;
    }
    else
    {
        newitem->next = head;
        head->prev = newitem;
        head = newitem;
    }
}


// INSERT AT LAST
void insertLast(int x)
{
    NODE* newitem = new NODE(x);

    if(head == NULL)
    {
        head = newitem;
        tail = newitem;
    }
    else
    {
        tail->next = newitem;
        newitem->prev = tail;
        tail = newitem;
    }
}


// INSERT AFTER MATCHED VALUE
void insertAfterMatched(int x, int match)
{
    if(head == NULL)
        return;

    NODE* cur = head;

    while(cur != NULL)
    {
        if(cur->val == match)
        {
            NODE* newitem = new NODE(x);

            newitem->next = cur->next;
            newitem->prev = cur;

            if(cur->next != NULL)
            {
                cur->next->prev = newitem;
            }
            else
            {
                tail = newitem;
            }

            cur->next = newitem;

            return;
        }

        cur = cur->next;
    }
}


// INSERT BEFORE MATCHED VALUE
void insertBeforeMatched(int x, int match)
{
    if(head == NULL)
        return;

    NODE* cur = head;

    while(cur != NULL)
    {
        if(cur->val == match)
        {
            NODE* newitem = new NODE(x);

            newitem->next = cur;
            newitem->prev = cur->prev;

            if(cur->prev != NULL)
            {
                cur->prev->next = newitem;
            }
            else
            {
                head = newitem;
            }

            cur->prev = newitem;

            return;
        }

        cur = cur->next;
    }
}


// DELETE FIRST
void DeleteFirst()
{
    if(head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    NODE* cur = head;

    if(head == tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }

    delete cur;
}


// DELETE LAST
void DeleteLast()
{
    if(tail == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    NODE* cur = tail;

    if(head == tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }

    delete cur;
}


// DELETE MATCHED ITEM
void DeleteMatchitem(int match)
{
    if(head == NULL)
        return;

    NODE* cur = head;

    while(cur != NULL)
    {
        if(cur->val == match)
        {
            if(head == tail)
            {
                head = NULL;
                tail = NULL;
            }

            else if(cur == head)
            {
                head = head->next;
                head->prev = NULL;
            }

            else if(cur == tail)
            {
                tail = tail->prev;
                tail->next = NULL;
            }
            else
            {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }

            delete cur;
            return;
        }

        cur = cur->next;
    }
}


// PRINT FROM HEAD TO TAIL
void printList()
{
    if(head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    NODE* cur = head;

    while(cur != NULL)
    {
        cout << cur->val;

        if(cur->next != NULL)
            cout << " <-> ";

        cur = cur->next;
    }

    cout << endl;
}


// PRINT FROM TAIL TO HEAD
void printReverse()
{
    if(tail == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    NODE* cur = tail;

    while(cur != NULL)
    {
        cout << cur->val;

        if(cur->prev != NULL)
            cout << " <-> ";

        cur = cur->prev;
    }

    cout << endl;
}


int main()
{
    int x, match;
   head = new NODE(20);
    NODE* p = new NODE(30);
    NODE* q = new NODE(40);
    NODE* r = new NODE(50);

    head->next = p;
    p->prev = head;

    p->next = q;
    q->prev = p;

    q->next = r;
    r->prev = q;

    r->next = NULL;

    tail = r;


    cout << "Initial List: ";
    printList();

    cout << endl;
    cout << "MENU:" << endl;
    cout << "1. Insert before head" << endl;
    cout << "2. Insert at last" << endl;
    cout << "3. Insert after matched value" << endl;
    cout << "4. Insert before matched value" << endl;
    cout << "5. Delete first node" << endl;
    cout << "6. Delete last node" << endl;
    cout << "7. Delete matched item" << endl;
    cout << "8. Print linked list" << endl;
    cout << "9. Print reverse" << endl;
    cout << "0. Exit program" << endl;


    while(1)
    {
        int ch, item, match;

        cin >> ch;

        switch(ch)
        {
        case 1:
            cin >> item;
            insertFirst(item);
            break;

        case 2:
            cin >> item;
            insertLast(item);
            break;

        case 3:
            cin >> match >> item;
            insertAfterMatched(item, match);
            break;

        case 4:
            cin >> match >> item;
            insertBeforeMatched(item, match);
            break;

        case 5:
            DeleteFirst();
            break;

        case 6:
            DeleteLast();
            break;

        case 7:
            cin >> item;
            DeleteMatchitem(item);
            break;

        case 8:
            printList();
            break;

        case 9:
            printReverse();
            break;

        case 0:
            return 0;
        }
    }
}
