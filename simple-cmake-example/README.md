# Simple cmake example

So far I used Visual Studio Code to directly compile the single source code file.
In this example I used `cmake` to build the project files.

Here's how:

```bash
# Setup and first build
cd simple-cmake-example
mkdir build
cd build
cmake ..
cmake --build .

# Rebuild and run after changes
cmake --build . && ./SimpleCMakeExample
```
