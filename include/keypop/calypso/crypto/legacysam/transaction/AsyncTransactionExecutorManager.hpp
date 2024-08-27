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
#include <vector>

#include "keypop/calypso/crypto/legacysam/transaction/TransactionManager.hpp"

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace transaction {

/**
 * Transaction manager dedicated to execute commands prepared asynchronously using
 * AsyncTransactionCreatorManager#exportCommands().
 *
 * <p>An instance of this interface can be obtained via the method {@link
 * keypop::calypso::crypto::legacysam::LegacySamApiFactory
 *    ::createAsyncTransactionExecutorManager(
 *        const std::shared_ptr<CardReader>, const LegacySam, const std::string&).
 *
 * @see AsyncTransactionCreatorManager
 * @since 0.2.0
 */
class AsyncTransactionExecutorManager : public TransactionManager<AsyncTransactionExecutorManager> {
public:
    /**
     * Virtual destructor.
     */
    virtual ~AsyncTransactionExecutorManager() = default;
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
