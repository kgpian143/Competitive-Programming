#include <iostream>
#include <vector>
using namespace std;

string solution(string s, int t, int n, int x)
{
    vector<int> strip;
    for (char c : s)
    {
        strip.push_back(c - '0');
    }
    int turn = 0;
    auto check_empty_cells = [&](int i)
    {
        for (int j = i; j < i + n; j++)
        {
            if (j >= t || strip[j] != 0)
            {
                return false;
            }
        }
        return true;
    };
    while (true)
    {
        for (int i = 0; i < t; i++)
        {
            if (check_empty_cells(i))
            {
                for (int j = i; j < i + n; j++)
                {
                    strip[j] = x + turn;
                }
                break;
            }
            else
            {
                return "Samuel";
            }
        }

        for (int i = 0; i < t; i++)
        {
            if (check_empty_cells(i))
            {
                for (int j = i; j < i + n; j++)
                {
                    strip[j] = x + turn;
                }
                break;
            }
            else
            {
                return "Tina";
            }
        }

        turn++;
        if (turn >= x)
        {
            return "Tie";
        }
    }
}

int main()
{
    string s = "123456789";
    int t = 9;
    int n = 3;
    int x = 5;
    cout << solution(s, t, n, x) << endl;
    return 0;
}
