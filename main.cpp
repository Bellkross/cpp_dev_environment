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

int main() 
{
    int n;
    cin >> n;
    int* a = new int[n];
    unordered_map<int, int> points;
    set<int> integers;
    unordered_map<string, int> mem;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        integers.insert(a[i]);
        ++points[a[i]];
    }
    cout << boredom(integers, points, mem) << std::endl;
    return 0;
}