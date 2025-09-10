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
namespace spi {

/**
 * Service to be implemented in order to compute the dynamic unlock data
 * expected by the SAM.
 *
 * @since 0.4.0
 */
class LegacySamDynamicUnlockDataProviderSpi {
public:
    /**
     * Returns the dynamic unlock data computed by an origin SAM.
     *
     * <p>Note: the serial number and the challenge are required in the
     * preparation of the SAM Generate Unlock command.
     *
     * @param samSerialNumber The target SAM serial number.
     * @param samChallenge The challenge provided by the target SAM.
     * @return An 8-byte byte array.
     * @since 0.4.0
     */
    virtual const std::vector<uint8_t>& getUnlockData(
        const std::vector<uint8_t>& samSerialNumber,
        const std::vector<uint8_t>& samChallenge) const = 0;
};

} /* namespace spi */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
