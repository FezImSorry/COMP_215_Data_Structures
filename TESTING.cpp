#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q[5], fin;
    int n, mini, size1;

    cout << "Enter: ";
    cin >> n;

    while (n != -1)
    {
        q[0].push(n);
        cin >> n;
    }

    size1 = q[0].size();

    for(int i = 1; i <= size1; i++)
    {
        while (q[i].size() != 0)
        {

            if(q[i].front() < mini)
            {
                mini = q[i].front();
                q[i].pop();
            }

            q[i+1].push(q[i].front());
            q[i].pop();
        }

        fin.push(mini);
    }

    while (fin.size() != 0)
    {
        cout << fin.front();
        fin.pop();
    }

    return 0;
}
