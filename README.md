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
![Class Diagram](https://github.com/cs100/final-project-bdo023_jperc004_anakc001/blob/master/images/Project%20Class%20diagram.png)
 
 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 Inputs from main:
 ![Inputs#1](https://github.com/cs100/final-project-bdo023_jperc004_anakc001/blob/master/images/inputs.PNG) <br />
 Command line inputs and outputs:
 ![outputs](https://github.com/cs100/final-project-bdo023_jperc004_anakc001/blob/master/images/inputs%232.PNG) 
 ![Inputs#1](https://github.com/cs100/final-project-bdo023_jperc004_anakc001/blob/master/images/inputs%233.PNG)
 ![Inputs#1](https://github.com/cs100/final-project-bdo023_jperc004_anakc001/blob/master/images/inputs%234.PNG)
 
 ## Installation/Usage
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
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
