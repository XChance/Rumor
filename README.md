# Rumor

This is my own Cellular Automaton, Rumor

## How it works

A few cells with a rumor are spawned on a 200 x 200 plane. 

Every tick, a cell randomly decide to talk to a neighbor. If the neighbor knows the rumor and believes it, then they share the rumor with the cell, the cell now knows of the rumor and has a certain belief value.

If the neighbor does not know the rumor but the cell does and believes it, then the cell shares the rumor with the neighbor. 

A cell can only talk five times.

### Example
![](sample_run.gif)
