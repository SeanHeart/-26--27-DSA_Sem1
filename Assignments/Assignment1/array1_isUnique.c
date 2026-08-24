//this is miss' answer
int isUnique(BookShelf BS){
    int i, j;
    int retVal = 1;
    for(i=0; i<BS.shelves[0].bookCount; i++){
        for(j=i+1; j<BS.shelves[0].bookCount; j++){
            if(strcmp(book i, book j) == 0){
                retVal = 0;
            }
        }
    }
    return retVal;
}

//isUnique (revised version for efficiency)
int isUnique(BookShelf BS){
    int i, j = BS.shelves[0].bookCount;
    int retVal = 1;
        //red               //yellow
        //Where it will stop //When it should stop
    for(i=0; i<BS.shelves[0].bookCount && j==BS.shelves[0].bookCount; i++){
        for(j=i+1; j<BS.shelves[0].bookCount && strcmp(book i, book j) != 0; j++){

        }
    }
    return (j == BS.shelves[0].bookCount)1?0;
}