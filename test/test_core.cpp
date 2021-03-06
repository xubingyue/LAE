/*
 *  test_core.cpp
 *  lae
 *
 *  Created by Kyle C Weicht on 6/6/12.
 *  Copyright (c) 2012 Kyle C Weicht. All rights reserved.
 */

/*----------------------------------------------------------------------------*/
/* C headers */
/* C++ headers */
/* External headers */
/* Internal headers */
#include "lae_test.h"
#include "lae_core.h"
/*----------------------------------------------------------------------------*/

namespace
{
/*----------------------------------------------------------------------------*\
Internal
\*----------------------------------------------------------------------------*/
TEST(CreateAndDestroyCore)
{
    lae_core* core = lae_core_create();
    CHECK_POINTER_NOT_NULL(core);
    lae_core_destroy(core);
}

} // anonymous namespace

/*----------------------------------------------------------------------------*\
External
\*----------------------------------------------------------------------------*/
