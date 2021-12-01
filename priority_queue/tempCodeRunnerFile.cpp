int size = n;
    while(size>1){
        swap(input[0], input[size-1]);
        size--;
        int parentIndex = 0;
        int lchildIndex = 2*parentIndex+1;
        int rchildIndex = 2* parentIndex +2;
        while(lchildIndex < size){
            int minIndex = parentIndex;
            if(input[minIndex] > input[lchildIndex]){
                minIndex = lchildIndex;
            }
            if(rchildIndex < size &&  input[minIndex] > input[rchildIndex]){
                minIndex = rchildIndex;
            }
            if(minIndex == parentIndex){
                break;
            }
            swap(input[minIndex], input[parentIndex]);
            parentIndex = minIndex;
            lchildIndex = parentIndex*2 +1;
            rchildIndex = parentIndex*2 +2;
        }
    }