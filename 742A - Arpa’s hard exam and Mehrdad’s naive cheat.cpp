#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

#define int     long long
#define ull     unsigned long long
#define vi      vector<int>
#define pii     pair<int,int>
#define vip     vector<pair<int,int>>
#define umap    unordered_map
#define uset    unordered_set
#define pb      push_back
#define ppb     pop_back
#define pf      push_front
#define ff      first
#define ss      second 
#define in      insert
#define ub      upper_bound
#define lb      lower_bound

#define all(v)      v.begin(), v.end()
#define eps         (double)(1e-7)
#define pi          (double)(acos(-1))
#define fl(i,n)     for(int i=0;i<n;i++)
#define rl(i,m,n)   for(int i=n;i>=m;i--)
#define gcd(a,b)    __gcd(a, b)
#define lcm(a,b)    (a * b) / __gcd(a, b)
#define mod         1000000007

#define setbit(n)      __builtin_popcountll(n)  // Count of set bit
#define zerobit(n)     __builtin_ctzll(n)       // Count of 0 bit before 1st 1
#define getbit(n,i)    ((n & (1LL << i)) != 0)  // ith bit ?
#define setbit0(n,i)   (n & (~(1LL << i)))      // unset any bit
#define setbit1(n,i)   (n | (1LL << i))         // set any bit
#define togglebit(n,i) (n ^ (1LL << i))

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))

#define case     cout<<"Case "<<_<<": "
#define yes      cout<<"yes\n"
#define no       cout<<"no\n"
#define ps(x,y)  fixed<<setprecision(y)<<x
#define endl     "\n"
int _;

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// template<class T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// template<class T> using o_mset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// s.order_of_key(x) = number of elements strictly less than x
// *s.find_by_order(i) = ith element in set (0 index)
int binExp(int a,int b,int M){int res=1;while(b){if(b&1) res=(res*1LL*a)%M;a=(a*1LL*a)%M;b>>=1;}return res;}

// Operator overloads
template<typename T1, typename T2>      // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T>                    // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2>      // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second <<"\n"); }
template<typename T>                    // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
void readarr(int arr[],int n){fl(i,n) cin>>arr[i];}
void printarr(int arr[], int n){fl(i,n) cout << arr[i] << " ";cout << "\n";}

// sort pair by 2nd value => sorta -> ascending & sortd-> decending
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}
// Implementation : sort(all(v),sorta); Here, v is vector of pairs

// Check
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(int x){if (x >= 0) {int sr = sqrt(x);return (sr * sr == x);}return false;}

/*= = = = = = = = = = = = = = = = = = = = = = = = = = = = 

                    Code Start From Here                    

= = = = = = = = = = = = = = = = = = = = = = = = = = = = */

int power(int a, int n, int m)
{
    int res = 1;
    while(n)
    {
        if(n&1) res = (res * a) % m, n--;
        else a = (a * a) % m, n/=2;
    }
    return res;
}

void solve()
{
    int n; cin>>n;
    cout<<power(8,n,10)<<endl;
}   

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int test=1;
    //cin>>test;
    for(_=1; _<=test; _++)
    {
        solve();
    }
    return 0;
}  
