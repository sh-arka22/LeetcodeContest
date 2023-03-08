class Solution {
public:
    bool isPossible(long long  tar , vector<int>  stations, int r , int k){
        long long sum=0;
        int n=stations.size();
        //ith station power is sum of [i-r,i+r]
        for(int i=0;i<r;i++)
            sum+=stations[i];
        for(int i=0;i<n;i++){
            //slide window by 1 : add rth on right and subtract r+1th on left
            if(i+r < n)
                sum += stations[i+r];
            if(i-(r+1) >= 0)
                sum -= stations[i-(r+1)];
            // check if more stations required to achieve stations
            if(sum < tar){
                // if can not be achieved with remaining k stations, return false
                if(tar-sum > k)
                    return false;
                // can be achieved, add these stations at r distance on right and update remaining stations
                if(i+r <= n-1)
                    stations[i+r] += tar-sum;
                k -= tar-sum;
                sum=tar;        //sum = sum + tar - sum
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        long long low = 0;
        long long high = k;
		long long ans = 0;
        int n = stations.size();
        for(int i=0;i<n;i++)
            high += (long long) stations[i];
        while(low <= high){
            long long  mid = low + (high - low)/2;
            if(isPossible(mid,stations,r,k)){
				ans = mid;
                low = mid+1;
			}
            else
                high = mid-1;
        }
        return ans;
    }
};