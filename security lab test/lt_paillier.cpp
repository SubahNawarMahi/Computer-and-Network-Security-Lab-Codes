#include <bits/stdc++.h>
using namespace std;

#define lli long long int

lli big_mod(lli base, lli power, lli mod)
{
    if (power == 0)
    {
        return 1;
    }
    else if (power % 2)
    {
        lli a = base % mod;
        lli b = big_mod(base, power - 1, mod);
        return (a * b) % mod;
    }
    else
    {
        lli b = big_mod(base, power / 2, mod);
        return (b * b) % mod;
    }
}

lli gcd(lli a, lli b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

lli modulo_inverse(lli base, lli mod)
{
    lli ans = -1;
    for (lli i = 1; i < mod; i++)
    {
        if ((i * base) % mod == 1)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

lli L(lli x, lli n)
{
    lli ans = (x - 1) / n;
    return ans%n;
}

int main()
{
    lli n, n2, p, q, lamda, g, miu, en, en1, dec, msg, r;

    p = 101;
    q = 107;
    n = p * q;
    n2 = (p - 1) * (q - 1);

    if (gcd(n, n2) == 1)
    {
        lamda =  gcd(p - 1, q - 1);
        lamda = lamda%n;
        lamda = n2/lamda;
        cout << "lamda: " << lamda << endl;

        g = 13;
        cout << "g: " << g << endl;
        if (gcd(g, n) == 1)
            cout << "ok1" << endl;
        lli temp = big_mod(g, lamda, n * n);
        temp = L(temp, n);
        miu = modulo_inverse(temp, n);
//        if (miu < 0)
//            miu += n;
        cout << "miu: " << miu << endl;

        // Encryption
        r = 11;
        if (gcd(r, n) == 1)
            cout << "ok2" << endl;

        cout << "Enter the message to encrypt: ";
        cin >> msg;

        lli n_sqr = n * n;
        en = big_mod(g, msg, n_sqr);
        cout<<en<<endl;
        en1 = big_mod(r, n, n_sqr);
        en = (en * en1) % n_sqr;
        cout << "Encrypted message: " << en%n_sqr << endl;

        // Decryption
        dec = big_mod(en, lamda, n_sqr);
         cout<<dec<<endl;
        dec = L(dec, n);
        cout<<dec<<endl;
        dec = (dec * miu) % n;
        cout << "Decrypted message: " << dec %n<< endl;
    }

    return 0;
}
