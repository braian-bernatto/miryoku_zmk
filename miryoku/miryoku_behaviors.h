// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

#pragma once

// Define the basic hold-tap macros
#define U_MT_L(MOD, TAP) &lhm MOD TAP
#define U_MT_R(MOD, TAP) &rhm MOD TAP
#define U_LT(LAYER, TAP) &u_lt LAYER TAP

// Define the main U_MT macro that selects left or right based on position
#define U_MT(MOD, TAP) U_MT_L(MOD, TAP)
