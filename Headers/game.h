
void loadScreen(SDL_Surface*screen,int map[NBR_VERT_BLOCK][NBR_VERT_BLOCK],SDL_Surface**surfaces);
int startGame(SDL_Surface*screen);  
int  setPlayerPosition(int map[NBR_HORIZ_BLOCK][NBR_VERT_BLOCK],Position*playerPosition);
void editLevel(SDL_Surface*screen);
void movePlayer(Position*playerPosition,int map[NBR_HORIZ_BLOCK][NBR_VERT_BLOCK],int*currNbrGoal,int direction);
