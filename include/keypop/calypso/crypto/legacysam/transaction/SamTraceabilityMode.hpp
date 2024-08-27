/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

#include <memory>
#include <stdexcept>
#include <string>

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {
namespace transaction {

/**
 * The SAM traceability mode to use with traceable signature operations.
 *
 * @since 0.3.0
 */
enum class SamTraceabilityMode {
    /**
     * Full SAM serial number (4 Bytes).
     *
     * @since 0.3.0
     */
    FULL_SERIAL_NUMBER,

    /**
     * Truncated SAM serial number (3 LSBytes)
     *
     * @since 0.3.0
     */
    TRUNCATED_SERIAL_NUMBER
};

} /* namespace transaction */
} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
