#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

typedef long long ll;

vector<ll> Nvi;
vector<ll> Mvi;

ll binary_search_index(vector<ll> v, ll data, bool flag)
{
    // auto it = lower_bound(v.begin(), v.end(), data);
    // if (flag)
    //     it = upper_bound(v.begin(), v.end(), data);
    // if (it == v.end()) {
    //     return -1;
    // } else {
    //     printf("index: %lld\n", distance(v.begin(), it));
    //     return distance(v.begin(), it); // изменить на O(1)
    // }
    ll counter = 0;
    for (const auto& i : v) {
        if (flag) {
            if (i >= data) counter++;
        } else {
            if (i <= data) counter++;            
        }
    }
    return counter;
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
    ll min_cost = min(Nvi[0], Mvi[0]);
    ll max_cost = max(*(Nvi.end() - 1), *(Mvi.end() - 1));
    ll trade = -1;
    ll cost = -1;
    ll a = 0, b = 0;
    printf("min_cost: %lld\n", min_cost);
    printf("max_cost: %lld\n\n", max_cost);
    vector<ll> NMunion_v; 
    set_union(Nvi.begin(), Nvi.end(),
        Mvi.begin(), Mvi.end(),
        back_inserter(NMunion_v));
    set<ll> NMunion(NMunion_v.begin(), NMunion_v.end());
    for (const auto &i_cost : NMunion) {
        a = binary_search_index(Nvi, i_cost, false);
        b = binary_search_index(Mvi, i_cost, true);
        if (trade < (min(a, b) * i_cost)) {
            trade = min(a, b) * i_cost;
            cost = i_cost;
        }
        printf("i_cost: %lld\n", i_cost);
        printf("a i_cost: %lld\n", a);
        printf("b i_cost: %lld\n", b);
        printf("TRADE: %lld\n\n", trade);
    }
    printf("%lld %lld\n", cost, trade);
    return 0;
}