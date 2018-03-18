#include<iostream>
using namespace std;

struct nodeType
{
    int info;
    nodeType * link;
};

class myList
{
    private:
        nodeType * first;
        nodeType * last;
        int count;
    public:
        myList();
        void addItem(int);
        void print();
        void reverse();
        void rotateCW();
};

myList::myList()
{
    first = NULL;
    last = NULL;
    count = 0;
}
//add an item to the list;
void myList::addItem(int item)
{
    nodeType * newNode;
	newNode = new nodeType;

	newNode->info = item;
	newNode->link = NULL;

	if( first == NULL ){
        first = newNode;
        last = newNode;
        count++;
        return;
	}

    last->link = newNode;
    last = newNode;
    count++;
}

void myList::reverse()
{
    if(first == NULL) return;

    nodeType *trailCurrent, *current = first, *next;

    last = first;

    while(current != NULL){
        next = current->link;
        current->link = trailCurrent;
        trailCurrent = current;
        current = next;
    }

    first = trailCurrent;
}

void myList::rotateCW()
{
    nodeType *newNode, *current;

    newNode->link = first;
    newNode->info = last->info;
    current = first;

    while (current != NULL)
    {
        if (current->link->link == NULL)
        {
            last = current;
            current = current->link;
            //delete current;
            last->link = NULL;
        }
        else
            current = current->link;

        first = newNode;
    }
}

//to print the list
void myList::print()
{
    if( first != NULL )
    {
        nodeType * current;
        current = first;

        while( current != NULL )
        {
            cout<< current->info << " ";
            current = current->link;
        }
    }
    else
        cerr<<"Empty List\n";
}


int main()
{
    myList list1;
    int num;

    cout<<"Enter 5 numbers: ";
    for(int i = 0; i < 5; i++){
        cin >> num;
        list1.addItem(num);
    }

    list1.print();
    cout<<"\nAfter Reversing:\n";
    list1.rotateCW();
    list1.print();
}
