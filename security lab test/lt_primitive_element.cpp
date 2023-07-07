#include<bits/stdc++.h>
using namespace std;
#define lli long long int
vector<lli>v(100000,0);
vector<lli>prime;
//100000
lli big_mod(lli base,lli power,lli mod)
{
    if(power==0)
    {
        return 1;
    }
    else if(power%2)
    {
        lli a = base%mod;
        lli b = big_mod(base,power-1,mod);
        return (a*b)%mod;
    }
    else
    {
        lli a= big_mod(base,power/2,mod);
        return (a*a)%mod;
    }
}
lli prime_factor()
{
    for(lli i=3;i<sqrt(100000);i+=2)
    {
        for(lli j=i*i;j<sqrt(100000);j+=(i+i))
        {
            v[j-1]=1;

        }
    }
    prime.push_back(2);
    for(lli i=3;i<100000;i+=2)
    {
        if(v[i-1]==0)
        {
            prime.push_back(i);
        }

    }
}
/*
prime = 7
3^1 % 7 = 3
3^2 % 7 = 2
3^3 % 7 = 6
3^4 % 7 = 4
3^5 % 7 =
3^6 % 7 =
*/
lli primitive_root(lli prime)
{


    lli ans;
    for(lli i=2;i<prime;i++)
    {
        map<lli , lli>mp;
        lli flag=1;
        for(lli j=1;j<prime-1;j++)
        {
            lli x = big_mod(i,j,prime);
            if(mp[x]!=0)
            {
                flag=0;
                break;
            }
            else
            {
                mp[x]++;
            }
            cout<<i<<"^"<<j<<"%"<<prime<<"="<<x<<endl;
        }
        if(flag==1)
        {
            ans=i;
            break;
        }

    }
    return ans;
}
void check_primitive(lli base,lli prime)
{
    map<lli,lli>mp;
    int flag=1;
    for(lli i=1;i<prime-1;i++)
    {
        lli x= big_mod(base,i,prime);
        if(mp[x]!=0)
        {
            flag=0;
            cout<<"not primitive root"<<endl;
            break;
        }
        else
        {
            mp[x]++;
        }
    }
    if(flag==1)
    {cout<<" primitive root "<<endl;}
}
int main()
{
    prime_factor();
    cout<<prime[2]<<endl;
    cout<<primitive_root(7)<<endl;
    check_primitive(2,7);
    return 0;
}
