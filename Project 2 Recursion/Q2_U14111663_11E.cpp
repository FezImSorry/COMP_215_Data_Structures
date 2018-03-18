#include <iostream>
#include <iomanip>
using namespace std;

void reverse(int num)
{
    if (num < 10)
        cout << num;
    else
    {
        cout << num % 10;
        reverse(num / 10);
    }
}

int main()
{
    int num;

    cout << "Enter Number: ";
    cin >> num;
    reverse(num);

    return 0;
}
