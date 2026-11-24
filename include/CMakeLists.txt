# *****************************************************************************
# Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/     *
#                                                                             *
# This program and the accompanying materials are made available under the    *
# terms of the MIT License which is available at                              *
# https://opensource.org/licenses/MIT.                                        *
#                                                                             *
# SPDX-License-Identifier: MIT                                                *
# *****************************************************************************/

SET(LIBRARY_NAME keypopcalypsocryptolegacysam)

# Declare this library as header only.
ADD_LIBRARY(

    ${LIBRARY_NAME}

    INTERFACE
)

# Keypop dependencies are supplied by Conan (requires) via CMakeDeps
FIND_PACKAGE(keypop-calypso-crypto-symmetric-cpp-api REQUIRED CONFIG)
FIND_PACKAGE(keypop-calypso-card-cpp-api REQUIRED CONFIG)
FIND_PACKAGE(keypop-reader-cpp-api REQUIRED CONFIG)

TARGET_INCLUDE_DIRECTORIES(

    ${LIBRARY_NAME}

    INTERFACE

    ${CMAKE_CURRENT_SOURCE_DIR}
)

TARGET_LINK_LIBRARIES(

    ${LIBRARY_NAME}

    INTERFACE

    Keypop::Calypso::Crypto::Symmetric
    Keypop::Calypso::Card
    Keypop::Reader
)

ADD_LIBRARY(

    Keypop::Calypso::Crypto::LegacySam

    ALIAS

    ${LIBRARY_NAME}
)
