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

#include "keypop/calypso/crypto/legacysam/transaction/SignatureComputationData.hpp"

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace transaction {

/**
 * Contains the input/output data of the
 * FreeTransactionManager::prepareComputeSignature(const
 * std::shared_ptr<SignatureComputationData>) method for basic signature
 * computation using the "Data Cipher" command.
 *
 * <p>An instance of this interface can be obtained via the method
 * keypop::calypso::crypto::legacysam::LegacySamApiFactory::createBasicSignatureComputationData().
 *
 * @since 0.1.0
 */
class BasicSignatureComputationData
: public SignatureComputationData<BasicSignatureComputationData> {
    /**
     * Virtual destructor.
     */
    virtual ~BasicSignatureComputationData() = default;
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
