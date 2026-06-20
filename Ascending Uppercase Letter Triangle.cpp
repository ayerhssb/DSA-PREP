#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    void printLetterTriangle(int n) {
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout<<char('A'+j)<<" ";
            }
            cout<<"\n";
        }
    }
};
