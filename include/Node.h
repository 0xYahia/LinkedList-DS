#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;
template<class T>
class Node
{
    public:
        T Data;
        Node *Next, *Prev;

            Node(T data)
            {
            Data = data;
            Next = Prev = NULL;
            }

    protected:

    private:
};

#endif // NODE_H
