#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int n, temp, r, sum  ;
    // temp=n;
    int t;
    cin >> t;
    int i = 0;
    while (i < t)
    {
        cin >> n;
        temp = n;
        sum = 0 ;
        cout<<"temp"<<temp<<endl ;
        while (n > 0)
        {
            sum = sum*10 ;
            r = n % 10;
            sum = (sum + r);
            n = n / 10;
        }
        cout<<"sum"<<sum<<endl ;
        if (temp == sum)
        {
            cout << "wins" << endl;
        }
        else
        {
            cout << "loses" << endl;
        }
        i++;
    }
    return 0;
}