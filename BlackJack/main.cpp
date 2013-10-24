//
//  main.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/21/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include <iostream>
#include "BlackJackGame.h"


int main(int argc, const char * argv[])
{
    std::srand( static_cast<unsigned int>( std::time(0) ) );
    
    BlackJackGame::BlackJackGame blackJackGame;
    
    blackJackGame.Start( );
}

