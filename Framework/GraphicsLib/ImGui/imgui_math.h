#pragma once

inline ImVec2 operator+(ImVec2 a, ImVec2 const& b) { a.x += b.x; a.y += b.y; return a; }
inline ImVec2 operator-(ImVec2 a, ImVec2 const& b) { a.x -= b.x; a.y -= b.y; return a; }
inline ImVec2 operator*(ImVec2 a, ImVec2 const& b) { a.x *= b.x; a.y *= b.y; return a; }
inline ImVec2 operator/(ImVec2 a, ImVec2 const& b) { a.x /= b.x; a.y /= b.y; return a; }
inline void operator+=(ImVec2& a, ImVec2 const& b) { a.x += b.x; a.y += b.y; }
inline void operator-=(ImVec2& a, ImVec2 const& b) { a.x -= b.x; a.y -= b.y; }
inline void operator*=(ImVec2& a, ImVec2 const& b) { a.x *= b.x; a.y *= b.y; }
inline void operator/=(ImVec2& a, ImVec2 const& b) { a.x /= b.x; a.y /= b.y; }

inline ImVec2 operator+(ImVec2 a, float const& b) { a.x += b; a.y += b; return a; }
inline ImVec2 operator-(ImVec2 a, float const& b) { a.x -= b; a.y -= b; return a; }
inline ImVec2 operator*(ImVec2 a, float const& b) { a.x *= b; a.y *= b; return a; }
inline ImVec2 operator/(ImVec2 a, float const& b) { a.x /= b; a.y /= b; return a; }
inline void operator+=(ImVec2& a, float const& b) { a.x += b; a.y += b; }
inline void operator-=(ImVec2& a, float const& b) { a.x -= b; a.y -= b; }
inline void operator*=(ImVec2& a, float const& b) { a.x *= b; a.y *= b; }
inline void operator/=(ImVec2& a, float const& b) { a.x /= b; a.y /= b; }
