int maxSubArray(int* a, int n) {
    int sum=a[0], max=a[0];

    for(int i=1;i<n;i++) {
        if(sum<0)
            sum=0;

        sum+=a[i];

        if(sum>max)
            max=sum;
    }

    return max;
}
