long long bc(ll n, ll k)
{
    vector<ll> C(k+1);
    fill(C.begin(), C.end(), 0); 
    C[0] = 1;  // nC0 is 1
 
    for (long long i = 1; i <= n; i++)
    {
        // Compute next row of pascal triangle using
        // the previous row
        for (long long j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j-1];
    }
    return C[k];
}
