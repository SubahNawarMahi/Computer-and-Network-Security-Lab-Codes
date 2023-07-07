#include <bits/stdc++.h>

using namespace std;
int main()
{
    int i, j;
    string input = "Transposition";
    string key = "ciphe";
    string sorted_key = key;
    sort(sorted_key.begin(), sorted_key.end());

    map<char, int> s_pos;
    for (int i = 0; i < key.size(); i++)
    {
        s_pos[sorted_key[i]] = i;
    }
    vector<int> seq;
    for (i = 0; i < key.size(); i++)
    {
        seq.push_back(s_pos[key[i]]);
        cout<<s_pos[key[i]]<<endl;
    }

    int key_size = key.size();
    vector<char> v[key_size];
    for (int i = 0; i < input.size(); i++)
    {
        int ind = seq[i % key_size];
        v[ind].push_back(input[i]);
    }

    int minsize = input.size() / key_size;
    if (input.size() % key_size)
    {
        minsize++;
    }
    for (i = 0; i < key_size; i++)
    {
        if (v[i].size() < minsize)
        {
            v[i].push_back('*');
        }
    }
    string encription = "";
    for (i = 0; i < key_size; i++)
    {
        for (j = 0; j < v[i].size(); j++)
            encription = encription + v[i][j];
    }
    cout << encription << endl;

    string dec = "";
    for (i = 0; i < input.size(); i++)
    {
        char val = v[seq[i % key_size]][i / key_size];
        dec = dec + val;
    }
    cout << dec << endl;

    return 0;
}
