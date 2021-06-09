#include <bits/stdc++.h>

using namespace std;

class hamming
{
public:
    //Function that generates hamming code
    vector<int> generateHammingCode(
        vector<int> msgBits, int m, int r)
    {
        //Store the Hamming Code
        vector<int> hammingCode(r + m);
    
        //Find positions of redundant bits
        for (int i = 0; i < r; ++i) {
    
            //Placing -1 at redundant bits
            hammingCode[pow(2, i) - 1] = -1;
        }
    
        int j = 0;
    
        //Iterate to update the hamming code
        for (int i = 0; i < (r + m); i++) {
    
            //Placing msgBits where -1 is absent
            if (hammingCode[i] != -1) {
                hammingCode[i] = msgBits[j];
                j++;
            }
        }
    
        for (int i = 0; i < (r + m); i++) {
    
            //If current bit is not redundant bit then continue
            if (hammingCode[i] != -1)
                continue;
    
            int x = log2(i + 1);
            int one_count = 0;
    
            //Find msg bits containing set bit
            for (int j = i + 2;
                j <= (r + m); ++j) {
    
                if (j & (1 << x)) {
                    if (hammingCode[j - 1] == 1) {
                        one_count++;
                    }
                }
            }
    
            //Generating hamming code for even parity
            if (one_count % 2 == 0) {
                hammingCode[i] = 0;
            }
            else {
                hammingCode[i] = 1;
            }
        }
    
        //Return the generated code
        return hammingCode;
    }
    
    //Function that finds the hamming code of a given bits message
    hamming(vector<int>& msgBit)
    {
    
        //Message bit size
        int m = msgBit.size();
        int r = 1;
    
        //Find number of redundant bits
        while (pow(2, r) < (m + r + 1)) {
            r++;
        }
    
        //Generating Code
        vector<int> ans
            = generateHammingCode(msgBit, m, r);
    
        //Print the hamming code and message bits
        cout << "Message bits are: ";
        for (int i = 0; i < msgBit.size(); i++)
            cout << msgBit[i] << "";
    
        cout << "\nHamming code is: ";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << "";
        cout << endl;
    }
};