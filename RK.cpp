#include<iostream>
using namespace std;

class RabinKarp {
    const int PRIME = 31;  // Prime base for hashing
    const int MOD = 1009;  // Modulus for hashing

    // Function to calculate the hash value of a string
    long long calculateHash(const string& str, int length) {
        long long hash = 0;
        for (int i = 0; i < length; i++) {
            hash = (hash * PRIME + str[i]) % MOD;  // Rolling hash calculation
        }
        return hash;
    }

    // Function to update the hash when sliding the window
    long long updateHash(long long prevHash, char oldChar, char newChar, int patternLength) {
        prevHash = (prevHash - oldChar + MOD) % MOD;  // Remove oldChar's effect
        prevHash = (prevHash * PRIME + newChar) % MOD;  // Add newChar's effect
        return prevHash;
    }

public:
    // Function to search for the pattern in the text
    void search(const string& text, const string& pattern) {
        int n = text.length();
        int m = pattern.length();

        if (n < m) return;  

        long long patternHash = calculateHash(pattern, m);  
        long long textHash = calculateHash(text, m); 
        for (int i = 0; i <= n - m; i++) {
            // If the hashes match, check the actual substring to avoid collisions
            if (textHash == patternHash && text.substr(i, m) == pattern) {
                cout << "Pattern found at index " << i << endl;
            }

            // Update the hash for the next window of the text
            if (i < n - m) {
                textHash = updateHash(textHash, text[i], text[i + m], m);
            }
        }
    }
};

int main() {
    RabinKarp rk;
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";
    rk.search(text, pattern);  // Searching for the pattern "GEEK" in the given text
    return 0;
}

