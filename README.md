# Pong

Our Project
We programmed the game using C++
We used the ncurses C++ library to program the game
ncurses uses ASCII characters to display and play the game
We use make to compile and run the game
The game can be played either by yourself or with another person
Inputs from players are taken from the keyboard
To make the AI, we simply made a “perfect” AI which will pretty much always win
This AI is what we named the ‘HardComputer’
To make the easy AI, we simply made it so the paddle moves slower
Yes, it is hard coming up with ideas of how to make an AI that isn’t perfect for pong



Design Principles
Abstraction - details of how member functions are hidden from other classes
Encapsulation - All variables and functions are kept private/protected unless it is a getter/setter function
Inheritance - there is the use of subclasses (Player2 -> EasyComp, HardComp, Human)
High Cohesion - Each class handles its own tasks. Classes don’t do things they shouldn’t. 
Loose coupling - Changing the code of one class doesn’t affect the other (strategy design pattern and factory)
Law of Demeter (Principle of Least Knowledge)
Objects only call functions that belong to itself and does not call member functions of objects from other function calls

