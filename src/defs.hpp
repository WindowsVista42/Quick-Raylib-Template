#ifndef DEFS_HPP
#define DEFS_HPP

#include <cstdint>
#include <raylib.h>
#include <raymath.h>

typedef float  f32;
typedef double f64;

typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;
typedef intptr_t isize;

typedef uint8_t   u8;
typedef uint16_t  u16;
typedef uint32_t  u32;
typedef uint64_t  u64;
typedef uintptr_t usize;

#define every(name, end) (usize name = 0; name < end; name += 1)
#define range(name, start, end) (usize name = start; name < end; name += 1)
#define iter(ty, name, start, end) (ty name = start; name != end; name ++)

#define ARRAY_OP(ty) \
ty& operator [] (int i) { \
    return ((ty*)this)[i]; \
}

union v2 { 
    struct {
        f32 x;
        f32 y;
    };

    Vector2 v;

    ARRAY_OP(f32)
};

union v3 {
    struct {
        f32 x;
        f32 y;
        f32 z;
    };

    Vector3 v;

    ARRAY_OP(f32)
};

union v4 {
    struct {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };

    Vector4 v;

    ARRAY_OP(f32)
};

struct p2 { 
    i32 x;
    i32 y;

    ARRAY_OP(i32)
};

struct p3 {
    i32 x;
    i32 y;
    i32 z;

    ARRAY_OP(i32)
};

struct p4 {
    i32 x;
    i32 y;
    i32 z;
    i32 w;

    ARRAY_OP(i32)
};

struct m22 {
    v2 xs;
    v2 ys;

    ARRAY_OP(v2)
};

struct m33 {
    v3 xs;
    v3 ys;
    v3 zs;

    ARRAY_OP(v3)
};

union m44 {
    struct {
        v4 xs;
        v4 ys;
        v4 zs;
        v4 ws;
    };

    struct {
        f32 m0, m4, m8,  m12;
        f32 m1, m5, m9,  m13;
        f32 m2, m6, m10, m14;
        f32 m3, m7, m11, m15;
    };

    Matrix m;

    ARRAY_OP(v4)
};

#endif //DEFS_HPP
