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
    std::cout << "**********************************************" << std::endl;
    std::cout << "****          Welcome To BlackJack        ****" << std::endl;
    std::cout << "**** Here are the rules                   ****" << std::endl;
    std::cout << "****     Dealer has to hit on a soft 17   ****" << std::endl;
    std::cout << "****     No Splitting                     ****" << std::endl;
    std::cout << "****     No Insurance                     ****" << std::endl;
    std::cout << "****     Enjoy! Let the game begin.       ****" << std::endl;
    std::cout << "**********************************************" << std::endl;
    std::cout << "**********************************************" << std::endl;
    
    
    // create a logger instance
    BlackJackGame::Logger::CreateLog();

    BlackJackGame::Logger::LogMessage("Starting BlackJack");

    BlackJackGame::BlackJackGame blackJackGame;
    
    // start the black jack game
    blackJackGame.Start( );

    BlackJackGame::Logger::LogMessage("Quitting BlackJack");
    
    //Destroy the logger.
    BlackJackGame::Logger::DestroyLog();
    
}

