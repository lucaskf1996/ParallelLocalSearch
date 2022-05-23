#include<iostream>
#include <random>
#include<algorithm>
#include<fstream>  
#include<omp.h>
#include<bits/stdc++.h>
#include <vector>


// CHECK IF PAIR IS EQUAL
int checkPair(char c1, char c2, int wmat, int wmis, int score){
    if(c1==c2){
        return wmat;
    }
    else{
        return wmis;
    }
}

std::string generate_subsequence_b(std::string seq, int k, int seqSize){
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(0, seqSize-k);

    int index = distribution(rd);

    return seq.substr(index, k);
}

int generate_k(int n, int m){
    std::uniform_int_distribution<int> distribution2(1,m);
    std::uniform_int_distribution<int> distribution1(1,n);
    std::random_device rd;
    if(n>m){
        return distribution2(rd);
    }
    else{
        return distribution1(rd);
    }
}

int generate_p(int m){
    std::uniform_int_distribution<int> distribution2(1,m);
    std::random_device rd;
    return distribution2(rd);
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

    std::vector<std::default_random_engine> engines;
    std::random_device random;
    std::default_random_engine generator1(random());
    engines.push_back(generator1);
    std::default_random_engine generator2(random());
    engines.push_back(generator2);
    std::default_random_engine generator3(random());
    engines.push_back(generator3);
    std::default_random_engine generator4(random());
    engines.push_back(generator4);

    int max_score;
    
    if(n>m){ 
        max_score = -n*2;
    }
    else{
        max_score = -m*2;
    }
    int rounds = 10000;

    std::time_t start, end;
    std::uniform_int_distribution<int> distribution2(1,m);
    std::uniform_int_distribution<int> distribution1(1,n);
    std::uniform_int_distribution<int> distribution3(20,std::sqrt(2*n*m));
    // int omp_get_thread_num();
    // time(&start);
    #pragma omp parallel for shared(bestA, bestB, max_score) firstprivate(a, b)
    {
        for(int round = 0; round<rounds; round++){
            if(n>m){ 
                k = distribution2(engines[round%4]);
            }
            else{
                k = distribution1(engines[round%4]);
            }
            std::uniform_int_distribution<int> distribution(0, m-k);
            std::string subA = a.substr(0, k);
            p = distribution3(engines[round%4]);
            for(int i = 0; i < p; i++){
                // std::cout << i << std::endl;
                score = 0;
                int j = distribution(engines[round%4]);
                std::string subB = b.substr(j, k);
                for(int index = 0; index < k; index++){
                    if(subA[index]==subB[index]){
                        score += wmat;
                    }
                    else{
                        score += wmis;
                    }
                    // score += checkPair(subA[index], subB[index], wmat, wmis, score);
                }

                #pragma omp critical
                {
                    if(score > max_score){
                        max_score = score;
                        bestA = subA;
                        bestB = subB;
                    }
                }
            }
        }
    }
    // time(&end);
    // std::ofstream outfile ("output.txt");
    // double time_taken = double(end - start);
    // outfile << "Time taken by program is : " << time_taken << std::setprecision(5) << std::endl;
    // outfile << max_score << std::endl << "bestA: " << bestA << std::endl << "bestB: " << bestB << std::endl;
    // outfile.close();
}