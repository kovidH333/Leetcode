class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        // brute force - TLE
        // int maxi = INT_MIN;
        // for(int i=0; i<values.size(); i++){
        //     for(int j=i+1; j<values.size(); j++){
        //         int res = values[i]+values[j]+i-j;
        //         maxi=max(res,maxi);
        //     }
        // }
        // return maxi;


        int i_max = values[0];
        int res = INT_MIN;
        for(int j=1; j<values.size(); j++){
            res = max(res,i_max+values[j]-j);
            i_max = max(values[j]+j,i_max);
        }
        return res;
    }
};