
double multiply(double x, int m)
{
    double ans = 1.0;
    for(int i = 0; i < m; i++)
        ans*=x;
    return ans;
}
double findNthRootOfM(int n, long long m) {
        
         if(n==1)
             return (double)m;
        double low = 1, high = m, mid;
        double epsilon = 1e-8;
        while(abs(low-high) > epsilon)
        {
            mid = (high+low)/2.0;
            
            if(multiply(mid,n) < m)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
    
        return low;
        
}
