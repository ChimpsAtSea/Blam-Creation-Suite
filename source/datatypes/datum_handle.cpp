/*
DATUM_HANDLE.CPP
Monday, February 24, 2020 12:39:32 AM
*/

#include <limits.h>

#include <datatypes/datum_handle.h>

/* ---------- code */

c_datum_handle::c_datum_handle() :
    c_datum_handle(0)
{
}

c_datum_handle::c_datum_handle(unsigned long value) :
    m_value(value)
{
}

c_datum_handle::c_datum_handle(unsigned short index, unsigned short identifier) :
    c_datum_handle(static_cast<unsigned long>(index) | (static_cast<unsigned short>(identifier) << 16))
{
}

c_datum_handle::c_datum_handle(const c_datum_handle &other) :
    c_datum_handle(other.m_value)
{
}

unsigned long c_datum_handle::get_value() const
{
    return m_value;
}

unsigned short c_datum_handle::get_index() const
{
    return static_cast<unsigned short>(m_value & USHRT_MAX);
}

unsigned short c_datum_handle::get_identifier() const
{
    return static_cast<unsigned short>(m_value >> 16);
}

c_datum_handle::operator unsigned long() const
{
    return m_value;
}
