#include <bits/stdc++.h>
using namespace std;

class solution {
public:    
    bool canArrangeBooks(vector<int>& books, int shelfSize) {
        int n=books.size();
        if(n%shelfSize!=0){return false;}
        sort(books.begin(),books.end());
        int i=0;
        while(i<n){
            int t=shelfSize-1;
            while(t--){
                if(books[i]+1!=books[i+1]){return false;}
            }
            i=shelfSize+i;
        }
        return true;
        
    }
};
