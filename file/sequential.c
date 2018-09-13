void sequential() {
  int fileNum=0,sb[10],nb[10],block[100],endBlock;;
  sb[0]=0;
  printf("Enter the number of files : ");
  scanf("%d",&fileNum);
  int i;

  for (i = 0; i < fileNum; i++) {
    printf("Block numbers : ");
    scanf("%d",&nb[i]);

    if(i==0) {
      endBlock=0;
    }
    else {
      endBlock = endBlock;
    }
    int j;
    for(j = endBlock; j < nb[i]+endBlock ;j++) {
      block[i] = i;
    }
    endBlock = j;

  }
  printf("File Num\tBlock Count\tAllocated Blocks\n");
  for(i = 0 ; i < fileNum ; i++) {
    printf("%d\t%d\t",i,nb[i]);
    if(i==0) {
      endBlock=0;
    }
    else {
      endBlock = endBlock;
    }
    int j;
    for(j = endBlock; j < nb[i]+endBlock ;j++) {
      printf("%d   ",j);
    }
    endBlock = j;
    printf("\n");
  }
}
