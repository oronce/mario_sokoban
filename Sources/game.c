#include "../Headers/constant.h" 
#ifndef DEF_GAMEH
#define DEF_GAMEH
#include "../Headers/game.h"
#include "../Headers/file.h"

#endif

void moveMario(Position*playerPosition,int map[NBR_HORIZ_BLOCK][NBR_VERT_BLOCK],int direction,int marioDirection){
    if(map[playerPosition->y][playerPosition->x]==MARIO_LEFT+GOAL || map[playerPosition->y][playerPosition->x]==MARIO_RIGHT+GOAL  || map[playerPosition->y][playerPosition->x]==MARIO_UP+GOAL || map[playerPosition->y][playerPosition->x]==MARIO_DOWN+GOAL){
        map[playerPosition->y][playerPosition->x] = GOAL;
    }else{
        map[playerPosition->y][playerPosition->x] = BLANK;
    }
    printf(" direction from moveMario : %d\n",direction);
    switch (direction){
    case RIGHT:
        playerPosition->x += 1;
    break;
    case LEFT:
        playerPosition->x -= 1;
    break;
    case UP:
        playerPosition->y -= 1;
    break;
     case DOWN:
        playerPosition->y += 1;
    break;
    }

    map[playerPosition->y][playerPosition->x] = marioDirection;
}

