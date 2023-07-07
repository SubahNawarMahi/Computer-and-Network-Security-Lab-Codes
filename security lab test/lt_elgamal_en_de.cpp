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
        if((i*base)%mod==1)
        {
            ans=i;
            break;
        }
    }
    return ans;

}
lli coprime(lli prime)
{
    lli ans;
    for(lli i=2;i<prime;i++)
    {
        if(gcd(i,prime)==1)
        {
            ans=i;
            break;
        }
    }
    return ans;
}
lli primitive_root(lli prime)
{
    lli ans;
    for(lli i=2;i<prime;i++)
    {
        map<lli,lli>mp;
        int flag = 1;
        for(lli j=1;j<prime-1;j++)
        {
            lli x= big_mod(i,j,prime);
            if(mp[x]!=0)
            {
                flag=0;
                break;
            }
            else
            {
                mp[x]++;
            }
        //     cout<<i<<"^"<<j<<"%"<<prime<<"="<<x<<endl;
        }
        if(flag==1)
        {
            ans=i;
            break;
        }
    }
    return ans;
}
int main()
{
    cout<<big_mod(2,3,5)<<endl;
    lli msg,primitive,prime,random_k,y,c1,c2,private_key,x,d,d1,d2;
    cout<<"enter message"<<endl;
    cin>>msg;
    cin>>prime;
    private_key=17;

    primitive=primitive_root(prime);
    cout<<"primitive "<<primitive<<endl;
    //public key
   lli public_key = big_mod(primitive,private_key,prime);
    cout<<"public key: "<<public_key<<endl;

    //encryption
    random_k=coprime(prime);

    c1 = big_mod(primitive,random_k,prime);
    c2 = big_mod(public_key,random_k,prime);
    c2 = c2*msg;
    c2 = big_mod(c2,1,prime);
    cout<<"c1: "<<c1<<endl;
    cout<<"c2: "<<c2<<endl;

    //decryption
    d = big_mod(c1,private_key,prime);
    d = modulo_inverse(d,prime);
    d = (c2*d)%prime;
    d=big_mod(d,1,prime);
    cout<<"decrypt"<<d<<endl;


    return 0;
}
