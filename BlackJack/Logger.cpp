//
//  Logger.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/28/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include "Logger.h"

#include <asl.h>

BlackJackGame::Logger* BlackJackGame::Logger::s_instance = NULL;

namespace BlackJackGame
{
    /*******************************************
     
     Logger
     destructor - need to close the log
     *******************************************/
    Logger::~Logger( )
    {
        asl_close(m_log);
    }
  
    
    /*******************************************
     
     CreateLog
        Create the logger
     *******************************************/
    void Logger::CreateLog( )
    {
        if(s_instance == NULL)
        {
            s_instance = new Logger( );
        }
    }
    
    /*******************************************
     
     DestroyLog
      Ensure destroying the logger
     *******************************************/
    void Logger::DestroyLog( )
    {
        if(s_instance)
        {
            delete s_instance;
        }
        
    }

    
    /*******************************************
     
     Logger 
        Allow objects to log a message
     *******************************************/
    void Logger::LogMessage( const char* message, ErrorLevel level /*= INFO*/ )
    {
        Logger *instance = GetInstance( );

        switch(level)
        {
            case ErrorLevel::INFO:
                asl_log(instance->GetLog( ), NULL, ASL_LEVEL_INFO, "%s", message);
                break;
                
            case ErrorLevel::WARNING:
                asl_log(instance->GetLog( ), NULL, ASL_LEVEL_WARNING, "%s", message);
                break;
                
            case ErrorLevel::ERROR:
                asl_log(instance->GetLog( ), NULL, ASL_LEVEL_ERR, "%s", message);
                break;
                
            case ErrorLevel::EMERGENCY:
                asl_log(instance->GetLog( ), NULL, ASL_LEVEL_EMERG, "%s", message);
                break;
                
            default:
                
                //unknown error levels should be debug
                
                asl_log(instance->GetLog( ), NULL, ASL_LEVEL_DEBUG, "%s", message);
                break;
        }
        
        
    }
}