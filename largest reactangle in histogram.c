#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int maxArea(int hist[], int n){
    int stack[MAX];
    int top=-1;
    int area_max=0;
    int i=0;
    
    while(i<n){
        if (top==-1 || hist[stack[top]]<=hist[i]){
            stack[++top]=i++;
        }
        else{
            int s_top=stack[top--];
            int height=hist[s_top];
            int width=(top==-1) ? i:i-stack[top]-1;
            int area=height*width;
            if (area>area_max){
                area_max=area;
            }
        }
    }
    while (top!=-1){
        int s_top=stack[top--];
        int height=hist[s_top];
        int width=(top==-1) ? i:i-stack[top]-1;
        int area=height*width;
        if (area>area_max){
            area_max=area;
        }
    }
    return area_max;
}
int main(){
    int hist[]={4,8,2,6,9,7};
    int n=sizeof(hist)/sizeof(hist[0]);
    printf("for the input: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", hist[i]);
    }
    printf("\nthe largest area is %d",maxArea(hist,n));
    return 0;
}