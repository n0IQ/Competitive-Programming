#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second
 
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repR(i, n) for (int i = n-1; i >= 0; --i)
#define repA(i, a, n) for (int i = a; i <= n; ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
 
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vd vector<double>
#define vb vector<bool>
 
#define vpii vector<pii>
#define vpll vector<pll>
#define vpdd vector<pdd>
 
 
#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
 
int main()
{
  fastio
  
  int T;
  cin >> T;

  while (T-- > 0)
  {
    int a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    
    int a1=a, b1=b, x1=x, y1=y, n1= n;
    
    ll ans1 = 0, ans2 = 0;
    
    if(a-n >= x) {
      a1 = a-n;
      
      ans1 = (a1*1LL*b1);
    }
    else {
      int temp = abs(a-x);
      a1 = x;
      n1 -= temp;
      
      if(b1-n1 >= y){
        b1 -= n1;
      }
      else {
        b1 = y;
      }
      
      
      ans1 = (a1*1LL*b1);
    }
    
    if(b-n >= y) {
      b = b-n;
      
      ans2 = (a*1LL*b);
    }
    else {
      int temp = abs(b-y);
      b = y;
      n -= temp;
      
      if(a-n >= x){
        a -= n;
      }
      else {
        a = x;
      }   
      
      ans2 = (a*1LL*b);
    }
    
    cout << min(ans1, ans2) << '\n';
  }

  return 0;
}
