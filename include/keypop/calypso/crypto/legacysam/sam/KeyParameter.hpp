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
 * POJO containing the parameters for a key managed by SAM, whether it's a
 * system key or a work key.
 *
 * @since 0.2.0
 */
class KeyParameter {
public:
    /**
     * Gets the raw data of the key's parameters.
     *
     * @return a byte array of 13 bytes representing the key's parameters,
     * including KIF, KVC, algorithm, and PAR1 to PAR10.
     * @since 0.2.0
     */
    virtual const std::vector<uint8_t>& getRawData() const = 0;

    /**
     * Returns the key identifier (KIF).
     *
     * @return The KIF value.
     * @since 0.2.0
     */
    virtual uint8_t getKif() const = 0;

    /**
     * Returns the key version (KVC).
     *
     * @return The KVC value.
     * @since 0.2.0
     */
    virtual uint8_t getKvc() const = 0;

    /**
     * Returns the key algorithm.
     *
     * @return The algorithm identification byte.
     * @since 0.2.0
     */
    virtual uint8_t getAlgorithm() const = 0;

    /**
     * Returns the value of the parameter whose number is provided.
     *
     * @param parameterNumber The number of the parameter to get (in range
     * [1..10]).
     * @return The parameter value.
     * @throw IllegalArgumentException If the argument is out of range.
     * @since 0.2.0
     */
    virtual uint8_t getParameterValue(const int parameterNumber) const = 0;
};

} /* namespace sam */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
