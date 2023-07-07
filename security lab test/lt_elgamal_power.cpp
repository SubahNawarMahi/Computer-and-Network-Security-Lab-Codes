#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli big_mod(lli base,lli power,lli mod)
{
    if(power==0)
        {return 1;}
    else if(power%2)
    {
        lli a= base%mod;
        lli b = big_mod(base,power-1,mod);
        return (a*b)%mod;
    }
    else
    {

        lli b = big_mod(base,power/2,mod);
        return (b*b)%mod;
    }
}
lli primitive_root(lli prime)
{
    lli ans;
    lli mod=prime;
    for(lli i=2;i<prime;i++)
    {
        map<lli,lli>mp;
        int flag=1;
        for(lli j=1;j<prime-1;j++)
        {
            lli x= big_mod(i,j,mod);
            if(mp[x]!=0)
            {
                flag=0;
                break;
            }
            else
            {
                mp[x]++;
            }
        }
        if(flag==1)
        {
            ans=i;
            break;
        }
    }
    return ans;
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
    lli msg,c1,c2,power,w,i,j,k,d,private_key,primitive,prime,public_key;
    cout<<"enter msg"<<endl;
    cin>>msg;
    cin>>w;
    private_key=17;
    prime = 10007;
    primitive=primitive_root(prime);
    k=7;

    public_key=big_mod(primitive,private_key,prime);

    c1= big_mod(primitive,k,prime);
    c2=big_mod(public_key,k,prime);
    c2=c2*msg;
    c2=big_mod(c2,1,prime);

    lli c1_d,c2_d;
    c1_d=big_mod(c1,w,prime);
    c2_d=big_mod(c2,w,prime);
    //decryption
    d= big_mod(c1,private_key,prime);
    d= modulo_inverse(d,prime);
    d= c2*d;
    d=big_mod(d,1,prime);

    cout<<d<<endl;

    lli d_d;
        d_d= big_mod(c1_d,private_key,prime);
    d_d= modulo_inverse(d_d,prime);
    d_d= c2_d*d_d;
    d_d=big_mod(d_d,1,prime);
    cout<<d_d<<endl;

    lli temp;
    temp=big_mod(msg,w,prime);


    return 0;
}
