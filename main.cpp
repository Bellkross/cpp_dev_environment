#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string to_string(const set<int>& integers) 
{
    ostringstream oss;
    for (const int& i : integers) {
        oss << i << " ";
    }
    return oss.str();
}

// https://codeforces.com/problemset/problem/455/A
int boredom(set<int>& integers, const unordered_map<int, int>& points, unordered_map<string, int>& mem)
{
    string str_ints = to_string(integers);
    if (mem.count(str_ints)) {
        return mem[str_ints];
    }
    const vector<int> ints(integers.begin(), integers.end());
    if (ints.size() == 1) {
        return ints[0] * points.at(ints[0]);
    }
    int integers_size = ints.size();
    int res = 0;
    for (int i = 0; i < integers_size; ++i) {
        int removed = ints[i];
        int removed_points = removed * points.at(removed);
        vector<int> removed_integers;
        if (integers.count(removed - 1)) {
            removed_integers.push_back(removed - 1);
        }
        if (integers.count(removed + 1)) {
            removed_integers.push_back(removed + 1);
        }
        removed_integers.push_back(removed);
        integers.erase(removed - 1);
        integers.erase(removed);
        integers.erase(removed + 1);
        int curr = removed_points + boredom(integers, points, mem);
        if (curr > res) {
            res = curr;
        }
        for (const int ri : removed_integers) {
           integers.insert(ri); 
        }
    }
    mem[str_ints] = res;
    return res;
}

long b(const vector<long>& ints, const unordered_map<long, long>& points, int i, unordered_map<int, long>& mem) {
    if (i >= ints.size()) 
    {
        return 0;
    }
    if (mem.count(i) > 0)
    {
        return mem[i];
    }
    long curr = ints[i];
    long curr_points = curr * points.at(curr);
    int use_i = (i + 1 < ints.size() && ints[i + 1] == curr + 1) ? i + 2 : i + 1;
    long use = static_cast<long>(static_cast<long>(curr_points) + static_cast<long>(b(ints, points, use_i, mem)));
    long no_use = b(ints, points, i + 1, mem);
    mem[i] = max(use, no_use);
    return mem[i];
}

int main() 
{
    int n;
    cin >> n;
    long* a = new long[n];
    unordered_map<int, long> mem;
    unordered_map<long, long> points;
    set<long> integers;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        integers.insert(a[i]);
        ++points[a[i]];
    }
    vector<long> ints(integers.begin(), integers.end());
    cout << b(ints, points, 0, mem) << std::endl;
    return 0;
}