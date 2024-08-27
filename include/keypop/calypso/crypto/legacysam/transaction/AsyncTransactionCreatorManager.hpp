/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "keypop/calypso/crypto/legacysam/transaction/WriteTransactionManager.hpp"

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace transaction {

/**
 * Transaction manager dedicated to operations performed asynchronously. This manager prepares
 * commands using a control SAM, and the result is available as a string to be imported and
 * processed by a {@link AsyncTransactionExecutorManager}.
 *
 * <p>An instance of this interface can be obtained via the method
 * keypop::calypso::crypto::legacysam::LegacySamApiFactory
 *     ::createAsyncTransactionCreatorManager(const std::string&, SecuritySetting).
 *
 * @see AsyncTransactionExecutorManager
 * @since 0.2.0
 */
class AsyncTransactionCreatorManager
: public WriteTransactionManager<AsyncTransactionCreatorManager> {
public:
    /**
     * Returns a string containing the prepared commands to be executed by a target SAM.
     *
     * <p>These commands can later be imported and processed by a {@link
     * AsyncTransactionExecutorManager}.
     *
     * @return A not empty string.
     * @since 0.2.0
     */
    virtual const std::string exportCommands() const = 0;
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
