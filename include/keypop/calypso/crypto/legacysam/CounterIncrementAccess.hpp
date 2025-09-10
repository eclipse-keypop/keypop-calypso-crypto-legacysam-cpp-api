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

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {

/**
 * Enumeration of the different possible access rights for incrementing event
 * counters.
 *
 * @since 0.3.0
 */
enum class CounterIncrementAccess {
    /**
     * Enables to increment the value of an event counter using the "Increment
     * Counter" command.
     *
     * @since 0.3.0
     */
    FREE_COUNTING_ENABLED,

    /**
     * Forbids to increment the value of an event counter using the "Increment
     * Counter" command.
     *
     * @since 0.3.0
     */
    FREE_COUNTING_DISABLED
};

} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
