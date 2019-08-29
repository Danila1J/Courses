
int min(const int* data,int n){
    int min=0;
    for (int i = 1; i <n ; ++i) {
        if(data[i]<=data[min]){
            min=i;
        }
    }
    return min;
}

void selectionSort(int *data,int n){
    for (int i = 0; i <n-1 ; ++i) {
        int ind=i+min(data+i,n-i);
        int tmp=data[ind];
        data[ind]=data[i];
        data[i]=tmp;
    }
}
