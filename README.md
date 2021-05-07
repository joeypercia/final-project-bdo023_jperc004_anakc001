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
   * Types of tasks: personal, work, study (Tasks)
   * vector<Tasks*> (List of tasks)
 - Outputs:
   * Priority (int)
   * Due Date (string) 
 - We will also rely on github work flow and unit testing in this project.
  

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
# Class Diagram
This class diagram included 2 design patterns composite and strategy. The composite pattern is used to create individual tasks and list of tasks that can contain tasks. The list of tasks can also represent larger tasks that contain smaller subtasks. However a list of tasks doesn't have a certain type because it can contain different types of tasks. Types of tasks will be limited to three types personal, work and study. The strategy pattern is used to filter and print out certain tasks based on their priority, types and due date. 
![Class Diagram](https://raw.githubusercontent.com/cs100/final-project-bdo023_jperc004_anakc001/master/class%20diagram.png?token=ANHJRTOUMR5XTOL6VRV6323ATTQLS)
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
