//
//  main.cpp
//  reverseWordsMac
//
//  Created by 黄美强 on 15/9/29.
//  Copyright (c) 2015年 黄 美强. All rights reserved.
//
#include <iostream>

using namespace std;


void reduceSpace(string &s) {
    //reduce space first
    int i = 0;
    while(i<s.size() && s.at(i) == ' '){
        s.erase(s.begin() + i);
    }
    if(s.size() == 0){
        return;
    }
    bool lastS = false;
    for(int i = 1; i<s.size(); i++){
        if(!lastS){
            if(s.at(i) == ' '){
                lastS = true;
            }
            else
                lastS = false;
        }else{
            if(s.at(i) == ' '){
                s.erase(s.begin()+i);
                i--;
            }else{
                lastS = false;
            }
        }
    }
    if(s.at(s.size()-1) == ' '){
        s.erase(s.end()-1);
    }
}
void reverseWords(string &s) {
    reduceSpace(s);
    int i = 0;
    int icount = 0;
    int j = s.size()-1;
    int jcount = 0;
    while(j>i){
        while(i<s.size() && s.at(i) != ' '){
            i++;
            icount++;
        }
        while(j>=0 && s.at(j) != ' '){
            j--;
            jcount++;
        }
        if(i>j){
            return;
        }
        int diff = jcount - icount;
        string wordl = s.substr(j+1,jcount);
        string words = s.substr(i-icount,icount);
        if(diff>0){
            for(int k = j; k >= i; k--){
                s.at(k + diff) = s.at(k);
            }
        }else{
            for(int k = i; k <= j; k++){
                s.at(k + diff) = s.at(k);
            }
        }
        for(int k = 0; k<icount; k++){
            s.at(j+jcount-k) = words.at(icount-1-k);
        }
        for(int k = 0; k<jcount; k++){
            s.at(i-icount + k) = wordl.at(k);
        }
        i = i+diff+1;
        j = j+diff-1;
        icount = 0;
        jcount = 0;
    }
    
}

int main() {
    string s = "hi!";
    reverseWords(s);
    cout << 'S' << s.c_str() <<'E'<< endl;
    return 0;
}

