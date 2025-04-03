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
#define SEE(mask) bitset<(sizeof(bit)) * 8>(mask).to_string().substr(sizeof(bit) * 8 - n)

#define SHIFT(x) 1 << x
#define LEFTMASK(x) 1 << (n - 1)
#define REMOVE(a, order) (a ^ order)
#define ISONE(a, order) (a & order)


adj_t adjacency_o = {
    {0, 2, 9, INF},
    {1, 0, 6, 4},
    {INF, 7, 0, 8},
    {6, 3, INF, 0}
};

// adj horizontal filp and vertical flip call adj_sp
adj_t adjacency = {
    {0, INF, 3, 6},
    {8, 0, 7, INF},
    {4, 6, 0, 1},
    {INF, 9, 2, 0}
};




int main() {
    int n; // # of vertices
    // cin >> n;
    n = 4;
    const bit mask = ~((1 << n) - 1); // 2^n - 1
    const bit max = ~0;

    dp_t dp(n, vector<int>(COMB(n - 1), UND)); // omit bit leftmost

    

    
    

    vector<bit> c = bitCombination(n, 1);
    for (int i = 0; i < c.size(); i++) {
        bit subset = c[i]; 
        cout << "subset: " << SEE(subset) << endl;
        bit passes = (i != c.size() - 1) ? (subset | LEFTMASK(n)) : subset; // when not last, pass v1
        for (int i = 0; i < n; i++) {
            bit possible = SHIFT(i); 
            if (!ISONE(passes, possible)) {
                cout << "dp[" << i << "]" << "[{" << SEE(subset) << "}]=";
                if (subset != 0b0) {
                    int min = INF;
                    cout << "min(" << endl;
                    for (int j = 0; j < n; j++) {
                        bit s = SHIFT(j);
                        if (ISONE(subset, s)) {
                            cout << "\tadjacency[" << i << "][" << j << "] , + pass " << SEE(REMOVE(subset, s)) << " aka dp[" << j << "][" << REMOVE(subset, s) << "]";
                            cout << " = " << adjacency[i][j]+dp[j][REMOVE(subset, s)] << endl;
                            if (adjacency[i][j] + dp[j][REMOVE(subset, s)] < min) {
                                min = adjacency[i][j] + dp[j][REMOVE(subset, s)];
                            }
                        }
                    }
                    cout << ")\n";
                    dp[i][subset] = min;
                } else {
                    cout << "\tadjacency[" << i << "][" << n-1 << "]";
                    cout << adjacency[i][n-1] << endl;
                    dp[i][subset] = adjacency[i][n-1];
                }
            }
        }
    }
    
    cout << "ans: " << dp[n-1][COMB(n-1)-1] << endl;


}
    






