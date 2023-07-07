#include<bits/stdc++.h>
using namespace std;
#define lli long long int
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
lli gcd(lli a,lli b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
lli modulo_inverse(lli base,lli mod)
{
    lli ans=-1;
    for(lli i=1;i<mod;i++)
    {
        if((base*i)%mod==1)
        {
            ans=i;
            break;
        }
    }
    return ans;
}
int main()
{
    lli msg,e,d,n,phi_n,p,q,i,j,k,c,de,sign,ver;
    cout<<"Enter msg"<<endl;
    cin>>msg;
    cout<<"Enter public key"<<endl;
    cin>>e; //public
    cout<<"Enter primes"<<endl;
    cin>>p;
    cin>>q;
    n = p*q;
    phi_n = (p-1)*(q-1);
    if(gcd(e,phi_n)==1)
    {
        cout<<"valid public key"<<endl;
        d = modulo_inverse(e,phi_n);//private
    //signature
    sign = big_mod(msg,d,n);
    cout<<sign<<endl;
    //verification
    ver=big_mod(sign,e,n);
    cout<<ver<<endl;
    }
    else
    {
        cout<<"not valid public key"<<endl;
    }


    return 0;
}
