#pragma once

enum e_graphics_data_format
{
    _graphics_data_format_unspecified,

    _graphics_data_format_r32g32b32a32_typeless,
    _graphics_data_format_r32g32b32a32_float,
    _graphics_data_format_r32g32b32a32_uint,
    _graphics_data_format_r32g32b32a32_sint,
    _graphics_data_format_r32g32b32_typeless,
    _graphics_data_format_r32g32b32_float,
    _graphics_data_format_r32g32b32_uint,
    _graphics_data_format_r32g32b32_sint,
    _graphics_data_format_r16g16b16a16_typeless,
    _graphics_data_format_r16g16b16a16_float,
    _graphics_data_format_r16g16b16a16_unorm,
    _graphics_data_format_r16g16b16a16_uint,
    _graphics_data_format_r16g16b16a16_snorm,
    _graphics_data_format_r16g16b16a16_sint,
    _graphics_data_format_r32g32_typeless,
    _graphics_data_format_r32g32_float,
    _graphics_data_format_r32g32_uint,
    _graphics_data_format_r32g32_sint,
    _graphics_data_format_r32g8x24_typeless,
    _graphics_data_format_d32_float_s8x24_uint,
    _graphics_data_format_r32_float_x8x24_typeless,
    _graphics_data_format_x32_typeless_g8x24_uint,
    _graphics_data_format_r10g10b10a2_typeless,
    _graphics_data_format_r10g10b10a2_unorm,
    _graphics_data_format_r10g10b10a2_uint,
    _graphics_data_format_r11g11b10_float,
    _graphics_data_format_r8g8b8a8_typeless,
    _graphics_data_format_r8g8b8a8_unorm,
    _graphics_data_format_r8g8b8a8_unorm_srgb,
    _graphics_data_format_r8g8b8a8_uint,
    _graphics_data_format_r8g8b8a8_snorm,
    _graphics_data_format_r8g8b8a8_sint,
    _graphics_data_format_r16g16_typeless,
    _graphics_data_format_r16g16_float,
    _graphics_data_format_r16g16_unorm,
    _graphics_data_format_r16g16_uint,
    _graphics_data_format_r16g16_snorm,
    _graphics_data_format_r16g16_sint,
    _graphics_data_format_r32_typeless,
    _graphics_data_format_d32_float,
    _graphics_data_format_r32_float,
    _graphics_data_format_r32_uint,
    _graphics_data_format_r32_sint,
    _graphics_data_format_r24g8_typeless,
    _graphics_data_format_d24_unorm_s8_uint,
    _graphics_data_format_r24_unorm_x8_typeless,
    _graphics_data_format_x24_typeless_g8_uint,
    _graphics_data_format_r8g8_typeless,
    _graphics_data_format_r8g8_unorm,
    _graphics_data_format_r8g8_uint,
    _graphics_data_format_r8g8_snorm,
    _graphics_data_format_r8g8_sint,
    _graphics_data_format_r16_typeless,
    _graphics_data_format_r16_float,
    _graphics_data_format_d16_unorm,
    _graphics_data_format_r16_unorm,
    _graphics_data_format_r16_uint,
    _graphics_data_format_r16_snorm,
    _graphics_data_format_r16_sint,
    _graphics_data_format_r8_typeless,
    _graphics_data_format_r8_unorm,
    _graphics_data_format_r8_uint,
    _graphics_data_format_r8_snorm,
    _graphics_data_format_r8_sint,
    _graphics_data_format_a8_unorm,
    _graphics_data_format_r1_unorm,
    _graphics_data_format_r9g9b9e5_sharedexp,
    _graphics_data_format_r8g8_b8g8_unorm,
    _graphics_data_format_g8r8_g8b8_unorm,
    _graphics_data_format_bc1_typeless,
    _graphics_data_format_bc1_unorm,
    _graphics_data_format_bc1_unorm_srgb,
    _graphics_data_format_bc2_typeless,
    _graphics_data_format_bc2_unorm,
    _graphics_data_format_bc2_unorm_srgb,
    _graphics_data_format_bc3_typeless,
    _graphics_data_format_bc3_unorm,
    _graphics_data_format_bc3_unorm_srgb,
    _graphics_data_format_bc4_typeless,
    _graphics_data_format_bc4_unorm,
    _graphics_data_format_bc4_snorm,
    _graphics_data_format_bc5_typeless,
    _graphics_data_format_bc5_unorm,
    _graphics_data_format_bc5_snorm,
    _graphics_data_format_b5g6r5_unorm,
    _graphics_data_format_b5g5r5a1_unorm,
    _graphics_data_format_b8g8r8a8_unorm,
    _graphics_data_format_b8g8r8x8_unorm,
    _graphics_data_format_r10g10b10_xr_bias_a2_unorm,
    _graphics_data_format_b8g8r8a8_typeless,
    _graphics_data_format_b8g8r8a8_unorm_srgb,
    _graphics_data_format_b8g8r8x8_typeless,
    _graphics_data_format_b8g8r8x8_unorm_srgb,
    _graphics_data_format_bc6h_typeless,
    _graphics_data_format_bc6h_uf16,
    _graphics_data_format_bc6h_sf16,
    _graphics_data_format_bc7_typeless,
    _graphics_data_format_bc7_unorm,
    _graphics_data_format_bc7_unorm_srgb,
    _graphics_data_format_ayuv,
    _graphics_data_format_y410,
    _graphics_data_format_y416,
    _graphics_data_format_nv12,
    _graphics_data_format_p010,
    _graphics_data_format_p016,
    _graphics_data_format_420_opaque,
    _graphics_data_format_yuy2,
    _graphics_data_format_y210,
    _graphics_data_format_y216,
    _graphics_data_format_nv11,
    _graphics_data_format_ai44,
    _graphics_data_format_ia44,
    _graphics_data_format_p8,
    _graphics_data_format_a8p8,
    _graphics_data_format_b4g4r4a4_unorm,
    _graphics_data_format_p208,
    _graphics_data_format_v208,
    _graphics_data_format_v408,

