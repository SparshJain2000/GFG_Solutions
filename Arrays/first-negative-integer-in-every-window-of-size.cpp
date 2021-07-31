vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    list<long long>l;
    for(int i=0;i<K;i++){
        if(A[i]<0)l.push_back(A[i]);
    }
    vector<long long>ans;
    if(l.empty())ans.push_back(0);
    else ans.push_back(l.front());
    for(int i=1;i<N-K+1;i++){
        if(A[i+K-1]<0)l.push_back(A[i+K-1]);
        if(A[i-1]<0)l.pop_front();
        if(l.empty())ans.push_back(0);
        else ans.push_back(l.front());
    }
    return ans;
 }
