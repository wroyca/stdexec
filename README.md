# stdexec - Senders/receivers asynchronous execution C++ library

This is a `build2` package repository for
[`stdexec`](https://github.com/NVIDIA/stdexec), the reference implementation
of `std::execution` (senders/receivers, P2300), a standard model for
asynchronous execution in C++.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`stdexec` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](libstdexec/PACKAGE-README.md) file.

Note that upstream does not make versioned releases. The packages follow the
upstream snapshots that are shipped in the NVIDIA HPC SDK (for example,
`nvhpc-26.05`) using the `0.0.Z` versioning scheme where each consecutive
packaged snapshot increments `Z`.

The development setup for `stdexec` uses the standard `bdep`-based workflow.
For example:

```
git clone --recurse-submodules .../stdexec.git
cd stdexec

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
