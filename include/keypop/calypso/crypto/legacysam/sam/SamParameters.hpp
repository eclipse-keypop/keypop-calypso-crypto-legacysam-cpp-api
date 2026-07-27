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
namespace sam {

/**
 * POJO containing the parameters of the SAM.
 *
 * @since 0.7.0
 */
class SamParameters {
public:
    /**
     * Virtual destructor.
     */
    virtual ~SamParameters() = default;

    /**
     * Retrieves the raw data of the SAM's parameters.
     *
     * @return a byte array of 29 bytes representing the SAM's parameters.
     * @since 0.7.0
     */
    virtual const std::vector<uint8_t> getRawData() const = 0;
};

} /* namespace sam */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
