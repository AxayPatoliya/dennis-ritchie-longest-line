/* C++ implementation to Check if
two strings after processing
backspace character are equal or not*/

#include <bits/stdc++.h>
using namespace std;

bool compare(string s, string t)
{
    int ps, pt, i;
    ps = -1;

    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '#' && ps != -1)

            ps -= 1;

        else if (s[i] != '#')
        {

            s = s[i];
            ps += 1;
        }
    }

    pt = -1;

    for (i = 0; i < t.size(); i++)
    {
        if (t[i] == '#' && pt != -1)
            pt -= 1;

        else if (t[i] != '#')
        {

            t[pt + 1] = t[i];

            pt += 1;
        }
    }
    if (pt != ps)

        return false;

    else if (ps == -1 && pt == -1)

        return true;
    else
    {

        for (i = 0; i <= pt; i++)
        {

            if (s[i] != t[i])

                return false;
        }
        return true;
    }
}

// Driver code
int main()
{
    // initialise two strings
    string s;
    string t;

    cin>>s;
    cin>>t;


    if (compare(s, t))

        cout << "True";
    else

        cout << "False";
}
