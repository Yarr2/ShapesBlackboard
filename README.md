Stus Yarema 1 Assignment OOP and Design practices

I worked in Visual Studio and tried using filters, which was not very convinient and at the end GitHub looks pretty bad, next time I will try to use 
CMake build system and create usuall directories instead of filters of VS.

Here is my original class diagram based on which I started working on this project:
<img width="1006" height="1121" alt="image" src="https://github.com/user-attachments/assets/345a4bb9-2044-4980-b3ed-81591644cb08" />

as addition to this block "ICommand" was intended to be an interface so that every command I will want to add will be it's separete class.

Main idea from class diagram was implemented, although almost at every step I've seen that I need some field or method which was not in my original idea this can be clearly seen by comparing number of methods in classes at my diagram and what is in code. 

How my code works:

Firstly we have an abstract class shape, with few children who symbolise different shapes(rectangle,line,circle,triangle). This shapes are combined inside
vector as a field of Board object, which is our board we needed to do. Also there are few Utility classes like Color, Rect, FileManager, they serve a purpose of combining some functionality into one abstraction. 

Then I have huge block of CLI classes, I tried using Dependency Injection, by creating a Command interface, which will conect different commands with our main CLI body, after completing assignment I consider it not a very great decision as Command interface is basically 1 method, so it does not seem very usefull. 
