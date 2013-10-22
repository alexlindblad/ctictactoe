//
//  CGameBoard.c
//  CTicTacToe
//
//  Created by Alex Lindblad on 10/21/13.
//  Copyright (c) 2013 Alex Lindblad. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "CGameBoard.h"

static const int kCBoardWidth = 3;
static const int kCBoardHeight = 3;
static const int kCNumBoardCells = kCBoardHeight*kCBoardWidth;
typedef enum CellEntry {
    kCCellNoEntry = -1,
    kCCellEntryX,
    kCCellEntryO
} CellEntry;

struct CGameCell{
    CellEntry _entry;
};
typedef struct CGameCell Cell;

struct CGameBoard {
    Cell _cells[kCNumBoardCells];
};

/*!
* Internal method declaration
*/
void CGameBoard_Init(GameBoard* board);
void CGameBoard_DrawCell(Cell cell);
/*!
* public methods
*/
GameBoard* CGameBoard_NewBoard(void) {
    GameBoard* board = (GameBoard*)malloc(sizeof(GameBoard));
    CGameBoard_Init(board);
    return board;
}

void CGameBoard_Draw(GameBoard* board) {

    printf("    1   2   3  \n");
    printf("      |   |    \n");
    printf("A   ");
    CGameBoard_DrawCell(board->_cells[0]);
    printf(" | ");
    CGameBoard_DrawCell(board->_cells[1]);
    printf(" | ");
    CGameBoard_DrawCell(board->_cells[2]);
    printf("  \n");
    
    printf("      |   |    \n");
    printf("   ---+---+--- \n");
    printf("      |   |    \n");
    printf("B   ");
    CGameBoard_DrawCell(board->_cells[3]);
    printf(" | ");
    CGameBoard_DrawCell(board->_cells[4]);
    printf(" | ");
    CGameBoard_DrawCell(board->_cells[5]);
    printf("  \n");
    
    printf("      |   |    \n");
    printf("   ---+---+--- \n");
    printf("      |   |    \n");
    printf("C   ");
    CGameBoard_DrawCell(board->_cells[6]);
    printf(" | ");
    CGameBoard_DrawCell(board->_cells[7]);
    printf(" | ");
    CGameBoard_DrawCell(board->_cells[8]);
    printf("  \n");
    printf("      |   |    \n\n");
}

void CGameBoard_Clean(GameBoard* board) {
    if (board != NULL)
        free(board);
}

/*!
* Internal method implementation
*/
void CGameBoard_Init(GameBoard* board) {
    for (int i = 0; i < kCNumBoardCells; i++) {
        board->_cells[i]._entry = kCCellNoEntry;
    }
}

void CGameBoard_DrawCell(Cell cell) {
    switch (cell._entry) {
        case kCCellEntryX:
            printf("X");
            break;
        case kCCellEntryO:
            printf("O");
            break;
        case kCCellNoEntry:
        default:
            printf(" ");
        break;

    }
}