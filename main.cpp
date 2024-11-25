#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{
    return 0;
}

/*
n of 18
n of 21
n of 25
plank len = 60
1: 2. 18 + 21 + 25 = 64. 60 (25, 18, 17) + 60 (39, 21)
2: 3. at least 128 total length needed. We have 60 (21, 21, 18) + 60 (18, 42) + 60 (25, 25, 10). We need 18*2 (36) + 21*2 (42) + 25*2 (50).
3: 4. at least 192. 60*4: 60 (21, 21, 18) + 60 (21, 21, 18) + 60 (). 18*4 72 + 21*4 84 + 25*4 100

*/
