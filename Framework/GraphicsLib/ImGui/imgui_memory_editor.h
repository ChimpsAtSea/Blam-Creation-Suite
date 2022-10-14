#pragma once

struct s_imgui_memory_editor_settings
{
    BCS_SHARED s_imgui_memory_editor_settings();

    bool        Open;                                                                   // = true   // set to false when DrawWindow() was closed. ignore if not using DrawWindow().
    bool        ReadOnly;                                                               // = false  // disable any editing.
    int         Cols;                                                                   // = 16     // number of columns to display.
    bool        OptShowOptions;                                                         // = true   // display options button/context menu. when disabled, options will be locked unless you provide your own UI for them.
    bool        OptShowDataPreview;                                                     // = false  // display a footer previewing the decimal/binary/hex/float representation of the currently selected bytes.
    bool        OptShowHexII;                                                           // = false  // display values in HexII representation instead of regular hexadecimal: hide null/zero bytes, ascii values as ".X".
    bool        OptShowAscii;                                                           // = true   // display ASCII representation on the right side.
    bool        OptGreyOutZeroes;                                                       // = true   // display null/zero bytes using the TextDisabled color.
    bool        OptUpperCaseHex;                                                        // = true   // display hexadecimal values as "FF" instead of "ff".
    int         OptMidColsCount;                                                        // = 8      // set to 0 to disable extra spacing between every mid-cols.
    int         OptAddrDigitsCount;                                                     // = 0      // number of addr digits to display (default calculated based on maximum displayed addr).
    float       OptFooterExtraHeight;                                                   // = 0      // space to reserve at the bottom of the widget to add custom widgets
    ImU32       HighlightColor;                                                         //          // background color of highlighted bytes.
    ImU8        (*ReadFn)(const ImU8* data, size_t off);                                // = 0      // optional handler to read bytes.
    void        (*WriteFn)(ImU8* data, size_t off, ImU8 d);                             // = 0      // optional handler to write bytes.
    bool        (*HighlightFn)(const ImU8* data, size_t off);                           //= 0       // optional handler to return Highlight property (to support non-contiguous highlighting).
    bool        (*CustomUIFn)(void* userdata, void* data, size_t size);                                                        // = 0      // optional handler to show custom ui
};

BCS_SHARED extern void imgui_memory_editor(
    s_imgui_memory_editor_settings& settings, 
    void* data, 
    uint64_t data_size,
    void* userdata = nullptr);
