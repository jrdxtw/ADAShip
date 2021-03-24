# ADAShip 

Challenge Outline
Adaship, a take-off the classic 1v1 sea warfare game; Battleship! is a command-line game. The idea of the game is that You and an opponent each place a number of sea operated ships such as submarines, patrol boats even deadly destroyers on your own board, you must then alternate turns "firing" torpedoes and missiles at each other’s ships. The game is won when one player has destroyed or sunk all the emery player’s ships. boards will have to gather and hold data relating to placed boats, fired shots, and missed shots. The player also needs to be able to take torpedo shots and receive information on the result of the shot (hit/miss).
When all opposing warfare vehicles are destroyed then then the player wins the game. A CPU player needs to be created utilising an auto-placing feature. The boards will also need to be displayed to the user containing the placed ships and hits/misses. The game needs to prevent invalid input but also invalid auto placing & manual placements.
The main requirements of the game are:
•	the size of the board and details on the ships should be stored in a separate text or ini file and be read by the programme
•	the board locations should be referenced using a single notation type coordinate system e.g. (A5, D2, F10)
•	the board must have letters along the X axis to represent each column and numbers along the Y axis to represent each row
•	players ships can be placed horizontally or vertically and cannot be placed on another ship or at all outside of the board's boundaries
•	the programme should display whether a ship has been hit or if it has been destroyed/ sank
•	there are multiple 'game modes':
o	player versus computer
o	player versus player
o	player versus computer salvo game
o	player versus player salvo game
o	player versus computer with hidden mines
o	player versus player with hidden mines
o	computer versus computer with hidden mines

My solution includes:

Player One v AI

One player takes on the Adaship battleship supercomputer. 

Custom Board Dimensions:

The dimensions of the board will be imported from a file, essentially this means that the overall size of the board could be between 5x5 to 50x50, for my board size I decided to make it an optimal size for users’ depth of field and screen size fitting so that they are able to see all aspects of the game clearly.
Analysis, Decomposition & Development
For this assignment the required language is C++, a low-level language from the C family. Object orientated programming (OOP) will also need to be involved throughout the program executing objects that are organized into classes, which allows individual objects to be grouped together.
Approaching this development stage, I adopted the waterfall methodology which involved me constantly stress testing multiple elements to ensure that it would running without any bugs or errors. The development process for me involved me separating keeping a good standard of code specifically keeping everything as organised, simplicity is key in the flow of code as well as the logical aspect of it. Commenting and wanting to make it easier to non-programmers to understand what is going on. I believe in the philosophy of breaking, you will learn from it and I believe stress testing your code will ultimately make you better. I believe showing firstly a full operational game firstly was crucial before trying at merit level features. 

Design features:

Upon the aesthetic side of things, for whoever may want to play “ADAShips” I wanted to create an environment that is enjoyable for any age. I took inspiration from the classic game and decided to add graphical aspects of it into the game such as the retro block styling menu.

Reflective Review:
Having very little know of coding let alone C++, this assignment has given me a greater understanding of what is achievable via using classes and objects and how they are associated with attributes and methods. Understanding the differences with private and public and how you can execute them in many scenarios as well doing extra research into header files and how that correlates to using good standards of code will ultimately make you a better programmer. 
