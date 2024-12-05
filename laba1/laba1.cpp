#include <iostream>
#include "LinkedLIst.h"

using namespace std;

#define CB cout <<
#define CE << " "
#define CEL << endl;
#define EOL CB endl;

void LinkedListTest()
{
    LinkedList<int>* l = new LinkedList<int>;
    l->PushBack(5);
    l->PushBack(3);
    l->PushBack(2);
    l->PushBack(6);
    l->PushFront(9);
    l->Print();
    l->InsertAt(7, 2);
    l->Print();
}

void QueueTest()
{
    Queue<int>* q = new Queue<int>;

    q->Push(5);
    q->Push(3);
    q->Push(4);
    q->Push(2);
    q->Print();
    q->Pop();
    q->Print();
    q->Push(6);
    q->Print();
}

void StackTest()
{
    Stack<int>* s = new Stack<int>;
    s->Push(5);
    s->Push(3);
    s->Push(4);
    s->Push(2);
    s->Pop();
    s->Push(1);
    s->Print();
}

int main()
{

    return 0;
}
