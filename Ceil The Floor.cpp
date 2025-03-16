pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int f=-1,c=-1;
	int left=0, right = n-1;

	while(left<=right){
		int mid=(left+right)/2;
		if(a[mid]==x){
			f=a[mid];
			c=a[mid];
			return {f,c};
		}
		else if(a[mid]<=x){
			f = max(f,a[mid]);
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	left=0, right = n-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(a[mid]>=x){
			if(c=-1){
				c=a[mid];
			}
			else{
				c=min(c,a[mid]);
			}
			
			right=mid-1;
		}
		else{
			left=mid+1;
		}
	}

	return {f,c};
}
