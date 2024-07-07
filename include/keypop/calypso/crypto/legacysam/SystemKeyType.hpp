/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

namespace keypop {
namespace calypso {
namespace crypto {
namespace legacysam {

/**
 * Enumeration of the system key types of a Legacy Sam.
 *
 * <p>Each type corresponds to a specific use.
 *
 * @since 0.2.0
 */
enum class SystemKeyType {
    /**
     * Personalization key, to decipher and authorize the writing of parameters and system keys.
     *
     * @since 0.2.0
     */
    PERSONALIZATION,

    /**
     * Work file key, to decipher and authorize the writing of work keys.
     *
     * @since 0.2.0
     */
    KEY_MANAGEMENT,

    /**
     * Reloading key, to decipher and authorize the writing of counter ceilings.
     *
     * @since 0.2.0
     */
    RELOADING,

    /**
     * Authentication key, to generate the signature of data read from the SAM.
     *
     * @since 0.2.0
     */
    AUTHENTICATION,
};

} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
