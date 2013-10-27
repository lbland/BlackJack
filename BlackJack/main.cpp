//
//  main.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/21/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include "BlackJackGame.h"

#include <asl.h>


int main(int argc, const char * argv[])
{
    aslclient log_client = asl_open("com.lorenbland.BlackJack", "Logging for BlackJack", 0);
    asl_log(log_client, NULL, ASL_LEVEL_INFO,"BlackJack was started");

    BlackJackGame::BlackJackGame blackJackGame;
    
    blackJackGame.Start( );
   
    asl_log(log_client, NULL, ASL_LEVEL_INFO, "BlackJack is closing");

    asl_close(log_client);
}

