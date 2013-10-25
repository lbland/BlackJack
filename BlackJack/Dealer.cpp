//
//  Dealer.cpp
//  BlackJack
//
//  Created by Loren Bland on 10/22/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#include "Dealer.h"
#define BLACK_JACK 21


namespace BlackJackGame
{

    /****************************************
     
     Dealer class -  The dealer owns the deck
     ****************************************/
    Dealer::Dealer( )
    : m_deckPtr( new Deck( ) ),
      m_dealersCards( new Hand( ) ),
      m_playersCards( new Hand( ) ),
      m_handsPlayerWon( 0 ),
      m_handsDealerWon( 0 ),
      m_draws( 0 ),
      m_state( GameState::DEAL_CARDS ),
      m_numberOfHandsDelt( 0 )
    {
        
    }
    
    /*****************************************
     
     Start - Start Dealing
     
     *****************************************/
    void Dealer::Start( )
    {
        NextStep( );
    }
    
    /*****************************************
     
     NextStep
     
     
     *****************************************/
    void Dealer::NextStep( )
    {
        
        bool continuePlaying = true;
        
        while( continuePlaying )
        {
            switch( m_state )
            {
                case GameState::DEAL_CARDS:
                    Deal( );
                    break;
                case GameState::CHECK_HANDS:
                    CheckForBlackJacks( );
                    break;
                case GameState::PLAYERS_TURN:
                    AskForUserInput();
                    break;
                    
                case GameState::CHECK_PLAYERS_HAND:
                    CheckForPlayerBust();
                    break;
                    
                case GameState::DEALERS_TURN:
                    DealersTurn();
                    break;
                
                case GameState::CHECK_DEALERS_HAND:
                    CheckForDealerBust();
                    break;
                
                case GameState::COMPARE_HANDS:
                    CompareHands();
                    break;
                
                case GameState::PLAYER_WIN:
                    PlayerWin();
                    break;

                case GameState::DEALER_WIN:
                    DealerWin();
                    break;
                    
                case GameState::DRAW:
                    Draw();
                    break;
                
                case GameState::FINISH_HAND:
                    FinishHand();
                    break;
                
                case GameState::PLAY_AGAIN:
                    PlayAgain( );
                    break;
                
                case GameState::END_GAME:
                    
                    continuePlaying = false;
                    break;
                    
                default:
                    std::cout << "An Error has occurred, please start playing again" << std::endl;
                    continuePlaying = false;
                    break;
                
            }
        }
        
        std::cout << "Thanks for playing.  Come back again" <<std::endl;
    }
    
    
    
    /****************************************
     
     Deal - deals the blackjack hands
     ****************************************/
    void Dealer::Deal( )
    {
        // first card to player
        GiveUserOneMoreCard( );
        // dealer gets 2nd card
        GiveDealerOneMoreCard( );
        // 3rd card to player
        GiveUserOneMoreCard( );
        // dealer gets 4th card
        GiveDealerOneMoreCard( );
        
        std::cout << "You have: " << std::endl;
        std::cout << m_playersCards->GetHandShowingAllCards( ) << std::endl;
        
        std::cout << "Dealer has: " << std::endl;
        std::cout << m_dealersCards->GetDealersHandAsString( ) << std::endl;
        
        m_state = CHECK_HANDS;

    }
    
    
    /****************************************
     
     CheckForBlackJacks - checks for blackJacks
     ****************************************/
    void Dealer::CheckForBlackJacks( )
    {
        int playersHand = m_playersCards->GetCount( );
        int dealersHand = m_dealersCards->GetCount( );
        
        if( playersHand == BLACK_JACK || dealersHand == BLACK_JACK )
        {
            // dealer has to flip cards
            std::cout << "BlackJack" << std::endl;
            std::cout << "Dealer has: " << std::endl;
            std::cout << m_dealersCards->GetHandShowingAllCards( ) << std::endl;
            
            m_state = GameState::COMPARE_HANDS;
        }
        else
        {
            m_state = GameState::PLAYERS_TURN;
        }

    }
    
    
    /****************************************
     
     AskForUserInput - asks the user to give a action
     ****************************************/
    void Dealer::AskForUserInput( )
    {
        std::cout << "What would you like to do (h)it or (s)tay?" << std::endl;
        std::string input;
        getline( std::cin, input );
        
        if( input.compare("s") == 0 || input.compare("S") == 0 )
        {
            m_state = GameState::DEALERS_TURN;
        }
        else if( input.compare("h") == 0 || input.compare("H") == 0 )
        {
            GiveUserOneMoreCard( true );
            m_state = GameState::CHECK_PLAYERS_HAND;
        }
        else
        {
            std::cout << "Please enter a valid action: \n h - Hit \n s - Stay" << std::endl;
            m_state = GameState::PLAYERS_TURN;
        }
        
    }
    
    
    /****************************************
    DealersTurn - should the dealer hit if so, hit.
    
     ****************************************/
    void Dealer::DealersTurn( )
    {
        // turn over deal
        std::cout << std::endl;
        std::cout << "Dealer has: " << std::endl;
        
        // see what the dealer has
        std::cout << m_dealersCards->GetHandShowingAllCards( ) << std::endl;
        
        if( ShouldDealerHit( ) )
        {
            GiveDealerOneMoreCard( true );
            m_state = GameState::CHECK_DEALERS_HAND;
        }
        else
        {
            m_state = GameState::COMPARE_HANDS;
        }
    }
    
