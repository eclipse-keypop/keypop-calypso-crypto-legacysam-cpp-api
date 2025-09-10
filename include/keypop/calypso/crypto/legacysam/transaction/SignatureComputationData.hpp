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
 * Contains the input/output data of the {@link
 * FreeTransactionManager#prepareComputeSignature(SignatureComputationData)}
 * method for common signature computation modes.
 *
 * @param <T> The type of the lowest level child object.
 * @since 0.1.0
 */
template <typename T>
class SignatureComputationData {
public:
    /**
     * Sets the data to be signed and the KIF/KVC of the key to be used for the signature
     * computation.
     *
     * @param data The data to be signed.
     * @param kif The KIF of the key to be used for the signature computation.
     * @param kvc The KVC of the key to be used for the signature computation.
     * @return The current instance.
     * @since 0.1.0
     */
    virtual T& setData(
        const std::vector<uint8_t>& data, const uint8_t kif, const uint8_t kvc)
        = 0;

    /**
     * Sets the expected size of the signature in bytes, which can be between 1
     * and 8 bytes (optional).
     *
     * <p>By default, the signature will be generated on 8 bytes.
     *
     * <p>Note: the longer the signature, the more secure it is.
     *
     * @param size The expected size [1..8]
     * @return The current instance.
     * @since 0.1.0
     */
    virtual T& setSignatureSize(const int size) = 0;

    /**
     * Sets a specific key diversifier to use before signing (optional).
     *
     * <p>By default, the key diversification is performed with the full serial
     * number of the target card or SAM depending on the transaction context
     * (Card or SAM transaction).
     *
     * @param diversifier The diversifier to be used (from 1 to 8 bytes long).
     * @return The current instance.
     * @since 0.1.0
     */
    virtual T& setKeyDiversifier(const std::vector<uint8_t>& diversifier) = 0;

    /**
     * Returns the computed signature.
     *
     * @return A byte array of 1 to 8 bytes.
     * @throws IllegalStateException If the command has not yet been processed.
     * @since 0.1.0
     */
    const std::vector<uint8_t>& getSignature() const = 0;
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
