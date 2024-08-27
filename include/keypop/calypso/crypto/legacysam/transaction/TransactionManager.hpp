/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace transaction {

/**
 * Common API for all legacy SAM transaction managers.
 *
 * @param <T> The type of the lowest level child object.
 * @since 0.1.0
 */
template <typename T>
class TransactionManager {
public:
    /**
     * Process all previously prepared commands.
     *
     * @return The current instance.
     * @throw ReaderIOException If a communication error with the card reader or SAM reader occurs.
     * @throw SamIOException If a communication error with the SAM occurs.
     * @throw InvalidSignatureException If a signature associated to a prepared signature
     *        verification command is invalid.
     * @throw UnexpectedCommandStatusException If a command returns an unexpected status.
     * @throw InconsistentDataException If inconsistent data have been detected.
     * @since 0.1.0
     */
    virtual T& processCommands() = 0;
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
