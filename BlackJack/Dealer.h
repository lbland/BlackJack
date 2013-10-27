//
//  Dealer.h
//  BlackJack
//
//  Created by Loren Bland on 10/22/13.
//  Copyright (c) 2013 Loren Bland. All rights reserved.
//

#ifndef __BlackJack_Dealer_h
#define __BlackJack_Dealer_h

#include <iostream>
#include <list>
#include "Deck.h"
#include "Hand.h"


namespace BlackJackGame
{
    
    static const unsigned int  BLACK_JACK = 21;
    static const unsigned int HOW_MANY_GAMES_TO_PLAY_BEFORE_SHUFFLING = 6;
    
    class Dealer
    {
        
    public:
        
        Dealer( );
        void Start( );
    private:
        
        enum GameState
        {
            DEAL_CARDS,
            CHECK_HANDS,
            PLAYERS_TURN,
            CHECK_PLAYERS_HAND,
            DEALERS_TURN,
            CHECK_DEALERS_HAND,
            COMPARE_HANDS,
            PLAYER_WIN,
            DEALER_WIN,
            DRAW,
            FINISH_HAND,
            END_GAME,
            PLAY_AGAIN
        };
        
        void Deal( );
        void AskForUserInput( );
        void DealersTurn( );
        void GiveUserOneMoreCard( bool initialDeal = false );
        void GiveDealerOneMoreCard( bool initialDeal = false );
        void CompareHands( );
        bool ShouldDealerHit( ) const;
        void NextStep( );
        void CheckForBlackJacks( );
        void CheckForPlayerBust( );
        void CheckForDealerBust( );
        void PlayerWin( );
        void DealerWin( );
        void Draw( );
        void FinishHand( );
        void PlayAgain( );
        
        
        
        DeckPtr     m_deckPtr;
        HandPtr     m_playersCards;
        HandPtr     m_dealersCards;
        
        int         m_handsPlayerWon;
        int         m_handsDealerWon;
        int         m_draws;
        GameState   m_state;
        int         m_numberOfHandsDelt;
        
    };
    
    typedef std::shared_ptr<Dealer> DealerPtr;
};


#endif /* defined(__BlackJack__Dealer__) */
