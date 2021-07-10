#include "../Headers/constant.h"   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_video.h>   
     
#include "../Headers/game.h"
#include "../Headers/file.h"                   
#include "../Headers/custom.h"
 

void pause();      
            
                  
  
int main(int argc, char *argv[])  
{  
        
      
    if (SDL_Init(SDL_INIT_VIDEO) == -1) { 
     
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());    
		exit(EXIT_FAILURE); 
	}
 
	//variable declaration    
	SDL_Surface*screen = NULL ;       
	SDL_Surface*homeScreen = NULL ;	              
    SDL_Rect homeScreenPosition ;
    homeScreenPosition.x=0;              
    homeScreenPosition.y=0;   
    int continu = 1;   //for event loop                    
    SDL_Event event;           
	//set icon   
	SDL_WM_SetIcon(SDL_LoadBMP("images/sdl_icone.bmp"), NULL);

	//create surface named screen           
	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32,SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF|SDL_RESIZABLE); 
	// screen test
	if (screen == NULL) {  
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());  
        exit(EXIT_FAILURE);
    }	
	//window name  
	SDL_WM_SetCaption("Mario Sokoban", NULL);       
	 
	//home screen load and blitting 
	homeScreen=IMG_Load("../images/menu.jpg"); 
    SDL_BlitSurface(homeScreen,NULL,screen,&homeScreenPosition );                         
    SDL_Flip(screen);      
     
	//event manager        
    while(continu){   
        SDL_BlitSurface(homeScreen,NULL,screen,&homeScreenPosition );                         
        SDL_Flip(screen); 
        SDL_WaitEvent(&event);    
        switch(event.type){
            case SDL_QUIT:
                SDL_Quit();    
                continu = 0;  
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){      
                    case SDLK_ESCAPE : 
                        SDL_Quit();       
                        continu = 0;     
                    break; 
                    case SDLK_1 :   
                        startGame(screen); 
                    break;
                    case SDLK_2 :
                        customLevel(screen);   
                    break;
                }  
            break;                          
        }
    } 

     SDL_FreeSurface(homeScreen);   
	 SDL_Quit();
	 
    return EXIT_SUCCESS;  
}
 

  

  
  



void pause() 
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;   
        }
    }
}


         








  



















/*printf("countNumberWeFindSearch:%d \n dico string: %s\n check : %d\n starstr: %s\n strLength: %d\n",countNumberWeFindSearch,str,check,starStr,strLength);
		printf("numberofTry: %d\n", numberOfTry );*/


                                 
                                                          
                                                                                               
                          
     
/*int nbrUser = 2 ;
	User usrArr[nbrUser]; 
	       
	createUser(usrArr,nbrUser);             
	
	printf("\n \n \n");           
	   
	printUser(usrArr,nbrUser);*/   
  






