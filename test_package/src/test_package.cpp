/******************************************************************************
 * Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT.                                       *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

#include <iostream>

#include "keypop/calypso/crypto/legacysam/LegacySamApiFactory.hpp"
#include "keypop/calypso/crypto/legacysam/LegacySamApiProperties.hpp"

int
main() {
    /* LegacySamApiFactory.hpp transitively pulls in keypop-calypso-card-cpp-api
     * (and, through it, keypop-reader-cpp-api) headers; compiling it here
     * proves the whole transitive dependency chain resolves through
     * Conan/CMake alone. */
    std::cout
        << "Keypop::Calypso::Crypto::LegacySam header-only package resolved "
           "and linked correctly (API version "
        << keypop::calypso::crypto::legacysam::LegacySamApiProperties_VERSION
        << ")" << std::endl;
    return 0;
}
