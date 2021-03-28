/*
*game.c
*
*
*By Rocee 19 march 2020
*
*
*contain all functions to play the game, manage keyboard events etc 
*/




#ifndef DEF_GAMEH
#define DEF_GAMEH
#include "../Headers/game.h"
#include "../Headers/constant.h"  
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_video.h>   

#endif
void test(){
    
}

void restartGame(){

}

void movePlayer(Position*playerPosition,int map[NBR_HORIZ_BLOCK][NBR_VERT_BLOCK],int*currNbrGoal,int direction){
    switch (direction){
    case UP:
        printf("UP work\n");
        if(playerPosition->y-1<0)break;

        if( map[playerPosition->y-1][playerPosition->x]==BLANK){
            map[playerPosition->y][playerPosition->x]=BLANK;
            playerPosition->y-=1;
            map[playerPosition->y][playerPosition->x]=MARIO_UP;
        }

        if(map[playerPosition->y-1][playerPosition->x]==BOX && map[playerPosition->y-2][playerPosition->x]==BLANK || map[playerPosition->y - 2][playerPosition->x ] == GOAL ){
            /* printf("enter collision\n");
            printf("box: %d\n",map[playerPosition->y+1][playerPosition->x]);*/


            map[playerPosition->y-1][playerPosition->x]=BLANK;// clear actual box

            if(map[playerPosition->y-2][playerPosition->x]==BLANK){
                map[playerPosition->y-2][playerPosition->x]=BOX; //SET NEW BOX
            }else if(map[playerPosition->y-2][playerPosition->x]==GOAL){
                map[playerPosition->y-2][playerPosition->x]=BOX_OK; //set BOX_OK
                ++*(currNbrGoal);
            }

            //MOVE MARIO
            //clean current position
            map[playerPosition->y][playerPosition->x]=BLANK;
            // update playerPosition
            playerPosition->y-=1;
            //set a new case to the player position
            map[playerPosition->y][playerPosition->x]=MARIO_UP;
        }
    break;
    
    case  DOWN :
        printf("DOWN work\n");
        if (playerPosition->y + 1 > NBR_VERT_BLOCK - 1)break;
        if (playerPosition->y + 1 <= NBR_VERT_BLOCK - 1 && map[playerPosition->y + 1][playerPosition->x] == BLANK) {
            map[playerPosition->y][playerPosition->x] = BLANK;
            playerPosition->y += 1;
            map[playerPosition->y][playerPosition->x] = MARIO_DOWN;
        }

        if (map[playerPosition->y + 1][playerPosition->x] == BOX && map[playerPosition->y + 2][playerPosition->x] == BLANK || map[playerPosition->y+ 2][playerPosition->x ] == GOAL){
            printf("enter collision\n");
            map[playerPosition->y + 1][playerPosition->x] = BLANK; // clear actual box

            //for goal setting
            if (map[playerPosition->y + 2][playerPosition->x] == BLANK) {
                map[playerPosition->y + 2][playerPosition->x] = BOX; //SET NEW BOX
            }
            else if (map[playerPosition->y + 2][playerPosition->x] == GOAL) {
                map[playerPosition->y + 2][playerPosition->x] = BOX_OK; //set BOX_OK
                 ++*(currNbrGoal);
            }

            //MOVE MARIO
            map[playerPosition->y][playerPosition->x] = BLANK;
            playerPosition->y += 1;
            map[playerPosition->y][playerPosition->x] = MARIO_DOWN;
        }        
    break;
    case LEFT :
            //avoid map segmentation core (acess memory that  dont exit in map)
        if (playerPosition->x - 1 < 0) break;

        if (playerPosition->x - 1 <= NBR_HORIZ_BLOCK - 1 && map[playerPosition->y][playerPosition->x - 1] == BLANK) {
            printf("LEFT work\n");
            map[playerPosition->y][playerPosition->x] = BLANK;
            playerPosition->x -= 1;
            map[playerPosition->y][playerPosition->x] = MARIO_LEFT;
        }

        if (map[playerPosition->y][playerPosition->x - 1] == BOX && map[playerPosition->y][playerPosition->x - 2] == BLANK || map[playerPosition->y][playerPosition->x - 2] == GOAL){
            printf("enter collision\n");
            printf("box: %d\n", map[playerPosition->y][playerPosition->x + 1]);
            map[playerPosition->y][playerPosition->x - 1] = BLANK; // clear actual box

            if (map[playerPosition->y][playerPosition->x - 2] == BLANK){
                map[playerPosition->y][playerPosition->x - 2] = BOX; //SET NEW BOX
            }
            else if (map[playerPosition->y][playerPosition->x - 2] == GOAL){
                map[playerPosition->y][playerPosition->x - 2] = BOX_OK; //set BOX_OK
                 ++*(currNbrGoal);
            }

            //MOVE MARIO
            map[playerPosition->y][playerPosition->x] = BLANK;
            playerPosition->x -= 1;
            map[playerPosition->y][playerPosition->x] = MARIO_LEFT;
        }
    break;
    case RIGHT :
    printf("RIGHT work\n");
    if (playerPosition->x + 1 > NBR_VERT_BLOCK - 1)break;
    if (playerPosition->x + 1 <= NBR_HORIZ_BLOCK - 1 && map[playerPosition->y][playerPosition->x + 1] == BLANK){
        map[playerPosition->y][playerPosition->x] = BLANK;
        playerPosition->x += 1;
        map[playerPosition->y][playerPosition->x] = MARIO_RIGHT;
    }

    if (map[playerPosition->y][playerPosition->x + 1] == BOX && map[playerPosition->y][playerPosition->x + 2] == BLANK || map[playerPosition->y][playerPosition->x + 2] == GOAL){
        printf("enter collision\n");
        printf("box: %d\n", map[playerPosition->y][playerPosition->x + 1]);
        map[playerPosition->y][playerPosition->x + 1] = BLANK; // clear actual box

        //for goal setting
        if (map[playerPosition->y][playerPosition->x + 2] == BLANK){
            map[playerPosition->y][playerPosition->x + 2] = BOX; //SET NEW BOX
        }
        else if (map[playerPosition->y][playerPosition->x + 2] == GOAL){
            map[playerPosition->y][playerPosition->x + 2] = BOX_OK; //set BOX_OK
            ++*(currNbrGoal);
        }

        //MOVE MARIO
        map[playerPosition->y][playerPosition->x] = BLANK;
        playerPosition->x += 1;
        map[playerPosition->y][playerPosition->x] = MARIO_RIGHT;
    }
    break;

    }
}









