[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/UZUHfaOB)

# Assignment 05- Multiplayer Blackjack Game Simulation #

## Overview
Develop a multiplayer Blackjack game using Java. This application simulates the server (dealer) and clients (players) and communicates over TCP/IP using sockets. The server handles game logic and client management, while each client represents a player interfacing with the server.

## Game Rules

### Card Values
- **Numbers**: Cards 2 through 10 are valued at their face value.
- **Face Cards**: Jack, Queen, and King are worth 10 points each.
- **Ace**: Can be worth 1 or 11 points, whichever is more beneficial for the hand.

### Objective
Players aim to have a hand value closer to 21 than the dealer's hand without exceeding 21.

### Player Rules
- Each player starts with two cards.
- Players can choose to "Hit" (take another card) or "Stand" (end their turn and keep their total).
- If a player's total exceeds 21, they bust and lose immediately.

### Dealer Rules
- The dealer starts with two cards, revealing only one initially.
- The dealer must hit on 16 or below and stand on a soft 17 (an ace and any other cards summing to either 7 or 17).

### Winning Conditions
- A player wins by not busting and having a total greater than the dealer's or if the dealer busts and the player does not.
- A win with a Blackjack (ace and a 10-value card) pays 3:2.
- A regular win pays 1:1.
- In case of a tie, the bet is returned to the player.

### Player Accounts
- Each player starts with a predetermined balance (e.g., $1000).
- Players place bets at the start of each round. The bet must be within the minimum and maximum limits set ($10 to $500).
- When a player is out of money, their session is ended.

### Betting Rules
- Players cannot bet more than their current balance.
- Bets are placed before cards are dealt.

### Balance Displays
- Players' balances are updated and displayed at the end of each round.
- Players with a balance of zero cannot continue playing.

## Technical Requirements

### TCP/IP Networking
- Implement TCP/IP sockets in Java to connect the server and clients.
- The server listens on a designated port, handling incoming client connections and managing game sessions.
- Clients connect to the server using its IP address and port, participating in the game through command-response interactions defined by the protocol.

### Threaded Architecture
- **Server Thread**: Manages the game logic and the actions of the dealer.
- **Client Threads**: Each thread represents a player handling decisions and communicating with the server thread.

### Communication Mechanism
- Use synchronized blocks or methods to ensure thread-safe operations, particularly for shared resources like player balances and game states.

### User Interface
- Implement a console-based interface for user inputs and game state outputs. Ensure that messages from different threads are displayed in an orderly manner without interleaving.
- Before the clients start, request the number of clients from the user.

### Communication Protocol 
- Define a text-based protocol to handle interactions between the client and server. The protocol should include commands and responses to manage the game flow.
  
#### Commands Sent to Server:
- **BET <amount>:** Places a bet.
- **HIT:** Requests another card.
- **STAND:** Ends the player's turn.
- **QUIT:** Disconnects client from the server.

#### Responses from Server: ####
- **WELCOME <initial balance>:** Acknowledges connection and sends initial balance.
- **DEALT <card1> <card2>:** Cards dealt to the player.
- **DEALER <card>:** Shows one of the dealer's cards.
- **ACTION:** Requests the player's next move.
- **RESULT <win/lose/push> <amount>:** Sends round result and updated balance.
- **ERROR <message>:** Communicates an error message.

## Sample Run
```
Welcome to Blackjack!
Enter Number of Players: 2

Initial balances:
Player 1: $1000
Player 2: $1000

Round 1:
Please enter your bet, Player 1: $200
Player 1 bets $200 and has $800 remaining.
Please enter your bet, Player 2: $150
Player 2 bets $150 and has $850 remaining.

Dealing cards...
Player 1's hand: Queen of Hearts, 7 of Diamonds (Total: 17)
Player 2's hand: 9 of Clubs, 8 of Spades (Total: 17)
Dealer's showing: King of Diamonds

Player 1, choose your action: stand
Player 2, choose your action: hit
Player 2 hits and receives: 2 of Hearts (Total: 19)
Player 2, choose your action: stand

Dealer's turn...
Dealer's hidden card is a 6 of Hearts (Total: 16)
Dealer hits and receives a 5 of Clubs (Total: 21)
Dealer stands with 21.

Results:
Player 1 loses $200. New balance: $800
Player 2 loses $150. New balance: $850
Dealer wins.

End of Round 1.
Would you like to play another round? Yes/No: no
Thank you for playing!
