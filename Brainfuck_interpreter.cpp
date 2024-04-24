#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void check(vector<char> w);
void read();
vector<char> w;
vector<char> ans(100000, 0);

int main()
{
    read();
    check(w);
}
void read()
{
    fstream p("input.txt");
    char c;
    while (p.good())
    {
        p >> c;
        w.push_back(c);
    }
    p.close();
}

void check(vector<char> w)
{

    char c;
    int z;
    int wsk = 0;
    for (int i = 0; i < w.size() - 1; i++)
    {
        c = w[i];
        switch (c)
        {
        case '>':
        {
            wsk++;
            break;
        }
        case '<':
        {
            wsk--;
            break;
        }
        case '+':
        {
            ans[wsk]++;
            break;
        }
        case '-':
        {
            ans[wsk]--;
            break;
        }
        case '.':
        {
            cout << ans[wsk];
            break;
        }
        case ',':
        {
            cin >> z;
            ans[wsk] = z;
            break;
        }
        case '[':
        {
            if (ans[wsk] == 0)
            {
                int licznik = 1;
                for (int j = i + 1; j < w.size(); j++)
                {
                    if (w[j] == '[')
                        licznik++;
                    else if (w[j] == ']')
                        licznik--;
                    if (licznik == 0)
                    {
                        i = j;
                        break;
                    }


                }
            }
            break;
        }
        case ']':
        {
            int licznik2 = 1;
            for (int k = i - 1; k >= 0; k--)
            {
                if (w[k] == '[')
                    licznik2--;
                else if (w[k] == ']')
                    licznik2++;

                if (licznik2 == 0)
                {
                    i = k - 1;
                    break;
                }

            }
            break;
        }
        }
    }
}