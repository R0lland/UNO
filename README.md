## UNO
UNO Game in C++ by Mateus Trombetta.

# Cards available
- Number Card: Cards with a color and a number from 0 to 9.
- Reverse Card: Cards that change the direction of the game.
- Skip Card: Skips the next player turn.
- Draw +2 Card: Makes the next player draws 2 cards
- Wild card: Changes the color for any color the player wants
- Wild +4 card: Changes the color of the game, and makes the next player draws 4 cards.
- Swap Card: Allows the player to swap his cards with any player
- Draw +2 Discard Card: Draws 2 random cards from the discard pile.

# Commands Available
- Draw Card: The player can draw a card during his turn if he didn't used a card. Changes turn to another player.     
- Clear Console: Player can clear the console any time. Does not change turn.    
- UNO: The player can shout Uno when he has 2 cards in hands. Does not change turn.   

# How to play:
The game starts by asking how many player will play the game, the number of player must be between 2 and 10.   
The game will display all the player cards and start the turn.   
Each turn, the player must choose between a card or an action, they are choosen using an id for each item.   

Choosing Cards:   
Example: `[0] yellow 7`   
`[0]` - represents the id you must put in the console.   
`yellow` - indicates the card color.  
`7` - display value of the card.   

Choosing Actions:   
Example: `[100] Draw Card`   
`[100]` - represents the id you must put in the console. Special actions ids are over 100.   
`Draw Card` - indicates the action you will perform.

When one player wins, the game can be replayed if desired.

Coloring System used: https://github.com/aafulei/color-console
