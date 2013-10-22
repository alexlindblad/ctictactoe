//
//  CGameController.c
//  CTicTacToe
//
//  Created by Alex Lindblad on 10/21/13.
//  Copyright (c) 2013 Alex Lindblad. All rights reserved.
//

#include <stdio.h>
#include "CGameController.h"
#include "CGameBoard.h"

int CGameController_Run(void) {
    GameBoard* gb = CGameBoard_NewBoard();
    CGameBoard_Draw(gb);


    CGameBoard_Clean(gb);
    return 0;
}