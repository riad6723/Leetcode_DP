class Solution {
public:

    int dp[100010][2][5];

    int rec(int pos,bool okToBuy,int cnt,vector<int> &vec){
        //base case
        if(cnt==4)return 0;
        if(pos>=vec.size())return 0;
        if(dp[pos][okToBuy][cnt]!=-1)return dp[pos][okToBuy][cnt];

        if(okToBuy==true){
            int buying=rec(pos+1,false,cnt+1,vec)-vec[pos];
            int skipping=rec(pos+1,true,cnt,vec);
            return dp[pos][okToBuy][cnt]=max(buying,skipping);
        }
        else{
            int selling=rec(pos+1,true,cnt+1,vec)+vec[pos];
            int skipping=rec(pos+1,false,cnt,vec);
            return dp[pos][okToBuy][cnt]=max(selling,skipping);
        }
    }

    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
       return rec(0,true,0,prices);

    }
};
