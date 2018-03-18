#include <iostream>
#include <stack>
using namespace std;

template <class type>
bool isSame(stack<type> s1, stack<type> s2)
{

    if (s1.size() != s2.size())
        return false;

    while (s1.size() != 0)
    {
        if (s1.top() == s2.top())
        {
            s1.pop();
            s2.pop();
        }
        else
            return false;
    }

    return true;
}

int main()
{
    stack<int> s1, s2;
    int stackSize1, stackSize2, value;

    cout << "Enter sizes for the stacks: ";
    cin >> stackSize1 >> stackSize2;

    cout << "Enter values for stack 1: ";
    for (int i = 0; i < stackSize1; i++)
    {
        cin >> value;
        s1.push(value);
    }

    cout << "Enter values for stack 2: ";
    for (int i = 0; i < stackSize2; i++)
    {
        cin >> value;
        s2.push(value);
    }

    if (isSame(s1, s2))
        cout << "same";
    else
        cout << "not same";

    return 0;
}