int setPlayerPosition(int map[NBR_HORIZ_BLOCK][NBR_VERT_BLOCK],Position*playerPosition){
    for(int i=0  ; i<NBR_HORIZ_BLOCK ; i++){
        for(int j=0 ; j<NBR_VERT_BLOCK ; j++){
            if (map[i][j]==MARIO_DOWN || map[i][j]==MARIO_UP || map[i][j]==MARIO_LEFT || map[i][j]==MARIO_RIGHT ){
                /*printf("player position: map[%d][%d], position in file:%d\n",i,j);*/
                playerPosition->y=i;
                playerPosition->x=j;
                printf("player position found sucefully\n");
                return 1;
            }
        }
    }
    printf("player position not found, check if it exist and   if it MARIO_DOWN constant\n");
    return 0;      
}
//salut tout le monde 

/*
*get total of GOAL BLOCK 
*
*@ param{int*} pointer to double dimension table
*@ return {INT} TOTAL OF GOAL BLOCK INSIDE MAP 
*/
int getGoalSum (int map[NBR_HORIZ_BLOCK][NBR_VERT_BLOCK]){
    int nbrOfGoal=0 ; 
    for(int i=0  ; i<NBR_HORIZ_BLOCK ; i++){
        for(int j=0 ; j<NBR_VERT_BLOCK ; j++){
            if (map[i][j]==GOAL){
                ++nbrOfGoal;
            }
        }
    }
    printf("GOAL T: %d\n",nbrOfGoal);
    return nbrOfGoal;
}

void loadScreen(SDL_Surface*screen,int map[NBR_HORIZ_BLOCK][NBR_VERT_BLOCK],SDL_Surface**surfaces){
    SDL_Rect objectPosition ;
    objectPosition.x=0;
    objectPosition.y=0; 
    for(int i=0 ; i<NBR_HORIZ_BLOCK ; i++){
        objectPosition.x=0;
        for(int j=0 ; j<NBR_VERT_BLOCK ; j++){
            switch (map[i][j]){
            case WALL:
                SDL_BlitSurface(surfaces[WALL],NULL,screen,&objectPosition ); 
                break;
            case BOX:
                SDL_BlitSurface(surfaces[BOX],NULL,screen,&objectPosition );
                break;
            case BOX_OK:
                SDL_BlitSurface(surfaces[BOX_OK],NULL,screen,&objectPosition );
                break;
            case GOAL:
                SDL_BlitSurface(surfaces[GOAL],NULL,screen,&objectPosition );
                break;
            case MARIO_DOWN:
                SDL_BlitSurface(surfaces[MARIO_DOWN],NULL,screen,&objectPosition );
                break;
            case MARIO_UP:
                SDL_BlitSurface(surfaces[MARIO_UP],NULL,screen,&objectPosition );
                break;
            case MARIO_LEFT:
                SDL_BlitSurface(surfaces[MARIO_LEFT],NULL,screen,&objectPosition );
                break;
            case MARIO_RIGHT:
                SDL_BlitSurface(surfaces[MARIO_RIGHT],NULL,screen,&objectPosition );
                break;                       
            }
            objectPosition.x+=34;
        }
        objectPosition.y+=34;
    }
    SDL_Flip(screen);
}

