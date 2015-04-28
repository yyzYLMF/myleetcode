/*
 * @yang 2015/4/27
 *
 * Count the number of prime numbers less than a non-negative number, n
 *
 * Hint: The number n could be in the order of 100,000 to 5,000,000.
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

//TLE
class Solution {
    public:
    bool isPrime(vector<int> sushu, int chidu, int num) {
        int i;
        for(i=0;i<chidu;++i) {
            if((num)%(sushu[i])==0)
                break;
        }
        if(i<chidu)
            return false;
        else
            return true;
    }
    
    int countPrimes(int n) {
        vector<int> sushu;
        int chidu,i,j;
        int ret=0;
        int bianjie;

        sushu.push_back(2);
        sushu.push_back(3);
        sushu.push_back(5);
        sushu.push_back(7);
        if(n<=10) {
            for(i=2;i<=n;++i) {
                if(i==2 || i==3 || i==5 || i==7)
                    ret++;
            }
            return ret;
        }
        else {
            chidu = 4;
            bianjie = 100;
            ret = 4;
            for(i=11;i<=n;i=i+2) {
                if(i>=bianjie) {
                    bianjie *=10;
                    chidu=sushu.size();
                }
                if(isPrime(sushu,chidu,i)) {
                    sushu.push_back(i);
                    ret++;
                }
            }
            return ret;
        }
    }
};

//AC
class Solution2 {
    public:
    int countPrimes(int n) {
        int i,j,ret;
        //vector<int> primes;
        int m=sqrt(n+1);
        int *sign;
        sign = new int[n];
        memset(sign,0,n*sizeof(int));
        
        for(i=2;i<=m;++i) {
            if(!sign[i]) {
                for(j=i*i;j<n;j+=i) {
                    sign[j]=1;
                }
            }
        }
        ret=0;
        for(i=2;i<n;++i)
            if(sign[i]==0)
                ret++;
        return ret;
    }
};

int main() {
    Solution2 solu;
    int num;
    while(cin>>num)
        cout<<solu.countPrimes(num)<<endl;
    return 0;
}
