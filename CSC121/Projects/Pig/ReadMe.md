# Topical Information
This project will help you show your mastery of strings (and branching, looping, functions, etc.).

# Background Information
Pig Latin is a commoner's tongue from the middle ages. It was developed to make the common man sound as fancy as his/her lord. It has nothing to do with pigs or Latin. [Or maybe Jason is just making all that up... But it is a 'real' language in use by millions every day. See the Wikipedia entry for more information — just ignore that bit about programming it with recursion; you still aren't allowed to use recursion!]

To form a Pig Latin word from an English word, you first determine if the first letter is a vowel or consonant (vowels are a, e, i, o, uand sometimes y— at least for the sake of this discussion). If it is a consonant, remove its consonant group(all consonants up to a vowel; but watch out for qusince it acts together as a consonant), move this groupto the rear of the word, and add "ay"after it. If the first letter is a vowel, leave it there and simply append "yay"to the end of the word.

For example:

| English | Pig Latin | English | Pig Latin | Commentary                    |
|---------|-----------|---------|-----------|-------------------------------|
| is      | isyay     | a       | ayay      | vowel start                   |
| form    | ormfay    | to      | otay      | consonant start               |
| them    | emthay    | the     | ethay     | consonant group start         |
| through | oughthray | scroll  | ollscray  | longer consonant group start  |
| qat     | atqay     | quad    | adquay    | q vs. qu start                |
| yellow  | ellowyay  | sky     | yskay     | y start vs. y as vowel        |

(Note in the bottom two examples how yis treated as a consonant at the beginning of a word but as a vowel inside/at the end of a word.)

Here's a whole paragraph of samples:

    This is the winter of our discontent!
    My dog has 376 fleas.
    The rancid dogs of war move into our shallow graves.
    Happy Gilmore has won the Pennant!
    Trolls stroll through the quad as Brian and his scruffy pooch await the scrumptious cat stuck in a tall qat.
It would become:

    Isthay isyay ethay interway ofyay ouryay iscontentday!
    Ymay ogday ashay 376 easflay.
    Ethay ancidray ogsday ofyay arway ovemay intoyay ouryay allowshay avesgray.
    Appyhay Ilmoregay ashay onway ethay Ennantpay!
    Ollstray ollstray oughthray ethay adauay asyay Ianbray andyay ishay uffyscray oochpay awaityay ethay umptiousscray atcay uckstay inyay ayay alltay atqay.
(Note how capitalization transfers to the new first letter. Note also how punctuation is not considered part of the word.)

# Program Information
Write an English to Pig Latin translator. The user types in their sentence(s) (having a sentence end with a \nis acceptable) and you print them back out in Pig Latin.

In addition to the notes above, also watch out for the occasional word which has neither vowels nor consonants. And when watching for punctuation and/or word boundaries, note that '(single quotes; ticks) are used as not only quoting symbols but also contractions and possessive formation! Whether you decide that a hyphenated word is a single unit or two separate parts is up to you, but make your choice clear in the comments.

Be sure to let the user repeat the entry/translation cycle as many times as they want.


# Options
You may choose to alter your program from above to add any of the following (bulleted) options. You won't be handing in a separate program (unless specifically told to do so!). You will simply change the program you already have to adhere to the new specifications below. This change is considered significant enough to increase your level as stated below.

Again: do NOT create/hand-in multiple programs! Simply altering the program you have already written is enough to increase its level by the amount specified in the option you choose...

Add (Level 1) to allow them to enter a whole paragraph of text at once instead of just one line at a time.

Add (Level 3) to add a menu to allow them to translate either from English to Pig Latin orvice-versa.

Reverse is actually pretty fun! However, you'll haveto use an alternate form of Pig Latin which forms the translated form like "is-thay"for "this"— note the hyphen at the old word's end. Otherwise you'll never figure out where to stop reverse translating before the "ay"/"yay"part. Note the Pig Latin for "yellow"above, for instance.

In fact, check out these doozies!

Investigating barrier symbols to allow reverse translation back to English.
| English    | Pig Latin          | English    | Pig Latin          | Commentary                                                                                                                  |
|------------|--------------------|------------|--------------------|-----------------------------------------------------------------------------------------------------------------------------|
| stroll     | oll-stray          | trolls     | olls-tray          | *whew!*                                                                                                                     |
| our        | our-yay            | your       | our-yay            | *yeow!*  Let's watch out for that consonant y more particularly...                                                          |
| our        | our-yay            | your       | our-y,ay           | That's better. Note that we use a comma instead of a single quote mark to avoid confusion with apostrophes in contractions. |
| yellow'll  | ellow'll-y,ay      | Yasmin's   | Asmin's-y,ay       | Just remember when testing that the barrier symbols are not pronunciation barriers — just translation helper buddies.       |

(You should also subsume your "again?"question into the menu as a quit option.)

Add (Level 1) to take note of those strange words such as Yves, Yvette, or Ypsilantiwhere a leading yis not actually a consonant but a vowel — because it is being followed by a consonant rather than a vowel, you see. That is, Yvesshould be translated as Yvesyay(or Yves-yayif doing the above option for reversible translation) rather than Esyvay.

Although all the ones I've found are proper nouns, don't make that assumption in your code! (Never limit your code's potential effectiveness if you can reasonably easily help it!)

Add (Level ??) to include some prettification features as from that one lab. For each feature you include here I'll give you half the original level ('round' downto the nearest halfif necessary). That includes the original lab's level as well as those for any options. (I'd give you full, but you'll probably be doing that lab and getting full credit for the lab portion of the portfolio, anyway.)

Okay, okay! I'll tell you what. I'll give you one fourth more — so three-quarters of the original level; rounding downto the nearest half— if you re-use the lab's codes here via its library option. Of course it depends on what options you do, but that's a possible(Level 10.5)!)
