// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

#pragma once

// Define key positions for Corne (42-key layout)
// Left-hand keys (0-4, 12-16, 24-28)
#define KEYS_L 0 1 2 3 4 12 13 14 15 16 24 25 26 27 28

// Right-hand keys (6-11, 18-23, 30-35)
#define KEYS_R 6 7 8 9 10 11 18 19 20 21 22 23 30 31 32 33 34 35

// Thumb keys (36-41)
#define THUMBS 36 37 38 39 40 41

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

// Use left or right home row mods based on key position (for QWERTY layout)
#define U_MT(MOD, TAP) U_MT_L(MOD, TAP)
