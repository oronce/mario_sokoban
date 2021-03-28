int customGetStr( char*buffer ,FILE*file);
int loadMap(int[NBR_VERT_BLOCK][12],int reset,char*);
int loadLeveldata(int,char*buffer,FILE*levelFile,char*level); 
void fillDataInMap(char*buffer,int[NBR_VERT_BLOCK][12]); 
int checkLevelExist(char*buffer,FILE*levelFile,char*level);
int saveLevel(int map[NBR_VERT_BLOCK][12],char*levelNbr);

