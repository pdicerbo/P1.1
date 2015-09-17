Land or Water?
==============

Main task
---------

Write a program that takes geographic coordinates as input from the user or on stdin, and prints out if that point is on land or on water. The program should be useable as part of a UNIX pipe on the command line. 

Helpful datasets for this task are available from http://www.landcover.org/data/landcover/. One data set is checked in to the course Git repository with its accompanying information sheet.

Remember docstrings and testing!

Extra task 1
------------

Decide for each earthquake in the attached file if it occured on land or on water and add that information as an additional column to the data file.

Extra task 2
------------

Add a command line option to your tool that plots the land cover type in a 10°x10° box around the requested position. This option does *not* need to work in a pipe.

Useful tools
------------

Find out more information about these, they will be useful in your task:

* numpy.fromfile
* numpy.memmap
* argparse (Python standard library)
* matplotlib.plt.imshow
