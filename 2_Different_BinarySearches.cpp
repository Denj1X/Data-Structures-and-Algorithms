#include <bits/stdc++.h>
using namespace std;
int lower_fct(const vector <int> &values, const int &nr)
{   ///cam la fel ca la clasa, dar cu poz-ul
    ///si operatiile schimbate (+ cu -)
    int poz = values.size() - 1, pow = (1<<20);
    while(pow)
    {   if(poz-pow >= 0 && values[poz-pow] >= nr)
            poz -= pow;
        pow >>= 1;
    }
    return poz;
}
int upper_fct(const vector <int> &values, const int &nr)
{   ///cod asemanator cu cea a scris profu la seminar
    int n = values.size(), pow = (1<<20), poz = 0;
    while(pow)
    {   if(poz+pow<n && values[poz+pow] <= nr)
            poz += pow;
        pow >>= 1;
    }
    return poz;
}
int nr_ap(const vector <int> &values, const int &nr)
{   int jos = lower_fct(values, nr);
    int sus = upper_fct(values, nr);
    if((sus && jos) || values[sus] == nr) return sus-jos+1;
    else return 0;
}
///lower_bound si upper_bound manual implementate
int main()
{   int n,x; cin>>n>>x;
    vector <int> v;
    for(int i=0;i<n;i++)
    {   int val; cin>>val;
        v.push_back(val);
    }
    sort(v.begin(),v.end());
    cout<<nr_ap(v,x);
    return 0;
}