ReadMe
# BLACK JACK
Hello.  This is my commandline black jack game.  The rules are the dealer must hit on soft 17 and
there are no splits.  The deck is shuffled every 6 games.

#Thoughts
Here are some of the design decisions I made:
1) In a real game of Black Jack the dealer controls the game. So I put the game state machine inside the dealer class.  The dealer will prompt the user for input and process what the user wants to do.  It is also responsible for determining if the dealer should hit.
2) I thought there should be a Deck class which contains cards.  A Hand (class) consists of delt cards from the deck
3) This is the first time ive used c++11 so I wanted to leverage some of the new featueres.  shared_ptrs allow easy sharing of objects.
4) I wanted the ability to log message to the apple system logger. I looked for an open source project that did that, but did not find one.  I thought bringing in a library like boost was overkill, so i wrote a logging class that needs to be created and destroyed.  Its global so class can use it.  I could have just created a instance of the log class and passed it to all the classes but I like this solution better.  The DestroyLog method ensures the Logger is closed.  Singleton sometiems have lifecycle issues.  This will not.

5) I was looking forward to the new UT system in xcode.  I had read about XCText, but I did not know that STL does not work with this system.  So I was not able to provide unit tests with the new xcode build.  This was also my first time using Xcode 5.  

# Compile
I am using the 10.8 Latest sdk and it is targetted for the 10.8 OS.  It shoud be compiled in xcode 5 using the libc++ standard library.  Once the program is started through the commandline the dealer will let you leave the table at the end of hand, only if you want!


#Enjoy