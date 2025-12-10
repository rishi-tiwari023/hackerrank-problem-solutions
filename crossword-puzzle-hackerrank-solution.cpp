#include <bits/stdc++.h>
using namespace std;

struct Gap {
    Gap(int x, int y, int l, bool acr) : row(x), col(y), len(l), across(acr) {}

    int row;
    int col;
    int len;
    bool across;
};

bool operator==(const Gap &lhs, const Gap &rhs) {
    return ((lhs.row == rhs.row) && (lhs.col == rhs.col) && (lhs.len == rhs.len) && (lhs.across == rhs.across));
}

ostream &operator<<(ostream &os, const Gap &g) {
    return os << "{" << g.row << ", " << g.col << ", " << g.len << ", " << g.across << "}";
}

pair<vector<vector<char>>, bool> solve(vector<vector<char>> M, vector<Gap> g, vector<string> w) {
    if (w.empty()) return make_pair(M, true);

    // Over all gaps
    for (int i = 0; i < g.size(); ++i) {
        // Try every remaining word
        for (int j = 0; j < w.size(); ++j) {
            Gap gg = g[i];
            if (gg.len != static_cast<int>(w[j].size())) continue;

            vector<vector<char>> MM = M;  // Copy of M

            // Every character of the gap
            if (gg.across) {
                bool success = true;
                for (int k = 0; k < gg.len; ++k) {
                    if (MM[gg.row][gg.col + k] == '-') MM[gg.row][gg.col + k] = w[j][k];
                    else if (MM[gg.row][gg.col + k] != w[j][k]) success = false;
                }

                if (success) {
                    vector<Gap> gg_vec = g;
                    gg_vec.erase(gg_vec.begin() + i);
                    vector<string> ww = w;
                    ww.erase(ww.begin() + j);
                    pair<vector<vector<char>>, bool> x = solve(MM, gg_vec, ww);
                    if (x.second) return x;
                }
            } else {
                bool success = true;
                for (int k = 0; k < gg.len; ++k) {
                    if (MM[gg.row + k][gg.col] == '-') MM[gg.row + k][gg.col] = w[j][k];
                    else if (MM[gg.row + k][gg.col] != w[j][k]) success = false;
                }

                if (success) {
                    vector<Gap> gg_vec = g;
                    gg_vec.erase(gg_vec.begin() + i);
                    vector<string> ww = w;
                    ww.erase(ww.begin() + j);
                    pair<vector<vector<char>>, bool> x = solve(MM, gg_vec, ww);
                    if (x.second) return x;
                }
            }
        }
    }

    return make_pair(M, false);
}

vector<Gap> find_gaps(const vector<vector<char>> &M) {
    vector<Gap> gaps;

    // row wise iteration
    for (int row = 0; row < static_cast<int>(M.size()); ++row) {
        int start = -1;
        int stop = -1;
        if (M[row][0] == '-') {
            start = 0;
            stop = 0;
        }

        int col = 1;
        for (col = 1; col < static_cast<int>(M[row].size()); ++col) {
            if ((M[row][col] != M[row][col - 1]) && (start == -1)) {
                start = col;
            } else if (M[row][col] != M[row][col - 1]) {
                stop = col - 1;
                if (stop > start) {
                    gaps.push_back(Gap(row, start, stop - start + 1, true));
                }

                start = -1;
                stop = -1;
            }
        }

        stop = col - 1;
        if ((M[row][stop] == '-') && (stop > start)) {
            gaps.push_back(Gap(row, start, stop - start + 1, true));
        }
    }

    // column wise iteration
    for (int col = 0; col < static_cast<int>(M[0].size()); ++col) {
        int start = -1;
        int stop = -1;
        if (M[0][col] == '-') {
            start = 0;
            stop = 0;
        }

        int row = 1;
        for (row = 1; row < static_cast<int>(M.size()); ++row) {
            if ((M[row][col] != M[row - 1][col]) && (start == -1)) {
                start = row;
            } else if (M[row][col] != M[row - 1][col]) {
                stop = row - 1;
                if (stop > start) {
                    gaps.push_back(Gap(start, col, stop - start + 1, false));
                }

                start = -1;
                stop = -1;
            }
        }

        stop = row - 1;
        if ((start > -1) && (M[stop][col] == '-') && (stop > start)) {
            gaps.push_back(Gap(start, col, stop - start + 1, false));
        }
    }

    return gaps;
}

vector<string> vectorize(const string &words) {
    int start = 0;
    int stop = 0;
    vector<string> out;

    for (int idx = 0; idx < static_cast<int>(words.size()); ++idx) {
        if (words[idx] == ';') {
            out.push_back(words.substr(start, idx - start));
            start = idx + 1;
        }
    }

    // Push the last word
    out.push_back(words.substr(start, stop - start + words.size() - stop));

    return out;
}

int main() {
    vector<vector<char>> M(10, vector<char>(10, ' '));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> M[i][j];
        }
    }

    vector<Gap> gaps = find_gaps(M);

    string words;
    cin >> words;
    vector<string> w = vectorize(words);

    pair<vector<vector<char>>, bool> x = solve(M, gaps, w);
    if (x.second) {
        vector<vector<char>> &m = x.first;
        for (const auto &v : m) {
            for (char c : v) cout << c;
            cout << '\n';
        }
    }
    return 0;
}

