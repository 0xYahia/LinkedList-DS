#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
using namespace std;

template<class T>
class LinkedList
{
    Node<T> *head, *tail;

    public:
        LinkedList()
        {
            head = tail = NULL;
        }
        int counter = 0;

    void Add(T data)
    {
        Node<T> *node = new Node<T>(data); 
        if(head == NULL)
        {
            head = tail = node;
        }
        else
        {
            tail->Next = node ;
            node->Prev = tail;
            tail = node;
        }
        counter++;

    }

    void Display()
    {
        Node<T> *current = head;
        while(current != NULL)
        {
            cout<< current->Data<< "  ";
            current = current->Next;
        }
        cout<<endl;
    }
    int Search(T data)
    {
        Node<T> *node= getNodeByData(data);
        if(node == NULL)
            return 0;
        else
            return 1;
    }

    void Remove(int data)
    {
        Node<T> *node = getNodeByData(data);

        if(node == NULL)
            return;
        if(node == head)
        {
            if(node == tail)
            {
                head = tail = NULL;
            }
            else
            {
                head = head->Next;
                head->Prev = NULL;
            }
        }
        else if(node == tail)
        {
            tail = tail->Prev;
            tail->Next = NULL;
        }
        else
        {
            /*
            Node *A = node->Prev;
            Node *B = node->Next;

            A->Next = B
            B->Prev = A
            */

            //OR
            node->Prev->Next = node->Next;
            node->Next->Prev = node->Prev;

        }
        counter--;
            delete node;
    }

    int GetCount()
    {
        return counter;
    }
    T GetDataByIndex(int index)
    {
       // cout<<"\n the count is items is"<< GetCount()<<endl;
        if(index < 0){return -111111;}
        Node<T> *current = head;
        int counter2 = 0;

        while(current != NULL)
        {
            if(counter2 == index)
            {
                return current->Data;
            }
            counter2++;
            current = current->Next;
        }
        return GetDataByIndex(index - GetCount()-1);

    };
   void InsertAfter(T data, T afterData)
    {
        Node<T> *current = head;
        Node<T> *target =new Node<T>(data);
        while(current != NULL)
        {
            if(afterData == current->Data)
            {
                // target of next = current of next
                target->Next = current->Next;
                //target of prev = current
                target->Prev = current;

                //curren of next = target
                    current->Next = target;
                //target of next of prev = target
                target->Next->Prev = target;
                return;
            }
            current = current->Next;
        };

        target->Prev = tail;
        tail->Next = target;
        tail= target;

    }

    LinkedList<T>* Reverse()
    {
        LinkedList<T> *myList2 = new LinkedList();
        Node<T> *tailRev = this->tail;
        while(tailRev != NULL)
        {
            myList2->Add(tailRev->Data);
            tailRev = tailRev->Prev;
        }
        return myList2;
    }


    void InPlaceReverse()
    {
        *this = *(this->Reverse());
    }
    protected:

    private:
        Node<T>* getNodeByData(T data)
        {
            Node<T> *current = head;
            while(current != NULL)
            {
                if(data == current->Data)
                    return current;
                else
                    current = current->Next;
            }
            return NULL;
        }

};

#endif // LINKEDLIST_H
