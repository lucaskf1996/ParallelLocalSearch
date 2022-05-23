#include<iostream>
#include <random>
#include<algorithm>
#include<fstream>  
#include<bits/stdc++.h>

// CHECK IF PAIR IS EQUAL
int checkPair(char c1, char c2, int wmat, int wmis, int score){
    if(c1==c2){
        return wmat;
    }
    else{
        return wmis;
    }
}

int main(){
    int n, m;
    int wmat = 2;
    int wmis = -1;
    int wgap = -1;
    int k, p, j, score;

    std::string a, b;
    std::string bestA, bestB;
    std::cin >> n;
    std::cin >> m;
    std::cin >> a;
    std::cin >> b;

    std::random_device rd;
    std::uniform_int_distribution<int> distribution2(1,m);
    std::uniform_int_distribution<int> distribution1(1,n);
    std::uniform_int_distribution<int> distribution3(20,std::sqrt(2*n*m));
    std::string subA, subB;
    int max_score;

    if(n>m){ 
        max_score = -n*2;
    }
    else{
        max_score = -m*2;
    }

    int rounds = 10000;

    std::time_t start, end;
  
    time(&start);
    
    for(int round = 0; round<rounds; round++){
        if(n>m){
            k = distribution2(rd);
        }
        else{
            k = distribution1(rd);
        }
        std::uniform_int_distribution<int> distribution21(0,m-k);
        subA = a.substr(0,k);
        p = distribution3(rd);
        for(int i = 0; i < p; i++){
            score = 0;
            j = distribution21(rd);
            subB = b.substr(j,k);
            // std::cout << subA.length() << "  " << subB.length() << "  " << k << "  " << j << std::endl;
            for(int index = 0; index < k; index++){
                score += checkPair(subA[index], subB[index], wmat, wmis, score);
            }
            // scoreList[i] = score;
            if(score > max_score){
                max_score = score;
                bestA = subA;
                bestB = subB;
            }
        }
    }
    time(&end);
    std::ofstream outfile ("output.txt");
    double time_taken = double(end - start);
    outfile << "Time taken by program is : " << time_taken << std::setprecision(5) << std::endl;
    outfile << max_score << std::endl << "bestA: " << bestA << std::endl << "bestB: " << bestB << std::endl;
    outfile.close();
}