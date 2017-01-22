ll maxAreaHist(vll& v){
	ll maxArea = 0, area;
	v.pb(0);
	int n = sz(v), top;
	stack<int> st;
	for(int i = 0; i < n; ++i){
		while(!st.empty()  && v[i] < v[st.top()]){
			top = st.top(); st.pop();
			if(st.empty()) area = v[top]*i;
			else area = v[top] * (i - st.top() - 1);
			maxArea = max(maxArea, area);
		}
		st.push(i);
	}
	v.pop_back();
	return maxArea;
}
