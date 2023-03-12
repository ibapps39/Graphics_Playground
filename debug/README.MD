# Debugging and Unit Testing
## What is this folder for?
- This is where the unit tests and other debugging files are located.
## What tests are available?
- The following are available:
  - [Under Contribut]
## What CFLAGS are used and why?
- -g: Generate debug information for the binary, which allows you to use a debugger to step through your code and inspect variables.
- -Wall: Enable all warning messages, which can help you catch potential problems before they become bugs.
- -Wextra: Enable additional warning messages not enabled by -Wall.
- -pedantic: Enable warnings for non-standard or undefined behavior, which can help you write more portable code.
- -std=c17: Use the C99 standard, which adds new features to the C language.
- -D_GNU_SOURCE: Define _GNU_SOURCE macro, which enables various GNU extensions.
- -D_DEBUG: Define _DEBUG macro, which allows you to include additional debugging.
- -D_UNIT_TEST: Define _UNIT_TEST macro, which allows you to include additional unit testing code in your program.
- -I./include: Add the ./include directory to the include path, which allows you to include headers from that directory.
