// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

#pragma once

// Define left and right hand home row mods
#define U_MT_L(MOD, TAP) &lhm MOD TAP  // Left hand home row mods
#define U_MT_R(MOD, TAP) &rhm MOD TAP  // Right hand home row mods
#define U_LT(LAYER, TAP) &u_lt LAYER TAP

// Redefine U_MT based on key position
// This macro will automatically choose left or right behavior
#define U_MT(MOD, TAP) \
    (((TAP) <= 5 || ((TAP) >= 12 && (TAP) <= 17) || ((TAP) >= 24 && (TAP) <= 29) || ((TAP) >= 36 && (TAP) <= 38)) ? \
    U_MT_L(MOD, TAP) : U_MT_R(MOD, TAP))
