vi stable_marriage(vvi& men, vvi& women)
{
	int n = sz(men);
	vi ans(n, -1), prop(n, 0), match(n, -1);
	queue<int> q;
	for(int i = 0; i < n; ++i)
		q.push(i);
	while(!q.empty()){
		int m = q.front(), w = men[m][prop[m]++];
		if(match[w] == -1){
			ans[m] = w;
			match[w] = m;
			q.pop();
		} else{
			int m2 = match[w], mfirst = 0;
			for(int i = 0; i < n && women[w][i] != m2; ++i){
				if(women[w][i] == m){
					mfirst = 1;
					break;
				}
			}
			if(mfirst){
				q.pop();
				ans[m] = w;
				match[w] = m;
				ans[m2] = -1;
				q.push(m2);
			}
		}
	}
	return ans;
}
