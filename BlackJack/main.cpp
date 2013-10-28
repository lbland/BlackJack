//
//  main.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/21/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include "BlackJackGame.h"
#include "Logger.h"


int main(int argc, const char * argv[])
{
    BlackJackGame::Logger::GetInstance()->LogMessage("LORESNTEST", BlackJackGame::ErrorLevel::ERROR);

    BlackJackGame::BlackJackGame blackJackGame;
    
    blackJackGame.Start( );

}

