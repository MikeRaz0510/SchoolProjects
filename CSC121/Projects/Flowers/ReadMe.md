# Topical Information
This project will help you demonstrate your mastery of decision making and repetition as well as while improving your handle on functional design.

# Program Information
The Busy Bee Blossom Boutique has come to you with a quandary. Their 'Bargain Basement Blossom Basket' has sold so much that they are having trouble keeping track of their inventory for the basic components. They'd like your help.

The problem is that they aren't sure whether they have enough of each type of flower on hand because so many orders come in and different florists fill them. They need a central location to track their flower counts. If they could just enter the information and have the counts automatically updated right there next to the phone as orders come in, it would greatly simplify their lives.

A 'Bargain Basement Blossom Basket' can consist of up to 5types of flowers from 3flower categories. The price of the basket is determined by the sum of the prices for each category chosen. The three categories are pretty, so-so, and ugly. Pretty flowers cost $15.00per bunch. So-so flowers cost $8.50per bunch. And ugly flowers cost only $1.80per bunch.

The customer may choose up to 5bunchesfrom these categories — each bunch can be of a different category — to be placed in their basket. After this, the florist will pick flowers from each desired category to put together in the basket. This situation has proven win-win: the customer gets the guaranteed lowest price in town and the florist gets profits because of the categorization (similar to salad bar or buffet profit models).

The florist entering the order will need to type the number of categories first. Then they'll type the categories in — by letter (P, S, U). You'll update the inventory counts for the flowers in each category, calculate the price of the basket, and print out the new inventory values and the total price.

Of course, to update inventory values, you'll have to have read in the initial values for the category counts at the beginning of the program. (This is a little set-up phase that happens only when the program first begins. As the program loops later, this inventory set-up will not repeat!)

Watch for any possible (reasonable) error conditions! Check that you don't over-sell any flower categories. Check that the florist doesn't accidentally enter bad data (too many or too few categories). Check that they enter valid categories (we only have Pretty, So-so, and Ugly). And so on, and so forth...

Allow them to continue entering orders until they enter 0bunches for a basket. This is the special value that allows them to quit for the evening. (When this happens, be sure to display the final inventory counts so the clerk can write them down now and re-enter them in the morning!)

Don't forget to use functions to ease your design process. Among others, I'd recommend a separate function for determining the st, rd, nd, or thon the prompts (see below). Note that this can be seen as either one return value or as TWO'return' values...

As an example, you might have the program interaction look something like (the parts in blue are typed by the user):
```
$ ./flowers.out

          Welcome to the Bargain Basement Blossom Basket Program!!!
                (Designed for the Busy Bee Blossom Boutique)

How many flowers are there in the pretty category?  42
How many flowers are there in the so-so category?  105
How many flowers are there in the ugly category?  516

Thank you!!!  Please enter order information...

How many categories in this basket?  45

Too many categories!!!  You can only have 5 or fewer!!!
 
How many categories in this basket?  -4

Too few categories!!!  You can only have between 1 and 5!!!
 
How many categories in this basket?  4

What category for 1st bunch?  Q

Unknown category!!  Please enter Pretty, So-so, or Ugly (by letter!)...

What category for 1st bunch?  S
What category for 2nd bunch?  s
What category for 3rd bunch?  u
What category for 4th bunch?  P

The customer's basket will cost $33.8.

There are currently:

        41 Pretty flowers,
        103 So-so flowers, and
        515 Ugly flowers.


How many categories in this basket?  0

Thank you for using the BBBBP!!

Don't forget to record the inventory counts for re-entry tomorrow!

Sleep well...see you in the morning!

$
```
Or perhaps:
```
$ ./flowers.out

          Welcome to the Bargain Basement Blossom Basket Program!!!
                (Designed for the Busy Bee Blossom Boutique)

How many flowers are there in the pretty category?  2
How many flowers are there in the so-so category?  10
How many flowers are there in the ugly category?  51

Thank you!!!  Please enter order information...

How many categories in this basket?  3

What category for 1st bunch?  p
What category for 2nd bunch?  P
What category for 3rd bunch?  P

You cannot sell any more Pretty flowers!  I'm all out of Pretty flowers!

What category for 3rd bunch?  s

The customer's basket will cost $38.5.

There are currently:

        NO Pretty flowers,
        9 So-so flowers, and
        51 Ugly flowers.


How many categories in this basket?  0

Thank you for using the BBBBP!!

Don't forget to record the inventory counts for re-entry tomorrow!

Sleep well...see you in the morning!

$
```

# Options

You may choose to alter your program from above to add any of the following (bulleted) options. You won't be handing in a separate program (unless specifically told to do so!). You will simply change the program you already have to adhere to the new specifications below. This change is considered significant enough to increase your level as stated below.

Again: do NOT create/hand-in multiple programs! Simply altering the program you have already written is enough to increase its level by the amount specified in the option you choose...

Add (Level 1) for placing your suffix function into a library. (The one that does the st, nd, rd, ththing.) You can increase this by another (Level 0.5) to re-use the library you wrote for the associated lab.

Add (Level 2) to use a string to collect all of their basket information. Then, afterthey've entered all that information, do your inventory updates and cost calculations. (Note: You still have to make sure there are enough of a flower type to sell that many during basket information entry. Just don't do the actual inventory update and basket calculations until after entry is done.)

(You might already have your program structured a bit like this, anyway, but putting the string in is worth this little bit extra.)

Add an additional (Level 2) to do the above option but use a vector of characters instead of a string. (That's a total of (Level 4)...)

Add an additional (Level 2) to allow for the category Random. (This is for use when the customer has no real preference but doesn't want to appear arbitrarily cheap by picking all ugly flowers.) If the operator enters this category, choose either Pretty, So-so, or Ugly — not choosing a category that is already sold out, of course. Each should be equally likely — we aren't trying to gouge the customer for more cash here!

Add (Level 3) to use a structure type to hold both current inventory figures and current basket totals. I'd suggest that the struct look something like:

    struct FlowerTypes
    {
        long pretty, so_so, ugly;
    };
In other words, you'd have two variables (say inventoryand basket) instead of six variables (like inv_pret, inv_soso, inv_ugly, bsk_pret, bsk_soso, bsk_ugly). Then you'd just use the 'dot-notation' (.) to access the particular part of inventory or basket information you needed. So to see if you had enough pretty flowers to sell another bunch, you could:

    if (inventory.pretty > 0)
    {
        // okay to sell a pretty bunch!
    }
Which is somewhat more convenient and readable than:

    if (inv_pret > 0)
    {
        // okay to sell a pretty bunch!
    }
You'll want a helper function to initialize such a structure to all 0's. You'll also have to alter a couple of functions you already have: read initial inventory, print current/final inventory, update inventory figures, and track current basket vs. current inventory legality — at the least. On the bright side, though, you will be cutting down on the number of arguments to those functions! (One third as many generally speaking. *grin*)
