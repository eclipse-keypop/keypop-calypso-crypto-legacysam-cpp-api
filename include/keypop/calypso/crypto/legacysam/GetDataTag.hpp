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
 * Enumeration of all output data tags.
 *
 * <p>May not be applicable to all products.
 *
 * @since 0.5.0
 */
enum class GetDataTag {
    /**
     * CA Certificate (CACert)
     *
     * <p>CACert may be unavailable.
     *
     * @since 0.5.0
     */
    CA_CERTIFICATE
};

} /* namespace legacysam */
} /* namespace crypto */
} /* namespace calypso */
} /* namespace keypop */
