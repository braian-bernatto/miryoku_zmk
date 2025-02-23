// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

#pragma once

// Define key positions for Corne
#define KEYS_L LT0 LT1 LT2 LT3 LT4 LM0 LM1 LM2 LM3 LM4 LB0 LB1 LB2 LB3 LB4  // Left-hand keys
#define KEYS_R RT0 RT1 RT2 RT3 RT4 RM0 RM1 RM2 RM3 RM4 RB0 RB1 RB2 RB3 RB4  // Right-hand keys
#define THUMBS LH2 LH1 LH0 RH0 RH1 RH2                                      // Thumb keys

/* Left-hand HRMs */
ZMK_HOLD_TAP(hml,
    flavor = "tap-unless-interrupted";
    tapping-term-ms = <U_TAPPING_TERM>;
    quick-tap-ms = <175>;
    require-prior-idle-ms = <150>;
    bindings = <&kp>, <&kp>;
    hold-trigger-key-positions = <KEYS_R THUMBS>;
    hold-trigger-on-release;
)

/* Right-hand HRMs */
ZMK_HOLD_TAP(hmr,
    flavor = "tap-unless-interrupted";
    tapping-term-ms = <U_TAPPING_TERM>;
    quick-tap-ms = <175>;
    require-prior-idle-ms = <150>;
    bindings = <&kp>, <&kp>;
    hold-trigger-key-positions = <KEYS_L THUMBS>;
    hold-trigger-on-release;
)

/* Layer-tap behavior */
ZMK_HOLD_TAP(lt,
    flavor = "tap-preferred";
    tapping-term-ms = <U_TAPPING_TERM>;
    quick-tap-ms = <175>;
    bindings = <&mo>, <&kp>;
    retro-tap;
)

// Redefine the Miryoku macros
#define U_MT_L(MOD, TAP) &hml MOD TAP
#define U_MT_R(MOD, TAP) &hmr MOD TAP
#define U_LT(LAYER, TAP) &lt LAYER TAP

// Use left or right home row mods based on key position
#define U_MT(MOD, TAP) U_MT_L(MOD, TAP)
