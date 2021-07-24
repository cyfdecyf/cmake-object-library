Object library is a very useful feature which is introduced in cmake 2.8.8.

This feature allows us group a bunch of object files and pass them as src to
`add_library` or `add_executable`.

Benefits:

- Avoids unnecessary static library creation
- No need for linking hack for circular static library dependency

Run `make VERBOSE=1` to see the actual compile and link commands.

References:

- [Object Library Tutorial](https://gitlab.kitware.com/cmake/community/-/wikis/doc/tutorials/Object-Library)
- [Document](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#object-libraries)

