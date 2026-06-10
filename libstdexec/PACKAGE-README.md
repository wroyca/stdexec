# libstdexec - Senders/receivers asynchronous execution C++ library

This is a `build2` package for the [`stdexec`](https://github.com/NVIDIA/stdexec)
C++ library. It provides the reference implementation of `std::execution`
(senders/receivers, P2300), a standard model for asynchronous execution in
C++, including the `stdexec` core as well as the `exec` extensions.

Note that upstream does not make versioned releases (the package follows the
upstream snapshots that are shipped in the NVIDIA HPC SDK, for example,
`nvhpc-26.05`). As a result, this package uses the `0.0.Z` versioning scheme
where each consecutive packaged snapshot increments `Z`.


## Usage

To start using `libstdexec` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libstdexec ^0.0.1
```

Then import the library in your `buildfile`:

```
import libs = libstdexec%lib{stdexec}
```


## Importable targets

This package provides the following importable targets:

```
lib{stdexec}
lib{parallel_scheduler}
```

The `lib{stdexec}` target is the header-only (binless) library providing the
`<stdexec/...>` and `<exec/...>` headers.

The `lib{parallel_scheduler}` target is the compiled parallel scheduler
implementation (upstream's `STDEXEC_BUILD_PARALLEL_SCHEDULER` CMake option)
which can be used to replace the default header-only implementation. It is
only available if the `config.libstdexec.parallel_scheduler` configuration
variable is `true`.


## Configuration variables

This package provides the following configuration variables:

```
[bool] config.libstdexec.parallel_scheduler ?= false
```

The `parallel_scheduler` variable enables building the compiled
`lib{parallel_scheduler}` library (see above). It corresponds to upstream's
`STDEXEC_BUILD_PARALLEL_SCHEDULER` CMake option and matches its default
(disabled).
