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

#include "keypop/calypso/crypto/legacysam/SystemKeyType.hpp"
#include "keypop/calypso/crypto/legacysam/transaction/TransactionManager.hpp"

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace transaction {

/**
 * Transaction manager dedicated to "READ" operations.
 *
 * @param <T> The type of the lowest level child object.
 * @since 0.1.0
 */
template <typename T>
class ReadTransactionManager : public TransactionManager<T> {
public:
    /**
     * Schedules the execution of a "Read Parameters" command for the SAM.
     *
     * <p>Once this command is processed, the result is accessible with
     * LegacySam#getSamParameters().
     *
     * @return The current instance.
     * @since 0.7.0
     */
    virtual T& prepareReadSamParameters() = 0;

    /**
     * Schedules the execution of a "Read Key Parameters" command for a system
     * key.
     *
     * <p>Once this command is processed, the result is accessible with
     * LegacySam#getSystemKeyParameter(SystemKeyType).
     *
     * @param systemKeyType The type of system key.
     * @return The current instance.
     * @throw IllegalArgumentException If the provided argument is null.
     * @since 0.2.0
     */
    virtual T& prepareReadSystemKeyParameters(const SystemKeyType systemKeyType)
        = 0;

    /**
     * Schedules the execution of a "Read Key Parameters" command for a work key
     * referenced by its record number.
     *
     * <p>Once this command is processed, the result is accessible with
     * LegacySam#getWorkKeyParameter(int).
     *
     * @param recordNumber The key record number (in range [1..126]).
     * @return The current instance.
     * @throw IllegalArgumentException If the provided record number is out of
     * range.
     * @since 0.7.0
     */
    virtual T& prepareReadWorkKeyParameters(const int recordNumber) = 0;

    /**
     * Schedules the execution of a "Read Key Parameters" command for a work key
     * referenced by its KIF and KVC.
     *
     * <p>Once this command is processed, the result is accessible with
     * LegacySam#getWorkKeyParameter(uint8_t, uint8_t).
     *
     * @param kif The key KIF.
     * @param kvc The key KVC.
     * @return The current instance.
     * @since 0.7.0
     */
    virtual T&
    prepareReadWorkKeyParameters(const uint8_t kif, const uint8_t kvc)
        = 0;

    /**
     * Schedules the execution of a "Read Event Counter" and "Read Ceiling"
     * commands to read the status of a counter.
     *
     * <p>Note: the status of each counter of the record to which the targeted
     * counter belongs will be read. The number of commands actually transmitted
     * to the SAM will be optimized when the processCommands() method is
     * executed.
     *
     * @param counterNumber The number of the counter whose status is to be read
     * (in range [0..26]).
     * @return The current instance.
     * @throw IllegalArgumentException If the provided argument is out of range.
     * @since 0.2.0
     */
    virtual T& prepareReadCounterStatus(const int counterNumber) = 0;

    /**
     * Schedules the execution of a "Read Event Counter" and "Read Ceiling"
     * commands to read the status of all counters.
     *
     * @return The current instance.
     * @since 0.2.0
     */
    virtual T& prepareReadAllCountersStatus() = 0;
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
