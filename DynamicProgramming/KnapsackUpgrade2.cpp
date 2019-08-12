#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

class Knapsack01{

public:
    int Kanpsasckup2(const vector<int> &w,const vector<int> &v,int C){
        if(w.size()!=v.size()) return 0;
        int n = w.size();
        if(n==0||C==0) return 0;
        
        vector<int> memo(C+1,-1);
        
        for(int j=0;j<=C;j++){
            memo[j] = (j>= w[0]?v[0]:0);
        }        
        for(int i=1;i<n;i++){
            // 如果j小于w[i]，说明物品已经不能放入背包中了
            for(int j=C;j>=w[i];j--){
                // 从后向前进行判断
                memo[j] = max(memo[j],v[i]+memo[j-w[i]]);
            }
        }
        return memo[C];
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
    int bv = Knapsack01().Kanpsasckup2(weight,value,5);
    cout<<bv<<endl;
    return 0;
}
