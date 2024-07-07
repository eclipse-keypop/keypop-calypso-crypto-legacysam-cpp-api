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
 * Service to be implemented in order to check dynamically if a SAM is revoked.
 *
 * @since 0.1.0
 */
class LegacySamRevocationServiceSpi {
public:
    /**
     * Checks if the SAM with the provided serial number is revoked or not.
     *
     * <p>Note: the provided SAM serial number can be complete (4 bytes) or
     * partial (3 LSBytes).
     *
     * @param serialNumber The complete or partial SAM serial number to check.
     * @return True if the SAM is revoked, otherwise false.
     * @since 0.1.0
     */
    virtual bool
    isSamRevoked(const std::vector<uint8_t>& serialNumber) const = 0;

    /**
     * Checks if the SAM with the provided serial number and the associated
     * counter value is revoked or not.
     *
     * <p>Note: the provided SAM serial number can be complete (4 bytes) or
     * partial (3 LSBytes).
     *
     * @param serialNumber The complete or partial SAM serial number to check.
     * @param counterValue The SAM counter value.
     * @return True if the SAM is revoked, otherwise false.
     * @since 0.1.0
     */
    virtual bool isSamRevoked(
        const std::vector<uint8_t>& serialNumber,
        const int counterValue) const = 0;
};

} /* namespace spi */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
