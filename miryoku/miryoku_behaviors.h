// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

/ {
    behaviors {
        // Left-hand home row mods
        lhm: left_home_row_mods {
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            flavor = "tap-unless-interrupted";    
            tapping-term-ms = <280>;             
            quick-tap-ms = <200>;                
            require-prior-idle-ms = <150>;       
            bindings = <&kp>, <&kp>;
            
            // Only trigger mods for right-hand keys
            hold-trigger-key-positions = <
                6  7  8  9  10 11    // Right top row
                18 19 20 21 22 23    // Right home row
                30 31 32 33 34 35    // Right bottom row
                39 40 41             // Right thumb keys
            >;
            hold-trigger-on-release;  
        };

        // Right-hand home row mods
        rhm: right_home_row_mods {
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            flavor = "tap-unless-interrupted";
            tapping-term-ms = <280>;
            quick-tap-ms = <200>;
            require-prior-idle-ms = <150>;
            bindings = <&kp>, <&kp>;
            
            // Only trigger mods for left-hand keys
            hold-trigger-key-positions = <
                0  1  2  3  4  5     // Left top row
                12 13 14 15 16 17    // Left home row
                24 25 26 27 28 29    // Left bottom row
                36 37 38             // Left thumb keys
            >;
            hold-trigger-on-release;
        };

        // Layer taps remain the same
        u_lt: u_lt {
            compatible = "zmk,behavior-hold-tap";
            #binding-cells = <2>;
            tapping-term-ms = <280>;
            quick-tap-ms = <200>;
            flavor = "tap-preferred";
            bindings = <&mo>, <&kp>;
            retro-tap;
        };
    };
};

// Redefine the Miryoku macros
#define U_MT_L(MOD, TAP) &lhm MOD TAP
#define U_MT_R(MOD, TAP) &rhm MOD TAP
#define U_LT(LAYER, TAP) &u_lt LAYER TAP

// Use left or right home row mods based on key position (for QWERTY layout)
#define U_MT(MOD, TAP) U_MT_L(MOD, TAP)
