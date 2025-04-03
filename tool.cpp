#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MAX_LEN 16
#define INF INT_MAX / 2
#define UND -1

typedef unsigned int bit;
typedef vector<vector<int> > dp_t;
typedef vector<vector<int> > adjacency_t;
typedef adjacency_t adj_t;

#define COMB(n) (1 << (n)) //n bit combination
#define SEE(mask) bitset<(sizeof(bit)) * 8>(mask).to_string().substr(sizeof(bit) * 8 - n)

void print2DVector(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == INF) {
                printf("%4s", "INF");
                continue;
            } else if (v[i][j] == -1) {
                printf("%4s", " ");
            } else {
                printf("%4d", v[i][j]);
            }
        }
        cout << endl;
    }
}

void print1DVector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


#define count1(x) __builtin_popcount(x)
vector<bit> bitCombination(int n, int omit = 1) {
    vector<bit> all(COMB(n - omit));
    for (int i = 0; i < all.size(); i++) {
        all[i] = bit(i);
    }
    sort(all.begin(), all.end(), [](bit a, bit b) {
        return count1(a) < count1(b);
    });
    return all;
}


// void bitCombination(int n, int r, vector<bitset<MAX_LEN> > &setOfBitmasks) {
//     vector<bitset<MAX_LEN> > allBitmasks(1 << (n - 1));  // vector(8)
//     for (int i = 0; i < (1 << (n - 1)); i++) { // 
//         allBitmasks[i] = bitset<MAX_LEN>(i); // 000, 001, 010, 011, 100, 101, 110, 111
//     }
//     for (int i = 0; i < allBitmasks.size(); i++) { // 8
//         if (allBitmasks[i].count() == r) { 
//             setOfBitmasks.push_back(allBitmasks[i]);
//         }
//     }
//     sort(setOfBitmasks.begin(), setOfBitmasks.end(), [](bitset<MAX_LEN> a, bitset<MAX_LEN> b) {
//         return a.to_ulong() < b.to_ulong();
//     });
    
// }