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

#include <memory>
#include <stdexcept>
#include <string>

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace transaction {

/**
 * Indicates that an unexpected command status was returned by the card or SAM.
 *
 * <p>This can occur if the card or SAM is not Calypso compliant or if the card
 * has refused the secure session closing.
 *
 * <p>For this last case, this is usually due to an incorrect SAM signature, or
 * that the secure session has been altered by other APDU commands that would
 * have interfered with it.
 *
 * <p>If a secure session was open, the card discarded all data by cancelling
 * all updates except for PIN verification attempts.
 *
 * @since 0.1.0
 */
class UnexpectedCommandStatusException : public std::runtime_error {
public:
    /**
     * @param message Message to identify the exception context.
     * @param cause The cause.
     * @since 0.1.0
     */
    UnexpectedCommandStatusException(
        const std::string& message, const std::shared_ptr<std::exception> cause)
    : std::runtime_error(message) {
        (void)cause;
    }
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
