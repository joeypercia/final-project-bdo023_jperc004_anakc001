# Task Scheduler

 Authors:[Bang Do](https://github.com/FireFly0000) [Artip Nakchinda](https://github.com/TheMarkVI) [Joseph Percia](https://github.com/joeypercia)
 
 Our project will be a task scheduler that will allow its user to view, add, delete, and modify a list of tasks. The tasks will have a variety of attributes including priority, type (personal/work/study), and due date. Users may create a list of tasks composed of other types of sub tasks. The user can also choose to sort their task list by priority, due date, and type. To accomplish this, we will use both composite and strategy design patterns.
 
 Creating tasks composed of other tasks can be accomplished with the composite design pattern. A composite design pattern simplifies the process of creating subtasks by allowing all tasks to be treated the same way through a common interface. By defining a base task class that we can perform all of our operations on, we can avoid the issue of having to define functions to handle every type of task. With the composite design pattern, complex or leaf objects are treated the same way, and allows complex objects to be composed of other complex or leaf objects, which is exactly the kind of functionality we need to create subtasks in our task scheduler.
 
  To solve the issue of filtering the user's tasks by certain criteria, we can use the strategy design pattern. In order to filter the tasks, we would need to implement another class that has an aggregated relationship with the base class of the tasks. This class then can be derived into different interfaces that select certain tasks to print out based on different criteria such as priority or types of the tasks. For example if we want to print out the 5 most prioritized tasks, we can implement a method in one of those derived classes to filter the tasks based on their priority. Or if we want to filter the tasks based on their types then we can have a derived class to contain a method that filters out a certain type of tasks.   
  
  We believe this project can be completed with just the C++ standard library, using CMake to compile and the Googletest framework to test.
  
  We think that this project could be interesting and important because it demonstrates how some basic design patterns could be combined to create a more complex program.
  
 - Inputs:
   * Title (string)
   * Description (string)
   * Types of tasks: type1, type2, type3 (string passed in through command line)
   * vector<BaseTasks*> (List of tasks)
   * Print* print (using to print out certain tasks based on their properties)
 - Outputs:
   * Priority (int)
   * Due Date (string) 
 - We will also rely on github work flow and unit testing in this project.
  
# Class Diagram
This class diagram included 2 design patterns composite and strategy. The composite pattern is used to create individual tasks and list of tasks that can contain tasks. The list of tasks can also represent larger tasks that contain smaller subtasks. However a list of tasks doesn't have a certain type because it can contain different types of tasks. Types of tasks will be limited to three types personal, work and study. The strategy pattern is used to filter and print out certain tasks based on their priority, types and due date. 
![Project Class diagram](https://user-images.githubusercontent.com/81598667/222568433-819e31c5-6a47-4794-bdb3-d326d226e356.png)

 ## Screenshots
 Inputs from main:
 ![inputs](https://user-images.githubusercontent.com/81598667/222568461-940671d4-3108-4d87-be66-3eb47030c5cc.png) <br>

 Command line inputs and outputs:
 ![inputs#2](https://user-images.githubusercontent.com/81598667/222568506-4f380930-265b-4d26-8ed6-f8a4387088da.png) <br>
 ![inputs#3](https://user-images.githubusercontent.com/81598667/222568534-56db6207-bbab-4d25-8b20-7d1c6d82625e.png) <br>
 ![inputs#4](https://user-images.githubusercontent.com/81598667/222568579-2b06e973-3797-4da4-99f4-0395ac019cc7.png) <br>

 
 ## Installation
 To install this program:
 - First, `git clone` this repository (include `--recursive` so googletest submodule is loaded)
 - Next, run `cmake3 .` command to build the required makefiles to build/compile program (For machines other than hammer, you can just run `cmake .`) 
 - After that, run `make` to build and compile the program.
 - Installation should be done at this point. Try running `./main` or `./test` to verify it is working correctly.
 
 ## Usage
 - Our program supports a task scheduler that can create tasks and lists of tasks(a list can contain other lists to create sublists of tasks).
 - The constructor of a single task takes in 4 strings as its title, description, type and due date. It also takes in another integer as its priority. This constructos also takes inputs from the command line so that the users can input different types of tasks (we limit it at 3 types).
 - Users can also create lists of tasks. A list only has a title, a description and a priority number. It does not have a specific due date or type because it should contains smaller tasks that can have different types and due dates. A list constructor takes in two strings for title and description and one integer for priority.
 - Users then can add different tasks or other lists to a list using the add() function. The sortP() function can be used to sort the orders of tasks based on their priority.
 - There are different ways the users can use to display the tasks. Using the set_print() functions, users can out the tasks in the following formats:
   * Print_top5: print out top 5 most prioritized tasks or sublists of a list. 
   * Print_type1: print out all tasks of type1 of a list, including the ones belong to a sublist in that list. (same for Print_type2 and Print_type3).
   * Print_date: takes in a due date and print out any tasks have that due date, includeing the ones belong to a sublist in that list.
 - There are also a delete and edit feature. Users can pass in new title, description, type, due date, or priority number to modify a task or a list using the edit() function. edit_at() helps edit a specific task or sublist in a list.
 - The del(int id) functions help delete a specific task or sublist in a list using its index number.     
 ## Testing
 - We test our program using a series of unit tests on all the main functions (features).
 - First we tested the constructor of a single task and its display formats. We also tested the edit() feature on a single task.
 - Second we tested the constructor of a list and make sure we can add tasks to a list. We then tested the display formats to make sure specific tasks are output based on their properties. 
 - Third we tested the adding of sublist to a list, we make sure that the display formats logic still work when there are sublists in a list.
 - Fourth, we tested the edit and delete features on a list to make sure that we can edit or delete a specific task a sublist in a list.
 - Finally we make sure that the program executes and runs without any errors, bugs all memory leaks.  
 
