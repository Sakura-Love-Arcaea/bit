#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>


#include "./tool.cpp"

using namespace std;

typedef unsigned int bit;
typedef vector<vector<int> > dp_t;
typedef vector<vector<int> > adjacency_t;
typedef adjacency_t adj_t;

#define COMB(n) (1 << (n)) //n bit combination
#define SEE(mask, n) bitset<(sizeof(bit)) * 8>(mask).to_string().substr(sizeof(bit) * 8 - n)


adj_t adjacency = {
    {0, 2, 9, INF},
    {1, 0, 6, 4},
    {INF, 7, 0, 8},
    {6, 3, INF, 0}
};

int main() {
    int n; // # of vertices
    // cin >> n;
    n = 4;
    const bit mask = ~((1 << n) - 1); // 2^n - 1
    const bit max = ~0;

    dp_t dp(n, vector<int>(COMB(n - 1), INF)); // omit bit leftmost

    

    vector<bit> c = bitCombination(n, 1);
    for (int i = 0; i < c.size(); i++) {
        cout << SEE(c[i], n) << endl;
    }
    #define ORDER(x) 1 << x
    #define REMOVE(a, order) a ^ order
    #define HAVE(a, order) a & order

    // bit example = 0b0011; // 已經去除vi 算min的。
    // for (int i = 0; i < n; i++) {
    //     bit order = ORDER(i);
    //     if (HAVE(example, order)) {
    //         cout << "vi to " << SEE(order, n) << " , pass " << SEE(REMOVE(example, order), n) << endl;
    //     }
    // }

    bit example2 = 0b0011;
    bit passInv = ~example2;
    cout << SEE(passInv, n) << endl;






}