class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiouAEIOU";
        string vowelList = "";

        
        for (int i = 0; i < s.size(); i++) {
            if (vowels.find(s[i]) != string::npos) {
                vowelList += s[i];
            }
        }

        
        sort(vowelList.begin(), vowelList.end());

        int index = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (vowels.find(s[i]) != string::npos) {
                s[i] = vowelList[index];
                index++;
            }
        }

        return s;
    }
};
