/*
因为 F(i,c) = max(F(i-1,c),v(i)+F(i-1,c-w(i))
第一行元素只依赖于第i-1行元素。所以，表格只需要维持两行即可，即优化空间复杂度O(2*C) = O(C)
轮流使用上下两行，上面一行处理偶数行，下面一行处理偶数行

*/

#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

class Knapsack01{

public:
    int Knapsackup(const vector<int> &w,const vector<int> &v,int C){
        int n = w.size();
        if(n==0||C==0) return 0;
        vector<vector<int> > memo(2,vector<int>(C+1,-1));
        for(int j=0;j<=C;j++){
            memo[0][j] = (j>=w[0]?v[0]:0);
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=C;j++){
                memo[i%2][j] = memo[(i-1)%2][j];
                if(j>=w[i]){
                    memo[i%2][j] = max(memo[i%2][j],v[i]+memo[(i-1)%2][j-w[i]]);
                }
            }
        }
        return memo[(n-1)%2][C];
    }
};

int main(){
    vector<int> weight;
    vector<int> value;
    int wa[3] = {1,2,3};
    int va[3] = {6,10,12};
    for(int i=0;i<3;i++){
        weight.push_back(wa[i]);
        value.push_back(va[i]);
    }
    int bv = Knapsack01().Knapsack(weight,value,5);
    cout<<bv<<endl;
    return 0;
}
