#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    int n;

    cout << "Enter number: ";
    cin >> n;

    while (n != 0)
    {
        int temp = n % 2;
        n = n / 2;
        s.push(temp);
    }

    while (s.size() != 0)
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}
