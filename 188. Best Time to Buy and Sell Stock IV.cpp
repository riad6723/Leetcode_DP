class Solution {
public:

    int dp[1001][2][201];

    int rec(int pos,bool okToBuy,int cnt,int k,vector<int> &vec){
        //base case
        if(cnt==2*k)return 0;
        if(pos>=vec.size())return 0;
        if(dp[pos][okToBuy][cnt]!=-1)return dp[pos][okToBuy][cnt];

        if(okToBuy==true){
            int buying=rec(pos+1,false,cnt+1,k,vec)-vec[pos];
            int skipping=rec(pos+1,true,cnt,k,vec);
            return dp[pos][okToBuy][cnt]=max(buying,skipping);
        }
        else{
            int selling=rec(pos+1,true,cnt+1,k,vec)+vec[pos];
            int skipping=rec(pos+1,false,cnt,k,vec);
            return dp[pos][okToBuy][cnt]=max(selling,skipping);
        }
    }

    int maxProfit(int k,vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
       return rec(0,true,0,k,prices);

    }
};
