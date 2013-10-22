//
//  CGameController.c
//  CTicTacToe
//
//  Created by Alex Lindblad on 10/21/13.
//  Copyright (c) 2013 Alex Lindblad. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include "CGameController.h"
#include "CGameBoard.h"

typedef struct User {
    CellEntry currentEntry;
} User;

void CGameController_SwitchUser(User* user) {
    if (user->currentEntry == kCCellEntryX) {
        user->currentEntry = kCCellEntryO;
    } else {
        user->currentEntry = kCCellEntryX;
    }
}

void CGameController_PrompUserForInput(User user, RowIndicator* row, ColIndicator* col) {
    if (user.currentEntry == kCCellEntryX)
        printf("X-> ");
    else
        printf("O-> ");
    
    printf("select a cell: ");
    char input[2];
    scanf(" %2c", input);
    if (input[0] == 'a' || input[0] == 'A') {
        *row = kCRowA;
    } else if (input[0] == 'b' || input[0] == 'B') {
        *row = kCRowB;
    } else if (input[0] == 'c' || input[0] == 'C') {
        *row = kCRowC;
    }
    
    if (input[1] == '1') {
        *col = kCCol1;
    } else if (input[1] == '2') {
        *col = kCCol2;
    } else if (input[1] == '3') {
        *col = kCCol3;
    }
    
}


int CGameController_Run(void) {
    GameBoard* gb = CGameBoard_NewBoard();
    
    User user;
    user.currentEntry = kCCellEntryX;
    
    while (!CGameBoard_HasWinner(gb)) {
        CGameBoard_Draw(gb);
        RowIndicator row;
        ColIndicator col;
        CGameController_PrompUserForInput(user, &row, &col);
        while (CGameBoard_SelectCell(gb, row, col, user.currentEntry) != kCCellSelectNoError) {
            CGameBoard_Draw(gb);
            printf("Invalid input, please try again.\n");
            CGameController_PrompUserForInput(user, &row, &col);
        }
        
        CGameController_SwitchUser(&user);
    }
    CGameBoard_Draw(gb);
    printf("We have a WINNER!!!\n");
    CGameBoard_Clean(gb);
    return 0;
}