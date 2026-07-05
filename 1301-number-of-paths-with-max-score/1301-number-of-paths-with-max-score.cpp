class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> ways(n + 1, vector<int>(n + 1, 0));

        dp[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        vector<pair<int,int>> dir = {
            {1,0},
            {0,1},
            {1,1}
        };

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){

                if(board[i][j]=='X' || board[i][j]=='S')
                    continue;

                for(auto [dx,dy]:dir){

                    int x=i+dx;
                    int y=j+dy;

                    if(dp[x][y]==-1)
                        continue;

                    if(dp[x][y]>dp[i][j]){
                        dp[i][j]=dp[x][y];
                        ways[i][j]=ways[x][y];
                    }
                    else if(dp[x][y]==dp[i][j]){
                        ways[i][j]+=ways[x][y];
                        ways[i][j]%=MOD;
                    }
                }

                if(dp[i][j]!=-1 && board[i][j]!='E'){
                    dp[i][j]+=board[i][j]-'0';
                }
            }
        }

        if(dp[0][0]==-1)
            return {0,0};

        return {dp[0][0], ways[0][0]};
    }
};