int startGame(SDL_Surface*screen){

    //current number of goal 
    int currNbrGoal = 0;
    //nbr of GOAL to hit
    int nbrGoalToHit = 0;
    
    //player position in the map
    Position playerPosition = {0,0};

    //declaration of event variable type
    SDL_Event event;

    //boolean to manage event loop
    int continu=1;

    // declare all usable block surface 
    SDL_Surface*surfaces[NBR_OF_OBJECT]={NULL};
    surfaces[BLANK] = NULL;
    surfaces[WALL] = IMG_Load("../images/wall.jpg");
    surfaces[BOX] =IMG_Load("../images/box.jpg");
    surfaces[BOX_OK] =IMG_Load("../images/box_ok.jpg");
    surfaces[GOAL] = IMG_Load("../images/goal.png");
    surfaces[MARIO_DOWN] = IMG_Load("../images/mario_down.gif");
    surfaces[MARIO_UP] = IMG_Load("../images/mario_up.gif");
    surfaces[MARIO_LEFT] = IMG_Load("../images/mario_left.gif"); 
    surfaces[MARIO_RIGHT] = IMG_Load("../images/mario_right.gif");
     
    
    /*SDL_BlitSurface(wall,NULL,screen,&objectPosition ); 
    SDL_Flip(screen); */
    //clean screen by fill it with white screen
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_Flip(screen);
    //declaration of map
    int map[NBR_HORIZ_BLOCK][NBR_VERT_BLOCK]={0};

    //reset level
    int resset = 0;
    
    //load level on map(memmory)
    if(loadMap(map,resset,"1")){

        //load map on screen
        loadScreen(screen,map,surfaces);
    }else{
        printf("errors occurs when loading map\n");
        exit(EXIT_FAILURE);
    }

    

    if(!setPlayerPosition(map,&playerPosition))
        exit(EXIT_FAILURE);
    
    
    if(  (nbrGoalToHit=getGoalSum(map)) < 0  ){
        printf("error occurs in getGoalSum function\n GOAL constant  are missing in map");
        exit(EXIT_FAILURE);
    }

    SDL_EnableKeyRepeat(50,200);

    while (continu){
        SDL_WaitEvent(&event);
        switch (event.type){
            case SDL_QUIT:
                continu=0;
            break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE :       
                        continu = 0;
                    break; 
                    case SDLK_UP :
                       movePlayer(&playerPosition,map,&currNbrGoal,UP);
                    break;
                    case SDLK_DOWN :
                        movePlayer(&playerPosition,map,&currNbrGoal,DOWN);
                    break;
                    case SDLK_RIGHT :
                       movePlayer(&playerPosition,map,&currNbrGoal,RIGHT);
                    break;
                    case SDLK_LEFT :
                        movePlayer(&playerPosition,map,&currNbrGoal,LEFT);
                    break;
                    case SDLK_s :
                        saveLevel(map,"1");
                    break;
                    case SDLK_r :
                        resset = 1 ; 
                        if(loadMap(map,resset,"1")){

                        //load map on screen
                        loadScreen(screen,map,surfaces);
                        }else{
                            printf("errors occurs when loading map\n");
                            exit(EXIT_FAILURE);
                        }

                        if(!setPlayerPosition(map,&playerPosition)) exit(EXIT_FAILURE);
                    
                    
                        if(  (nbrGoalToHit=getGoalSum(map)) < 0  ){
                            printf("error occurs in getGoalSum function\n GOAL constant  are missing in map");
                            exit(EXIT_FAILURE);
                        }
                        
                    break;
                }
                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); 
                loadScreen(screen,map,surfaces);
            break;
            case SDL_MOUSEBUTTONUP:
                printf("x :%d\n y: :%d\n",event.button.x,event.button.y);
                int cy = 0;
                for (int i = 0; i < NBR_HORIZ_BLOCK ; i++){
                    int cx = 0;
                     //printf("cy: %d\n",cy);
                    for (int j = 0; j < NBR_VERT_BLOCK; j++){
                       /*printf("map[%d][%d]=%d\n ",i,j,map[i][j]);*/
                       //printf("if((button.x:%d>cx:%d  && button.x<(cx+34):%d)  && button.x>cx:%d  && button.x<(cy+34):%d) )",event.button.x,)
                       if ((event.button.x>cx && event.button.x<(cx+34)) && (event.button.y>cy && event.button.y<(cy+34))  ){
                           printf("map[%d][%d]=%d\n ",i,j,map[i][j]);
                       }
                       
                       cx+=34;
                       //printf("cx :%d\n",cx);
                    }
                    cy+=34;
                }
                
            break;      
        }
        if(nbrGoalToHit==currNbrGoal){printf("You win\n");break;} 
    }
}


