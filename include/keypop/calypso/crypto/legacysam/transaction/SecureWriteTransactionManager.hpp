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

#include "keypop/calypso/crypto/legacysam/SystemKeyType.hpp"
#include "keypop/calypso/crypto/legacysam/transaction/WriteTransactionManager.hpp"

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace transaction {

using keypop::calypso::crypto::legacysam::SystemKeyType;

/**
 * Transaction manager dedicated to "WRITE" operations secured by a control SAM.
 *
 * <p>The write operations defined here can only be executed synchronously.
 *
 * @since 0.7.0
 */
class SecureWriteTransactionManager
: public WriteTransactionManager<SecureWriteTransactionManager> {
public:
    /**
     * Schedules the execution of a "Write Parameters" command to write the SAM
     * parameters file.
     *
     * @param parameters A 29-byte byte array representing the content of the
     * SAM parameters file.
     * @return The current instance.
     * @throw IllegalArgumentException If the provided argument is null or out
     * of range.
     * @since 0.7.0
     */
    virtual SecureWriteTransactionManager&
    prepareWriteSamParameters(const std::vector<uint8_t>& parameters)
        = 0;

    /**
     * Schedules the execution of a "Write Key" command to perform the transfer
     * of a system key from the control SAM to the target SAM.
     *
     * @param systemKeyType The type of system key.
     * @param kvc The KVC of the key.
     * @param systemKeyParameters A 29-byte byte array containing the key
     * parameter data.
     * @return The current instance.
     * @throw IllegalArgumentException If one of the provided argument is null
     * or out of range.
     * @since 0.7.0
     */
    virtual SecureWriteTransactionManager& prepareTransferSystemKey(
        const SystemKeyType systemKeyType,
        const uint8_t kvc,
        const std::vector<uint8_t>& systemKeyParameters)
        = 0;

    /**
     * Schedules the execution of a "Write Key" command to perform the transfer
     * of a system key from the control SAM to the target SAM, the key being
     * first diversified (with the serial number of the target SAM).
     *
     * @param systemKeyType The type of system key.
     * @param kvc The KVC of the key.
     * @param systemKeyParameters A 29-byte byte array containing the key
     * parameter data.
     * @return The current instance.
     * @throw IllegalArgumentException If one of the provided argument is null
     * or out of range.
     * @since 0.7.0
     */
    virtual SecureWriteTransactionManager& prepareTransferSystemKeyDiversified(
        const SystemKeyType systemKeyType,
        const uint8_t kvc,
        const std::vector<uint8_t>& systemKeyParameters)
        = 0;

    /**
     * Schedules the execution of a "Write Key" command to perform the transfer
     * of a work key from the control SAM to the target SAM.
     *
     * <p>The record number supplied indicates the destination location in the
     * work key file. If its value is zero, then the location will be chosen
     * automatically by the SAM.
     *
     * @param kif The KIF of the key.
     * @param kvc The KVC of the key.
     * @param workKeyParameters A 29-byte byte array containing the key
     * parameter data.
     * @param targetRecordNumber The number of the record where to store the key
     * (in range [0..126]).
     * @return The current instance.
     * @throw IllegalArgumentException If one of the provided argument is null
     * or out of range.
     * @since 0.7.0
     */
    virtual SecureWriteTransactionManager& prepareTransferWorkKey(
        const uint8_t kif,
        const uint8_t kvc,
        const std::vector<uint8_t>& workKeyParameters,
        const int targetRecordNumber)
        = 0;

    /**
     * Schedules the execution of a "Write Key" command to perform the transfer
     * of a work key from the control SAM to the target SAM, the key being
     * first diversified with the serial number of the target SAM).
     *
     * <p>The record number supplied indicates the destination location in the
     * work key file. If its value is zero, then the location will be chosen
     * automatically by the SAM.
     *
     * @param kif The KIF of the key.
     * @param kvc The KVC of the key.
     * @param workKeyParameters A 29-byte byte array containing the key
     * parameter data.
     * @param targetRecordNumber The number of the record where to store the key
     * (in range [0..126]).
     * @return The current instance.
     * @throw IllegalArgumentException If one of the provided argument is null
     * or out of range.
     * @since 0.7.0
     */
    virtual SecureWriteTransactionManager& prepareTransferWorkKeyDiversified(
        const uint8_t kif,
        const uint8_t kvc,
        const std::vector<uint8_t>& workKeyParameters,
        const int targetRecordNumber)
        = 0;

    /**
     * Schedules the execution of a "Write Key" command to perform the transfer
     * of a work key from the control SAM to the target SAM, the key being first
     * diversified with the provided diversifier.
     *
     * <p>The record number supplied indicates the destination location in the
     * work key file. If its value is zero, then the location will be chosen
     * automatically by the SAM.
     *
     * @param kif The KIF of the key.
     * @param kvc The KVC of the key.
     * @param workKeyParameters A 29-byte byte array containing the key
     * parameter data.
     * @param targetRecordNumber The number of the record where to store the key
     * (in range [0..126]).
     * @param diversifier A 8-byte byte array to use as key diversifier.
     * @return The current instance.
     * @throw IllegalArgumentException If one of the provided argument is null
     * or out of range.
     * @since 0.7.0
     */
    virtual SecureWriteTransactionManager& prepareTransferWorkKeyDiversified(
        const uint8_t kif,
        const uint8_t kvc,
        const std::vector<uint8_t>& workKeyParameters,
        const int targetRecordNumber,
        const std::vector<uint8_t>& diversifier)
        = 0;

    /**
     * Schedules the execution of a "Write Key" command to transfer a lock file
     * from the control SAM
     * to the target SAM.
     *
     * @param lockIndex The index of the lock file.
     * @param lockParameters The lock permissions parameters.
     * @return The current instance.
     * @since 0.7.0
     */
    virtual SecureWriteTransactionManager&
    prepareTransferLock(const uint8_t lockIndex, const uint8_t lockParameters)
        = 0;

    /**
     * Schedules the execution of a "Write Key" command to transfer a lock file
     * from the control SAM to the target SAM, the key being first diversified
     * (with the serial number of the target SAM).
     *
     * @param lockIndex The index of the lock file.
     * @param lockParameters The lock permissions parameters.
     * @return The current instance.
     * @since 0.7.0
     */
    virtual SecureWriteTransactionManager& prepareTransferLockDiversified(
        const uint8_t lockIndex, const uint8_t lockParameters)
        = 0;

    /**
     * Schedules the execution of a "Write Key" command to set the lock file of
     * the SAM.
     *
     * <p>The lock value will be transferred in plain text.
     *
     * @param lockIndex The index of the lock file.
     * @param lockParameters The lock permissions parameters.
     * @param lockValue A 16-byte byte array representing the lock's value.
     * @return The current instance.
     * @throw IllegalArgumentException If lockValue is null or out of range.
     * @since 0.7.0
     */
    virtual SecureWriteTransactionManager& preparePlainWriteLock(
        const uint8_t lockIndex,
        const uint8_t lockParameters,
        const std::vector<uint8_t>& lockValue)
        = 0;
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
