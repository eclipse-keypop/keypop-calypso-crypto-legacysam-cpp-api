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

#include "keyple/core/util/cpp/exception/RuntimeException.hpp"

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace transaction {

using keyple::core::util::cpp::exception::RuntimeException;

/**
 * Indicates that a signature is invalid.
 *
 * @since 0.1.0
 */
class InvalidSignatureException final : public RuntimeException {
public:
    /**
     * @param message The message to identify the exception context.
     * @since 0.1.0
     */
    explicit InvalidSignatureException(const std::string& message)
    : RuntimeException(message) {
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
    : RuntimeException(message) {
        (void)cause;
    }
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
