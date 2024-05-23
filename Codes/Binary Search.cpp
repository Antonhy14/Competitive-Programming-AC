vector<int> v;
int binary_search(int x) {
    int l=0, r = v.size()-1;

    while(l<=r) {
        int m = (l+r)/2;

        if(v[m]==x) 
            return m;
        else if(v[m]>x)
            r = m-1;
        else if(v[m]<x)
            l = m+1;
    }
    return -1;
}
