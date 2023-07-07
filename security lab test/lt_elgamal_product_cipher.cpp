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
    lli msg,msg2,c11,c22,primitive,prime,random_k,y,c1,c2,private_key,x,d,d1,d2;
    cout<<"enter message"<<endl;
    cin>>msg;
    cin>>msg2;
    cout<<msg*msg2<<endl;
    cin>>prime;
    private_key=17;

    primitive=primitive_root(prime);
    cout<<"primitive "<<primitive<<endl;
    //public key
   lli public_key = big_mod(primitive,private_key,prime);
    cout<<"public key: "<<public_key<<endl;

    //encryption
    random_k=coprime(prime);
lli    k2=7;

    c1 = big_mod(primitive,random_k,prime);
    c2 = big_mod(public_key,random_k,prime);
    c2 = c2*msg;
    c2 = big_mod(c2,1,prime);
    cout<<"c1: "<<c1<<endl;
    cout<<"c2: "<<c2<<endl;

       c11 = big_mod(primitive,k2,prime);
    c22 = big_mod(public_key,k2,prime);
    c22 = c22*msg2;
    c22 = big_mod(c22,1,prime);
    cout<<"c11: "<<c11<<endl;
    cout<<"c22: "<<c22<<endl;

    lli c_mul1,c_mul2;
    c_mul1=c1*c11;
    c_mul1=big_mod(c_mul1,1,prime);
    c_mul2=c2*c22;
    c_mul2=big_mod(c_mul2,1,prime);

    cout<<"c1*c11= "<<c_mul1<<endl;
     cout<<"c2*c22= "<<c_mul2<<endl;



    //decryption
    d = big_mod(c1,private_key,prime);
    d = modulo_inverse(d,prime);
    d = (c2*d)%prime;
    d=big_mod(d,1,prime);
    cout<<"decrypt "<<d<<endl;
   //  d1;
    d1 = big_mod(c11,private_key,prime);
    d1 = modulo_inverse(d1,prime);
    d1 = (c22*d1)%prime;
    d1=big_mod(d1,1,prime);
    cout<<"decrypt "<<d1<<endl;
    cout<<"d1*d2 "<<big_mod(d*d1,1,prime)<<endl;
    //d2;
        d2= big_mod(c_mul1,private_key,prime);
    d2 = modulo_inverse(d2,prime);
    d2 = (c_mul2*d2)%prime;
    d2=big_mod(d2,1,prime);
    cout<<"decrypt "<<d2<<endl;


    return 0;
}
