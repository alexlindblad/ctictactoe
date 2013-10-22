//
//  CGameBoard.h
//  CTicTacToe
//
//  Created by Alex Lindblad on 10/21/13.
//  Copyright (c) 2013 Alex Lindblad. All rights reserved.
//

#ifndef CTicTacToe_CGameBoard_h
#define CTicTacToe_CGameBoard_h

#include <stdbool.h>

typedef enum CellEntry {
    kCCellNoEntry = -1,
    kCCellEntryX,
    kCCellEntryO
} CellEntry;

typedef enum RowIndicator {
    kCRowInvalid,
    kCRowA,
    kCRowB,
    kCRowC
} RowIndicator;

typedef enum ColIndicator {
    kCColInvalid,
    kCCol1,
    kCCol2,
    kCCol3
} ColIndicator;

typedef enum CellSelectError {
    kCCellSelectNoError = 0,
    kCCellSelectUnavailable
} CellSelectError;

struct CGameBoard;
typedef struct CGameBoard GameBoard;

GameBoard* CGameBoard_NewBoard(void);

void CGameBoard_Draw(GameBoard* board);

void CGameBoard_Clean(GameBoard* board);

CellSelectError CGameBoard_SelectCell(GameBoard* board,
                                      RowIndicator row,
                                      ColIndicator col,
                                      CellEntry entry);

bool CGameBoard_HasWinner(GameBoard* board);

#endif
