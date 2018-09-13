void indexed() {
  struct block {
    char fname[15];
  }*index[10][10];
  struct block *ptr;
  int fileNum=0,nb[10];
  char name[15];

  printf("Enter the number of files : ");
  scanf("%d",&fileNum);
  int i,j;
  for (i = 0; i < fileNum; i++) {
    printf("Block numbers (File %d) : ",i);
    scanf("%d",&nb[i]);
    printf("File Name of File (%d) : ",i);
    char name[15];
    scanf("%s",name);

    for(j=0;j < nb[i]; j++) {
      ptr = (struct block*) malloc (sizeof(struct block));
      strcpy(ptr -> fname, name);
      index[i][j] = ptr;
    }
  }
    printf("FNAME\tBlock Count\tAlloted Blocks\n");
    for (i = 0; i < fileNum; i++) {
      ptr = index[i][0];
      printf("%s\t%d\t", ptr -> fname, nb[i]);
      for(j=0;j < nb[i]; j++) {
        printf("%p",index[i][j]);
        if( j != nb[i]-1 )
          printf(", ");
      }
      printf("\n");
    }
}
