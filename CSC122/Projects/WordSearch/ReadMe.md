# Topical Information
The purpose of this project is to test your ability to use files, strings (or Strings?), dynamic memory, and libraries effectively in program design.

# Program Information
A popular past-time is the word search puzzle (if you don't believe me, look in your daily paper and in the news stand in the check-out line at the grocery store). In such a puzzle, a grid of letters is presented which presumably contains words. However, the words are cleverly hidden among the other letters. Their camouflage is aided by them being aligned in many different orientations: horizontal, vertical, diagonal, and sometimes even backwards! The person's goal is to find the words and circle each one. Most often the person is also given a list of the words which should be found:

    apple                        hananabs
    pear                         mpearoap
    banana                       npsgrape
    grape                        uleapnbm
    orange                       aenuraol
                                 agrafnel
                                 epanqust
bananais located backwards across the top row. appledrops down from the last ain banana. pearis forwards from the first pin apple. grapeis on the line below this. orangeis on a backwards diagonal crossing grapeat the r.

You'd like to write a program to create such puzzles and let people play the game "virtually". (No, I'm not implying polymorphism...) You've got a file with plenty of words to choose from or its companion with no proper nouns and you're fairly certain you can randomly choose words from the list and place them with other random characters in a grid.

How big should the grid be? Well, square is typical and wide enough to hold the longest word selected horizontally would be good. Maybe add a little wiggle room — two spaces on each side just for flexibility perhaps? Of course, you remember how to create a dynamically sized 2D structure, don't you?

What's that? Not sure how to place them in a grid with random characters? Well, the most obvious way to place the words in the grid is to simply choose a position and orientation at random, checking to see that any crosses occur at the same letter. If they do, place it. If not, select a new random position/orientation. Continue until you've placed the word or MAX_TRIESplacement attempts have failed (if you don't cap it, you may never end). So, given the word list (apple, pear, banana, grape, and orange), you might place things like this:

    apple                         ananab 
    pear                          pearo  
    banana                        p grape
    grape                         l a    
    orange                        en     
                                  g      
                                 e       
bananawas chosen for a backwards, sideways orientation and there was enough room. applewas chosen for a forwards, down orientation and happened to cross bananaat an a. pearwas chosen for forwards, sideways and crossed appleat a p. orangewas chosen for a backwards, back-diagonal and didn't cross anything (at the time). Finally, grapewas chosen for forwards, sideways and crossed orangeat the r.

Then just fill in the rest of the grid with random letters (don't worry if they happen to spell other words, that's what the word list is there for -- to limit what the player is searching for). Be careful of not only single crosses, but double and higher crosses: see how applecrosses with both bananaand pearabove.

Now the only confusing part is how the user will circle the words they've found!..*eww*

Since it would be hard for the program to detect the user drawing circles on the screen, perhaps the user could merely enter the coordinates of the beginning character and indicate a direction/length/ending coordinate and the program would simply remove the word from their to find list (perhaps giving them points or something...).

But then it can be confusing for the user to ignore that word if it isn't highlighted in some way. The simplest way would be to have everything begin in lowercase and then uppercase words which have been found. ...yeah, that's probably good enough.

So, in the above grid, after the user found the word orange, the program would display:

    apple                        hananabs
    pear                         mpearOap
    banana                       npsgRape
    grape                        uleApnbm
                                 aeNuraol
                                 aGrafnel
                                 Epanqust
See how the found word now stands out from the surroundings? *sigh* Squint, then!

# Options
You may choose to alter your program from above to add any of the following (bulleted) options. You won't be handing in a separate program (unless specifically told to do so!). You will simply change the program you already have to adhere to the new specifications below. This change is considered significant enough to increase your level as stated below.

Again: do NOT create/hand-in multiple programs! Simply altering the program you have already written is enough to increase its level by the amount specified in the option you choose...

Add (Level 3) to use operator overloading to good effect in your class design. (I'd consider using an operator to insert new words into the puzzle, an operator to shuffle the puzzle, and an operator to test whether a user-entered position was a match to a real word in the puzzle. But there are surely others...)

Add (Level 2) to use ANSI terminal escape sequences to do highlighting of found words. (Hint: the sequence you are most interested in is the set graphics rendition; but colors are also cool.) These sequences won't work on all terminals. (DOS/WinXX will need to have ansi.sys or ansi.com loaded for them to work, for instance.)

Other resources:

ANSI/VT100 Terminal Control Escape Sequences (especially Set Display Attributes at the bottom)
ANSI in bash under Linux (see section 6.1)
ANSI color escape sequences at StackOverflow
ANSI Escape Sequences Technical Notes (see the Display Attribute section)
dir_colors Man Page (coloring Linux ls output)
OS/2 FAQ (see, this stuff even works on OS/2!)
Be careful as ANSI sequences may not mesh well with cout. Only use the highlighting/color codes.

The user should be allowed to choose whether to use the ANSI highlighting or the UPPERCASE highlighting. (You may make this a startup option or an interactive option.)

Add (Level 4) to do a crossword puzzle insteadof a word search. A good crossword will have a theme to tie all the words together. (This isn't required, but it would actually make it easier for you, I'd think.) You'll have to come up with words and clues yourself (you won't need more than 40-80 to show that your program works).

Also study a few crosswords to see how they are formed. You'll notice that on children's versions, words are almost never placed side-by-side (otherwise, they'd have to form two-letter, three-letter, or even longer words all along the common overlap -- Scrabble™-style). Grown-ups' puzzles do this, but they don't stay on topic! (Aka the 'theme' mentioned above...)

Note that they typically have some form of symmetry. Add another (Level 2) if your puzzles do too.

Thought-provoker: How will you number the puzzle items? Note that there is a "Down" list and a "Across" list of clues and each is numbered separately. If you look around a bit, you'll notice that if two words intersect at the head, they share a number. Otherwise, they are numbered essentially from left to right and top to bottom.

Thought-provoker: How will you show the form of the puzzle until they fill in a word?

Add (Level 3) to use a more sophisticated placement method. One in particular would be to create a statistics list for each letter. While reading through your word file, create a list for each letter of the alphabet. The list should contain nodes with a word's file position, the number of characters that precede this letter in the word, and the number of characters that follow this letter in the word. Since you don't know how many words are in the file or how long each is, the list should be dynamic. To save lots of re-allocation -- and add another (Level 2.5), make the list a linked list (with allinsertion and removal functions implemented).

Note that there may be several 'hits' for the same word. If your file started like this:
```
   banana
   apple
```
Then your information list might look something like:

    a --> { 0, 1, 4 }, { 0, 3, 2 }, { 0, 5, 0 }, { 7, 0, 4 }
    b --> { 0, 0, 5 }
    c --\\
    d --\\
    e --> { 7, 4, 0 }
    ...
Since there are 3 a's in bananaand one in apple, etc. (The \\here represent nullptr pointers -- hence empty lists. The { } groups are nodes. I've simply comma-separated the nodes instead of linking them to save typing and space.)

Hint: You can store the pointers to the head of each list in an array/vector 26 elements long -- one position for each letter. (The index can be found by tolower(letter)-(______)'a'. Just fill in the (______) with long or vector<YourListType>::size_type as appropriate...)

Once you've gotten all this information, placement becomes easier: simply pick a grid position, look through the list for the letter that's there and figure out if any word even CANfit there (watch out for orientation!). If so, use it (you have its file position). If not, try a new grid position.

Note that this option can help with both the word search and the crossword version. However, depending on what file format you choose for your crossword words/clues, it may be more difficult to gather this information.
