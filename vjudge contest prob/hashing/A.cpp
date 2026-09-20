#include <bits/stdc++.h>
using namespace std;

#define LEN 1000005
int base=31;
long long power[LEN];

void init()
{
    power[0]=1;
    for(int i=1; i<LEN; i++)
    {
        power[i]=power[i-1]*base;
    }
}

void prefixHash(string s,int n,vector<long long>& ph)
{
    long long sum=0;
    for(int i=0; i<n; i++)
    {
        sum*=base;
        sum+=(sum[i]-'a'+1);
        ph[i]=sum;
    }
}

long long calcHash(int l,int r,vector<long long>& ph)
{
    if(l==r)
    {
        return ph[r];
    }
    else
        return ph[r]-ph[l-1]*power[r-l+1];
}

int main()
{
    init();
    string s,p;
    cin>>s>>p;
    int n=s.size();
    int m=p.size();
    if(m > n)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<long long> ph(n);
    prefixHash(s,n,ph);
    long long patternHash = 0;

    for(int i = 0; i < m; i++)
    {
        patternHash *= base;
        patternHash += (p[i] - 'a' + 1);
    }

    int count = 0;

    // Check every substring of length m
    for(int i = 0; i + m <= n; i++)
    {
        int l = i;
        int r = i + m - 1;

        long long currentHash = calcHash(l, r, ph);

        if(currentHash == patternHash)
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
