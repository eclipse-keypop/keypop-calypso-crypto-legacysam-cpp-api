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
 * FreeTransactionManager::prepareGenerateCardAsymmetricKeyPair(KeyPairContainer)
 * method.
 *
 * <p>A key pair consists of a byte array containing the public key and a
 * private key values.
 *
 * @since 0.5.0
 */
class KeyPairContainer {
public:
    /**
     * Returns the key pair.
     *
     * @return The key pair as a 96-byte byte array.
     * @since 0.5.0
     */
    virtual const std::vector<uint8_t> getKeyPair() = 0;
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
