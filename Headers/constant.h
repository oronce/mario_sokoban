#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

//NUMBER OF OBJECT OR ELEMENT AVAILABLE
#define NBR_OF_OBJECT 9

//NUMBER OF BLOCK ON VERTICAL ONE LINE
#define NBR_HORIZ_BLOCK 12
//NUBER OF BLOCK IN ONE HORIZONTAL LINE 
#define NBR_VERT_BLOCK 12

#define BLOCK_SIZE 34
#define SCREEN_WIDTH  (BLOCK_SIZE*NBR_HORIZ_BLOCK)
#define SCREEN_HEIGHT (BLOCK_SIZE*NBR_VERT_BLOCK)

typedef enum Sprite Sprite ;

enum Sprite{
    BLANK , WALL , BOX , BOX_OK , GOAL , MARIO_DOWN , MARIO_UP,
    MARIO_LEFT, MARIO_RIGHT 
};

enum { UP , DOWN , LEFT , RIGHT };

typedef struct Position Position ;

struct Position{
    int x ;
    int y ;
};


#endif