void movePlayer(Position*playerPosition,int map[NBR_HORIZ_BLOCK][NBR_VERT_BLOCK],int*currNbrGoal,int direction){
    switch (direction){
    case UP:
        printf("UP work\n");
        if(playerPosition->y-1<0)break;

        if(map[playerPosition->y - 1][playerPosition->x ] == WALL){
            printf("warning : wall\n");
            break;
        }
        if( (map[playerPosition->y - 1][playerPosition->x ] ==BOX || map[playerPosition->y - 1][playerPosition->x ] == BOX_OK  ) && (map[playerPosition->y - 2][playerPosition->x] == WALL) ){
            printf("warning : BOX+WALL"); 
            break;
        } 
        if( (map[playerPosition->y - 1][playerPosition->x] == BOX || map[playerPosition->y - 1][playerPosition->x] == BOX_OK  ) &&  (map[playerPosition->y - 2][playerPosition->x] == BOX || map[playerPosition->y - 2][playerPosition->x] == BOX_OK  ) ) {
            printf(" block it :2 BOX\n");
            break;
        }

        if ( map[playerPosition->y - 1][playerPosition->x ] == BLANK){
            printf(" BLANK manager\n");
            moveMario(playerPosition,map,direction,MARIO_UP);
            
            //PLAYER AND GOAL CASE

        }else if(map[playerPosition->y - 1][playerPosition->x ] == GOAL){
            printf(" GOAL manager\n");
            moveMario(playerPosition,map,direction,MARIO_UP+GOAL);

        }else if(map[playerPosition->y - 1][playerPosition->x] == BOX  && map[playerPosition->y - 2][playerPosition->x] == BLANK){
            printf(" BOX manager\n");
            moveMario(playerPosition,map,direction,MARIO_UP);
            map[playerPosition->y - 1][playerPosition->x] = BOX ;

        }else if((map[playerPosition->y - 1][playerPosition->x] == BOX) && (map[playerPosition->y - 2][playerPosition->x] == GOAL )){
            printf("BOX AND GOAL MANAGER\n");
            moveMario(playerPosition,map,direction,MARIO_UP);

            map[playerPosition->y - 1][playerPosition->x] = BOX_OK ;
            ++*(currNbrGoal);

        }else if(map[playerPosition->y - 1][playerPosition->x] == BOX_OK && map[playerPosition->y - 2][playerPosition->x] == GOAL ){
            printf("BOX_OK AND GOAL MANAGER\n");
            moveMario(playerPosition,map,direction,MARIO_UP+GOAL);
            map[playerPosition->y - 1][playerPosition->x] = BOX_OK;

        }else if(map[playerPosition->y - 1][playerPosition->x] == BOX_OK){
            printf("BOX_OK OUT MANAGER\n");
            moveMario(playerPosition,map,direction,MARIO_UP+GOAL);
            map[playerPosition->y - 1][playerPosition->x] = BOX;
            --*(currNbrGoal); 
        }



    break;
    
    case  DOWN :
        if (playerPosition->y + 1 > NBR_VERT_BLOCK - 1)break;
        if(map[playerPosition->y+ 1][playerPosition->x ] == WALL){
            printf("warning : wall");
            break;
        }
        if( (map[playerPosition->y + 1][playerPosition->x ] ==BOX || map[playerPosition->y + 1][playerPosition->x ] == BOX_OK  ) && (map[playerPosition->y + 2][playerPosition->x] == WALL) ){
            printf("warning : BOX+WALL"); 
            break;
        } 
        if( (map[playerPosition->y + 1][playerPosition->x] == BOX || map[playerPosition->y + 1][playerPosition->x] == BOX_OK  ) &&  (map[playerPosition->y + 2][playerPosition->x] == BOX || map[playerPosition->y + 2][playerPosition->x] == BOX_OK  ) ) {
            printf(" block it :2 BOX\n");
            break;
        }

        if ( map[playerPosition->y+ 1][playerPosition->x ] == BLANK){
            printf(" BLANK manager\n");
            moveMario(playerPosition,map,direction,MARIO_DOWN);
            
            //PLAYER AND GOAL CASE

        }else if(map[playerPosition->y + 1][playerPosition->x ] == GOAL){
            printf(" GOAL manager\n");
            moveMario(playerPosition,map,direction,MARIO_DOWN+GOAL);

        }else if(map[playerPosition->y + 1][playerPosition->x] == BOX  && map[playerPosition->y + 2][playerPosition->x] == BLANK){
            printf(" BOX manager\n");
            moveMario(playerPosition,map,direction,MARIO_DOWN);
            map[playerPosition->y + 1][playerPosition->x] = BOX ;

        }else if((map[playerPosition->y + 1][playerPosition->x] == BOX) && (map[playerPosition->y + 2][playerPosition->x] == GOAL )){
            printf("BOX AND GOAL MANAGER\n");
            moveMario(playerPosition,map,direction,MARIO_DOWN);

            map[playerPosition->y + 1][playerPosition->x] = BOX_OK ;
            ++*(currNbrGoal);

        }else if(map[playerPosition->y + 1][playerPosition->x] == BOX_OK && map[playerPosition->y + 2][playerPosition->x] == GOAL ){
            printf("BOX_OK AND GOAL MANAGER\n");
            moveMario(playerPosition,map,direction,MARIO_DOWN+GOAL);
            map[playerPosition->y + 1][playerPosition->x] = BOX_OK;

        }else if(map[playerPosition->y + 1][playerPosition->x] == BOX_OK){
            printf("BOX_OK OUT MANAGER\n");
            moveMario(playerPosition,map,direction,MARIO_DOWN+GOAL);
            map[playerPosition->y+1][playerPosition->x] = BOX;
            --*(currNbrGoal); 
        }



    break;

    case LEFT :
        if (playerPosition->x - 1 < 0)break;
        if(map[playerPosition->y][playerPosition->x - 1] == WALL){
            printf("warning : wall");
            break;
        }
        if( (map[playerPosition->y][playerPosition->x - 1] ==BOX || map[playerPosition->y][playerPosition->x - 1] == BOX_OK  ) && (map[playerPosition->y][playerPosition->x - 2] == WALL) ){
            printf("warning : BOX-WALL"); 
            break;
        } 
        if( (map[playerPosition->y][playerPosition->x - 1] == BOX || map[playerPosition->y][playerPosition->x - 1] == BOX_OK  ) &&  (map[playerPosition->y][playerPosition->x - 2] == BOX || map[playerPosition->y][playerPosition->x - 2] == BOX_OK  ) ) {
            printf(" block it :2 BOX\n");
            break;
        }

        if ( map[playerPosition->y][playerPosition->x - 1] == BLANK){
            printf(" BLANK manager\n");
            moveMario(playerPosition,map,direction,MARIO_LEFT);
            
            //PLAYER AND GOAL CASE

        }else if(map[playerPosition->y][playerPosition->x - 1] == GOAL){
            printf(" GOAL manager\n");
            moveMario(playerPosition,map,direction,MARIO_LEFT+GOAL);

        }else if(map[playerPosition->y][playerPosition->x - 1] == BOX  && map[playerPosition->y][playerPosition->x - 2] == BLANK){
            printf(" BOX manager\n");
            moveMario(playerPosition,map,direction,MARIO_LEFT);
            map[playerPosition->y][playerPosition->x - 1] = BOX ;
        
        }else if ((map[playerPosition->y][playerPosition->x - 1] == BOX) && (map[playerPosition->y][playerPosition->x - 2] == GOAL)){

            printf("BOX AND GOAL MANAGER\n");
            moveMario(playerPosition,map,direction,MARIO_LEFT);
            map[playerPosition->y][playerPosition->x - 1] = BOX_OK ;
            ++*(currNbrGoal);
        
        }else if (map[playerPosition->y][playerPosition->x - 1] == BOX_OK && map[playerPosition->y][playerPosition->x - 2] == GOAL){
            printf("BOX_OK AND GOAL MANAGER\n");
            moveMario(playerPosition,map,direction,MARIO_LEFT+GOAL);

            map[playerPosition->y][playerPosition->x - 1] = BOX_OK;

        }else if (map[playerPosition->y][playerPosition->x - 1] == BOX_OK){
            printf("BOX_OK OUT MANAGER\n");
            moveMario(playerPosition,map,direction,MARIO_LEFT+GOAL);

            map[playerPosition->y][playerPosition->x-1] = BOX;
            --*(currNbrGoal);  

        }
    break;

    case RIGHT :
        
        if (playerPosition->x + 1 > NBR_VERT_BLOCK - 1)break;
        if(map[playerPosition->y][playerPosition->x + 1] == WALL){
            printf("warning : wall");
            break;
        }
        if( (map[playerPosition->y][playerPosition->x + 1] ==BOX || map[playerPosition->y][playerPosition->x + 1] == BOX_OK  ) && (map[playerPosition->y][playerPosition->x + 2] == WALL) ){
            printf("warning : BOX+WALL"); 
            break;
        } 
        if( (map[playerPosition->y][playerPosition->x + 1] == BOX || map[playerPosition->y][playerPosition->x + 1] == BOX_OK  ) &&  (map[playerPosition->y][playerPosition->x + 2] == BOX || map[playerPosition->y][playerPosition->x + 2] == BOX_OK  ) ) {
            printf(" block it :2 BOX\n");
            break;
        }
            //PLAYER AND BLANK CASE
        if ( map[playerPosition->y][playerPosition->x + 1] == BLANK){
            printf(" BLANK manager\n");
            moveMario(playerPosition,map,direction,MARIO_RIGHT);
            
            //PLAYER AND GOAL CASE

        }else if(map[playerPosition->y][playerPosition->x + 1] == GOAL){
            printf(" GOAL manager\n");
            moveMario(playerPosition,map,direction,MARIO_RIGHT+GOAL);

        }else if(map[playerPosition->y][playerPosition->x + 1] == BOX  && map[playerPosition->y][playerPosition->x + 2] == BLANK){
            printf(" BOX manager\n");
            moveMario(playerPosition,map,direction,MARIO_RIGHT);
            map[playerPosition->y][playerPosition->x + 1] = BOX ;

        }else if((map[playerPosition->y][playerPosition->x + 1] == BOX) && (map[playerPosition->y][playerPosition->x + 2] == GOAL )){
            printf("BOX AND GOAL MANAGER\n");
            moveMario(playerPosition,map,direction,MARIO_RIGHT);
            map[playerPosition->y][playerPosition->x + 1] = BOX_OK ;
            ++*(currNbrGoal);

        }else if(map[playerPosition->y][playerPosition->x + 1] == BOX_OK && map[playerPosition->y][playerPosition->x + 2] == GOAL ){
            printf("BOX_OK AND GOAL MANAGER\n");
            moveMario(playerPosition,map,direction,MARIO_RIGHT+GOAL);
            map[playerPosition->y][playerPosition->x + 1] = BOX_OK;

        }else if(map[playerPosition->y][playerPosition->x + 1] == BOX_OK){
            printf("BOX_OK OUT MANAGER\n");
            moveMario(playerPosition,map,direction,MARIO_RIGHT+GOAL);
            map[playerPosition->y][playerPosition->x+1] = BOX;
            --*(currNbrGoal); 
        }



    break;

    }
}





