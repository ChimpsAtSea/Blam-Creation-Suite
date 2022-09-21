#pragma once

enum e_graphics_data_format
{
    _graphics_data_format_unspecified,
    _graphics_data_format_r8_unorm,
    _graphics_data_format_r8g8_unorm,
    _graphics_data_format_r8g8b8a8_unorm,
    _graphics_data_format_r32g32_float,
    _graphics_data_format_r32g32b32_float,
    _graphics_data_format_r32g32b32a32_float,
    _graphics_data_format_depth_float32,
};

BCS_DEBUG_API const char* graphics_data_format_to_string(e_graphics_data_format graphics_data_format);

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
