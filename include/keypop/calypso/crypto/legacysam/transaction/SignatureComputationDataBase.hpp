/******************************************************************************
 * Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT.                                       *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

#pragma once

#include <cstdint>
#include <vector>

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace transaction {

/**
 * C++ Non-templated base extraction class.
 */
class SignatureComputationDataBase {
public:
    /**
     * Returns the computed signature.
     *
     * @return A byte array of 1 to 8 bytes.
     * @throws IllegalStateException If the command has not yet been processed.
     * @since 0.1.0
     */
    virtual const std::vector<uint8_t>& getSignature() const = 0;
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
