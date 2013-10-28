//
//  main.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/21/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include "BlackJackGame.h"
#include <log4cxx/logstring.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/ndc.h>

using namespace log4cxx;
using namespace log4cxx::helpers;


int main(int argc, const char * argv[])
{

    BasicConfigurator::configure();
    LoggerPtr logger(log4cxx::Logger::getLogger("com.foo"));
    //LOG4CXX_INFO(<#logger#>, <#message#>)
    //::log4cxx::helpers::MessageBuffer oss_;
    //logger->forcedLog(::log4cxx::Level::getInfo(), oss_.str(oss_ << "LOGG"), LOG4CXX_LOCATION);

    logger->log(::log4cxx::Level::INFO_INT, "TEST", LOG4CXX_LOCATION);
    BlackJackGame::BlackJackGame blackJackGame;
    
    blackJackGame.Start( );

    //LOG4CXX_INFO(logger, "Quitting Blackjack ");
}

