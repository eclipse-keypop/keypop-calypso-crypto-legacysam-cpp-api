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

#include <memory>

#include "keypop/calypso/crypto/legacysam/sam/LegacySam.hpp"
#include "keypop/reader/CardReader.hpp"

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace transaction {

using keypop::calypso::crypto::legacysam::sam::LegacySam;
using keypop::reader::CardReader;

/**
 * Security setting to manage operations of a legacy SAM transaction secured by
 * a control SAM.
 *
 * <p>An instance of this interface can be obtained via the method {@link
 * LegacySamApiFactory#createSecuritySetting()}.
 *
 * @since 0.2.0
 */
class SecuritySetting {
public:
    /**
     * Sets the control SAM and the reader through which it can be accessed. It
     * will be used to perform all necessary cryptographic operations.
     *
     * @param samReader The reader to use to communicate with the SAM.
     * @param controlSam The control Legacy SAM.
     * @return The current instance.
     * @throw IllegalArgumentException If one of the arguments is null or if the
     * product type of LegacySam is equal to LegacySam::ProductType#UNKNOWN.
     * @since 0.2.0
     */
    virtual SecuritySetting& setControlSamResource(
        const std::shared_ptr<CardReader> samReader,
        const std::shared_ptr<LegacySam> controlSam)
        = 0;
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
