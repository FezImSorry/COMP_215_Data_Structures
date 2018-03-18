#include <iostream>
#include <iomanip>
using namespace std;

void printStars(int num, int i)
{
    if( num == 0) //Base Case
        return;
    else if( i == 0) //Initial Step
    {
        cout << right << setw(num + 3) << "*" << endl;
        printStars(num - 1, i + 1);
    }
    else if(i > 0)
    {
        for(int j = num; j >= 0; j--)
        {
            cout << " ";
        }

        for(int k = 0; k <= i; k++)
        {
            cout << " *";
        }

        cout << endl;
        printStars(num - 1, i + 1);
    }

    if(num > 1) //Printing Lower Half
    {
       for(int j = num; j >= 0; j--)
       {
            cout << " ";
       }

       for(int k = 0; k <= i; k++)
       {
            cout << " *";
       }

       cout << endl;
    }
}

int main()
{
    int num, i = 0;

    cout << "Please enter the number of lines:" << endl;
    cin >> num;
    printStars(num, i);

    return 0;
}
