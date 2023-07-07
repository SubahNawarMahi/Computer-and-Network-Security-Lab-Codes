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
lli primitive_root(lli prime)
{
    lli ans;
    for(lli i = 2;i<prime;i++)
    {
        map<lli,lli>mp;
        int flag=1;
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

    lli msg,y1,y2,primitive,prime,private_key,public_key,k,i,j,l;
    //msg
    cin>>msg;
    prime=10007;
    primitive=primitive_root(prime);
    cout<<primitive<<endl;//5
    private_key=17;
    k=7;
    public_key = big_mod(primitive,private_key,prime);

    //signature with private key

    y1 = big_mod(primitive,k,prime);
    y2 = ((msg-private_key*y1)*modulo_inverse(k,prime-1)) %(prime-1);
    if(y2<0)
    {
        y2+=(prime-1);
    }
    cout<<y1<<endl;
    cout<<y2<<endl;

    //verfication with public key
    lli lhs,l1,rhs;
    lhs=big_mod(y1,y2,prime);
    l1= big_mod(public_key,y1,prime);
    lhs=(lhs*l1)%prime;
    cout<<lhs<<endl;
    rhs = big_mod(primitive,msg,prime);
    cout<<rhs<<endl;


    return 0;
}
