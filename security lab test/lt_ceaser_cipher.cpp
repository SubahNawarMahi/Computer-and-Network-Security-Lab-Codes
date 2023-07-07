#include<bits/stdc++.h>
using namespace std;
int main()
{
    string plain,cipher,temp;
    int key,i,j,k;
    cin>>plain;
    cipher=plain;

    cin>>key;
    //cout<<plain+key<<endl;
    for(i=0; i<plain.size(); i++)
    {
        cout<<plain[i]<<"  "<<plain[i]-'A';
        if(plain[i]>='A' && plain[i]<='Z')
        {
            j=(((plain[i]-'A')+key)%26);
            cipher[i]=j+'A';
        }
        else if(plain[i]>='a' && plain[i]<='z')
        {
            j=(((plain[i]-'a')+key)%26);
            cipher[i]=j+'a';
        }
        cout<<j<<endl;

    }
    cout<<cipher<<endl;

    //decryption
    temp=cipher;
    for(i=0; i<cipher.size(); i++)
    {
        cout<<cipher[i]<<"  "<<plain[i]-'A';
        if(cipher[i]>='A' && cipher[i]<='Z')
        {
            j=(((cipher[i]-'A')-key+26)%26);
            temp[i]=j+'A';
        }
        else if(cipher[i]>='a' && cipher[i]<='z')
        {
            j=(((cipher[i]-'a')-key+26)%26);
            temp[i]=j+'a';
        }
        cout<<j<<endl;

    }
    cout<<temp<<endl;


    return 0;
}
