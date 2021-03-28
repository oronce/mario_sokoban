/*
*file.c
*
*
*By Rocee 19 march 2020
*
*
*contain function to get or store game data in files
*/

#include "../Headers/constant.h" 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_video.h>   
#include "../Headers/file.h"
 


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

int checkLevelExist(char*buffer,FILE*levelFile,char*level){
    while ( customGetStr(buffer,levelFile) != 0 ){
        if( strcmp(buffer,level) == 0 ){
            printf("level found suceffuly\n");
        }
    }
}

int saveLevel(int map[NBR_VERT_BLOCK][12],char*levelNbr){
    //open level file
    FILE* levelFile = NULL;
    levelFile = fopen("../dbfile/level.txt", "r+");

    char buffer[1000]={0};

    if (levelFile != NULL){
        printf("file is open well for saving\n");

        char level[100]="level.";
        //add level number to 'level.' world for search purposes in db
        strcat(level,levelNbr);
        while ( customGetStr(buffer,levelFile) != 0 ){
            if( strcmp(buffer,level) == 0 ){
                printf("level found for saving \n");
                //go to new line 
                customGetStr(buffer,levelFile);

                for (int i = 0; i < NBR_VERT_BLOCK; i++){
                    for (int j = 0; j < NBR_VERT_BLOCK; j++){ 
                        printf("map[][] = %c\n",(char)(map[i][j]+'0') );
                        fputc((char)(map[i][j]+'0'), levelFile);
                    }
                }
                
            }
    }
        



        /*for (int i = 0; i < NBR_VERT_BLOCK; i++){
            for (int j = 0; j < NBR_VERT_BLOCK; j++){ 
                printf("map[][] = %c\n",(char)(map[i][j]+'0') );
                fputc((char)(map[i][j]+'0'), levelFile);
            }
        }*/
        
        fclose(levelFile);
    }else{
        printf("cannot open file to save data \n");
    }

}
  
int loadLeveldata(int reset,char*buffer,FILE*levelFile,char*level){
    while ( customGetStr(buffer,levelFile) != 0 ){
        //for debug
        /*printf("buffer: %s ,,  size%ld\n",buffer,strlen(buffer));*/
        if( strcmp(buffer,level) == 0 ){
            printf("%s : found suceffully , LOADDING... \n",buffer);
            customGetStr(buffer,levelFile);
            if (reset == 0)customGetStr(buffer,levelFile);
            
            printf("%ld \n",strlen(buffer) );
            return 1;
        }
    }
    printf("error occurs in loadLeveldata function \nlevel probably don't exist check it\n");
    return 0;
}

int loadLeveldata2(char*buffer,FILE*levelFile,char*level){

}

void fillDataInMap(char*buffer,int map[NBR_VERT_BLOCK][NBR_VERT_BLOCK]){
    int bufPosition = 0; 
    for (int i = 0; i < NBR_VERT_BLOCK; i++){
        for (int j = 0; j < NBR_VERT_BLOCK; j++, ++bufPosition ){ 
            map[i][j]=(int)(buffer[bufPosition]-'0');
        }
    }
}

 
int loadMap(int map[NBR_VERT_BLOCK][NBR_VERT_BLOCK],int reset,char*levelNbr){

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
        
        
        //load data from file to buffer variable
        if(loadLeveldata(reset,buffer,levelFile,level)==1){
           
           // load data to map arr
           fillDataInMap(buffer,map);
           printf("data filling sucefully in map\n");
           sucess = 1;
        }else{
            sucess = 0 ;
            printf("dataload failed\n");
        }
        
         
    }else{
        printf("error with file opening, maybe path to file");
        sucess=0;
    }
      return sucess;
}
 