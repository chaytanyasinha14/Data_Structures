#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
#define pb push_back
#define fo(i, a, b) for (int i = a; i < b; i++)
#define sqr(x) ((ll)(x) * (x))
#define p(a) cout << a << "\n"
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);

/*.................................................................code starts here.........................................................*/

void solve(int t)
{
    ll n;
    cin >> n;
    ll p;
    ull h, range = 0;
    map<ll, ull> mapA;
    vector<vector<pair<ull, char> > > chain(n);
    map<ll, ull>::iterator itrS;
    map<ll, ull>::iterator itrE;
    map<ll, ull>::iterator Start;
    map<ll, ull>::iterator End;
    vector<pair<ull, char> >::iterator vitr;

    fo(i, 0, n)
    {
        cin >> p;
        cin >> h;
        range = max(range, h);
        mapA.insert(pair<ll, ull>(p, h));
    }
    ll i = 0;
    for (itrS = mapA.begin(); itrS != mapA.end(); ++itrS)
    {
        chain[i] = vector<pair<ull, char> >(1);
        chain[i][0] = pair<ull, char>(itrS->second, 'A');
        i++;
    }

    End = mapA.end();
    End = prev(End, 2);
    Start = mapA.begin();
    i = n - 2;
    ll j = 0;

    for (itrS = End; itrS != Start; --itrS)
    {
        j = i;
        for (itrE = next(itrS, 1); itrE != mapA.end(); itrE++)
        {
            j++;
            if (itrS->first == itrE->first - itrE->second || itrS->first + itrS->second == itrE->first - itrE->second || itrS->first + itrS->second == itrE->first)
            {
                vector<pair<ull, char>>::iterator chainItr = chain[j].begin();
                vector<pair<ull, char>>::iterator chainItrEnd = chain[j].end();
                if (itrS->first == itrE->first - itrE->second)
                {
                    for (vitr = chainItr; vitr != chainItrEnd; ++vitr)
                    {
                        if (vitr->second == 'L' || vitr->second == 'A')
                        {

                            ull value = vitr->first + itrS->second;
                            range = max(range, value);
                            chain[i].push_back(pair<ull, char>(value, 'L'));
                        }
                    }
                }
                else if (itrS->first + itrS->second == itrE->first - itrE->second)
                {
                    for (vitr = chainItr; vitr != chainItrEnd; ++vitr)
                    {
                        if (vitr->second == 'L' || vitr->second == 'A')
                        {

                            ull value = vitr->first + itrS->second;
                            range = max(range, value);
                            chain[i].push_back(pair<ull, char>(value, 'N'));
                        }
                    }
                }
                else
                {
                    for (vitr = chainItr; vitr != chainItrEnd; ++vitr)
                    {
                        if (vitr->second == 'R' || vitr->second == 'A' || vitr->second == 'N')
                        {

                            ull value = vitr->first + itrS->second;
                            range = max(range, value);
                            chain[i].push_back(pair<ull, char>(value, 'R'));
                        }
                    }
                }
            }
        }
        i--;
    }

    j = i;
    for (itrE = next(itrS, 1); itrE != mapA.end(); itrE++)
    {
        j++;
        if (itrS->first == itrE->first - itrE->second || itrS->first + itrS->second == itrE->first - itrE->second || itrS->first + itrS->second == itrE->first)
        {
            vector<pair<ull, char>>::iterator chainItr = chain[j].begin();
            vector<pair<ull, char>>::iterator chainItrEnd = chain[j].end();
            if (itrS->first == itrE->first - itrE->second)
            {
                for (vitr = chainItr; vitr != chainItrEnd; ++vitr)
                {
                    if (vitr->second == 'L' || vitr->second == 'A')
                    {

                        ull value = vitr->first + itrS->second;
                        range = max(range, value);
                        chain[i].push_back(pair<ull, char>(value, 'L'));
                    }
                }
            }
            else if (itrS->first + itrS->second == itrE->first - itrE->second)
            {
                for (vitr = chainItr; vitr != chainItrEnd; ++vitr)
                {
                    if (vitr->second == 'L' || vitr->second == 'A')
                    {

                        ull value = vitr->first + itrS->second;
                        range = max(range, value);
                        chain[i].push_back(pair<ull, char>(value, 'N'));
                    }
                }
            }
            else
            {
                for (vitr = chainItr; vitr != chainItrEnd; ++vitr)
                {
                    if (vitr->second == 'R' || vitr->second == 'A' || vitr->second == 'N')
                    {
                        ull value = vitr->first + itrS->second;
                        range = max(range, value);
                        chain[i].push_back(pair<ull, char>(value, 'R'));
                    }
                }
            }
        }
    }
    i--;

    cout << "Case #" << t << ": " << range << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("timber_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    fo(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}
