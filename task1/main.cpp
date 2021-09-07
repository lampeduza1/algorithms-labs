#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> Nvi;
vector<ll> Mvi;

//struct greater
//{
//  template<class T>
//  bool operator()(T const &a, T const &b) const { return a > b; }
//};

ll binary_search_index(vector<ll> v, ll data)
{
    auto it = lower_bound(v.begin(), v.end(), data);
    if (it == v.end() || *it != data) {
        return -1;
    } else {
        return distance(v.begin(), it);
    }
}

int main()
{
    ll N, M;
    scanf("%lld %lld", &N, &M);
    ll temp = 0;
    while (N--) {
        scanf("%lld", &temp);
        Nvi.push_back(temp);
    }
    while (M--) {
        scanf("%lld", &temp);
        Mvi.push_back(temp);
    }
    sort(Nvi.begin(), Nvi.end());
    sort(Mvi.begin(), Mvi.end());
    ll min_cost = Mvi[0];
    ll max_cost = *(Nvi.end() - 1);
    ll trade = -1;
    ll cost = -1;
    for (ll i_cost = min_cost; i_cost <= max_cost; i_cost++) {
        ll index_a = binary_search_index(Nvi, i_cost);
        ll a = 0;
        if (index_a != -1) a = index_a + 1;
        ll index_b = binary_search_index(Mvi, i_cost);
        ll b = 0;
        if (index_b != -1) b = Mvi.size() - (index_b + 1);
        if (trade < (min(a, b) * i_cost)) {
            trade = min(a, b) * i_cost;
            cost = i_cost;
        }
    }
    printf("%lld %lld\n", cost, trade);
    return 0;
}