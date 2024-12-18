pair<int, int> maxEl(vector<int>& arr){
    int sum=0, maxi=INT_MIN;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]>maxi) maxi = arr[i];
        sum += arr[i];
    }
    return {maxi, sum};
}

int noOfStudents(vector<int>& arr, int n, int mid){
    int student=1, sumPages=0;
    for(int i=0;i<n;i++){
        if(arr[i]+sumPages <= mid){
            sumPages+=arr[i];
        }
        else{
            // maxi=max(maxi,sumPages);
            sumPages=arr[i];
            student++;
        }
    }
    return student;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
    int low=maxEl(arr).first, high=maxEl(arr).second;

    while(low<=high){
        int mid=(low+high)>>1;
        // if(noOfStudents(arr,n,mid)==m) return mid;
        if(noOfStudents(arr,n,mid)> m) low=mid+1;
        else{
            high=mid-1;
        }
    }

    return low;
    
}