    /****************************************
     GiveUserOneMoreCard - give the user a card
     
     ****************************************/
    void Dealer::GiveUserOneMoreCard( bool initialDeal /* = false */)
    {
        CardPtr card = m_deckPtr->GetTopCard( );
        m_playersCards->AddCard( card );
        if( initialDeal )
        {
            std::cout << "You got: " << card->GetCardString( ) << std::endl;
            std::cout << "You have now: " << std::endl;
            std::cout << m_playersCards->GetHandShowingAllCards( ) << std::endl;
        }
    }

    
    /****************************************
     GiveDealerOneMoreCard - give the dealer a card
     
     ****************************************/
    void Dealer::GiveDealerOneMoreCard( bool initialDeal /* = false */)
    {
        CardPtr card = m_deckPtr->GetTopCard( );
        m_dealersCards->AddCard( card );
        if( initialDeal )
        {
            std::cout << "Dealer got: " << card->GetCardString( ) << std::endl;
            std::cout << "Dealer now has: " << std::endl;
            std::cout << m_dealersCards->GetHandShowingAllCards( ) << std::endl;
        }

    }
    
    
    /****************************************
     ShouldDealerHit - should the dealer hit, (TBD)dealer has to hit on soft 17.
     
     ****************************************/
    bool Dealer::ShouldDealerHit( )
    {
        int handCount = m_dealersCards->GetCount( );
        
        if(handCount >= 17)
        {
            std::cout << "Dealer has to stay." << std::endl;
            return false;
        }
        
        std::cout << "Dealer has to hit." << std::endl;
        return true;
    }
    
    
    
    /****************************************
     CompareHands - compares the 2 hands
     
     ****************************************/
    void Dealer::CompareHands( )
    {
        int playersHand = m_playersCards->GetCount( );
        int dealersHand = m_dealersCards->GetCount( );
        
        // player wins
        if( ( playersHand > dealersHand && !m_playersCards->HasBusted( ) ) || m_dealersCards->HasBusted( ) )
        {
            m_state = GameState::PLAYER_WIN;
        }
        else if( dealersHand > playersHand || m_playersCards->HasBusted( ) )
        {
            m_state = GameState::DEALER_WIN;
        }
        else if( dealersHand == playersHand )
        {
            m_state = GameState::DRAW;
        }
   
    }
    
    
    /****************************************
     CheckForPlayerBust - check for players bust
     
     ****************************************/
    void Dealer::CheckForPlayerBust( )
    {
        
        if( m_playersCards->HasBusted() )
        {
            m_state = GameState::COMPARE_HANDS;
        }
        else
        {
            m_state = GameState::PLAYERS_TURN;
        }
    
    }
    
    /****************************************
     CheckForDealerBust - check for dealer bust
     
     ****************************************/
    void Dealer::CheckForDealerBust( )
    {
        
        if( m_dealersCards->HasBusted() )
        {
            m_state = GameState::COMPARE_HANDS;
        }
        else
        {
            m_state = GameState::DEALERS_TURN;
        }
        
    }
    
    
    /****************************************
     PlayerWin - player won the game
     
     ****************************************/
    void Dealer::PlayerWin( )
    {
        m_handsPlayerWon++;
        std::cout << "You Win!" << std::endl;
        m_state = GameState::FINISH_HAND;
        
    }
    
    /****************************************
     DealerWin - Dealer Won the game
     
     ****************************************/
    void Dealer::DealerWin( )
    {
        m_handsDealerWon++;
        std::cout << "Dealer wins" << std::endl;
        m_state = GameState::FINISH_HAND;
    }
    
    /****************************************
     Draw - the game was a draw
     
     ****************************************/
    void Dealer::Draw( )
    {
        m_draws++;
        std::cout << "Game is a draw." << std::endl;
        m_state = GameState::FINISH_HAND;
        
    }
    
    
    /****************************************
     FinishHand - Print the stats for the game
     
     ****************************************/
    void Dealer::FinishHand( )
    {
        std::cout   << "Player has won "
                    << m_handsPlayerWon
                    << " games ( "
                    << static_cast<double>( static_cast<double>( m_handsPlayerWon ) /
                                            static_cast<double>( (m_handsPlayerWon+m_handsDealerWon+m_draws) )
                        * 100 )
                    << "% )"
                    << std::endl;
        
        
        std::cout   << "Dealer has won "
                    << m_handsDealerWon
                    << " games ( "
                    << static_cast<double>( static_cast<double>( m_handsDealerWon ) /
                                            static_cast<double>( (m_handsPlayerWon+m_handsDealerWon+m_draws) )
                        * 100 )
                    << "% )"
                    << std::endl;
        
        
        std::cout   << "There have been "
                    << m_draws
                    << " draws ( "
                    << static_cast<double>( static_cast<double>( m_draws ) /
                                            static_cast<double>( (m_handsPlayerWon+m_handsDealerWon+m_draws) )
                        * 100  )
                    << "% )"
                    << std::endl;
        
        // clear the hands.
        m_playersCards->ClearHand( );
        m_dealersCards->ClearHand( );
        
        m_state = GameState::PLAY_AGAIN;
        
    }
    
    /****************************************
     PlayAgain - ask user if they want to play again
     
     ****************************************/
    void Dealer::PlayAgain( )
    {
        std::cout << "What would you like to play another hand? (y)es or (n)o?" << std::endl;
        std::string input;
        getline( std::cin, input );
        
        if( input.compare("Y") == 0 || input.compare("y") == 0 )
        {
            m_numberOfHandsDelt++;
            
            if( m_numberOfHandsDelt == 6 )
            {
                std::cout << "SHUFFLING DECK" << std::endl;
                m_deckPtr->Shuffle( );
            }
            
            m_state = GameState::DEAL_CARDS;
        }
        else if( input.compare("N") == 0 || input.compare("n") == 0 )
        {
            m_state = GameState::END_GAME;
        }
        else
        {
            
            std::cout << "Please enter 'y' or 'n'" << std::endl;
        }
        
    }
    
}