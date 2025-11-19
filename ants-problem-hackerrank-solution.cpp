int solve(vector<int> V) {
    int n=V.size(),c=0;
    int x = 2*n/2*(n-n/2)*100000;
    sort(V.begin(),V.end());
    
    for(int i=0;i<n-1;i++)
    {
        if(V[i+1]-V[i]==1)
        {
            c++;
            i++;
        }
    }
    if(V[n-1]-V[0]==1)
        c++;
    x+=c;
    return x*2; 
}

