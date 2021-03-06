//
//  Change.cpp
//  changeTxt
//
//  Created by 孟令凯 on 2021/3/13.
//

#include "Change.hpp"
#include <iostream>
#include <ext/hash_map>
#include <ext/hash_set>
using namespace std;
using namespace __gnu_cxx;
void Change::squenceTxt(string str){
    fstream file;
    file.open(str+".txt",ios::in);
    int b,c;
    vector<vector<int>> num;
    while (!file.eof())            // 若未到文件结束一直循环
    {
        vector<int> a;

        if(file>>b>>c){
            a.push_back(b);
            a.push_back(c);

            num.push_back(a);
        }
    }
    file.close();
    
    std::cout<<"read"<<endl;

    sort(num.begin(),num.end());

    int l = (int)num.size();

    int i2 = 0;

    vector<int> mm;

    ofstream fout(str+"2.txt",ios::out);
    fout<<-1;
    for(int i = 0;i<l;i++){
        if(num[i][0] == i2){
            if(num[i][1]!=i2)
               mm.push_back(num[i][1]);
        }else{
            sort(mm.begin(),mm.end());

            for(int j = 0;j<mm.size();j++){
                fout<<"\n"<<i2<<" "<<mm[j];
            }
            mm.clear();
            i2 =num[i][0];
            if(num[i][1]!=i2)
               mm.push_back(num[i][1]);
        }
    }

    fout.close();
}

void Change::resolveTxt(const string str, const string output){
    ifstream infile;   //输入流
    int u,v;
    int n =0, m = 0;
    hash_map<int,vector<int>> outE;
    hash_map<int,vector<int>> inE;
    infile.open(str, ios::in);
    if (!infile.is_open()){
        cout<<"Open file failure"<<endl;
        exit(0);
    }
    while (!infile.eof())            // 若未到文件结束一直循环
    {
        infile >> u >> v;
        if(u == v) continue;
        m++;
        if(u>n) n = u;
        if(v>n) n = v;
        outE[u].push_back(v);
        inE[v].push_back(u);
    }
    infile.close();
    n++;
    
    ofstream fout(output+"/degree.txt",ios::out);
    
    fout<<n<<" "<<m;
    for(int i = 0;i<n;i++){
        fout<<"\n"<<outE[i].size()<<" "<<inE[i].size();
    }

    fout.close();
    
    ofstream fout2(output+"/out_edges.txt",ios::out);
    fout2<<1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<outE[i].size();j++){
            fout2<<"\n"<<outE[i][j];
        }
    }
    fout2.close();
    
    ofstream fout3(output+"/in_edges.txt",ios::out);
    fout3<<1;
    for(int i = 0;i<n;i++){
        sort(inE[i].begin(), inE[i].end());
        for(int j = 0;j<inE[i].size();j++)
            fout3<<"\n"<<inE[i][j];
    }
    fout3.close();
}

void Change::average_clustering_coefficient(string g){
    
}

void Change::Synthetic_Graph(string str, int num, int d){
    d++;
    int *judge = new int[num];
    for(int i = 0;i<num;i++){
        judge[i] = random(3);
    }
    ofstream fout(str,ios::out); //创建待写入数据文件
    for(int i = 0;i<num;i++){
        if(judge[i]>=d) continue;
        int out = random(d-judge[i]);
        int in = d-judge[i] -1;
        hash_set<int> outE;
        hash_set<int> inE;
        
        for(int j = 0;j<out;j++){
            int a = random(num);
            if(a == i || outE.find(a) != outE.end()){
                j--;
                continue;
            }
            fout<<"\n"<<i<<" "<<a;
            judge[a]++;
            outE.insert(a);
        }
        
        for(int j = 0;j<in;j++){
            int a = random(num);
            if(a == i || inE.find(a) != inE.end()){
                j--;
                continue;
            }
            fout<<"\n"<<a<<" "<<i;
            judge[a]++;
            inE.insert(a);
        }
    }
    fout.close();
}
