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
 * Indicates that a signature is invalid.
 *
 * @since 0.1.0
 */
class InvalidSignatureException final : public std::runtime_error {
public:
    /**
     * @param message The message to identify the exception context.
     * @since 0.1.0
     */
    explicit InvalidSignatureException(const std::string& message)
    : std::runtime_error(message) {
    }

    /**
     * Encapsulates a lower level exception.
     *
     * @param message Message to identify the exception context.
     * @param cause The cause.
     * @since 0.1.0
     */
    InvalidSignatureException(
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
