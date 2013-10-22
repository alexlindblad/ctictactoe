//
//  CGameBoard.c
//  CTicTacToe
//
//  Created by Alex Lindblad on 10/21/13.
//  Copyright (c) 2013 Alex Lindblad. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "CGameBoard.h"

static const int kCBoardWidth = 3;
static const int kCBoardHeight = 3;
static const int kCNumBoardCells = kCBoardHeight*kCBoardWidth;

struct CGameCell{
    CellEntry entry;
};
typedef struct CGameCell Cell;

struct CGameBoard {
    Cell cells[kCNumBoardCells];
};

/*!
* Internal method declaration
*/
void CGameBoard_Init(GameBoard* board);
void CGameBoard_DrawCell(Cell cell);
bool CGameBoard_CellAvailable(GameBoard* board, RowIndicator row, ColIndicator col);
int CGameBoard_CellIndex(RowIndicator row, ColIndicator col);
bool CGameBoard_CellsHaveSameEntries(GameBoard* board, int i, int j, int k);

/*!
* public methods
*/
GameBoard* CGameBoard_NewBoard(void) {
    GameBoard* board = (GameBoard*)malloc(sizeof(GameBoard));
    CGameBoard_Init(board);
    return board;
}

void CGameBoard_Draw(GameBoard* board) {
    assert(board != NULL);
    
    printf("    1   2   3  \n");
    printf("      |   |    \n");
    printf("A   ");
    CGameBoard_DrawCell(board->cells[0]);
    printf(" | ");
    CGameBoard_DrawCell(board->cells[1]);
    printf(" | ");
    CGameBoard_DrawCell(board->cells[2]);
    printf("  \n");
    
    printf("      |   |    \n");
    printf("   ---+---+--- \n");
    printf("      |   |    \n");
    printf("B   ");
    CGameBoard_DrawCell(board->cells[3]);
    printf(" | ");
    CGameBoard_DrawCell(board->cells[4]);
    printf(" | ");
    CGameBoard_DrawCell(board->cells[5]);
    printf("  \n");
    
    printf("      |   |    \n");
    printf("   ---+---+--- \n");
    printf("      |   |    \n");
    printf("C   ");
    CGameBoard_DrawCell(board->cells[6]);
    printf(" | ");
    CGameBoard_DrawCell(board->cells[7]);
    printf(" | ");
    CGameBoard_DrawCell(board->cells[8]);
    printf("  \n");
    printf("      |   |    \n\n");
}

void CGameBoard_Clean(GameBoard* board) {
    if (board != NULL)
        free(board);
}

CellSelectError CGameBoard_SelectCell(GameBoard* board,
                                      RowIndicator row,
                                      ColIndicator col,
                                      CellEntry entry) {
    assert(board != NULL);
    
    if (!CGameBoard_CellAvailable(board, row, col)) {
        return kCCellSelectUnavailable;
    }
    
    board->cells[CGameBoard_CellIndex(row, col)].entry = entry;
    return kCCellSelectNoError;
}

bool CGameBoard_HasWinner(GameBoard* board) {
    // check rows
    return (CGameBoard_CellsHaveSameEntries(board, 0, 1, 2) ||
            CGameBoard_CellsHaveSameEntries(board, 3, 4, 5) ||
            CGameBoard_CellsHaveSameEntries(board, 6, 7, 8) ||
    // check columns
            CGameBoard_CellsHaveSameEntries(board, 0, 3, 6) ||
            CGameBoard_CellsHaveSameEntries(board, 1, 4, 7) ||
            CGameBoard_CellsHaveSameEntries(board, 2, 5, 8) ||
    // check diagonals
            CGameBoard_CellsHaveSameEntries(board, 0, 4, 8) ||
            CGameBoard_CellsHaveSameEntries(board, 2, 4, 6));
}

/*!
* Internal method implementation
*/
void CGameBoard_Init(GameBoard* board) {
    assert(board != NULL);
    
    for (int i = 0; i < kCNumBoardCells; i++) {
        board->cells[i].entry = kCCellNoEntry;
    }
}

void CGameBoard_DrawCell(Cell cell) {
    switch (cell.entry) {
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

int CGameBoard_CellIndex(RowIndicator row, ColIndicator col) {
    int index = 0;
    if (row == kCRowB) {
        index += kCBoardWidth;
    } else if (row == kCRowC) {
        index += 2*kCBoardWidth;
    }
    
    if (col == kCCol2) {
        index += 1;
    } else if (col == kCCol3) {
        index += 2;
    }
    return index;
}

bool CGameBoard_CellAvailable(GameBoard* board, RowIndicator row, ColIndicator col) {
    assert(board != NULL);
    
    int index = CGameBoard_CellIndex(row, col);
    return (board->cells[index].entry == kCCellNoEntry);
}

bool CGameBoard_CellsHaveSameEntries(GameBoard* board, int i, int j, int k) {
    assert(i >= 0 && i < kCNumBoardCells);
    assert(j >= 0 && j < kCNumBoardCells);
    assert(k >= 0 && k < kCNumBoardCells);
    assert(board != NULL);

    return (board->cells[i].entry != kCCellNoEntry &&
            board->cells[i].entry == board->cells[j].entry &&
            board->cells[j].entry == board->cells[k].entry);

}