int setPlayerPosition(int map[NBR_HORIZ_BLOCK][NBR_VERT_BLOCK],Position*playerPosition){
    for(int i=0  ; i<NBR_HORIZ_BLOCK ; i++){
        for(int j=0 ; j<NBR_VERT_BLOCK ; j++){
            if (map[i][j]==MARIO_DOWN){
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
            case MARIO_DOWN + GOAL :
                SDL_BlitSurface(surfaces[GOAL],NULL,screen,&objectPosition );
                SDL_BlitSurface(surfaces[MARIO_DOWN],NULL,screen,&objectPosition );
                break;
            case MARIO_UP + GOAL :
                SDL_BlitSurface(surfaces[GOAL],NULL,screen,&objectPosition );
                SDL_BlitSurface(surfaces[MARIO_UP],NULL,screen,&objectPosition );
                break; 
            case MARIO_LEFT + GOAL :
                SDL_BlitSurface(surfaces[GOAL],NULL,screen,&objectPosition );
                SDL_BlitSurface(surfaces[MARIO_LEFT],NULL,screen,&objectPosition );
                break; 
            case MARIO_RIGHT + GOAL :
                SDL_BlitSurface(surfaces[GOAL],NULL,screen,&objectPosition );
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
    
    //load level on map(memmory)
    
    if(loadMap(map,"1")){

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
                }
                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); 
                loadScreen(screen,map,surfaces);
            break;
            case  SDL_MOUSEBUTTONUP :
                printf("x :%d\n y: :%d\n",event.button.x,event.button.y);
                int cordinateY = 0;
                for (int i = 0; i < NBR_HORIZ_BLOCK ; i++){
                    int cordinateX = 0;
                     //printf("cordinateY: %d\n",cordinateY);
                    for (int j = 0; j < NBR_VERT_BLOCK; j++){
                       /*printf("map[%d][%d]=%d\n ",i,j,map[i][j]);*/
                       //printf("if((button.x:%d>cordinateX:%d  && button.x<(cordinateX+34):%d)  && button.x>cordinateX:%d  && button.x<(cordinateY+34):%d) )",event.button.x,)
                       if ((event.button.x>cordinateX && event.button.x<(cordinateX+34)) && (event.button.y>cordinateY && event.button.y<(cordinateY+34))  ){
            
                        printf("map[%d][%d]=%d\n ",i,j,map[i][j]);

                       }
                       
                       cordinateX+=34;
                       //printf("cordinateX :%d\n",cordinateX);
                    }
                    cordinateY+=34;
                }
                
            break;      
        }
        if(nbrGoalToHit==currNbrGoal){printf("You win\n");break;} 
    }
}


