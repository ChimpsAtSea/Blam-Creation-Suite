#pragma once

inline ImVec2 operator+(ImVec2 a, ImVec2 const& b) { return { a.x + b.x, a.y + b.y }; }
inline ImVec2 operator-(ImVec2 a, ImVec2 const& b) { return { a.x - b.x, a.y - b.y }; }
inline void operator+=(ImVec2& a, ImVec2 const& b) { a.x += b.x; a.y += b.y; }
inline void operator-=(ImVec2& a, ImVec2 const& b) { a.x -= b.x; a.y -= b.y; }
