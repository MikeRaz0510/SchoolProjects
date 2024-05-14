# Topical Information
This program should help clarify to you the use of inheritance (and possibly polymorphism -- see the options below).

# Program Information
Watching 'Wild Kingdom' reruns on Animal Planet has taken its toll on your psyche. You have predators and prey on the brain! You feel driven to write a predator/prey simulation to alleviate the mental cacophany.

You see that all predators share certain traits and all prey share certain traits. (Heck, from biology class you realize that all creatures on Earth share some common traits.) So you decide to make a hierarchy (or two) to power your simulation.

Think simply here. Predators have a hunger which drives them to be predatory. They have a speed/cunning factor which helps them catch prey. They can eat prey.

Prey are worth a certain amount of food to a predator (a single rabbit won't fill a wolf's appetite, but 5 or 6 might). They also have speed/cunning that help them escape. They can be eaten/killed by predators (some prey isn't killed by being eaten -- grass will simply reduce in amount of food if a cow chomps on it some).

All creatures can procreate. They might die of starvation or being eaten, but they can all re-populate.

Create your hierarchy(ies) in a library for easy re-use.

Make a sample simulation application which allows the user to choose names for the predators and prey, give them ranges of values for speed, birth rate, hunger, and food worth -- all wolves are equally fast or hungry and all rabbits aren't equally fast and food-worthy. Randomly create creatures to fill your population. Then simulate their interaction:
```
   do
      each creature gets a chance to 'spawn'
      then predators attack (a random prey) and prey flees (when attacked)
      if the attack succeeds, the predator 'eats' the prey
      remove those who have died of starvation and/or being eaten
      report the counts of predators and prey left
   repeat until _______?
```
Common stopping conditions are the user tells you how many 'generations' to do, everything is dead, everything from either predator or prey is dead, or the system seems to be stable (the count of both populations over the past n generations is the same or oscillating -- this can be checked by keeping track of the recent maxes/mins of the population counts -- last 5-10 generations or so -- and seeing if the difference between them is converging). I'd implement the first three -- they aren't too hard to combine or code.

# Options
Add (Level 2) to extract the common interfaces and make the hierarchy polymorphic.
