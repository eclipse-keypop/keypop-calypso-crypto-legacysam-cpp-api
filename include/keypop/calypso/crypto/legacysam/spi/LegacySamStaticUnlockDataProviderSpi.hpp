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
 * Service to be implemented in order to compute the static unlock data expected
 * by the SAM.
 *
 * @since 0.4.0
 */
class LegacySamStaticUnlockDataProviderSpi {
public:
    /**
     * Returns the static unlock data expected by the target SAM.
     *
     * <p>Note: the serial number can be used as diversifier in the computation
     * of the unlock data.
     *
     * @param samSerialNumber The target SAM serial number.
     * @return A 16-byte byte array.
     * @since 0.4.0
     */
    virtual const std::vector<uint8_t>&
    getUnlockData(const std::vector<uint8_t>& samSerialNumber) const = 0;
};

} /* namespace spi */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
