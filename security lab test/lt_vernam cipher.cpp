#include<bits/stdc++.h>
using namespace std;
int main()
{
    string plain,key,cipher,temp="";
    int i,j,k,l;
    char a;
    cin>>plain;
    cin>>key;
    //temp.clear();
    temp=plain;
    if(key.size()==plain.size())
    {
        for(i=0; i<plain.size(); i++)
        {
            if(plain[i]==key[i])
                temp[i]='0';
            else
                temp[i]='1';

        }
        cipher=temp;
        cout<<cipher<<"cipher"<<endl;
    }
    else
    {
        cout<<"key size not equal to msg size"<<endl;
    }
    return 0;
}
