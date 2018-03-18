#include<iostream>
using namespace std;

struct nodeType
{
    int info;
    nodeType * back;
    nodeType * next;
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
        void makeUnique();
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
    nodeType *current, *trailCurrent, *newNode;
	newNode = new nodeType;
	bool found = false;

	newNode->info = item;
	newNode->back = NULL;
	newNode->next = NULL;

	if( first == NULL ){
        first = newNode;
        last = newNode;
        count++;
        return;
	}
	else {
        current = first;
        while (current != NULL && found == false) {
            if (current->info >= item)
                found = true;
            else {
                trailCurrent = current;
                current = current->next;
            }
        }
        if (current == first){
            first->back = newNode;
            newNode->next = first;
            first = newNode;
            count++;
        }
        else{
            if (current != NULL){
                trailCurrent->next = newNode;
                newNode->back = trailCurrent;
                newNode->next = current;
                current->back = newNode;
            }
            else{
                trailCurrent->next = newNode;
                newNode->back = trailCurrent;
                last = newNode;
            }
            count++;
        }
	}
}

void myList::makeUnique()
{
    nodeType *trailCurrent = first, *current = first->next, *next = NULL;

    if (first == NULL)
        return;

    while (current != NULL){
        next = current->next;

        if (trailCurrent->info == current->info){
                if (current->next == NULL){
                    current = NULL;
                    trailCurrent->next = NULL;
                    last = trailCurrent;
                    count--;
                }
                else{
                    trailCurrent->next = current->next;
                    next->back = current->back;
                    current = current->next;
                    count--;
                }
        }
        else{
            trailCurrent = current;
            current = current->next;
        }
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
            current = current->next;
        }
    }
    else
        cerr<<"Empty List\n";
}

int main( )
{
    myList list1;
    int num;

    cout<<"Enter 5 numbers: ";
    for(int i = 0; i < 5; i++){
        cin >> num;
        list1.addItem(num);
    }

    list1.print();
    cout<<"\nAfter Removing Duplicates:\n";
    list1.makeUnique();
    list1.print();
}
