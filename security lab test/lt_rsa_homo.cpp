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
        lli a = big_mod(base,power/2,mod);
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
        if((i*base)%mod==1)
        {
            ans=i;
            break;
        }
    }
    return ans;
}
int main()
{
    lli i,j,k,l,msg1,msg2,e,d,phi_n,p,q,n,c,c_mul,c1,c2,de,de1,de2,temp;
    cout<<"Enter msg1:"<<endl;
    cin>>msg1;
    cout<<"Enter msg2:"<<endl;
    cin>>msg2;

    cout<<"Enter public key:"<<endl;
    cin>>e;
    cout<<"Enter primes:"<<endl;
    cin>>p;
    cin>>q;
    n=p*q;
    phi_n=(p-1)*(q-1);

    c1=big_mod(msg1,e,n);
    c2=big_mod(msg2,e,n);
    c=(c1*c2)%n;
    cout<<"c=c1*c2 --->"<<c<<endl;


    //d=(1+k*phi_n)/e
    k=2;
    for(k=2;k<phi_n;k++)
    {
        if(((1+k*phi_n)%e)==0 )
        {
            d=(1+k*phi_n)/e;
        }
    }
    cout<<"d: "<<d<<endl;
    lli msg=msg1*msg2;
    c_mul=big_mod(msg,e,n);
    cout<<"(m1*m2)^e mod n ---->"<<c_mul<<endl;
    de1=big_mod(msg1,d,n);
    de2=big_mod(msg2,d,n);
    de=(de1*de2)%n;
     cout<<"de=de1*de2 --->"<<de<<endl;
     lli d_mul;
     d_mul=big_mod(c_mul,d,n);
     cout<<"(m1*m2)^ed mod n ---->"<<d_mul<<endl;


    return 0;
}
