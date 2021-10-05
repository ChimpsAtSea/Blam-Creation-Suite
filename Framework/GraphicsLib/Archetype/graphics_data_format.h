#pragma once

enum e_graphics_data_format
{
    _graphics_data_format_rgba8,
    _graphics_data_format_depth_float32,
};

#ifdef __cplusplus

#define c_type_1(type, name) union name { name(type x) :data{x} {} type data[1]; struct { type x; }; }
#define c_type_2(type, name) union name { name(type x, type ) :data{x,y} {} type data[2]; struct { type x, y; }; }
#define c_type_3(type, name) union name { name(type x, type y, type z) :data{x,y,z} {} type data[3]; struct { type x, y, z; }; }
#define c_type_4(type, name) union name { name(type x, type y, type z, type w) :data{x,y,z,w} {} type data[4]; struct { type x, y, z, w; }; }

#else

#define c_type_1(type, name) typedef union { name(type x) :data{x} {} type data[1]; struct { type x; }; } name
#define c_type_2(type, name) typedef union { name(type x, type ) :data{x,y} {} type data[2]; struct { type x, y; }; } name
#define c_type_3(type, name) typedef union { name(type x, type y, type z) :data{x,y,z} {} type data[3]; struct { type x, y, z; }; } name
#define c_type_4(type, name) typedef union { name(type x, type y, type z, type w) :data{x,y,z,w} {} type data[4]; struct { type x, y, z, w; }; } name

#endif

c_type_1(unsigned long, bool1);
c_type_2(unsigned long, bool2);
c_type_3(unsigned long, bool3);
c_type_4(unsigned long, bool4);
c_type_1(long, int1);
c_type_2(long, int2);
c_type_3(long, int3);
c_type_4(long, int4);
c_type_1(unsigned long, uint1);
c_type_2(unsigned long, uint2);
c_type_3(unsigned long, uint3);
c_type_4(unsigned long, uint4);
c_type_1(float, float1);
c_type_2(float, float2);
c_type_3(float, float3);
c_type_4(float, float4);

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
