#include "../Headers/file.h"
#include "../Headers/constant.h"  


/*
*get line start from where cursor are (without new line character opposite to fgets)
*
* @param {string} is a str to store the line from file
* @param {FILE} file from where we want take line
* @return {BOOLEAN} check if line exist or not
*/

int customGetStr( char*buffer ,FILE*file){
    
    int i = 0;
    char charr=' ';
    //clear the buffer in case it contain values
    for (int i = 0; i < sizeof buffer; i++) buffer[i]=0; 

    //input all character from line
    while ( charr != '\n'){
 
        charr=fgetc(file); 
        /*for debug
        printf("%c",charr); 
        */

        //stop input if it blank(thre no values)
        if (charr == EOF) return 0; 

        //ignore space or new line character 
        if(charr !='\n' && charr!=' ' ) buffer[i]=charr;   
        ++i;      
    } 
      return 1;
}
  
int loadLeveldata(char*buffer,FILE*levelFile,char*level){
    while ( customGetStr(buffer,levelFile) != 0 ){
        //for debug
        /*printf("buffer: %s ,,  size%ld\n",buffer,strlen(buffer));*/
        if( strcmp(buffer,level) == 0 ){
            printf("%s : found suceffully , LOADDING... \n",buffer);
            customGetStr(buffer,levelFile);
            printf("%ld \n",strlen(buffer) );
            return 1;
        }
    }
    printf("error occurs in loadLeveldata function \nlevel probably don't exist check it\n");
    return 0;
}

void fillDataInMap(char*buffer,int map[NBR_VERT_BLOCK][NBR_VERT_BLOCK]){
    int bufPosition = 0; 
    for (int i = 0; i < NBR_VERT_BLOCK; i++){
        for (int j = 0; j < NBR_VERT_BLOCK; j++, ++bufPosition ){ 
            map[i][j]=(int)(buffer[bufPosition]-'0');
        }
    }
}

 
int loadMap(int map[NBR_VERT_BLOCK][NBR_VERT_BLOCK],char*levelNbr){

    //boolean to check loaded sucess
    int sucess = 0 ;
 
    char level[100]="level.";
    //add level number to 'level.' world for search purposes in db
    strcat(level,levelNbr);

    //open level file
    FILE* levelFile = NULL;
    levelFile = fopen("../dbfile/level.txt", "r+");

    if (levelFile != NULL){
        printf("file is open well\n");

        //put cursor at start
        rewind(levelFile);

        //check level exist and get map data in last buffer variable
        char buffer[1000]={0};
        if(loadLeveldata(buffer,levelFile,level)==1){
           
           fillDataInMap(buffer,map);
           printf("data filling sucefully in map\n");
           sucess = 1;
        }else{
            sucess = 0 ;
            printf("dataload failed\n");
        }
        
        fclose(levelFile);
    }else{
        printf("error with file opening, maybe path to file");
        sucess=0;
    }
      return sucess;
}

int saveLevel(int map[NBR_VERT_BLOCK][12]){
    //open level file
    FILE* levelFile = NULL;
    levelFile = fopen("../dbfile/l.txt", "r+");

    if (levelFile != NULL){
        printf("file is open well for saving\n");

        for (int i = 0; i < NBR_VERT_BLOCK; i++){
            for (int j = 0; j < NBR_VERT_BLOCK; j++){ 
                printf("map[][] = %c\n",(char)(map[i][j]+'0') );
                fputc((char)(map[i][j]+'0'), levelFile);
            }
        }
        
        fclose(levelFile);
    }else{
        printf("cannot open file to save data \n");
    }

}
 