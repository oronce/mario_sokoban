
#include "../Headers/constant.h" 
#include "../Headers/custom.h"
#include "../Headers/file.h"
#include "../Headers/game.h"

void putBlock(SDL_Event*event,int block,int map[NBR_HORIZ_BLOCK][NBR_VERT_BLOCK]){
    printf("x :%d\n y: :%d\n",event->button.x,event->button.y);
    int cordinateY = 0;
    for (int i = 0; i < NBR_HORIZ_BLOCK ; i++){
        int cordinateX = 0;
        //printf("cordinateY: %d\n",cordinateY);
        for (int j = 0; j < NBR_VERT_BLOCK; j++){
            /*printf("map[%d][%d]=%d\n ",i,j,map[i][j]);*/
            //printf("if((button.x:%d>cordinateX:%d  && button.x<(cordinateX+34):%d)  && button.x>cordinateX:%d  && button.x<(cordinateY+34):%d) )",event.button.x,)
            if ((event->button.x>cordinateX && event->button.x<(cordinateX+34)) && (event->button.y>cordinateY && event->button.y<(cordinateY+34))  ){
            
                map[i][j] = block;
                printf("map[%d][%d]=%d\n ",i,j,map[i][j]);
                        
            }
                       
            cordinateX+=34;
            //printf("cordinateX :%d\n",cordinateX);
        }
        cordinateY+=34;
    }
}


void customLevel(SDL_Surface*screen){

    printf("enter customLevel\n");
    
    //event manager
    SDL_Event event;
    
    //store block that user want paste
    int block=WALL;
    
    int continu=1;

    //store game block in memory
    int map[12][12]={0};

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

    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_Flip(screen);

    

    printf("we still in custom function\n");
    while (continu){
        
        SDL_WaitEvent(&event);
        switch (event.type){

            case SDL_QUIT:
                continu=0;
            break;

            case SDL_KEYDOWN:
                printf("you press a key\n");
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE :      
                        continu = 0;   
                    break;
                    
                    case SDLK_0 :
                        block = BLANK;
                    break;
                    case SDLK_1 :
                        block = WALL;
                    break;
                    case SDLK_2 :
                        block = GOAL;
                    break;
                    case SDLK_3:
                        block = BOX;
                    break;    
                    case SDLK_4:
                        block = MARIO_DOWN;
                    break;
                    case SDLK_s :
                        saveLevel(map);
                    break;
                }
            break;

            case SDL_MOUSEBUTTONDOWN:
              
                if (event.button.button == SDL_BUTTON_RIGHT){
                    putBlock(&event,BLANK,map);
                }else if(event.button.button == SDL_BUTTON_LEFT){
                    putBlock(&event,block,map);
                }

            break;
            case SDL_MOUSEMOTION:
            
                printf("e.b.b: %d\n",event.button.button);
                if(event.button.button == SDL_BUTTON_WHEELUP){
                    putBlock(&event,BLANK,map);
                }
                if (event.button.button == SDL_BUTTON_LEFT){
                    putBlock(&event,block,map);
                } 
                
            break;
        }
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); 
        loadScreen(screen,map,surfaces);
        SDL_Flip(screen);
        
    }
    
}