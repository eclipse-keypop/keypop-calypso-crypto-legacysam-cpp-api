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

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace transaction {

/**
 * Contains the input/output data of the {@link
 * FreeTransactionManager#prepareVerifySignature(SignatureVerificationData)} method for common
 * signature verification modes.
 *
 * @param <T> The type of the lowest level child object.
 * @since 0.1.0
 */
template <typename T>
class SignatureVerificationData {
public:
    /**
     * Sets the signed data, the associated signature and the KIF/KVC of the key to be used for the
     * signature verification.
     *
     * @param data The signed data.
     * @param signature The associated signature.
     * @param kif The KIF of the key to be used for the signature verification.
     * @param kvc The KVC of the key to be used for the signature verification.
     * @return The current instance.
     * @since 0.1.0
     */
    virtual T& setData(
        const std::vector<uint8_t>& data,
        const std::vector<uint8_t>& signature,
        const uint8_t kif,
        const uint8_t kvc)
        = 0;

    /**
     * Sets a specific key diversifier to use before verifying the signature (optional).
     *
     * <p>By default, the key diversification is performed with the full serial number of the target
     * card or SAM depending on the transaction context (Card or SAM transaction).
     *
     * @param diversifier The diversifier to be used (from 1 to 8 bytes long).
     * @return The current instance.
     * @since 0.1.0
     */
    virtual T& setKeyDiversifier(const std::vector<uint8_t>& diversifier) = 0;

    /**
     * Returns the result of the signature verification process by indicating if the signature is
     * valid or not.
     *
     * @return True if the signature is valid.
     * @throw IllegalStateException If the command has not yet been processed.
     * @since 0.1.0
     */
    virtual bool isSignatureValid() const = 0;
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
