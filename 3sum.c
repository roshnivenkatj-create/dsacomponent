int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}

int** threeSum(int* a,int n,int* rs,int** cs){
    qsort(a,n,sizeof(int),cmp);
    int **ans=malloc(n*sizeof(int*));
    *cs=malloc(n*sizeof(int));
    *rs=0;

    for(int i=0;i<n-2;i++){
        if(i&&a[i]==a[i-1]) continue;
        int l=i+1,r=n-1;

        while(l<r){
            int s=a[i]+a[l]+a[r];

            if(s==0){
                ans[*rs]=malloc(3*sizeof(int));
                ans[*rs][0]=a[i];
                ans[*rs][1]=a[l];
                ans[*rs][2]=a[r];
                (*cs)[*rs]=3;
                (*rs)++;

                while(l<r&&a[l]==a[l+1])l++;
                while(l<r&&a[r]==a[r-1])r--;
                l++;r--;
            }
            else if(s<0)l++;
            else r--;
        }
    }
    return ans;
}
