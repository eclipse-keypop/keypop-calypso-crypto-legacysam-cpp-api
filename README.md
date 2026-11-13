# Keypop Calypso Crypto Legacy SAM C++ API
## Overview
This repository contains C++ source files aligned with the
[**Terminal Calypso Crypto Asymmetric**](https://terminal-api.calypsonet.org/specifications/calypso-layer/calypso-legacysam-api/)
specifications proposed by the [Calypso Networks Association](https://www.calypsonet.org). This C++ interface is a port
of the
[Keypop Calypso Crypto Legacy SAM Java API](https://github.com/eclipse-keypop/keypop-calypso-crypto-legacysam-java-api),
which remains the primary reference implementation. The C++ version aims to closely follow and maintain compatibility
with the Java version, ensuring consistent functionality and adherence to the established specifications.

The focus of this project is on providing interface definitions necessary for secure card transactions using asymmetric
key cryptography modules. These interfaces serve as a foundational layer that can be extended and customized to suit
specific application needs, while ensuring consistency across implementations, which is essential for enabling
certification processes.

While the codebase primarily consists of header files, some `.cpp` files are included for internal consistency testing
and validation.

## Key Characteristics
- **Interface-Driven Design**: The main source files define structures and interfaces. Concrete implementations can be
  provided by developers as per their specific requirements.
- **Modular Interfaces**: Designed to support modular extensions, allowing developers to implement custom functionality
  while adhering to the standardized interface structure defined by this project.
- **Compliance**: Aligned with the specifications of the Calypso Networks Association, ensuring that implementations
  conform to recognized standards, which is crucial for the terminal Calypso card layer certification.

## Usage
To use the interface definitions in your project, include the relevant headers in your source files and provide concrete
implementations of the defined interfaces as needed.

### Building with Conan
This repository is packaged as a [Conan](https://conan.io/) recipe (`conanfile.py`), providing the
`Keypop::Calypso::Crypto::LegacySam` CMake target as `keypop-calypso-crypto-legacysam-cpp-api`. It requires
`keypop-reader-cpp-api/2.1.0` and `keypop-calypso-card-cpp-api/2.2.0` (both declared with `transitive_headers=True`,
since this API's public headers include their headers directly) plus `keypop-calypso-crypto-symmetric-cpp-api/0.1.1`
(linked by the CMake target but not currently referenced by any public header), all resolved via Conan instead of
`FetchContent`. Downstream keypop/keyple recipes should consume this package the same way, with
`self.requires("keypop-calypso-crypto-legacysam-cpp-api/1.0.0")`.

The unit test suite is opt-in via the `with_tests` option (default `False`), so consumers of the package don't pay
for compiling GoogleTest.

#### Local development
Use `conan build` to configure/compile in-tree, in a regular `build/` folder you can inspect, rerun and debug
against (and which generates a `CMakeUserPresets.json` for IDE integration). The build type defaults to `Release`;
pass `-s build_type=Debug` for a debug build, which lands in its own `build/Debug` subfolder alongside `build/Release`:

```bash
# Release build, with the unit test suite, under ./build/Release
conan build . -o with_tests=True --build=missing

# Debug build, under ./build/Debug
conan build . -o with_tests=True -s build_type=Debug --build=missing

# Re-run the tests directly afterwards
./build/Release/bin/keypopcalypsocryptolegacysam_ut
./build/Debug/bin/keypopcalypsocryptolegacysam_ut
```

#### Packaging to the local cache
Use `conan create` to export the recipe and package to your local Conan cache, for consumption by other
recipes/repos (no remote upload involved):

```bash
# Build and export the package to the local cache
conan create . --build=missing

# Same, but also build and run the unit test suite as part of the recipe build
conan create . -o with_tests=True --build=missing

# Package a Debug build instead (build_type defaults to Release)
conan create . -o with_tests=True -s build_type=Debug --build=missing
```

### CI profiles
`profiles/` holds one Conan profile per platform built in CI (`linux-gcc`, `macos-clang`, `windows-msvc`),
replacing the old per-toolchain `.cmake` files. Pass one with `-pr:h` to build/package for that target; the
build type is still selected separately with `-s build_type=...`:

```bash
conan build . -pr:h=profiles/linux-gcc -o with_tests=True --build=missing
conan create . -pr:h=profiles/windows-msvc -s build_type=Debug --build=missing
```

## Documentation & Contribution Guide
The full documentation, including the **UML diagrams** and **design guide**, is available on
the [Keypop website](https://keypop.org/apis/calypso-layer/calypso-legacysam-api/).

### Contributing
Refer to the [contributing guide](https://keypop.org/community/contributing/) file for guidelines on how to contribute.
Please adhere to the [Code of Conduct](CODE_OF_CONDUCT.md) when participating in this project.

## License
This project is licensed under the [MIT License](LICENSE). For more details, please refer to the [LICENSE](LICENSE)
file.
