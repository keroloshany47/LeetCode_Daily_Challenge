class Solution {
public:
    int maxFreqSum(string s) {
        
        int freq[26]; 
        for (int i = 0; i < 26; i++) {
            freq[i] = 0; 
        }

        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            int index = c - 'a'; 
            freq[index] = freq[index] + 1; 
        }

        
        int maxVowel = 0;
        int maxConsonant = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue; 

            char c = 'a' + i; 

            
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                if (freq[i] > maxVowel) {
                    maxVowel = freq[i];
                }
            } else { 
                if (freq[i] > maxConsonant) {
                    maxConsonant = freq[i];
                }
            }
        }

        
        return maxVowel + maxConsonant;
    }
};
