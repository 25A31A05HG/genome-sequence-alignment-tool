
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// Convert DNA sequence to uppercase and validate it
string normalizeDNA(string s) {
    for (char &c : s) {
        c = toupper(static_cast<unsigned char>(c));

        if (c != 'A' && c != 'T' &&
            c != 'G' && c != 'C') {
            throw invalid_argument(
                "Invalid DNA sequence. Use only A, T, G, C."
            );
        }
    }
    return s;
}

// Build the Dynamic Programming table
vector<vector<int>> buildDP(
    const string &a, const string &b
) {
    int m = static_cast<int>(a.size());
    int n = static_cast<int>(b.size());

    vector<vector<int>> dp(
        m + 1, vector<int>(n + 1, 0)
    );

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i][j - 1]
                );
            }
        }
    }

    return dp;
}

// Reconstruct the LCS using backtracking
string reconstructLCS(
    const string &a,
    const string &b,
    const vector<vector<int>> &dp
) {
    int i = static_cast<int>(a.size());
    int j = static_cast<int>(b.size());

    string lcs;

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs.push_back(a[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string seq1, seq2;

    cout << "=== Genome Sequence Alignment Tool ===\n";

    try {
        cout << "Enter first DNA sequence: ";
        cin >> seq1;

        cout << "Enter second DNA sequence: ";
        cin >> seq2;

        seq1 = normalizeDNA(seq1);
        seq2 = normalizeDNA(seq2);

        vector<vector<int>> dp = buildDP(seq1, seq2);

        string lcs = reconstructLCS(seq1, seq2, dp);

        cout << "\n--- Alignment Results ---\n";
        cout << "Sequence 1: " << seq1 << '\n';
        cout << "Sequence 2: " << seq2 << '\n';
        cout << "Longest Common Subsequence: "
             << lcs << '\n';
        cout << "LCS Length: " << lcs.size() << '\n';

        double similarity =
            100.0 * lcs.size() /
            max(seq1.size(), seq2.size());

        cout << "LCS-based similarity: "
             << similarity << "%\n";

    } catch (const exception &e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
