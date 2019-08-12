/*
01背包问题是一个比较简单的动态规划问题，本意是给定物品的重量和价值，以及背包的容量，在物品都只有一件的情况下，求出背包能装的物品的最大价值
时间复杂度是O(n*C);
空间复杂度是O(n*C);
*/
#include<iostream>
#include<vector>
using namespace std;

class Knapsack01{

public:
    int Knapsack(const vector<int> &w,const vector<int> &v,int C){
        // 保证传入的数据是正确的
        if(w.size()!=v.size()) return 0;
        int n = w.size();
        // 如果传入的物品数量为0，直接返回0
        if(n==0) return 0;
        
        
        // 自底向上的表格
        vector<vector<int> > memo(n,vector<int>(C+1,-1));
        
        // 初始化第一行，得到相应的数值，这是说明是否拿第一个物品，只要容量大于第一个物品
        for(int j=0;j<=C;j++){
            memo[0][j] = (j>=w[0]?v[0]:0);
        }
        
        // 开始动态规划，从第一行开始，即开始考虑其他剩下的物品
        for(int i=1;i<n;i++){
            // 遍历容量
            for(int j=0;j<=C;j++){
                // 先不考虑当前的物品重量与背包的重量，直接将上面的值赋值
                memo[i][j] = memo[i-1][j];
                // 考虑第i个物品和容量之间的关系
                if(j>=w[i]){
                    // 判断当前背包的容量是否大于等于第i个物品的重量，如果大于，就判断是拿该物品的价值大还是不拿该物品的价值大
                    memo[i][j] = max(memo[i][j],v[i]+memo[i-1][j-w[i]]);
                }
            }
        }
        return memo[n-1][C];
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
