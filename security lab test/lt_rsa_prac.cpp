// ------------known plain text and public key, N--------------
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
vector<lli>prime;
vector<lli>v(100000,0);
lli big_mod(lli base,lli power,lli mod)
{
    if(power==0)
    {
        return 1;
    }
    else if(power%2)
    {
        lli a= base%mod;
        lli b=big_mod(base,power-1,mod);
        return (a*b)%mod;
    }
    else
    {
        lli a= big_mod(base,power/2,mod);
        return (a*a)%mod;
    }
}
lli modulo_inverse(lli base,lli mod)
{
    lli ans=-1;
    for(lli i=1; i<mod; i++)
    {
        if((i*base)%mod==1)
        {
            ans=i;
            break;
        }
    }
    return ans;
}
lli prime_factor()
{
    for(lli i=3; i<sqrt(100000); i+=2)
    {
        for(lli j=i*i; j<100000; j+=(i+i))
        {
            v[j-1]=1;
        }
    }
    prime.push_back(2);
    for(lli i=3; i<100000; i+=2)
    {
        if(v[i-1]==0)
        {
            prime.push_back(i);
        }
    }
}
lli gcd(lli a,lli b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
int main()
{
    cout<<big_mod(2,3,10)<<endl;
    lli private_key,e,public_key,d,k,n,phi_n,p,q,c,msg;
    cout<<"enter msg"<<endl;
    cin>>msg;
    cout<<"enter public key and value of N"<<endl;
    cin>>e;
    cin>>n;
    c=big_mod(msg,e,n);
    cout<<"cipher "<<c<<endl;
    //find prime values;
    prime_factor();
    p=0;
    q=0;
    for(lli i=0; prime[i]<=sqrt(n); i++)
    {
        if(n%prime[i]==0)
        {
            lli temp=n/prime[i];
            if(v[temp-1]==0&& temp!= prime[i])
            {
                cout<<"prime1 "<<prime[i]<<endl;
                cout<<"prime2 "<<temp<<endl;
                p=prime[i];
                q=temp;

                phi_n=(p-1)*(q-1);
               // d = gcd(e,phi_n);
               d= modulo_inverse(e,phi_n);
                cout<<"private key"<<d<<endl;
               lli de=big_mod(c,d,n);
                cout<<"decrypt "<<de<<endl;

            }
        }
    }
    return 0;

}
