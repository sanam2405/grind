bool findPattern(string p, string s)
{
        int n = s.length();
        int m = p.length();
    
        for(int i = 0; i <= n-m; i++)
        {
            string current = s.substr(i,m);
            if(current==p)
                return true;
        }
    
        return false;
}
