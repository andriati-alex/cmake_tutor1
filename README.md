# Hands on example of cmake

In this dummy (but rather illustrative) project I intent to provide a basic
usage introduction to cmake tool. The main sources I followed in this first
moment were:
* https://cliutils.gitlab.io/modern-cmake
* https://www.youtube.com/watch?v=mKZ-i-UfGgQ

## Goal of this small dummy example

The main goal is to provide a very simple usage of cmake developing an example
which requires a small knowledge of C language. That said we introduce the dir
structure of this mini-project, proposing ordered steps to follow. Thereafter,
the `CMakeLists.txt` and how to build the executable is explained

## Basic project organization

The first step is to create an `include` dir which must hold all data type
definitions (`typedef`s and function prototypes) the project will use. For
an even better practice, if the project will build more than an library it
is recommendable to have multiple dirs inside `include`, one for each lib
the project needs. But this last case of multiple libs is not treated here

The next step is the source dir, usually named `src` which must contain all
implementations for the libs, NOT EXECUTABLES. Again, if the project contains
multiple libraries it is a good practice to crete subdirs in `src` for each
lib. Of course, the name of the dirs in `src` should corresponds to the ones
in `include` with the function signatures. However, as mentioned above this
is not the case here, where only on lib is required.

The next point is to look at the `apps` folder that should contain the source
code of all executables. Another common name is `exe` for this dir.

The dir sructure explained above should be followed in every project. After
this rapid exaplanation, I recommend to explore the folders and files these
dir provide, in the order used to explain.

## Building the project

The `cmake` tool itself is intended to provided a pragmatic way to build and
organized the project in such way to avoid the hard-coded makefiles. In some
cases, eventually for small projects, it may even be a bit more toilsome the
implementation of cmake file, but it makes a lot more sense its syntax and
the way the libraries are generated, indicating all the dependences.

The very first thing to do in `CMakeLists.txt` is to indicate the minimum
version required. Then, another step is to provide simple project info as
name, description and language. Until this point no direct relation to the
project source files is needed.

After the steps above, the libs must be compiled. For that, we must use:
`add_library(target TYPE {all source files} {all headers (optional)})`
the target is a kind of variable that cmake use to refer to it. The type
is STATIC or SHARED. Finally, the source files that compose the lib must
be given, and a good practice is to also provide the headers as well. In
order to find these headers with function signatures we need to do:
`target_include_directories(target PUBLIC include)`
where target is understood to reference our lib, include is the dir that
contains all header files required and PUBLIC so that any executables to
call this lib also needs the header files and thus must include the same
dependencies. Therefore, PUBLIC means that all pre-requisites must be
informed to further dependencies.

Finally, once all libs are created, the executables can be defined with:
`add_executable(target_exe {source files})`
`target_link_libraries(target_exe PUBLIC target)`
where the seconf command make explicit the executable dependency of the
lib indicated by `target`

Finally, go ahead and see the `CMakeLists.txt` for more details.

## Building the application

To produce the executables, we just need to run first
`cmake -S . -B build`
where the `-S` indicate the source dir and `-B` where the
build files must be placed. In this step the makefile is
generated (that is it, no need to hard code makefiles).
Finally to really compile the executable run
`cmake --build build`
which will produce the executable in `build` directory.
Eventually, some command line variables can be set before
cmake execution. For instance the compiler can be set
for intel compiler (if installed) with
`CC=icc cmake -S . -B build`

## Additional ccls config for language server

Following the setup suggested by [coc-vim github page](https://github.com/neoclide/coc.nvim/wiki/Language-servers#ccobjective-c)
in order to a language server to work properly either the
`compile_commands.json` or `.ccls` files must be provided
For more details about project setup see also:
https://github.com/MaskRay/ccls/wiki/Project-Setup
Here I wrote an example of a `.ccls` file just to provide
the path to the headers for every `.c` file extension. As
can be noted, we must set the full path, therefore I used
`/home/andriati/projects/cmake_example/include`. Set it
appropriately depending on your project directory.
To work with `compile_commands.json`, `cmake` must be run
with the extra option `-DCMAKE_EXPORT_COMPILE_COMMANDS=YES`
to produce the `json` file. For instance:
`cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=YES`
and then copy the file `compile_commands.json` from `build`
dir to project root dir. I prefer this second approach, but
when you are starting a project you usually will take some
time to build it the first time. Therefore, it is always
interest to provide the `.ccls` file at least with the full
path to the `include` dir which contain all the headers.
The problem with only the `.ccls` for the language server
us that some features, as `goDefinition` for example will
open the header file instead of the source file as it would
happen if `compile_commands.json` was provided as well.
