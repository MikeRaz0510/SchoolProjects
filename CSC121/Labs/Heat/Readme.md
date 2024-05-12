# Topical Information
This lab will help you practice with vectors (and loops, of course).

# Program Information
Heat flow through a rod can be emulated fairly easily in a computer program. We can simulate the rod using a vector of temperature values. (No, heat and temperature are notthe same thing, but they are correspondent.)

The rod begins all at the same 'room' temperature. Holding one end or the other (or even both ends) of the rod at a constant temperature provides a heat source (or sink). (This represents holding a match or ice cube to the end of the rod.)

To update the temperature at each time step (seconds? micro-seconds? *shrug*), you take the average of the position and those on each side from the previous time step. For instance, if the following was the initial state of the rod:
```
+------+------+------+------+------+------+------+------+
|  10  |  10  |  10  |  10  |  10  |  10  |  10  |  10  |
+------+------+------+------+------+------+------+------+
```
And then the user specifies that there is a heat source at the left end of 100degrees (again, units are meaningless within our system):
```
+------+------+------+------+------+------+------+------+
| 100  |  10  |  10  |  10  |  10  |  10  |  10  |  10  |
+------+------+------+------+------+------+------+------+

```
Then the first time step would result in:
```
+------+------+------+------+------+------+------+------+
| 100  |  40  |  10  |  10  |  10  |  10  |  10  |  10  |
+------+------+------+------+------+------+------+------+
```
Note how the left end stays the same because it is the heat source and will not change. The next position, however, becomes the average of itself and its two neighbors — one left and one right. Likewise the position after that becomes the average of itself and its two neighbors (it just happens that its two neighbors had the same value as it did — since they all started out at 'room temperature' together and aren't near enough to the source to have yet been affected).

A second time step would result in:
```
+------+------+------+------+------+------+------+------+
| 100  |  50  |  20  |  10  |  10  |  10  |  10  |  10  |
+------+------+------+------+------+------+------+------+
```
After many time steps have passed, the heat will flow through the rod and all 7positions not attached to a heat source will eventually change. (Given enough time, they will even reach a state of equilibrium at which they all remain unchanging from step to step. In a case like this with a single source, they should all eventually reach the source temperature.)

You should allow the user to enter:

the length of their rod,

the initial temperature of the rod,

the number of time steps to simulate,

the positions of any heat sources (or sinks) (i.e. which end of the rod),

the temperatures of any heat sources (or sinks), and

the number of steps to skip between printings (that is, if they simulate for two minutes, they probably do not need to see all 120time steps...maybe just every 20th one or so).

Always display the initial (with heat sources/sinks applied) and final (after the last time step) states of the rod.

# Options
You may choose to alter your program from above to add any of the following (bulleted) options. You won't be handing in a separate program (unless specifically told to do so!). You will simply change the program you already have to adhere to the new specifications below. This change is considered significant enough to increase your level as stated below.

Again: do NOT create/hand-in multiple programs! Simply altering the program you have already written is enough to increase its level by the amount specified in the option you choose...

(Note: If the option includes its own TPQs, you mustanswer them in addition tothe ones above to earn the full credit!)

Add (Level 1.5) to allow the user to have as many sources/sinks as they please (limited only to the number of segments in the rod).
