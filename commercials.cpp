//
// https://open.kattis.com/problems/commercials
//



#include <stdio.h>

int main(){
    int n, p;
    int arr[n];
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);
        arr[i]-=p;//substract out the fee needed to pay
    }

    //implement kadane's algorithm to find most optimal subset
    int mEndingHere=0,mSoFar=0;
    for(int i=0;i<n;i++)
    {
        mEndingHere=mEndingHere+arr[i];
        if (mEndingHere<0) mEndingHere=0;
        if (mSoFar<mEndingHere) mSoFar=mEndingHere;
    }
    printf("%d\n",mSoFar);

    return 0;

}
