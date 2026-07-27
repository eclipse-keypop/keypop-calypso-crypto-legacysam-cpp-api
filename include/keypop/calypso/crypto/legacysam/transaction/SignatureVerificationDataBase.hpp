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
class SignatureVerificationDataBase {
public:
    /**
     * Returns the result of the signature verification process by indicating if
     * the signature is valid or not.
     *
     * @return True if the signature is valid.
     * @throw IllegalStateException If the command has not yet been processed.
     * @since 0.1.0
     */
    virtual bool isSignatureValid() const = 0;
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
