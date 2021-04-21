# Task Scheduler

 > Authors:\<[Bang Do](https://github.com/FireFly0000)\> \<[Artip Nakchinda](https://github.com/TheMarkVI)\> <[Joseph Percia](https://github.com/joeypercia)\>

  
## Project Description 
 > Your project description should summarize the project you are proposing. Be sure to include
 > * Why is it important or interesting to you?
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * [toolname](link) - Short description
 > * What will be the input/output of your project?
 > * What are the two design patterns you will be using? For each design pattern you must explain in 4-5 sentences:
 >   * Why you picked this pattern and what feature you will implement with it
 >   * What problem you anticipate encountering when implementing your project that you will solve using the design pattern
 >   * Why the chosen design pattern will lead to a good solution to that problem
 > * This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 
 
 Our project will be a task scheduler that will allow its user to view, add, delete, and modify a list of tasks. The tasks will have a variety of attributes including priority, type (personal/work/study), and due date. Users may create a list of tasks composed of other types of sub tasks. The user can also choose to sort their task list by priority, due date, and type. To accomplish this, we will use both composite and iterator design patterns.
 
 Creating tasks composed of other tasks can be accomplished with the composite design pattern. A composite design pattern simplifies the process of creating subtasks by allowing all tasks to be treated the same way through a common interface. By defining a base task class that we can perform all of our operations on, we can avoid the issue of having to define functions to handle every type of task. With the composite design pattern, complex or leaf objects are treated the same way, and allows complex objects to be composed of other complex or leaf objects, which is exactly the kind of functionality we need to create subtasks in our task scheduler.
 
  To solve the issue of filtering the user's tasks by certain criteria, we can use the iterator design pattern. In order to filter the tasks, we would need to implement different methods of iterating through the list depending on the criteria the user selected. For example, if we wanted to filter the user's task scheduler to only include a certain type of task, we could create a taskType iterator that would only visit tasks of the specified type. Or, if we wanted to filter by priority, we could create a priority iterator to get the priority of each task. Since we will most likely be using code to iterate through the task list many times throughout the project, having an interface to iterate through the task list will greatly reduce the amount of lines of code we use in the end.
  
  We believe this project can be completed with just the C++ standard library, using CMake to compile and the Googletest framework to test.
  
  - Why is the project important/interesting?
  - Inputs/Outputs
  - Other tools/technologies??
  

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
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
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
 
