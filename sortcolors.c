void sortColors(int* a, int n) {
    int l=0,m=0,r=n-1;

    while(m<=r) {
        if(a[m]==0) {
            int t=a[l]; a[l]=a[m]; a[m]=t;
            l++; m++;
        }
        else if(a[m]==1)
            m++;
        else {
            int t=a[m]; a[m]=a[r]; a[r]=t;
            r--;
        }
    }
}
