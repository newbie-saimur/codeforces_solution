#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define i_mn INT_MIN
#define i_mx INT_MAX

#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define pb push_back
#define pf push_front
#define m_p make_pair


#define pii pair<int,int>
#define vip vector<pair<int,int>>
#define umap unordered_map
#define mii map<int,int>
#define uset unordered_set

#define ff first
#define ss second
#define in insert
#define ub upper_bound
#define lb lower_bound

#define all(v) v.begin(), v.end()
#define asc(v) sort(v.begin(), v.end())
#define rev(v) sort(v.rbegin(), v.rend())
#define ign cin.ignore()
#define getln(s) getline(cin, s)

#define eps (double)(1e-7)
#define pi (double)(acos(-1))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / __gcd(a, b)
#define mod (ll)(1e9+7)

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))

#define case cout<<"Case "<<k<<": "
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define endl "\n"
int k;

/*= = = = = = = = = = = = = = = = = = = = = = = = = = = = 

                    Code Start From Here                    

= = = = = = = = = = = = = = = = = = = = = = = = = = = = */

void solve()
{
    ll n, a, b, c;
    cin>>n>>a>>b>>c;
    int count = 0;
    ll rem;
    for(ll i=0; i*a<=n; i++)
    {
        for(ll j=0; a*i+j*b<=n; j++)
        {
            int k;
            rem = n - i * a - b * j;
            if(rem%c==0)
            {
                k = rem/c;
                int temp = i + j + k;
                count = max(count, temp);
            }
        }
    }
    cout<<count<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll test=1;
    // cin>>test;
    for(k=1; k<=test; k++)
    {
        solve();
    }
    return 0;
} 
