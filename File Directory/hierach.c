struct dir {
  char fname[10][10];
  struct dir *subdir[10];
  char dname[10][10];
  int lastf, lastd;
}*root;

int dirsearch(){
  for (i = 0 ; i < 10 ; i++) {

    if(strcmp(name, uname[i]) == 0) {
      return i;
      break;
    }
  }
  return -1;
}

int filesearch(int currentuser){
  for (i = 0 ; i < 10 ; i++) {

    if(strcmp(name, ind[currentuser]->fname[i]) == 0) {
      return i;
      break;
    }
  }
  return -1;
}

void hierarichal() {

}
