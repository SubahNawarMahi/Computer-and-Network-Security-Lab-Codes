#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli big_mod(lli base,lli power,lli mod)
{
    if(power==0)
        {return 1;}
    else if(power%2)
    {
       lli a = base %mod;
       lli b = big_mod(a,power-1,mod)%mod;
       return (a*b)%mod;
    }
    else
    {
        lli a = big_mod(base,power/2,mod)%mod;
        return (a*a)%mod;
    }
}
lli modulo_inverse(lli base,lli mod)
{
    lli ans=-1;
    for(lli i=1;i<mod;i++)
    {
        if((i*base)%mod==1)
        {
            ans=i;
            break;
        }
    }
    return ans;
}
lli gcd(lli a,lli b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
int main()
{
    //cout<<big_mod(2,3,5);//3
    lli msg,plain_text,cipher_text,private_key, public_key,k,p,q,n,phi_n;
    lli i,j,l;
    cout<<"Message"<<endl;
    cin>>msg;
    cout<<"public key"<<endl;
    cin>>public_key;
    cout<<"primes"<<endl;
    cin>>p>>q;
    n=p*q;
    phi_n=(p-1)*(q-1);

    if (gcd(public_key,phi_n==1))
    {
        cout<<"valid public key"<<endl;
        //ed=1 mod phi_n
        lli d = modulo_inverse(public_key,phi_n);
        cout<<"decrypt key"<<endl;
        cout<<d<<endl;
        cout<<"encrypt msg"<<endl;
        lli c= big_mod(msg,public_key,n);
        cout<<c<<endl;
        cout<<"decrypt msg"<<endl;
        lli de = big_mod(c,d,n);
        cout<<de<<endl;

    }



    return 0;
}
