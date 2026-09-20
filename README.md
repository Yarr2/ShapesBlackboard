Stus Yarema 1 Assignment OOP and Design practices

!!! this is temporary README for clarity in case of early checks !!!

I worked in visual studio and extensively used VS filters which resulted in horrific looking github
page of a project.

Here I will quickly describe what and where works.

I have an abstract class Shapes with few children.

Board is a class where I store shapes. 

There are a few utility classes(Color, Rect, FileManager)

Also for CLI I have a new for me system which resulted in a whole bunch of classes, there 
I have main CLI loop , which calls a method to execute some command, where I defined Command interface
and every command type(draw, add,...) corresponds to particular class which implements it.

The Serialiser is transforming string into board and other way around, and File manager stores and 
gets strings from the file
