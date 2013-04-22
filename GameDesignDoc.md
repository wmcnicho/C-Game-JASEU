#Just Another ShootEmUp (JASEU)
My game is going to be a simple "Shoot em' up" style game. This type of gmae follows a top down scroller where the player controls
a spaceship or other type of craft that can shoot at other enemy spaceships.

#Enemy types (i.e. things)
  +Crusher(5 pts)- An enemy that only moves in vertical lines. Looks like a bunch of spikes.
  +ZigZagger(10 pts)- An enemy that moves in diagonal lines. Looks like an orange letter Z.
  +Tops(10 pts)- An enemy that moves in in progressively larger circles. Looks like a sunflower
  +Shooters(12 pts)- An enemy that moves in a horizontal line from one side of the screen to the other. When it reaches the other side
  it fires a projectile. Looks like a space ship
  +SonOfA***(50 pts)- An enemy that moves in a random direction and very quickly. Looks like a trollface.
  
#Gameplay
Gameplay consists of the basic use of W A S D or arrow keys to move your ship across the screen. When the spacebar or enter key is pressed a 
projectile will fire from the front of the spaceship. Player lives are tracked by a simple text object in the top of the screen. They the player
ship is hit by a projectile or enemy unit the play loses a life.  If a player scores 500 points they will gain another life. The player starts
with 3 lives (at the initilization of the game or after using a continue).

#Scoring
Score increases incrementally as time goes on (1 point every 2 seconds). Points are also gained by destroying enemies. If the player uses a
'continue' (3 max) he loses half his points and only recieves points at half the rate as before.

#Layout
![layout](http://i38.tinypic.com/15wmkqr.jpg "Layout")
#Ignore this stuff
You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.

Just make sure to separate paragraphs with an emptyline. 
Otherwise, they are considered in the same paragraph.

You link to [Google](https://www.google.com) as such and lists are written has follows:
  1. First you indent with two empty spaces.
  1. Then, you use:
    * `1.` to signal an ordered (i.e. numbered) list, or
    * `*`, `-`, `+` to represent an unordered list.
      1. Make sure to maintain indentation
      1. As it is used to identify sub-lists
  1. Numbering and symboles don't matter as they are auto-generated later.

Tables are pretty easy to make:

| Tables        | Are           | Easy          |
| ------------- |:-------------:| -------------:|
| left-aligned  | centered      | right-aligned |
| header are    | bolded and    | centered      |
| zebra stripes | are neat      | 1             |


Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")

