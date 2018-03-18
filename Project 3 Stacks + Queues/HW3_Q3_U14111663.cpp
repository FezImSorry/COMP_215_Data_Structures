#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
    stack<char> s;
    queue<char> q;
    string line;
    bool flag = true;

    cout << "enter";
    cin >> line;

    for (int i = 0; i < line.length(); i++)
    {
        if (isupper(line[i]))
            line[i] = tolower(line[i]);

        s.push(line[i]);
        q.push(line[i]);
    }

    while (s.size() > 0)
    {
        if (s.top() == q.front())
        {
            s.pop();
            q.pop();
        }
        else
        {
            flag = false;
            break;
        }

    }

    if(flag)
        cout << "palindrome";
    else
        cout << "not palindrome";

    return 0;
}
