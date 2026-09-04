//CODE FOR S.LINKLIST

#include <iostream>
using namespace std;

class NODE
{
public:
    int val;
    NODE* next;

    NODE(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

NODE* head = NULL;


void insertFirst(int x)
{
    NODE* newitem = new NODE(x);

    if(head == NULL)
    {
        head = newitem;
    }
    else
    {
        newitem->next = head;
        head = newitem;
    }
}


void insertLast(int x)
{
    NODE* newitem = new NODE(x);

    if(head == NULL)
    {
        head = newitem;
        return;
    }

    NODE* cur = head;

    while(cur->next != NULL)
    {
        cur = cur->next;
    }

    cur->next = newitem;
}


void insertbeforeMatched(int x, int match)
{
    if(head == NULL)
        return;

    NODE* newitem = new NODE(x);

    NODE* prev = NULL;
    NODE* cur = head;

    while(cur != NULL)
    {
        if(cur->val == match)
        {
            if(cur == head)
            {
                newitem->next = head;
                head = newitem;
            }
            else
            {
                prev->next = newitem;
                newitem->next = cur;
            }

            return;
        }

        prev = cur;
        cur = cur->next;
    }
}


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
            cur->next = newitem;

            return;
        }

        cur = cur->next;
    }
}


void DeleteFirst()
{
    if(head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    NODE* cur = head;

    head = head->next;

    delete cur;
}


void DeleteLast()
{
    if(head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    NODE* cur = head;
    NODE* prev = NULL;

    while(cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }

    prev->next = NULL;

    delete cur;
}


void DeleteMatchitem(int match)
{
    if(head == NULL)
        return;

    NODE* cur = head;
    NODE* prev = NULL;

    while(cur != NULL)
    {
        if(cur->val == match)
        {
            if(cur == head)
            {
                head = head->next;
                delete cur;
            }
            else
            {
                prev->next = cur->next;
                delete cur;
            }

            return;
        }

        prev = cur;
        cur = cur->next;
    }
}


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
            cout << " -> ";

        cur = cur->next;
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
    p->next = q;
    q->next = r;
    r->next = NULL;


    cout << "Initial List: ";
    printList();
    cout << endl;
    return 0;

//    cout << "MENU:" << endl;
//    cout << "1. Insert before head" << endl;
//    cout << "2. Insert at last" << endl;
//    cout << "3. Insert after matched value" << endl;
//    cout << "4. Insert before matched value" << endl;
//    cout << "5. Delete first node" << endl;
//    cout << "6. Delete last node" << endl;
//    cout << "7. Delete matched item" << endl;
//    cout << "8. Print linked list" << endl;
//    cout << "0. Exit program" << endl;
//
//
//    while(1)
//    {
//        int ch, item, match;
//
//        cin >> ch;
//
//        switch(ch)
//        {
//        case 1:
//            cin >> item;
//            insertFirst(item);
//            break;
//
//        case 2:
//            cin >> item;
//            insertLast(item);
//            break;
//
//        case 3:
//            cin >> match >> item;
//            insertAfterMatched(item, match);
//            break;
//
//        case 4:
//            cin >> match >> item;
//            insertbeforeMatched(item, match);
//            break;
//
//        case 5:
//            DeleteFirst();
//            break;
//
//        case 6:
//            DeleteLast();
//            break;
//
//        case 7:
//            cin >> item;
//            DeleteMatchitem(item);
//            break;
//
//        case 8:
//            printList();
//            break;
//
//        case 0:
//
//        }
//    }
}
