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

#include "keypop/reader/ChannelControl.hpp"
#include "keypop/reader/transaction/spi/CardTransactionManager.hpp"

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace transaction {

using keypop::reader::ChannelControl;

/**
 * Common API for all legacy SAM transaction managers.
 *
 * <p>Extends keypop::reader::transaction::spi::CardTransactionManager
 * to provide common card transaction operations.
 *
 * @param <T> The type of the lowest level child object.
 * @since 0.1.0
 */
template <typename T>
class TransactionManager
: public keypop::reader::transaction::spi::CardTransactionManager<T> {
public:
    /**
     * Process all previously prepared commands.
     *
     * @return The current instance.
     * @throw ReaderIOException If a communication error with the card reader or
     * SAM reader occurs.
     * @throw SamIOException If a communication error with the SAM occurs.
     * @throw InvalidSignatureException If a signature associated to a prepared
     * signature verification command is invalid.
     * @throw UnexpectedCommandStatusException If a command returns an
     * unexpected status.
     * @throw InconsistentDataException If inconsistent data have been detected.
     * @since 0.1.0
     * @deprecated Use processCommands(ChannelControl) instead.
     */
    virtual T& processCommands() = 0;

    /**
     * {@inheritDoc}
     *
     * @throw InvalidSignatureException If a signature associated to a prepared
     * signature verification command is invalid.
     * @throw InconsistentDataException If inconsistent data have been detected.
     * @since 0.8.0
     */
    virtual T& processCommands(const ChannelControl channelControl) = 0;
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