    k_num_graphics_data_formats
};

extern BCS_DEBUG_API const char* graphics_data_format_to_string(e_graphics_data_format graphics_data_format);
#ifdef __dxgiformat_h__
extern BCS_DEBUG_API BCS_RESULT graphics_data_format_to_dxgi_format(e_graphics_data_format graphics_data_format, DXGI_FORMAT& dxgi_format);
extern BCS_DEBUG_API BCS_RESULT dxgi_format_to_graphics_data_format(DXGI_FORMAT dxgi_format, e_graphics_data_format& graphics_data_format);
#endif

#ifdef __cplusplus

#define c_type_1(type, name) union name##1      \
{                                               \
    name##1() :data{ } {}                       \
    name##1(type x) :data{ x } {}               \
    type data[1];                               \
    struct { type x; };                         \
}                                       
#define c_type_2(type, name) union name##2                                  \
{                                                                           \
    name##2() :data{ } {}                                                   \
    name##2(type x, type y) :data{ x,y } {}                                 \
    name##2(name##1 value) :data{ value.x, value.x } {}                     \
    type data[2];                                                           \
    struct { type x, y; };                                                  \
}
#define c_type_3(type, name) union name##3                                  \
{                                                                           \
    name##3() :data{ } {}                                                   \
    name##3(type x, type y, type z) :data{ x,y,z } {}                       \
    name##3(name##1 value) :data{ value.x, value.x, value.x } {}            \
    name##3(name##2 value) :data{ value.x, value.y } {}                     \
    type data[3];                                                           \
    struct { type x, y, z; };                                               \
    name##2 xy;                                                             \
}
#define c_type_4(type, name) union name##4                                  \
{                                                                           \
    name##4() :data{ } {}                                                   \
    name##4(type x, type y, type z, type w) :data{ x,y,z,w } {}             \
    name##4(name##1 value) :data{ value.x, value.x, value.x, value.x } {}   \
    name##4(name##2 value) :data{ value.x, value.y, value.x, value.y } {}   \
    name##4(name##3 value) :data{ value.x, value.y, value.z } {}            \
    type data[4];                                                           \
    struct { type x, y, z, w; };                                            \
    name##3 xyz;                                                            \
    name##2 xy;                                                             \
}

#else

#define c_type_1(type, name) typedef union { name(type x) :data{x} {} type data[1]; struct { type x; }; } name
#define c_type_2(type, name) typedef union { name(type x, type ) :data{x,y} {} type data[2]; struct { type x, y; }; } name
#define c_type_3(type, name) typedef union { name(type x, type y, type z) :data{x,y,z} {} type data[3]; struct { type x, y, z; }; } name
#define c_type_4(type, name) typedef union { name(type x, type y, type z, type w) :data{x,y,z,w} {} type data[4]; struct { type x, y, z, w; }; } name

#endif

c_type_1(uint32_t, bool);
c_type_2(uint32_t, bool);
c_type_3(uint32_t, bool);
c_type_4(uint32_t, bool);
c_type_1(int32_t, int);
c_type_2(int32_t, int);
c_type_3(int32_t, int);
c_type_4(int32_t, int);
c_type_1(uint32_t, uint);
c_type_2(uint32_t, uint);
c_type_3(uint32_t, uint);
c_type_4(uint32_t, uint);
c_type_1(float, float);
c_type_2(float, float);
c_type_3(float, float);
c_type_4(float, float);

typedef union
{
    struct
    {
        float _11, _12, _13;
        float _21, _22, _23;
        float _31, _32, _33;
    };
    float m[3][3];
} float3x3;

typedef union
{
    struct
    {
        float _11, _12, _13, _14;
        float _21, _22, _23, _24;
        float _31, _32, _33, _34;
    };
    float m[3][4];
    float f[12];
} float3x4;

typedef union
{
    struct
    {
        float _11, _12, _13;
        float _21, _22, _23;
        float _31, _32, _33;
        float _41, _42, _43;
    };
    float m[4][3];
    float f[12];
} float4x3;

typedef union
{
    struct
    {
        float _11, _12, _13, _14;
        float _21, _22, _23, _24;
        float _31, _32, _33, _34;
        float _41, _42, _43, _44;
    };
    float m[4][4];
    float f[16];
} float4x4;
