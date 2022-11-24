// 2478. Number of Beautiful Partitions
int dp[1001][1001];
int m=1e9+7;
bool isprime(string &s,int i)
{
    return  s[i]=='3' || s[i]=='7' || s[i]=='5' || s[i]=='2';
}
int count_beautiful(int i,string&s,int k,int lim)
{
    if(i==s.size() && k==0)return 1;
    if(i>=s.size() || k<0)return 0;
    if(dp[i][k]!=-1)return dp[i][k];
    int pick=0;
   //create a partition of lim length if curr char is prime and prev char is non-prime
    if(isprime(s,i) && !isprime(s,i-1))
    {
        pick=count_beautiful(i+lim,s,k-1,lim)%m;
    }
    
    //move on increase the prev patition
    int unpick=0;
    unpick=count_beautiful(i+1,s,k,lim)%m;
    
    return dp[i][k]=(unpick%m+pick%m)%m;
    
}


class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength)
    {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        //valid string --->start with prime and end with non prime 
        if(!isprime(s,0) || isprime(s,n-1))return 0;
        return count_beautiful(minLength,s,k-1,minLength);    
    }
};