#include <iostream>
#include <vector>
#include <map>


int main() {
    int n = 0, k = 0;
    int temp;
    int c[300005] = {0};
    std::vector<int>v;
    std::cin >> n >> k;
    std::map<int, int>mp;

//    for(int i = 0; i < n; i++) std::cin >> v[i];
//    for(int i = 0; i < k; i++) mp[v[i]]++;
    for(int i = 0; i < n; i++) {
        std::cin >> temp;
        v.push_back(temp);
    }
    for(int i = 0; i < k; i++) mp[v[i]]++;
    size_t max = mp.size();
    for (int i = 0; i < n - k; i++) {
        mp[v[i + k]]++;
        mp[v[i]]--;
        if (mp[v[i]] == 0) {
            mp.erase(v[i]);
        }
        if (mp.size() > max) {
            max = mp.size();
        }
    }
    std::cout << max << std::endl;
    return 0;
}
