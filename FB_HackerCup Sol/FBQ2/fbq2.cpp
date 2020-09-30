//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE...
#include <iostream>
#include <string>
#include <bits/stdc++.h>
// #include <vector>
// #include <set>
// #include <map>
// #include <stack>

using namespace std;

typedef long long ll;
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
    string Pieces;
    char ans = 'N';
    cin >> n;
    cin >> Pieces;
    ll countA = 0, countB = 0;
    // char PArr[n];
    vector<char> noHuddle;
    fo(i, 0, n)
    {
        // PArr[i] = Pieces[i];
        if (Pieces[i] == 'A')
        {
            countA++;
        }
        else
        {
            countB++;
        }
    }
    if (countA - countB == 1 || countA - countB == -1)
    {
        ans = 'Y';
    }
    cout << "Case #" << t << ": " << ans << endl;
}

int main()
{
    freopen("INPUTQ22.txt", "r", stdin);
    freopen("OUTPUTQ22.txt", "w", stdout);
    int t;
    cin >> t;
    fo(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}
