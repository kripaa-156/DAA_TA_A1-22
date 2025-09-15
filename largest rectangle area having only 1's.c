#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int maxArea(int hist[],int n){
    int i=0;
    int s_top=-1;
    int max_area=0;
    int area;
    int top;
    int stack[MAX];
    while (i<n){
        if (s_top==-1 || hist[stack[s_top]]<=hist[i]){
            stack[++s_top]=i++;
        }
        else{
            top=stack[s_top--];
            area=hist[top]*(s_top==-1 ? i:i-stack[s_top]-1);
            if (area>max_area){
                max_area=area;
            }
        }
    }
    while(s_top!=-1){
        top=stack[s_top--];
        area=hist[top]*(s_top==-1 ? i:i-stack[s_top]-1);
        if (area>max_area){
            max_area=area;
        }
    }
    return max_area;
}
int rectangleMax(int matrix[][MAX],int rows,int cols){
    int result=0;
    int hist[MAX]={0};
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if (matrix[i][j]==0){
                hist[j]=0;
            }
            else{
                hist[j]++;
            }
        }
        int area=maxArea(hist,cols);
        if (area>result){
            result=area;
        }
    }
    return result;
}
int main(){
    int matrix[MAX][MAX];
    int cols,rows;
    printf("enter number of rows and coloumns:");
    scanf("%d%d",&rows,&cols);
    printf("enter matrix:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    int maximum_area=rectangleMax(matrix,rows,cols);
    printf("area of largest rectangle containing only 1's and 0's is %d",maximum_area);
    return 0;
}