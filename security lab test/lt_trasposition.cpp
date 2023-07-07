#include<bits/stdc++.h>
using namespace std;

int main()
{
    string m,k,encrypt,decrypt;

    m = "HELLO WORLD";
    k = "3142";

    int r = (m.size()+k.size()-1)/k.size();

    char arr[r][k.size()];

    memset(arr, '\0', sizeof(arr));

    int cnt=0;
    for (int i=1; i<=m.size(); i++)
    {
        arr[cnt][(i-1)%k.size()] = m[i-1];
        if(i%k.size()==0)
        {
            cnt++;
        }
    }
    cout<<"Matrix:\n";
    for(int i=0; i<r; i++)
    {
        for (int j=0; j<k.size(); j++)
        {

            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<k.size(); i++)
    {
        int z = k[i]-'0' - 1;

        for (int j=0; j<r; j++)
        {
            encrypt += arr[j][z];
        }
    }
    cout<<"Encrypt by column "<<k<<": "<<encrypt<<endl;

    char arr2[r][k.size()];

    memset(arr2, '\0', sizeof(arr2));

    int p = 0;
    for(int i=0; i<k.size(); i++)
    {
        int z = k[i]-'0' - 1;

        for (int j=0; j<r; j++)
        {
            arr2[j][z] += encrypt[p];
            p++;
        }
    }

    for(int i=0; i<r; i++)
    {
        for (int j=0; j<k.size(); j++)
        {

            decrypt += arr2[i][j];
        }
    }

    cout<<"Decrypt: "<<decrypt<<endl;






    return 0;
}
