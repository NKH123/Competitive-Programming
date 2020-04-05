#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int pa=0, pb=0, pc=0;
        string s="";
        while(!(pa==a && pb==b && pc==c)){
            pa=a, pb=b, pc=c;
            if(a>=b && a>=c){
                if(s.size()>=2){
                    if(s[0]=='a' && s[1]=='a'){
                        if(b>=c){
                            if(b>=1){
                                s="b"+s;
                                b-=1;
                            }
                        }
                        else{
                            if(c>=1){
                                s="c"+s;
                                c-=1;
                            }
                        }
                    }
                    else{
                        if(a>=2){
                            s="aa"+s;
                            a-=2;
                        }
                        else if(a>=1){
                            s="a"+s;
                            a-=1;
                        }
                    }
                }
                else{
                    if(a>=2){
                        s="aa"+s;
                        a-=2;
                    }
                    else if(a>=1){
                        s="a"+s;
                        a-=1;
                    }
                }
            }
            else if(b>=a && b>=c){
                if(s.size()>=2){
                    if(s[0]=='b' && s[1]=='b'){
                        if(a>=c){
                            if(a>=1){
                            s="a"+s;
                            a-=1;
                        }
                        }
                        else{
                            if(c>=1){
                            s="c"+s;
                            c-=1;
                        }
                        }
                    }
                    else{
                        if(b>=2){
                        s="bb"+s;
                        b-=2;
                    }
                    else if(b>=1){
                        s="b"+s;
                        b-=1;
                    }
                    }
                }
                else{
                    if(b>=2){
                        s="bb"+s;
                        b-=2;
                    }
                    else if(b>=1){
                        s="b"+s;
                        b-=1;
                    }
                }
                
            }
            else if(c>=a && c>=b){
                if(s.size()>=2){
                    if(s[0]=='c' && s[1]=='c'){
                        if(b>=a){
                            if(b>=1){
                            s="b"+s;
                            b-=1;
                        }
                        }
                        else{
                            if(a>=1){
                            s="a"+s;
                            a-=1;
                        }
                        }
                    }
                    else{
                        if(c>=2){
                        s="cc"+s;
                        c-=2;
                    }
                    else if(c>=1){
                        s="c"+s;
                        c-=1;
                    }
                    }
                }
                else{
                    if(c>=2){
                        s="cc"+s;
                        c-=2;
                    }
                    else if(c>=1){
                        s="c"+s;
                        c-=1;
                    }
                }
            }
            if(a==0 && b==0 && c==0){
                break;
            }
        }
        
        
        return s;
    }
};