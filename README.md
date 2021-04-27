ADASHIPS

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
o	player versus computer
o	Player versus Player

My initial design for the game was to have a selection of classes, specifically for the gameboard I wanted it to store information on the board and the target board, these methods would print the board and fire at a position. It will also have a child class for the boats that also store information about the boats and the methods that will display and place the boats and so on. Each user will have their own instance of the classes so that the user’s boats and boards are kept separate from each other. 
The main file will introduce a main menu system in it where the user can choose which game mode they would like to select. Wanting to make sure the programme runs efficiently   and wanted to achieve with a passing programme I have included 1 game mode to ensure that the system would run with no compiling errors. After including the only game mode. I wanted to make a push to include 2 more games mode in player versus player and both salvo game modes for player an AI. This would then call the relevant functions. As well as game modes I also includes a set up file for all functions related to setting up the player’s gameboard which will be called from the main file. Lastly, I introduced a file to store functionality that use a looping function to repeat each player turn until either of the player or the AI had won.

UML Diagram:

A UML flowchart diagram depicting my proposed solution I have outlined above. (file added via pdf)

Custom Board Dimensions:

The dimensions of the board will be imported from a file, essentially this means that the overall size of the board could be between 5x5 to 50x50, for my board size I decided to make it an optimal size for users’ depth of field and screen size fitting so that they are able to see all aspects of the game clearly.
Development:
Analysis & Decomposition:
For this assignment the required language is C++, a low-level language from the C family. Object orientated programming (OOP) will also need to be involved throughout the program executing objects that are organized into classes, which allows individual objects to be grouped together.
Approaching this development stage, I adopted the waterfall methodology which involved me constantly stress testing multiple elements to ensure that it would running without any bugs or errors. The development process for me involved me separating keeping a good standard of code specifically keeping everything as organised, simplicity is key in the flow of code as well as the logical aspect of it. Commenting and wanting to make it easier to non-programmers to understand what is going on. I believe in the philosophy of breaking, you will learn from it and I believe stress testing your code will ultimately make you better. I believe showing firstly a full operational game firstly was crucial before trying at merit level features. 

Design Challenges- features:

Upon the aesthetic side of things, for whoever may want to play “ADAShips” I wanted to create an environment that is enjoyable for any age. I took inspiration from the classic game and decided to add graphical aspects of it into the game such as the retro block styling menu.

Good standards of code:

I strive to use good coding standards throughout my code:
•	Include good quality, clear, jargon free and up to date internal documentation / comments; adopt
the philosophy of writing comments for non-programmers.
•	Simplicity in logic and flow.
•	Use a consistent naming convention for functions, variables, objects,  to provide clear contextual value, improved comprehension, and quick readability.
•	Use appropriate and consistent indentation, logical grouping, and spaced blocks within your codebases; adopt tabs or a set number of spaces for indenting.
•	Use spaces consistently to separate operators and delimiters.
•	Be consistent when aligning braces; use a vertically or slanted style.
•	Avoid single (long) lines of code containing multiple operations; consider ‘one line one instruction”.
•	Keep variable lifetimes and scope as short and as small as possible.
•	Avoid multipurpose functions and variables.
•	Know and test your code: adopt a personal and rigorous testing strategy; don’t just see it if works - test and fix its limits.
•	Test early and often, fail fast and resolve effectively.
To ensure I follow these standards I will repeatedly reflect on my code and review if there are any changes needed to follow these standards and refactor it if needed.
Development Phrases:
Keeping things organised and concise was important to me, I firstly set up the main structures of my code by creating classes under different characteristics of the game such as “gameboard”, “gamesetup” and “helpers”, during this phrase I found that it is the best practice to have a matching header file correspond for each file of the code where the classes as well as making sure functions are defined and all libraries are included. I think it makes things clearer and it's easier to use code from other files in another file.


Code Quality:

Throughout the programme whilst making code changes, I stress tested the programme, checking for a compiling error or bugs that I may come across. I tested using large inputs, edge cases and standards inputs to make my testing my robust to ensure that my code was operating at a high working level. If I came across an error, I would make a note of it and then add it to my personal review within the readme file to eventually find to solution.

Evaluation Analysis:

Throughout my coding process I took an iterative approach when it came to refactoring, for me I had an issue, I wanted to improve the design and the format of it without changing the behavioural aspects of it and do my best at preferring the functionally that being for each section and each task of the programme.
Coherence:
Module cohesion plays an important role due to the design of my classes; they are very focused on all methods within the class making sure that all function properly and that they relate back.

Issues:
•	spaces and non-standard capitalisation of the config file causes an error that breaks the programme. It is recommended you follow the current format when adding to the config file to prevent these errors. This refers to the good standard of coding where (Use spaces consistently to separate operators and delimiters.
•	placing a ship hasn't been configured to work with board sizes bigger than 10
•	for the code to support any number of boats I haven't added functionality to check whether the boats provided will fit in the specified board.
•	Refactoring – Keeping the consist shape to the programme front and back end.

Reflective Review:

Having very little know of coding let alone C++, this assignment has given me a greater understanding of what is achievable via using classes and objects and how they are associated with attributes and methods. Understanding the differences with private and public and how you can execute them in many scenarios as well doing extra research into header files and how that correlates to using good standards of code will ultimately make you a better programmer.
I believe if I had more time, I would have been able to implement more game mode and have them running efficiently. In review I was exposed to a wide range of standards and programming principles. Due my gameplay functions a filed being quite large, there is a lot of code repetition due to different games being very specific but instead calling different functions. Another aspect I wish I had introduced would have been to implement more OOP principles and refactor sections of code into their own functions, I believe this function orientated approach would improve clarity and readability

