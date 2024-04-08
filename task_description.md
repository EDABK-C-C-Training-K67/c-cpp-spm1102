# Midterm Project: Building a Command-Line Shell in C

## Objective
The goal of this project is to construct a command-line shell in the C programming language. This shell should be capable of executing common cmd commands and should also have the functionality to execute commands from a file.

## Specifications

1. **Command Processing**: The shell should be capable of reading commands from the command line interface as well as from a file.

2. **Built-in Commands**: The shell should support built-in cmd commands such as `dir`, `cd`, `cls`, etc.

3. **Command Execution**: The shell should be able to execute parsed commands using system calls.

4. **Error Handling**: The shell should handle errors gracefully and provide informative error messages to the user.

## Project Breakdown

1. **Setup**: Set up your development environment. This will include a C compiler and a text editor or Integrated Development Environment (IDE).

2. **Command Processing**: Implement a function to read commands from the command line and from a file.

3. **Command Parsing**: Implement a function to parse the command into a program and arguments.

4. **Command Execution**: Implement a function to execute the parsed command.

5. **Error Handling**: Implement error handling to manage any errors that occur during command processing, parsing, or execution.

6. **Testing**: Test your shell with various cmd commands and with commands from a file to ensure it works as expected.

## Deliverables

1. Source code files (`.c` and `.h` files). Commonly there are at least 3 folders: `src`, `inc` and `bin`.
2. A `README.md` file that explains how to compile and run your shell
3. A sample commands file for testing

## Evaluation Criteria

Your shell will be evaluated based on the following criteria:

1. **Functionality**: Does your shell correctly process, parse, and execute commands?
2. **Robustness**: Does your shell handle errors gracefully?
3. **Code Quality**: Is your code **well-organized** and easy to understand?
4. **Documentation**: Is your `README.md` clear and does it accurately describe how to use your shell?

Best of luck with your project!