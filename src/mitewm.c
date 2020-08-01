
#include <X11/Xlib.h>
#include <X11/cursorfont.h>
#include <X11/Xutil.h>
#include <cairo/cairo-xlib.h>
#include <stdlib.h>
#include <stdio.h>

// クライアントの構成ウインドウ識別番号
#define MTWM_CLIENT_WIDGETS    4    // 構成ウインドウの数
    #define MTWM_CLIENT_BOX      0  // Box
    #define MTWM_CLIENT_TITLEBAR 1  // Titlebar
    #define MTWM_CLIENT_EXIT     2  // Exit
    #define MTWM_CLIENT_APP      3  // Application

#define MTWM_MAX(A,B) (A)<(B) ? (B):(A)

// ディスプレイ
Display *mtwm_display;

// 根ウインドウ
Window   mtwm_root_window;

// ---------------------
// ===== configure =====
// ---------------------

// クライアントの枠線の幅。実は処理の大きさにそこそこ影響するようで、狭いほど処理が小さくなる。
const unsigned int mtwm_config_box_border            = 6;
// クライアントのTITLEBARの右端とAPPの右端のX座標の差 = EXITの幅
const unsigned int mtwm_config_titlebar_width_margin = 25;
// TITLEBARの高さ
const unsigned int mtwm_config_titlebar_height       = 25;

// クライアントの影の粗さ。必ず0より大きい値に！
// 1.5~2.5 ぐらいがいい感じ。粗すぎると変な見た目になるし、逆に
const double mtwm_config_shadow_roughness            = 2.0;

const unsigned int mtwm_width_diff  = mtwm_config_box_border*2;
const unsigned int mtwm_height_diff = mtwm_config_titlebar_height + mtwm_config_box_border*2;

#include "mtwm_client.c"
#include "mtwm_client_table.c"
#include "mtwm_background.c"
#include "mtwm_window_creation.c"
#include "mtwm_window_resize.c"
#include "mtwm_test.c"
#include "mtwm_main.c"

