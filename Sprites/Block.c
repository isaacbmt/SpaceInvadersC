#include "Block.h"

void free_block(void *data) {
    free(*(struct Block **) data);
}

void free_rect(void *data) {
    free(*(struct SDL_Rect **) data);
}

/**
 * Genera los escudos.
 * @param shields
 */
void generateShields(struct LinkedList *shields) {
    for (int i = 0; i < 4; ++i) {
        struct Block *block = (struct Block *) malloc(sizeof(struct Block));
        createBlock(block, 100 + i * (80 + 126));
        //printf("cosi: %i", i);
        add(shields, &block);
        //printf("cosi2: %i", i);
    }
    //struct Block *coso = (struct Block *) get(shields, 0);
    //printf("\nsize shields: %i, primero: %i\n", shields->size, coso->shield->size);
}

/**
 * Crea un bloque.
 */
void createBlock(struct Block *block, int xPos) {
    buildBlockMatrix(block);
    printf("Entro :)");
    block->shield = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    createList(block->shield, sizeof(struct SpaceRect *), free_rect);

//    printf("Entro :)");
    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 16; ++j) {
            if (block->state[i][j] != 0) {
                struct SDL_Rect *rect = (struct SDL_Rect *) malloc(sizeof(struct SDL_Rect));
                rect->x = xPos + j * 5;
                rect->y = 530 + i * 5;
                rect->w = rect->h = 5;
                struct SpaceRect *srect = (struct SpaceRect *) malloc(sizeof(struct SpaceRect));
                srect->rect = rect;
                srect->i = i;
                srect->j = j;
                add(block->shield, &srect);
            }
        }
    }
//    printf("size: %i", block->shield->size);
}

/**
 * Crea la forma del bloque.
 */
void buildBlockMatrix(struct Block *block) {
    int tmp[14][16] = {{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
                       {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
                       {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                       {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                       {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                       {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                       {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1}};

    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 16; ++j) {
            block->state[i][j] = tmp[i][j];
        }
       // printf("matriz: %i \n", i);
    }
}