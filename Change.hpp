//
//  Change.hpp
//  changeTxt
//
//  Created by 孟令凯 on 2021/3/13.
//

#ifndef Change_hpp
#define Change_hpp

#include <stdio.h>
#include <fstream>
#include "string"
#include "vector"
#include <cstdlib>
#include <ctime>
#define random(x) rand()%(x)
using namespace std;

class Change{
public:
    void squenceTxt(string str);
    void resolveTxt(const string str, const string output);
    void average_clustering_coefficient(string g);
    void Synthetic_Graph(string str, int num, int d);
};

#endif /* Change_hpp */
