# Highway-simulation

 The 'highway' is (rows x cols) grid of cells that can be occupied by a vehicle or not. All traffic starts at the left side of of the grid (at column 0) and travels right on, never switching lane (i.e., row). If a car moves beyond the last column it exits the simulation. As input you will be given a list of arrival times of vehicles, the goal is to produce the state of the highway after a specified number of simulation steps.
 
 The highway is a (rows x cols) grid, where row 0 corresponds to the topmost lane, and column 0 is the leftmost segment. I.e., a 3 lane highway of 10 segments.
 
 
 The simulation is executed in discrete time steps. Each step consists of 2 phases:

1) the movement phase, and
2) the arrival phase.

In the movement phase, all the vehicles that are already on the highway get to move. They do not move synchronous, but one after another: vehicles that entered the simulation first get to move first.

After all vehicles already on the board have been given the opportunity to move, new vehicles can arrive. These are read from a list that serves as the program input.

Input :

First a row with 3 integers:

number_of_rows number_of_colums number_of_timesteps

that specify the size of the highway and the number of steps to simulate.

This is followed by the aforementioned list of arrivals. Each entry is a row with 2 integers:

arrival_time row_index
-These rows will be ordered based on arrival time.


Output : 

The state of the highway after number_of_timesteps have been simulated, encoded as follows:

'.'  denotes empty space
'1'  denotes a vehicle
