[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/Ru2tx5lJ)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=14455099)
# 09 Domain classes

## Assignment spec

(10 points) Please provide implementation for `Students` class as declared in `domain/students.h`. Implementation should pass test case requirements as described in `test/test.cpp` under the test case `[students]` (please notice plural). 


## Steps

- Please accept `09` assignment from *BlackBoard* as usual. Visit generated repo `OU-CTCH1330/09-domain-classes-yourGitHubId` on GitHub, open Codespace.
- Bulk of the app code now is in `domain/` folder, unit tests are in `test/test.cpp`. Please spend some time making yourself familiar with new code. 
- Build unit test executable `test/test` by running task `Build test` (Menu > Terminal > RunTask). Equivalently can run `make test` in bash terminal. This step should fail at linking stage. If you search error output you can find following tell tale messages
> ld returned 1 exit status

> undefined reference to `ctch1330::domain::Students:: ...
- Above is telling that some functionality of  `Students` class as declared in `domain/students.h` has not been implemented in `domain/students.cpp`. In fact `students.cpp` file is altogether  missing! (intentionally deleted for the assignment).
- Before continuing explore relationship between `student.h` header and `student.cpp` implementation when coding `Student` (notice singular) class. We have to establish similar declaration - implementations relationship for `Students` (plural) class. <br />Note: `Student` is about modelling a single student, `Students` is about modelling the entire student body of the university. Two very different classes and functionality, but header - implementation mindset in both cases are the same.
- Our first goal is to at least get test executable to build. For this:
  - Create file `domain/students.cpp`. eg have something selected in Explorer `domain/` folder and click Menu > File > NewFile.
  - Implementation file typically starts with `#include` directive for corresponding header class. See how this is done for `Student` in `student.cpp`, do similar for `Students` in `students.cpp`.
  - Don't forget whole code lives in `ctch1330::domain` namespace. See how this is coded in `Student` in `student.cpp`, do similar for `Students` in `students.cpp`. Lecture also talks about this. 
  - The first thing to implement in `students.cpp` is definition/initiation of `students` static member from header file. This can be done with 
  ``` cpp
  #include "students.h"
  
  namespace ctch1330::domain
  {
    std::vector<Student> Students::students;
  }
  ```
  - Create stubs for functions to be implemented (still within `namespace{ ... }` brackets). Go over `students.h` header file and identify declared but unimplemented  functions there. If function code in header does not have body `{ /*some code*/}` then it is unimplemented, a mere declaration. You create stubs for these by copying their signature (their declaration) and appending empty body `{}` to it. For instance stub for `AddStudent()` would be as below. You should find **4** such functions in need for implementation and create stubs for it. 
  ``` cpp
  #include "students.h"
  
  namespace ctch1330::domain
  {
    std::vector<Student> Students::students;

    int Students::AddStudent(Student student)
    { 
      /* this is stub for now, later to be filled with code. */ 
    }    
  }

  ```
  - Once all 4 stubs have been created, test executable should at least build (run `Build test` task again). If you get errors, examine them, fix stubs. 
  - Once you get test build, this could be a good milestone to stage/commit/sync with GitHub repo (grading will for now fail).
- Now that we have test executable `test/test`, let's run it. This can be done in number of ways:
  - Run `Test all cases` task, this is the simplest, will build and run all test cases
  - Run `Test an individual case` task, pick `students` (plural) case when asked. This will build and run `[students]` test case.
  - Run `test/test --success` in bash terminal. This is testing only, will run all test cases, no build step included.
  - Run `test/test [students] --success` in bash terminal, this is the fastest. This is testing only, will run only a `[student]` test case, no build step included.
  <br /> Running from tasks (first two options) includes refreshing build. Running from terminal (last two options) is just testing, it's up to you to make sure `test/test` executable build is fresh. You can always produce fresh build with `Build test` task or `make test` bash terminal command.
- Test run will report errors, which is understandable, since we only implemented functions as stubs, without proper logic. Start implementing functions one at a time. 
<br /><span style='color: yellow'>Note:</span> please start with `AddStudent()` implementation, which is pre-req for entire test case. 
- When working on any given function:
  - Examine declaration in `students.h` file, (enhanced) comments there above each function declaration have a good description of function spec.
  - Examine test case as described in `test/test.cpp`. Our `Students` class test case is entirely in `[students]` (notice plural) **TEST_CASE**. Test case consists of **SECTION**s, each function implementation test is contained in a single section, which is accordingly named. By examining test code, you can gain more insight of what is expected from function. 
  - You can use debugger as we've examined before. Please make sure dropdown in Debugger tab (left navigation menu, 4th icon) is set to `Debug all tests` or `Debug an individual test` (not `Main program`). You set a breakpoint in target code and launch debugger  (Menu > Run > StartDebugging). Lecture has a demo of this.  
- As you fix each function, you should see respective test SECTION turning green and passing the test. Ultimately you should see all tests passing. 
  - If running `[students]` test case alone (`Test an individual case` task), you should see all **9** assertions passing, with message 
  <br /><span style='color: #8ae234'>All tests passed</span>  (9 assertions in 1 test case)
  <br />as displayed in the bottom of `test/successful_test_students.log` file.
  - If running `all` test cases (`Test all cases` task), you should see all **13** assertions passing, with message 
  <br /><span style='color: #8ae234'>All tests passed</span>  (13 assertions in 3 test cases)
  <br />as displayed in the bottom of `test/successful_test_all.log` file.
- Stage, commit and sync your code, make sure autograder accepts submission in GitHub actions. GitHub has been having a bit of a lag lately, may take up to a minute for your new sync to show up in Actions. 


## General tips 

These tips are general, not specific to current assignment.

- If something goes wrong, please reach out early on, <span style='color: #8ae234'>**DO NOT STRUGGLE**</span>. 
- Use GitHub PR, BlackBoard Discussions, MS Teams, email, or any other means for reaching out for instructor's help. Also feel free to collaborate with fellow students, especially now that sprint project has fostered an excellent teamwork. 
- Please remember, instructor can't see your code until sync'd with GitHub repo. Further, if you want to let fellow students examine your code your repo needs to be [made public](https://docs.github.com/en/repositories/managing-your-repositorys-settings-and-features/managing-repository-settings/setting-repository-visibility#changing-a-repositorys-visibility) (it's private at creation). Peer collaboration is highly encouraged, as long as it's genuine learning as opposed to mechanical copy/paste (see policies in the syllabus at BlackBoard > CTCH1330 > Docs).
- Syncing incremental progress milestones is recommended. Autograder doesn't care about repeated failures, only final success matters. 
- GitHub PR is an excellent place for code-centric discussions. This is also a standard in industry.
- Each assignment/repo expects a dedicated Codespace
- Please try not to spam Codespaces. If you've already created an instance, it's available at  [https://github.com/codespaces](https://github.com/codespaces) and they load faster (then a cold start of a fresh Codespace). Having multiple instances will fragment your work, as each Codespace has its individual local file system and one doesn't see changes in other, unless obviously synced through GitHub repo, to which they are all linked.
- Consider cleaning up CodeSpaces for past assignments. They can be deleted (if running, stopped and deleted) by clicking `...` next to them. This is optional, as old Codespaces are discarded anyway after a period of inactivity.  
