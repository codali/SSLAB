#define KGRN  "\x1B[32m"
#define KNRM  "\x1B[0m"
struct dir {
  char fname[10][10];
  struct dir *subdir[10];
  char dname[10][10];
  int lastf, lastd;
  struct dir *prev;
}*root = NULL, *current,*ptr;
char location[10][10],name[10];
int lastLoc = 0;

void directory();
int dirSearch(struct dir *loc){
  for (i = 0 ; i < 10 ; i++) {

    if(strcmp(name, loc -> dname[i]) == 0) {
      return i;
      break;
    }
  }
  return -1;
}

int fileSearch(struct dir *loc){
  for (i = 0 ; i < 10 ; i++) {

    if(strcmp(name, loc -> fname[i]) == 0) {
      return i;
      break;
    }
  }
  return -1;
}
struct dir *alloc(struct dir *loc){
  struct dir *temp;
  temp = (struct dir*) malloc (sizeof(struct dir));
  temp -> lastf = 0;
  temp -> lastd = 0;
  temp -> prev = loc;
  return temp;
}

void hierarichal() {
  if(root == NULL)
    root = (struct dir*) malloc (sizeof(struct dir));
  root -> lastf = 0;
  root -> lastd = 0;
  root -> prev = NULL;
  directory(root);
}

void directory(struct dir *loc) {
  printf("\nAddress : ");
  for(i = 0; i <= lastLoc ; i++)
    printf("%s/",location[i]);
  printf("\n");

  printf(" 1.MKDIR\n" );
  printf(" 2.RMDIR\n" );
  printf(" 3.TOUCH\n");
  printf(" 4.RM\n");
  printf(" 5.ls\n");
  printf(" 6.Search\n");
  printf(" 7.CD\n");
  printf(" 8.CD ..\n");
  printf(" 0.Exit\n");
  printf("\tCHOOSE :");
  int opt,i;
  scanf("%d", &opt);

  switch (opt) {
    case 1:
      printf("Directory Name :");
      scanf("%s", name);
      if(dirSearch(loc) == -1) {
        ptr = alloc(loc);
        strcpy(loc -> dname[loc -> lastd], name);
        loc -> lastd++;
        loc -> subdir[loc -> lastd] = ptr;
        printf("MKDIR Success\n");
      }
      else
        printf("Directory already present\n" );
      directory(loc);
      break;

    case 2:
      printf("Directory Name :");
      scanf("%s", name);
      if(dirSearch(loc) != -1) {
        i = dirSearch(loc);
        free(loc -> subdir[i]);
        strcpy(loc -> dname[i], "");
        printf("Deleted\n");
      }
      else
        printf("Directory not found\n" );
      break;

    case 3:
      printf("File Name :");
      scanf("%s", name);
      if(fileSearch(loc) == -1) {
        strcpy(loc -> fname[loc -> lastf], name);
        loc -> lastf++;
        printf("TOUCH Success\n");
      }
      else
        printf("File already present\n" );
      break;

    case 4:
      printf("File Name :");
      scanf("%s", name);
      if(fileSearch(loc) != -1) {
        i = fileSearch(loc);
        strcpy(loc -> fname[i], "");
        printf("Deleted\n");
      }
      else
        printf("File Not Found\n" );
      break;

      case 5:
        printf("\n");
        for (i = 0 ; i < 10 ; i++) {
          printf("%s%s%s\t",KGRN,loc->dname[i],KNRM);
        }
        printf("\n");
        for (i = 0 ; i < 10 ; i++) {
          printf("%s\t",loc->fname[i]);
        }
        break;

      case 6:
        printf("Under Construction\n");
        break;

      case 7:
        printf("Directory Name :");
        scanf("%s", name);
        if(dirSearch(loc) != -1) {
          i = dirSearch(loc);
          strcpy(location[i], loc -> dname[i]);
          lastLoc++;
          directory(loc -> subdir[i]);
        }
        else
          printf("No Such Dir\n" );
        break;
      case 8:
        if( loc -> prev != NULL )
          loc = loc -> prev;
          lastLoc--;
        break;
      case 0:exit(0);break;
      default: printf("Bro WTF u Just Entered\n");directory(loc);
  }
  directory(loc);
}
