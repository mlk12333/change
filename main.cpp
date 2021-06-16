//
//  main.cpp
//  changeTxt
//
//  Created by 孟令凯 on 2021/3/10.
//

#include <iostream>
#include "string"
#include "Change.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
//    if(argc<1) return 1;
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    string str = "/Users/milk/test_data/zata/index-paper.txt";
//    string str2 = "/Users/milk/test_data/zata/s_graph/graph.txt";
//    string output = "/Users/milk/test_data/zata/index-paper";
    
    Change change;
    int a;
    cin>>a;
    
    if(a == 1){
        string s;
        int num, d;
        cin>>s>>num>>d;
        change.Synthetic_Graph(s, num, d);//删掉第一行
    }
    else if(a == 2){
        string s;
        cin>>s;
        change.squenceTxt(s);//删掉第一行
    }else{
        string str, output;
        cin>>str>>output;
        change.resolveTxt(str, output);
    }
    
    
    
    
    
    
    
       
    return 0;
}
