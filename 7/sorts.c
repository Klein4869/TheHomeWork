#include "stdio.h"

void adjust(int k[ ],int i,int n)

{

    int j,temp;

    temp=k[i];

    j=2*i+1;

    while(j<n){

        if(j<n-1 && k[j]<k[j+1])

            j++;

        if(temp>=k[j]) 

            break;

        k[(j-1)/2]=k[j];

        j=2*j+1;

    }

    k[(j-1)/2]=temp;

}

void merge(int x[ ],int tmp[ ],int left,int leftend,int rightend)

{     

    int i=left, j=leftend+1, q=left;

    while(i<=leftend && j<=rightend)

    {

        if(x[i]<=x[j]) 

            tmp[q++]=x[i++];

        else

            tmp[q++]=x[j++];

    }

    while(i<=leftend)

        tmp[q++]=x[i++];

    while(j<=rightend)

        tmp[q++]=x[j++];

    for(i=left; i<=rightend; i++)

        x[i]=tmp[i];

}

void quickSort(int k[ ],int left,int right)

{     

    int i, last;

    if(left<right){

        last=left; 

        for(i=left+1;i<=right;i++)

            if(k[i]<k[left])

                swap(&k[++last],&k[i]); 

        swap(&k[left],&k[last]);

        quickSort(k,left,last-1); 

        quickSort(k,last+1,right);   

    }

}