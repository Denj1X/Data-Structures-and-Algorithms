#include <bits/stdc++.h>
using namespace std;
vector<long long> merge(vector<long long> left,
                        vector<long long> right,int &rev)
{   ///left = vectorul din stanga pana la mijlocul unui vector mai mare
    ///right = vectorul de la mijlocul pana in dreapta unui vector mai mare
    ///result = vectorul mai mare, unde a rezultat
    /// interclasarea celor doi vectori left si right
    vector<long long> result;
    while (left.size() > 0 || right.size() > 0)
    {   if (left.size() > 0 && right.size() > 0)
        {   if (left.front() <= right.front())
            {   result.push_back(left.front());
                left.erase(left.begin());
            }
            else
            {   rev += left.size();
                ///aici are loc modificare valorii rev
                result.push_back(right.front());
                right.erase(right.begin());
            }
        }
        else if (left.size() > 0)
        {   for (int i = 0; i < left.size(); i++)
               result.push_back(left[i]);
            break;
        }
        else if (right.size() > 0)
        {   for (int i = 0; i < right.size(); i++)
               result.push_back(right[i]);
            break;
        }
        ///in rest a fost acceasi interclasare
        ///de la MergeSort
    }
    return result;
}

vector<long long> mergeSort(vector<long long> m, int &rev)
{   if (m.size() <= 1)
        return m;
    vector<long long> left, right, result;
    int middle = (m.size()+ 1) / 2;
    for (int i = 0; i < middle; i++)
        left.push_back(m[i]);
    for (int i = middle; i < m.size(); i++)
        right.push_back(m[i]);
    left = mergeSort(left, rev);
    right = mergeSort(right, rev);
    result = merge(left, right, rev);
    return result;
}

int nr_inversiuni(vector<long long> &v)
{   int sol = 0;
    mergeSort(v, sol);
    return sol;
}
int main()
{   int n; cin>>n;
    vector<long long>v;
    for(int x,i=0;i<n;i++)
    {   cin>>x; v.push_back(x); }
    cout<<nr_inversiuni(v);
    return 0;
}
