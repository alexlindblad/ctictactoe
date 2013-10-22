//
//  CGameBoard.h
//  CTicTacToe
//
//  Created by Alex Lindblad on 10/21/13.
//  Copyright (c) 2013 Alex Lindblad. All rights reserved.
//

#ifndef CTicTacToe_CGameBoard_h
#define CTicTacToe_CGameBoard_h

struct CGameBoard;
typedef struct CGameBoard GameBoard;

GameBoard* CGameBoard_NewBoard(void);

void CGameBoard_Draw(GameBoard* board);

void CGameBoard_Clean(GameBoard* board);

#endif
