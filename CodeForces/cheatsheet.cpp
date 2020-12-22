//Compile via: g++ -std=c++11 -O2 -Wall test.cpp -o test


// Template
#include <bits/stdc++.h>

using namespace std;

int main() {

}

// Speed up cin/ cout
ios::sync_with_stdio(0);
cin.tie(0);

// Get a full line with all spaces
string s;
getline(cin, s);

// I don't know how many, keep reading
while (cin >> x) {
// code
}

// Bind stdin to file and stdout to file
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

// When shit hits the fan
__int128_t // (128 bit long number)

// Shortening long long
typedef long long ll;
// And others
typedef vector<int> vi;
typedef pair<int,int> pi;


// For example, we can define the following macros:
#define F first
#define S second
#define PB push_back
#define MP make_pair
// After this, the code
v.push_back(make_pair(y1,x1));
v.push_back(make_pair(y2,x2));
int d = v[i].first+v[i].second;
// can be shortened as follows:
v.PB(MP(y1,x1));
v.PB(MP(y2,x2));
int d = v[i].F+v[i].S;
// A macro can also have parameters which makes it possible to shorten loops
// and other structures. For example, we can define the following macro:
#define REP(i,a,b) for (int i = a; i <= b; i++)
// After this, the code
for (int i = 1; i <= n; i++) {
    search(i);
}
// can be shortened as follows:
REP(i,1,n) {
    search(i);
}
// Sometimes macros cause bugs that may be difficult to detect. For example,
// consider the following macro that calculates the square of a number:
#define SQ(a) a*a
// This macro does not always work as expected. For example, the code
cout << SQ(3+3) << "\n";
// corresponds to the code
cout << 3+3*3+3 << "\n"; // 15
// A better version of the macro is as follows:
#define SQ(a) (a)*(a)
// Now the code
cout << SQ(3+3) << "\n";
// corresponds to the code
cout << (3+3)*(3+3) << "\n"; // 36

// Sortings
// Init
int n = 7; // array size
int a[] = {4,2,5,3,5,8,3};
vector<int> v = {4,2,5,3,5,8,3};
string s = "monkey";

// Sort
sort(v.begin(),v.end());
sort(a,a+n);
sort(s.begin(), s.end());

// Reverse
sort(v.rbegin(),v.rend());

// User defined comparison operator for sort
struct P {
    int x, y;
    bool operator<(const P &p) {
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
};

// Example with comparison function
bool comp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}
// Now a vector of strings can be sorted as follows:
sort(v.begin(), v.end(), comp);

// debug a vector:
# define deb_v(x) cerr << $x << " = [("; \
    for (auto item: x) cerr << a[i] << " "; \
    cerr << ")\n";
